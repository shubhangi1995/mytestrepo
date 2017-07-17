/**
* Implements the poi events (popup and click event to open the detail in a left window).
* Project: Map Rnki Copyright: ]init[ AG , Germany 2017
* @author pfavero
*/

'use strict';

IPWA_MAP.Map.popup = {
  parentMap: null, // ol3 map ol.Map
  mapWidth: null,
  popup: null, // popup container
  olPopupTemplate: null,
  maxZoom: null,
  currentClusterFs: [],
  markerLabel: '',
  selFeature: null,

  POPUP_X_OFFSET: 50,
  POPUP_Y_OFFSET: 50,

  init: function (map, markerLabel, maxZoom) {
    this.parentMap = map;
    this.mapWidth = this.parentMap.getSize()[0];
    if (markerLabel) {
      this.markerLabel = markerLabel;
    }
    this.maxZoom = maxZoom;

    this.initPopup();

    this.addEventHandlers();
  },

  addEventHandlers: function () {
    var _this = this;
    this.parentMap.on('singleclick', function (evt) {
      var features = _this.getFeaturesAt(evt.pixel);
      if (!_.isEmpty(features)) {
        _this.zoomOrShowPopup(features, evt.pixel);
      }
    });
  },

  initPopup: function () {
    var _this = this;
    this.$popup = jQuery('.map-popup');
    var _olPopupSource = jQuery('#template-popup').html();
    this.olPopupTemplate = Handlebars.compile(_olPopupSource);
    var _close = this.$popup.find('.map-btn-close');
    this.$popupContent = this.$popup.find('.map-popup-content');
    this.$popup.append(this.$popupContent);

    this.$popup.hide();

    _close.on('click', function () {
      _this.closePopup();
    });
  },

  displayPopup: function (features, pixel) {
    if (!_.isEmpty(features)) {
      var _id = features[0].get('Node ID');
      var _this = this;
      jQuery.ajax({
        url: 'project-single-view-json/' + _id,
        type: 'GET',
        dataType: 'json',
        success: function (data) {
          // console.log('data.features', data.features);
          if (data && data.features && data.features.length > 0) {
            _this.setDataInPopup(data, 0, features);
            _this.closePopup();

            var _coordinates = features[0].getGeometry().getFirstCoordinate();

            _this.$popup.show();
            var _popupLeft = 120;
            _this.$popup.css('left', _popupLeft);
            features[0].set('type', 'selected');
            _this.selFeature = features[0];

            _this.centerSelPoi(_coordinates, _popupLeft);
          }
        },
        error: function (e) {
          // called when there is an error
          console.log('Error: ', e);
        }
      });
    } else {
      this.closePopup();
    }
  },

  getDataForPaging: function (index, olFeatures) {
    var _id = olFeatures[index].get('Node ID');
    var _this = this;
    jQuery.ajax({
      url: 'project-single-view-json/' + _id,
      type: 'GET',
      dataType: 'json',
      success: function (data) {
        _this.setDataInPopup(data, index, olFeatures);
      },
      error: function (e) {
        // called when there is an error
        console.log('Error: ', e);
      }
    });
  },

  setDataInPopup: function (data, index, olFeatures) {
    var _properties;

    if (data && data.features && data.features.length > 0 && data.features[index]) {
      _properties = data.features[index].properties;
    }

    var _topics = [];
    if (_properties && _properties.field_themenzuweisung !== '') {
      _topics = _properties.field_themenzuweisung.split(',');
    }

    var _olPopupHtml = this.olPopupTemplate({
      contentType: _properties?_properties.type:'',
      title: _properties?_properties.title:'',
      topics: _topics,
      date: _properties?_properties.views_conditional:''
    });
    this.$popupContent.html(_olPopupHtml);
    this.addPagingToPopup(olFeatures, index);
  },

  addPagingToPopup: function (olFeatures, index) {
    var _this = this;
    this.btnGoBackward = this.$popupContent.find('.btn-go-backward');
    this.btnGoForward = this.$popupContent.find('.btn-go-forward');
    if (olFeatures.length === 1) {
      this.btnGoBackward.hide();
      this.btnGoForward.hide();
    } else {
      if (index === 0) {
        this.btnGoBackward.addClass('disabled');
        this.btnGoBackward.on('click', function (evt) { evt.preventDefault(); });
      } else {
        this.btnGoBackward.on('click', function (evt) {
          evt.preventDefault();
          _this.getDataForPaging(index - 1, olFeatures);
        });
      }
      if (index === olFeatures.length - 1) {
        this.btnGoForward.addClass('disabled');
        this.btnGoForward.on('click', function (evt) { evt.preventDefault(); });
      } else {
        this.btnGoForward.on('click', function (evt) {
          evt.preventDefault();
          _this.getDataForPaging(index + 1, olFeatures);
        });
      }
    }
  },

  centerSelPoi: function (coordinates, popupLeft) {
    var _this = this;
    setTimeout(function () {
      var _centerPx = _this.parentMap.getPixelFromCoordinate(coordinates);
      var _center = _this.parentMap.getCoordinateFromPixel([_centerPx[0] + 50, _centerPx[1] + 100]);
      var _view = _this.parentMap.getView();
      _view.animate(
        { zoom: _view.getZoom(), center: _center }
      );
    }, 800);
  },

  zoomOrShowPopup: function (features, pixel) {
    var _hasMany = null;

    // Check if Marker is clustered
    _hasMany = features.length > 1;

    this.closePopup();

    if (_hasMany) {
      if (this.parentMap.getView().getZoom() === this.maxZoom) {
        // show the detail with more elements
        this.currentClusterFs = features;
        this.displayPopup(features, pixel);
      } else { // zoom
        this.currentClusterFs = [];
        var coordinatesArr = [];
        features.forEach(function (el, index) {
          coordinatesArr.push(el.getGeometry().getFirstCoordinate());
        });
        var extent = ol.extent.boundingExtent(coordinatesArr);
        this.zoomToExtend(extent);
      }
    } else {
      // show the detail
      this.currentClusterFs = [];
      this.displayPopup(features, pixel);
    }
  },

  closePopup: function () {
    this.$popup.hide();
    if (this.selFeature) {
      this.selFeature.set('type', 'notSelected');
    }
  },

  /**
  * Zooms to the extent with animation.
  * @param {ol.extend} extent
  */
  zoomToExtend: function (extent) {
    var view = this.parentMap.getView();
    var zoom = this.parentMap.getView().getZoom();
    view.fit(extent, { padding: [10, 20, 10, 20], duration: 1000, maxZoom: zoom + 3 });
  },

  getFeatureId: function (features) {
    var id = 0;
    for (var i = 0; i < features.length; i++) {
      id = features[i].get('id');
    }
    return id;
  },


  getFeatureIds: function (features) {
    var _ids = [];
    for (var i = 0; i < features.length; i++) {
      _ids.push(features[i].get('id'));
    }
    return _ids;
  },

  getFeaturesAt: function (pixel) {
    var features = [];
    var clusters = this.getClusterAt(pixel);
    // Only use first found feature/cluster, which always overlaps all other
    // "lower" features on map
    if (clusters.length > 0) {
      var cluster = clusters[0];
      features = cluster.get('features');
    }
    return features;
  },

  getClusterAt: function (pixel) {
    var clusters = [];
    this.parentMap.forEachFeatureAtPixel(pixel, function (cl, layer) {
      clusters.push(cl);
    });
    return clusters;
  }
};
