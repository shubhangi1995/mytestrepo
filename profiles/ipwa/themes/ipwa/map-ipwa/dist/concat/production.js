/**
* Initialization of the map component and connection to the filter
* Project: Map Ipwa Copyright: ]init[ AG , Germany 2017
* @author Paolo Favero
*/

'use strict';

var IPWA_MAP = window.Ipwa_MAP || {};
IPWA_MAP.Map = {};

// document ready
jQuery(function () {
  IPWA_MAP.Map.mapView.init();

  // the filter will be called from html in views-view--json-map.tpl.php
  IPWA_MAP.filter.connectFilterToMap();
});


/**
 * It connects buttons of the filter to the map
 * and
 */
IPWA_MAP.filter = {
  connectFilterToMap: function () {
    var _this = this;
    var _str = '';
    var _btn = jQuery('#edit-submit-projekt-map');
    // var _textField = jQuery('#edit-search-api-views-fulltext');
    if (_btn.length > 0) {
      _btn.on('click', function (event) {
        event.preventDefault();
        // _btn.button('loading');
        _str = _this.buildStrParameters();
        // console.log(_str);
        IPWA_MAP.Map.poiLayer.updateData(_str, _btn);
      });

    //   _textField.keypress(function (event) {
    //     if (event.keyCode === 13) {
    //       event.preventDefault();
    //       event.stopPropagation();
    //       _btn.button('loading');
    //       _str = _this.buildStrParameters();
    //       // console.log(_str);
    //       IPWA_MAP.Map.poiLayer.updateData(_str, _btn);
    //       return false; // this will stop the default event triggering
    //     }
    //     return false;
    //   });

    //   // Initialization
      _str = IPWA_MAP.filter.buildStrParameters();
      console.log(_str);
      IPWA_MAP.Map.poiLayer.updateData(_str, _btn);
    }
  },

  buildStrParameters: function () {
    var _form = jQuery('#views-exposed-form-projekt-map-project-map');
    var _filter = [_form.find('#edit-type'), // search
      _form.find('#edit-field-themenzuweisung'), // Inhaltstyp
      _form.find('#edit-field-akteurstyp'), // Dieser Artikel gehört zu
      _form.find('#edit-field-plz'), // plz
      _form.find('#edit-field-themenzuweisung-1') // Alle Themen
    ];
    // var _f2 = _form.find('.sol-selection');
    // for (var i = 0; i < _f2.length; i++) {
    //   _filter.push(_f2[i]);
    // }
    // console.log('_filter:', _filter);

    // build the string for the ajax request
    var _str = '';
    for (var _index = 0; _index < _filter.length; _index++) {
      var _item = jQuery(_filter[_index]);
      if (_item && _item.length > 0) {
        var _text = _item.val();
        var _options = _item.find('input:checked');
        if (_options && _options.length > 0) {
          if (_options.val() !== 'All') {
            // var _str2 = '';
            var _param = _options[0].name;
            // eslint-disable-next-line
            _options.each(function (index, opt) {
              _str += _param + '=' + jQuery(opt).val() + '&';
            });
          }
        } else if (_text) {
          _text = _text.trim();
          if (_text !== '' && _text !== 'All') {
            _text = _text.replace(/ /g, '+');
            _str += _item.attr('name') + '=' + _text+ '&';
          }
        }
      }
    }
    _str = _str.substring(0, _str.length - 1);
    console.log('_str:     ', _str);
    return _str;
  }
};

/**
* Initialization of the layer for Countries
* Project: Map Rnki Copyright: ]init[ AG , Germany 2017
* @author Paolo Favero
*/

'use strict';

IPWA_MAP.Map.countryLayer = {
  conf: {
    minResolution: 400,
    style: {
      strokeColor: '#C1C2BE',
      strokeWidth: 1,
      fillColor: '#F5F5F5'
    }
  },
  layer: null,
  parentMap: null,
  init: function (map) {
    var _this = this;
    this.parentMap = map;

    var format = new ol.format.TopoJSON();
    var features = format.readFeatures(IPWA_MAP.europeTopojson, {
      featureProjection: 'EPSG:25832'
    });
    var source = new ol.source.Vector();
    source.addFeatures(features);
    this.layer = new ol.layer.Vector({
      layerName: 'countryLayer',
      source: source,
      minResolution: _this.conf.minResolution,
      style: new ol.style.Style({
        fill: new ol.style.Fill({
          color: _this.conf.style.fillColor
        }),
        stroke: new ol.style.Stroke({
          color: _this.conf.style.strokeColor,
          width: _this.conf.style.strokeWidth
        })
      })
    });
    this.parentMap.addLayer(this.layer);
  }
};

/**
* Initialization of the map with its controls and layers
* Project: Map Ipwa Copyright: ]init[ AG , Germany 2017
* @author Paolo Favero
*/

'use strict';

IPWA_MAP.Map.mapView = {
  // variables /////////////////////////////////////////////////////////////////
  $mapDiv: null,
  map: null,
  saveMapBtn: null,
  isMobile: false,
  conf: {
    projection: 'EPSG:25832',
    minZoom: 2,
    maxZoom: 11,
    extent: [-46133.17, 5048875.268575671, 1206211.101424329, 6301219.54],
    restrictedExtent: {
      minLon: 6,
      minLat: 47,
      maxLon: 15,
      maxLat: 55
    },
    initialExtent: {
      center: { lon: 7.45, lat: 51.43 },
      zoom: 4
    },
    detailInitialExtent: {
      zoom: 8
    }
  },

  // methods ///////////////////////////////////////////////////////////////////
  init: function () {
    // console.log('start application');
    var restrictedExtent = [
      this.conf.restrictedExtent.minLon,
      this.conf.restrictedExtent.minLat,
      this.conf.restrictedExtent.maxLon,
      this.conf.restrictedExtent.maxLat
    ];

    var projection = ol.proj.get(this.conf.projection);
    // determines max zoom level
    projection.setExtent(this.conf.extent);

    this.map = new ol.Map({
      target: 'footer_map',
      controls: [],
      interactions: [],
      view: new ol.View({
        projection: projection,
        center: ol.proj.fromLonLat([this.conf.initialExtent.center.lon, this.conf.initialExtent.center.lat],
          this.conf.projection),
        zoom: this.conf.initialExtent.zoom,
        minZoom: this.conf.minZoom,
        maxZoom: this.conf.maxZoom,
        extent: ol.extent.applyTransform(restrictedExtent,
          ol.proj.getTransform('EPSG:4326', this.conf.projection))
      })
    });

    this.addAttribution();
    this.addInteractions();
    this.addControls();

    IPWA_MAP.Map.countryLayer.init(this.map);
    IPWA_MAP.Map.webatlasLayer.init(this.map, this.conf.projection);

    IPWA_MAP.Map.poiLayer.init(this.map, this.conf.projection, this.conf.detailInitialExtent.zoom);
    IPWA_MAP.Map.poiStyle.init();
    IPWA_MAP.Map.poiLayer.setStyle(function (cluster, resolution) {
      return IPWA_MAP.Map.poiStyle.styleFunction(cluster, resolution);
    });

    var markerLabel = '';
    IPWA_MAP.Map.popup.init(this.map, markerLabel, this.conf.maxZoom);
  },

  /**
  * Add controls to the map. Included:
  * <ul>
  * <li>custom geolocation control</li>
  * <li>zoom control</li>
  * <li>scale control</li>
  * </ul>
  */
  addInteractions: function () {
    this.map.addInteraction(new ol.interaction.DragRotate());
    this.map.addInteraction(new ol.interaction.DoubleClickZoom());
    this.map.addInteraction(new ol.interaction.DragPan());
    this.map.addInteraction(new ol.interaction.KeyboardPan());
    this.map.addInteraction(new ol.interaction.PinchZoom());
    this.map.addInteraction(new ol.interaction.KeyboardZoom());
    this.map.addInteraction(new ol.interaction.MouseWheelZoom());
    this.map.addInteraction(new ol.interaction.DragZoom());
  },

  /**
  * Add controls to the map. Included:
  * <ul>
  * <li>custom geolocation control</li>
  * <li>zoom control</li>
  * <li>scale control</li>
  * </ul>
  */
  addControls: function () {
    this.map.addControl(new ol.control.Zoom({
      zoomInTipLabel: 'Hineinzoomen',
      zoomOutTipLabel: 'Herauszoomen'
    }));
  },

  /**
  * Adds attribution
  */
  addAttribution: function () {
    var _attribution = '<div class="attribution"><a target="_blank" alt="{{text}}" title="{{text}}" href="{{link}}">{{text}}</a></div>';
    var _attributionTemplate = Handlebars.compile(_attribution);
    var _attributionHtml = _attributionTemplate({
      text: IPWA_MAP.Map.webatlasLayer.attributionWebAtlas.text,
      link: IPWA_MAP.Map.webatlasLayer.attributionWebAtlas.link
    });
    jQuery(IPWA_MAP.Map.mapView.map.getViewport()).parent().append(_attributionHtml);
  },

  isIE: function () {
    var ua = window.navigator.userAgent;
    var msie = ua.indexOf('MSIE');
    if (msie > 0 || !!navigator.userAgent.match(/Trident.*rv\:11\./)) { // eslint-disable-line
      return true;
    }
    return false;
  }
};


/**
* Initialization of the layer for POIs
* Project: Map Ipwa Copyright: ]init[ AG , Germany 2017
* @author Paolo Favero
*/

'use strict';

IPWA_MAP.Map.poiLayer = {
  init: function (map, projection, zoom) {
    this.parentMap = map;
    this.projection = projection;

    this.poiLayer = new ol.layer.Vector();
    this.parentMap.addLayer(this.poiLayer);

    this.geoJsonSource = new ol.source.Vector();

    this.clusterSource = new ol.source.Cluster({
      distance: 120,
      source: this.geoJsonSource
    });

    this.poiLayer = new ol.layer.Vector({
      source: this.clusterSource
    });

    this.parentMap.addLayer(this.poiLayer);

    this.mapWarning = jQuery('#map-warning');
    this.mapWarningContent = this.mapWarning.find('.map-warning-content');
    this.totalResult = jQuery('#map-total-result');
  },

  updateData: function (str, btn) {
    var _this = this;
    console.log('---> send ajax request for map data:', (str?'?'+str:'no filter'));
    _this.geoJsonSource.clear();
    var _url = '../sites/default/files/map-static.json';
    if (str) {
      _url = 'map-filter?' + str;
    }
    jQuery.ajax({
      url: _url,
      type: 'GET',
      dataType: 'json',
      success: function (data) {
        // console.log(data);
        if (data) {
          // btn.button('reset');
          _this.geoJsonSource.addFeatures((new ol.format.GeoJSON()).readFeatures(
            data,
            {
              dataProjection: 'EPSG:4326',
              featureProjection: _this.projection
            }
          ));

          // var _count = _this.geoJsonSource.getFeatures().length;
          // _this.totalResult.text(_count);
          /* if (str && str !== '' && _count >= _this.WARNING_COUNT) {
            // _this.mapWarning.modal();
          } else {
            // _this.mapWarning.modal('hide');
          }*/
        }
      },
      error: function (e) {
        // called when there is an error
        // btn.button('reset');
        console.error(e);
      }
    });
  },

  zoomToExtend: function () {
    var src = this.geoJsonSource;
    var extent = src.getExtent();
    var size = this.parentMap.getSize();
    var view = this.parentMap.getView();

    view.fit(extent, size, { padding: [10, 20, 10, 20] });
  },

  zoomToFeature: function (id) {
    var f = this.getFeatureByAttr('id', id);
    var geom = f.getGeometry();
    var size = this.parentMap.getSize();
    var view = this.parentMap.getView();

    var pan = ol.animation.pan({ duration: 1000, source: this.parentMap.getView().getCenter() });
    var zoom = ol.animation.zoom({ duration: 1000, resolution: this.parentMap.getView().getResolution() });
    this.parentMap.beforeRender(pan, zoom);

    view.fit(geom, size, { maxZoom: 8 });
  },

  getFeatureByAttr: function (attr, val) {
    var src = this.geoJsonSource;
    return src.forEachFeature(function (f) {
      var fAttr = f.get(attr);
      if (fAttr === val) {
        return f;
      }
      return null;
    });
  },

  setStyle: function (s) {
    this.poiLayer.setStyle(s);
  }
};


/**
* Style for POI layer
* Project: Map Rnki Copyright: ]init[ AG , Germany 2017
* @author pfavero
**/

'use strict';

IPWA_MAP.Map.poiStyle = {
  // cache key is either size number (cluster) or count (single feature)
  styleCacheCluster: {},
  styleCacheFeature: {},
  topicImgMapping: null,
  CLUSTER_COLOR: '#273753',  // blue for circle
  CLUSTER_EXT_COLOR: 'rgba(0, 69, 120, 0.5)',
  CLUSTER_SEL_COLOR: '#e74712',  // orange for circle
  CLUSTER_EXT_SEL_COLOR: 'rgba(231, 71, 18, 0.5)',
  CLUSTER_BORDER_WIDTH: 14,
  URL_ICON: '/profiles/ipwa/themes/ipwa/map-ipwa/dist/img/',
  imgSrc: '',

  init: function () {},

  styleFunction: function (cluster, resolution) {
    var _size = cluster.get('features').length;
    var _style = null;
    var _f = cluster.get('features')[0];
    if (_size > 1) {
      _style = this.styleCacheCluster[_size + '-' +_f.get('type')];
      if (!_style) {
        _style = this.getClusterStyle(_size, _f.get('type'));
        this.styleCacheCluster[_size + '-' +_f.get('type')] = _style;
      }
    } else {
      var _type = 'notSelected';
      if (_f.get('type') === 'selected') {
        _type = 'selected';
        _style = this.styleCacheFeature[_type];
        if (!_style) {
          _style = this.getSelSingleStyle(_type);
          this.styleCacheFeature[_type] = _style;
        }
      } else {
        _style = this.styleCacheFeature[_type];
        if (!_style) {
          _style = this.getSingleStyle(_type);
          this.styleCacheFeature[_type] = _style;
        }
      }
    }
    return _style;
  },

  getSingleStyle: function () {
    var _image = null;
    var _icon = this.URL_ICON+'pin.png';
    _image = new ol.style.Icon({
      anchor: [0.5, 1],
      opacity: 1,
      src: _icon
    });
    var _style = [new ol.style.Style({
      image: _image
    })];
    return _style;
  },
  getSelSingleStyle: function () {
    var _image = null;
    var _icon = this.URL_ICON+'sel-pin.png';
    _image = new ol.style.Icon({
      anchor: [0.5, 1],
      opacity: 1,
      src: _icon
    });
    var _style = [new ol.style.Style({
      image: _image
    })];
    return _style;
  },
  getClusterStyle: function (size, type) {
    var style = [];
    var fontDim = 14 + (Math.sqrt(size) * 0.65);
    var radius = 12 + (Math.sqrt(size) * 1.3);
    style = [new ol.style.Style({
      image: new ol.style.Circle({
        radius: radius,
        stroke: new ol.style.Stroke({
          color: type!=='selected'?this.CLUSTER_EXT_COLOR:this.CLUSTER_EXT_SEL_COLOR,
          width: this.CLUSTER_BORDER_WIDTH
        }),
        fill: new ol.style.Fill({
          color: type!=='selected'?this.CLUSTER_COLOR:this.CLUSTER_SEL_COLOR
        })
      }),
      text: new ol.style.Text({
        font: 'normal ' + fontDim + 'px BentonSans-Regular, Arial, helvetica, sans-serif',
        text: String(size),
        offsetY: 0,
        fill: new ol.style.Fill({
          color: '#fff'
        })
      })
    })];
    return style;
  }
};

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

    if (data && data.features && data.features.length > 0) {
      _properties = data.features[index].properties;
    }

    var _olPopupHtml = this.olPopupTemplate({
      contentType: _properties?_properties.type:'',
      title: _properties?_properties.title:'',
      topics: _properties?_properties.field_themenzuweisung:'',
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
        this.btnGoBackward.on('click', function (evt) { evt.preventDefault(); });
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
      var _pan = ol.animation.pan({ duration: 1000, source: _this.parentMap.getView().getCenter() });
      var _zoom = ol.animation.zoom({ duration: 1000, resolution: _this.parentMap.getView().getResolution() });
      _this.parentMap.beforeRender(_pan, _zoom);
      _this.parentMap.getView().setCenter(_center);
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
    var size = this.parentMap.getSize();
    var view = this.parentMap.getView();
    var pan = ol.animation.pan({ duration: 1000, source: this.parentMap.getView().getCenter() });
    var zoom = ol.animation.zoom({ duration: 1000, resolution: this.parentMap.getView().getResolution() });
    this.parentMap.beforeRender(pan, zoom);
    view.fit(extent, size, { padding: [10, 20, 10, 20] });
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

/* globals proj4 */

'use strict';

proj4.defs('EPSG:25832', '+proj=utm +zone=32 +ellps=GRS80 +units=m +no_defs');

/**
 * Implements the layer for web atlas WMTS
 * Project: Map Rnki Copyright: ]init[ AG , Germany 2017
 * @author Paolo Favero
 */

'use strict';

IPWA_MAP.Map.webatlasLayer = {
  webatlasLayer: null,
  parentMap: null,
  // info obtained from the capabilities file
  // @link http://sg.geodatenzentrum.de/wmts_webatlasde_grau/1.0.0/WMTSCapabilities.xml
  wmtsWebatlasConf: {
    urls: ['https://sg.geodatenzentrum.de/wmts_webatlasde_grau__63b89fd6-964c-87e3-8900-3e6b1caab5c3?'],
    layer: 'webatlasde_grau',
    matrixSet: 'DE_EPSG_25832_ADV',
    format: 'image/png',
    requestEncoding: 'KVP',
    matrixIds: ['00', '01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12', '13'],
    resolutions: [4891.9698102506645, 2445.9849051253323, 1222.9924525626661, 611.4962262813331,
      305.74811314066653, 152.87405657033375, 76.43702828516668, 38.218514142583295,
      19.109257071291694, 9.554628535645827, 4.777314267822919, 2.3886571339090437,
      1.1943285669545218, 0.5971642834772609],
    origins: [[-46133.17, 6301219.54], [-46133.17, 6301219.54], [-46133.17, 6301219.54],
      [-46133.17, 6301219.54], [-46133.17, 6301219.54],
      [-46133.17, 6301219.54], [-46133.17, 6301219.54], [-46133.17, 6301219.54],
      [-46133.17, 6301219.54], [-46133.17, 6301219.54], [-46133.17, 6301219.54],
      [-46133.17, 6301219.54], [-46133.17, 6301219.54], [-46133.17, 6301219.54]],
    style: 'default',
    wrapX: false
  },
  attributionWebAtlas: {
    text: '© Geobasis-DE / BKG 2017',
    link: 'http://www.bkg.bund.de'
  },
  init: function (map, projCode) {
    var projection = ol.proj.get(projCode);
    this.parentMap = map;
    this.webatlasLayer = new ol.layer.Tile({
      layerName: 'webatlasLayer',
      opacity: 1,
      extent: projection.getExtent(),
      projection: projection,
      source: new ol.source.WMTS({
        urls: this.wmtsWebatlasConf.urls,
        layer: this.wmtsWebatlasConf.layer,
        matrixSet: this.wmtsWebatlasConf.matrixSet,
        format: this.wmtsWebatlasConf.format,
        projection: projection,
        requestEncoding: this.wmtsWebatlasConf.requestEncoding,
        tileGrid: new ol.tilegrid.WMTS(
          {
            matrixIds: this.wmtsWebatlasConf.matrixIds,
            resolutions: this.wmtsWebatlasConf.resolutions,
            origins: this.wmtsWebatlasConf.origins
          }),
        style: this.wmtsWebatlasConf.style,
        wrapX: this.wmtsWebatlasConf.wrapX
      })
    });
    this.parentMap.addLayer(this.webatlasLayer);
  }
};

IPWA_MAP.europeTopojson =
{"type":"Topology","transform":{"scale":[0.0017162736451942758,0.0009617177835903347],"translate":[-68.37109375000003,-21.369042968750037]},"arcs":[[[43617,74000],[4,-45],[-6,-49],[-23,-27],[-22,-38],[-17,-47],[-17,-91],[-2,-62],[-40,26],[-20,17],[-36,5],[-35,-14],[-27,-32],[-36,-10],[-31,10],[-18,24],[-16,12],[-45,16],[-20,35],[15,16],[13,25],[11,36],[14,34],[-44,90],[-10,28],[-36,52],[0,26],[9,24],[-3,20],[5,45],[25,44],[17,53],[29,73],[64,88],[46,-14],[20,1],[12,-32],[4,-3],[-5,-28],[1,-62],[16,-63],[39,-61],[30,-45],[40,-36],[68,-33],[27,-8]],[[52048,79699],[-34,8]],[[52014,79707],[67,120],[25,78],[18,110],[16,35],[0,-50],[-7,-84],[-42,-143],[-43,-74]],[[54737,78515],[-36,20],[-8,16],[18,42],[-13,52],[-26,29],[-53,-44],[-50,0],[-61,-38],[-40,-62],[-38,-22],[-103,12],[-25,-27],[-21,-126],[-13,-24],[-86,5],[-82,-50],[-94,-40],[-47,28],[-27,32],[-51,-6],[-55,-14],[-38,8],[-42,-4],[-80,-24],[-102,8],[-44,21],[-4,19],[3,49],[0,76],[-17,67],[-48,60],[-51,41],[-66,43],[-48,19],[-26,4],[-6,25],[-10,21],[-22,19],[-49,25],[-41,6],[-33,-41]],[[53102,78740],[-25,51],[-25,91],[2,73],[15,72],[71,214],[-4,34],[-51,60],[-64,44],[-35,91],[-129,6],[-121,-5],[-38,4],[-116,39],[-111,62],[-75,36],[-63,41],[-33,43],[-54,-12],[-36,0]],[[52210,79684],[0,7],[-20,75],[21,116],[-39,169],[-63,204],[-5,218],[-4,49],[156,122],[198,132],[44,12],[182,78],[25,6],[164,-15],[128,-18],[109,2],[60,20],[54,-17],[43,-58],[45,7],[44,38],[243,-35],[55,1],[62,-6],[114,-35],[65,-32],[144,19],[62,1],[32,13],[99,88],[43,15],[40,16],[36,-13]],[[54347,80863],[24,-76],[73,-130],[80,-23],[221,-50],[45,-26],[124,-115],[74,-56],[48,-45],[72,-89],[42,-64],[70,-48],[82,-33],[30,-5],[-2,-47],[-14,-79],[-27,-102],[-29,-79],[-7,-31],[22,-25],[108,-12],[46,-14],[9,-21],[-24,-27],[-35,-23],[-15,-22],[-28,-77],[-180,10],[-24,-16],[-11,-35],[-9,-42],[-24,-49],[-48,-42],[-75,-16],[-61,-29],[-46,-89],[-34,-120],[1,-85],[5,-48],[-4,-27],[-23,-30],[-38,-78],[-31,-87],[-12,-47],[6,-22],[35,0],[50,-18],[26,-35],[10,-40],[0,-43],[-9,-24],[-40,-17],[-63,0]],[[45419,71150],[-45,6],[-9,-1],[-5,37],[3,78],[25,102]],[[45388,71372],[6,-17],[3,-21],[5,-23],[3,-28],[9,-28],[17,-27],[6,-26],[-9,-33],[-9,-19]],[[52400,66149],[0,0],[-100,-29],[-34,-34],[-20,-59],[-6,-31],[-18,-1],[-29,31],[-37,47],[-48,-3],[-165,-105],[-16,-54],[-3,-119],[-11,-32],[-18,-20],[-68,12],[-7,8]],[[51820,65760],[9,46],[-4,99],[-30,165],[-22,54],[-45,53],[-35,36],[-63,31],[-32,90],[-48,103],[-23,24]],[[51527,66461],[4,10],[11,77],[-14,57],[-21,48],[15,29],[44,0],[36,-6],[13,46],[76,30]],[[51691,66752],[72,32],[11,22],[-17,47],[10,29],[87,85],[14,38],[5,30],[-11,32],[-17,50],[8,21],[45,29],[37,33],[22,3],[13,-24],[0,-25],[12,-42],[27,-23],[45,-37],[52,-25],[41,-51],[55,-90],[9,-45],[50,-40],[47,-45],[-8,-83],[159,-73],[35,1],[17,-13],[0,-19],[-13,-58],[-65,-179],[-5,-38],[-46,-39]],[[52382,66255],[-7,-22],[13,-49],[12,-35]],[[38661,73411],[5,-53],[-26,-11],[-21,18],[-44,0],[-41,-11],[9,93],[81,-11],[37,-25]],[[46859,60440],[-28,-12],[-37,36],[-2,50],[7,15],[44,-23],[14,-46],[2,-20]],[[48913,61961],[-40,-118],[-19,-45],[-141,-289],[-16,-67],[-10,-73],[-14,-63],[-20,-60],[-18,-77],[3,-86],[7,-42],[17,-28],[28,-26],[21,-40],[-33,-37],[36,-73],[31,-44],[4,-43],[-1,-44],[-63,-81],[-25,-45],[-16,-55],[-6,-56],[7,-51],[-3,-50],[-64,6],[-65,31],[-67,-14],[-94,59],[-34,10],[-31,23],[-79,181],[-63,77],[-68,59],[-69,4],[-69,-7],[-61,37],[-124,123],[-132,98],[-56,64],[-26,43],[-30,29],[-75,28],[-68,67],[-31,5],[-66,-9],[-34,5],[-34,23],[-66,79],[-42,108],[-11,48],[29,124],[36,118],[31,34],[37,23],[22,36],[19,43],[67,-124],[31,-30],[31,6],[54,45],[5,48],[60,62],[76,1],[35,-11],[19,-56],[29,-17],[34,-7],[111,-107],[31,-17],[31,-3],[86,44],[66,17],[139,-24],[75,27],[52,3],[76,41],[59,68],[30,17],[33,5],[79,-4],[80,-16],[33,16],[28,45],[33,20],[35,-14],[92,77],[41,5],[39,-29],[-34,-50]],[[44777,62842],[-33,-102],[-35,72],[-2,63],[5,18],[43,-27],[22,-24]],[[47958,64546],[-26,-9],[-15,12],[-8,16],[10,39],[53,-23],[-1,-22],[-13,-13]],[[44665,64893],[-20,-47],[-27,3],[11,35],[25,71],[31,23],[13,-21],[-14,-40],[-19,-24]],[[45449,64729],[29,-66],[66,-273],[6,-59],[-13,-60],[-17,-43],[-65,-137],[10,-114],[24,-70],[4,-77],[-12,-97],[-41,-592],[-19,-105],[-12,-91],[-45,-28],[-57,29],[-72,52],[-34,-4],[-33,-17],[-28,15],[-26,29],[-20,-204],[-33,-83],[-49,-52],[-47,-4],[-48,18],[-41,0],[-31,39],[-24,69],[-39,83],[-40,99],[-4,90],[-7,197],[11,43],[17,41],[8,89],[-6,77],[12,27],[23,-27],[17,10],[-1,39],[5,73],[-30,60],[-51,21],[-5,63],[5,62],[27,42],[10,55],[0,168],[-36,62],[-14,94],[-19,60],[-34,61],[-38,49],[-23,47],[-5,125],[13,103],[12,45],[12,-7],[38,-51],[31,-12],[61,-13],[60,17],[74,47],[72,57],[103,166],[63,34],[33,44],[11,60],[27,15],[32,-58],[39,-6],[61,-47],[26,-46],[23,-54],[21,-25],[23,-13],[4,-13],[-19,-13],[-21,-63],[12,-18],[34,-34]],[[45894,66784],[19,-41],[2,-23],[-13,-27],[6,-60],[-49,50],[-74,-25],[-45,5],[-13,45],[11,26],[70,6],[22,13],[43,-6],[21,37]],[[47657,70271],[17,12],[24,-7],[31,-21],[51,-20],[1,-20],[-10,-26],[-40,-46],[-36,-51],[-4,-32],[5,-23],[12,-14],[53,7],[8,-19],[-26,-133],[8,-22],[47,-22]],[[47798,69834],[34,-31],[64,-85]],[[47896,69718],[25,-68],[-17,-23],[-40,-11],[-33,6],[37,41],[-90,150],[-41,-1],[-54,-63],[-151,64],[-29,-26],[-22,-50],[-52,-63],[-74,-28],[-83,-69],[-87,-49],[-66,-37],[-38,6],[60,81],[-26,1],[-80,-56],[-46,-48],[-15,-81],[-14,-132],[36,-35],[62,-175],[76,-74],[-15,-72],[-20,-56],[-46,-49],[-38,36],[-24,-1],[-17,-114],[33,-304],[53,-214],[52,-93],[120,-145],[125,-77],[227,-244],[124,-78],[32,-42],[75,-188],[65,-218],[70,-342],[50,-168],[101,-191],[208,-272],[190,-200],[176,-123],[138,-22],[326,28],[56,-12],[60,-33],[15,-86],[-22,-58],[-69,-60],[-70,-83],[-8,-113],[66,-80],[314,-211],[321,-177],[100,-90],[116,-140],[281,-193],[47,-94],[170,-201],[77,-156],[15,-121],[-37,-123],[-17,-86],[-29,-86],[-72,33],[-83,87],[-124,357],[-226,36],[-47,27],[-81,61],[-5,40],[-19,51],[-21,17],[-87,11],[-60,-58],[-70,-137],[-80,-196],[-82,-289],[-4,-117],[44,-113],[132,-63],[102,-100],[67,-105],[5,-254],[30,-144],[-44,-82],[-86,21],[-114,-52],[-81,-93],[-34,-88],[9,-231],[-17,-87],[-153,-166],[-81,-170],[-20,-70],[-30,-80],[-194,-3],[-46,99],[-2,147],[34,90],[71,42],[48,188],[-15,136],[28,60],[26,42],[55,25],[76,24],[8,189],[-60,86],[-21,120],[-28,223],[-98,284],[-53,253],[-42,125],[-62,65],[-113,-1],[-57,19],[-200,175],[-14,27],[1,47],[34,70],[-23,96],[-23,90],[-40,77],[-43,40],[-90,-25],[-31,-19],[-57,7],[-45,-34],[-25,-1],[70,135],[-18,31],[-70,56],[-94,8],[-26,7],[-16,-35],[-18,19],[2,61],[-110,270],[-73,110],[-37,19],[-67,-23],[-113,48],[-67,11],[-37,-12],[-55,-35],[-28,24],[-9,36],[-102,112],[-128,63],[-247,357],[-76,133],[-157,147],[-98,214],[-81,78],[-118,63],[-27,-8],[-36,-24],[-28,-3],[-22,28],[23,28],[25,13],[-10,82],[-134,212],[-79,68],[-22,42],[-16,57],[-17,38],[-37,22],[-32,-4],[-44,15],[2,101],[9,78],[-7,66],[-43,174],[-74,148],[-43,352],[-34,100],[-82,75],[-184,84],[-258,227],[-54,4],[-155,88],[-96,15],[-124,-79],[-151,-218],[-123,-226],[-45,-44],[-158,-77],[-140,-37]],[[44203,67729],[-2,58],[-5,44],[24,48],[39,56],[36,71],[15,52],[-7,34],[-16,51],[-22,3],[-133,-42],[-31,11],[-98,66],[-107,81],[-39,58],[-14,59],[11,37],[-9,37],[-21,49],[19,56],[33,70],[16,47],[28,13],[13,28],[-22,115],[-11,19],[-20,14],[-29,2],[-51,23],[-37,40],[-8,54],[-19,51],[-33,48],[-4,52],[37,27],[52,1],[36,-10],[81,83],[29,7],[27,18],[23,114],[17,34],[4,20],[-16,23],[-65,80],[-30,84],[-48,93],[-43,41],[-9,32],[-1,41],[9,36],[79,56],[47,60]],[[43928,69974],[20,-23],[43,-25],[116,34]],[[44107,69960],[72,33],[50,35],[32,-6],[114,-53],[37,27],[82,71],[13,38],[64,113],[1,28],[-26,71],[8,16],[79,73],[39,64],[42,44],[30,1],[9,-15],[3,-30],[-2,-125],[11,-39],[63,-89],[44,-51],[103,-35]],[[44975,70131],[5,-17]],[[44980,70114],[-28,-67],[62,-81],[11,-59],[29,-33],[41,16],[13,31],[-16,55],[-12,57],[3,33],[11,38],[28,53],[77,122]],[[45199,70279],[28,70],[5,109],[0,87],[26,21],[56,-15],[16,1],[8,-53],[23,-86],[28,-44],[30,-10],[34,-1],[87,53],[56,22],[32,-6],[19,-36],[40,-93],[23,-10],[28,10],[10,16],[-9,36],[-12,78],[-16,60],[-21,28],[-4,37],[13,66],[15,56],[30,15],[33,7],[45,-59],[53,-18],[39,3],[7,34],[-2,37],[-24,48],[5,73],[27,135],[16,-10],[58,-2],[64,-7],[41,-55],[40,-19],[58,-6],[38,8],[19,20],[22,65],[41,80],[65,41],[110,8],[55,15],[57,-1],[43,-12],[44,1]],[[46698,71076],[113,56],[117,44],[16,-7],[2,-15],[-21,-34],[-20,-45],[14,-52],[66,-103],[36,-79],[34,-60],[53,-31],[70,-19],[59,-7],[61,-22],[212,-56],[106,-15],[81,-3],[122,-36],[-11,-60],[-25,-15],[-43,-35],[-50,-47],[-46,-54],[-12,-58],[12,-38],[13,-14]],[[47122,67960],[-36,-7],[-26,-50],[17,-42],[35,8],[17,53],[-7,38]],[[30781,91084],[66,-3],[110,35],[45,24],[113,81],[66,22],[102,-5],[50,6],[1,-8],[-63,-33],[-51,-11],[-72,-50],[-68,-110],[-51,-55],[0,-24],[62,-42],[68,-25],[62,22],[27,-8],[25,-32],[14,-32],[3,-31],[-11,-65],[-38,-66],[-50,-55],[7,-17],[40,-9],[193,35],[20,-2],[12,-18],[2,-33],[10,-30],[19,-26],[-6,-27],[-84,-87],[100,55],[78,15],[135,-27],[56,-32],[32,-55],[47,19],[20,-2],[30,-31],[1,-33],[-22,-48],[-8,-44],[-23,-18],[-44,-13],[-13,-15],[20,-34],[28,-32],[41,-2],[7,-15],[1,-18],[-6,-22],[-13,-14],[-21,-8],[-27,-24],[101,-51],[13,-19],[1,-28],[-8,-31],[-17,-34],[-30,-19],[-73,-4],[-45,-21],[15,-37],[-1,-45],[-14,-54],[-57,-82],[-54,-43],[-53,-29],[-94,10],[-52,22],[6,-70],[-52,-44],[10,-36],[18,-18],[-9,-47],[-25,-46],[-42,-50],[-47,-31],[-94,-38],[-81,-62],[-54,-25],[-137,1],[-139,-40],[-197,-85],[-133,-68],[-102,-77],[-135,-126],[-101,-53],[-58,-14],[-112,-11],[-95,-34],[-313,-64],[-107,-35],[-13,-32],[-44,-48],[-3,-17],[19,-14],[4,-17],[-39,-56],[-78,-41],[-36,0],[-45,35],[-19,-1],[-7,-5],[-1,-11],[26,-43],[-47,-19],[-205,-50],[-347,37],[-138,38],[-170,60],[-101,16],[-144,4],[-118,85],[-54,52],[-4,22],[6,25],[12,16],[18,10],[39,0],[5,8],[-29,42],[-29,-14],[-76,-59],[-33,2],[-45,30],[-2,28],[-86,11],[-76,36],[-74,52],[-12,19],[36,29],[-7,6],[-27,5],[-54,-10],[-83,-65],[-35,-15],[-539,-15],[-136,-7],[-27,-10],[-23,43],[-22,94],[-7,62],[5,31],[19,36],[29,-6],[28,-29],[25,-41],[29,-20],[188,50],[76,33],[33,32],[38,54],[41,28],[19,26],[38,82],[26,39],[32,28],[36,18],[83,13],[-55,20],[-52,0],[-177,-87],[-60,0],[3,13],[25,25],[61,42],[-42,4],[-16,19],[-2,40],[31,66],[145,86],[50,13],[15,17],[-19,13],[-30,9],[-145,-89],[-106,-30],[-32,6],[-54,34],[-18,15],[-24,40],[3,23],[50,70],[-8,13],[-34,7],[-94,64],[-147,-7],[-365,37],[-76,-15],[-124,-55],[-75,-18],[-35,12],[-32,29],[-28,39],[-26,49],[11,34],[48,20],[36,9],[99,-12],[121,35],[77,7],[23,5],[45,37],[22,9],[35,-13],[17,-24],[122,38],[42,20],[5,11],[18,14],[61,-21],[49,0],[61,14],[109,7],[242,3],[37,31],[17,28],[21,71],[-9,14],[-152,-65],[-34,1],[-176,35],[-63,39],[21,31],[93,67],[95,54],[142,59],[33,22],[3,27],[-94,48],[-178,-13],[-46,57],[-148,33],[-98,-21],[-52,35],[-128,-48],[-281,-69],[-112,-47],[-61,-16],[-69,39],[-119,44],[-135,13],[-12,26],[78,79],[54,15],[54,-8],[103,-55],[72,-17],[-90,81],[3,31],[-7,46],[-28,20],[-27,52],[11,17],[35,7],[72,-18],[171,-89],[84,16],[46,32],[63,25],[-18,13],[-148,1],[-79,18],[-40,27],[-34,44],[12,21],[41,16],[126,-5],[-83,77],[-58,45],[-6,21],[4,27],[8,18],[11,9],[145,-45],[32,-2],[-30,29],[-63,43],[-3,16],[27,13],[13,25],[1,20],[44,17],[44,1],[45,-16],[138,-83],[20,-24],[7,-31],[-7,-38],[6,-16],[54,13],[43,-16],[21,5],[54,57],[37,-13],[22,-27],[7,-25],[4,-33],[-10,-70],[3,-10],[37,40],[64,3],[8,19],[2,74],[-5,62],[-7,13],[-210,86],[-37,20],[-46,42],[9,21],[41,19],[62,8],[144,-1],[14,9],[-28,22],[-66,14],[-16,13],[-7,25],[-79,-14],[-88,0],[-84,15],[-2,19],[33,29],[69,46],[32,12],[97,-8],[96,13],[77,-16],[62,-46],[87,-82],[119,-52],[11,-16],[63,-43],[125,-115],[127,-67],[6,-16],[-21,-20],[-49,-24],[11,-13],[64,-17],[46,-45],[3,-20],[-41,-140],[-22,-29],[-26,-16],[-118,26],[29,-44],[83,-48],[19,-26],[-12,-26],[9,-6],[31,14],[13,-15],[-6,-43],[-13,-36],[-21,-29],[6,-12],[33,3],[31,-7],[48,-40],[39,-121],[20,-39],[14,35],[17,88],[17,45],[15,2],[13,15],[11,28],[23,98],[79,74],[38,23],[35,5],[17,-10],[59,-77],[36,-13],[19,4],[25,53],[32,101],[7,113],[-17,124],[10,89],[38,54],[49,16],[61,-20],[45,-33],[88,-124],[71,-65],[61,-69],[32,-23],[60,-11],[16,4],[11,16],[6,28],[-13,177],[17,55],[25,40],[110,23],[59,24],[58,41],[48,21],[38,3],[40,-16],[42,-34],[64,-67],[82,-111],[104,-83],[54,-132],[12,-22],[12,-3],[14,17],[9,25],[2,58],[-29,78],[-97,196],[-1,37],[12,30],[68,3],[159,-18],[51,-30],[108,-120],[31,-29],[18,-7],[7,14],[42,23],[29,26],[48,66],[106,119],[22,3],[30,-9],[55,-31],[25,-25],[51,-19],[52,7],[72,41],[82,26],[28,58],[5,27],[-66,175],[28,36],[142,44],[125,3],[29,-12],[78,-85],[53,-43],[27,-34],[7,-76],[32,-28],[61,-32]],[[34041,78279],[-3,-30],[-43,38],[-21,40],[-118,19],[49,41],[24,-12],[83,-2],[24,-17],[5,-77]],[[36214,78461],[25,-36],[11,-38],[-43,-14],[-45,8],[-22,-25],[-2,-48],[16,-61],[30,-44],[24,-98],[19,-109],[31,-66],[7,-82],[-5,-40],[6,-72],[-13,-26],[10,-67],[36,-141],[16,-78],[10,-170],[-26,-64],[-34,-61],[-23,-72],[-17,-78],[-11,-125],[-74,-146],[-32,-37],[-37,-22],[81,-103],[-66,-46],[-72,-14],[-79,26],[-50,-4],[-45,-33],[-18,-20],[-14,10],[-30,84],[-22,-87],[-45,-28],[-79,6],[-131,-23],[-50,-25],[-21,-38],[-15,-45],[-21,-27],[-23,-13],[-101,-33],[-20,-14],[-47,-72],[-61,-42],[-51,-12],[-45,42],[-18,25],[-21,13],[-70,-2],[22,-13],[14,-30],[7,-57],[-8,-55],[-34,-29],[-41,-5],[-64,-58],[-85,-16],[-46,-53],[-282,-90],[-16,-1],[-39,23],[-42,10],[-42,-7],[-118,-51],[-57,10],[73,126],[98,63],[10,17],[-32,8],[-186,-43],[-64,-38],[-65,-11],[30,57],[83,79],[45,36],[27,15],[31,46],[88,52],[-283,-108],[-74,14],[-17,30],[-58,-15],[-22,73],[85,110],[50,47],[60,26],[57,37],[21,44],[-27,15],[-171,-12],[-82,10],[4,35],[16,40],[84,67],[46,11],[41,-7],[40,-17],[33,-22],[96,13],[-40,43],[-7,87],[-31,29],[39,41],[46,24],[75,84],[26,13],[149,20],[160,44],[159,61],[-81,34],[-39,45],[-63,-91],[-45,-34],[-128,-19],[-40,10],[-57,29],[-18,-11],[-16,-22],[-84,-44],[-89,-11],[103,82],[131,138],[29,44],[42,75],[-13,34],[-27,20],[95,156],[33,28],[61,5],[44,25],[20,0],[18,9],[39,47],[-61,30],[-62,15],[-192,-16],[-26,3],[-23,14],[-16,21],[-12,53],[-14,12],[-43,0],[-43,-16],[-30,1],[-29,24],[47,54],[-61,13],[-61,-11],[-51,17],[-1,34],[23,34],[-31,32],[-6,41],[32,20],[36,-7],[71,30],[92,15],[-79,30],[-31,25],[-2,39],[7,34],[91,56],[97,25],[-7,37],[7,40],[-99,12],[-97,-29],[11,77],[23,70],[5,45],[-5,49],[-45,-21],[-6,69],[-19,48],[-68,-33],[2,63],[20,43],[35,19],[35,-8],[65,1],[62,33],[90,8],[144,-10],[99,-93],[26,17],[39,58],[19,7],[149,-26],[92,-34],[25,11],[-14,65],[-31,45],[40,59],[48,40],[33,20],[75,24],[32,24],[22,75],[35,64],[-188,-33],[-179,75],[28,52],[38,30],[65,23],[6,28],[33,23],[55,60],[-20,79],[11,57],[39,38],[12,54],[18,39],[79,14],[77,37],[28,-3],[90,8],[31,-15],[-7,65],[56,9],[21,-13],[10,-46],[25,-30],[8,-51],[-17,-39],[-28,-31],[26,-31],[-40,-56],[43,24],[62,55],[-4,45],[-10,56],[-17,52],[8,56],[34,35],[92,18],[-38,64],[33,5],[37,-13],[53,-50],[55,-39],[58,-31],[-56,-62],[-67,-43],[-27,-46]],[[35631,79505],[-92,-67],[-15,-26],[-26,-102],[-3,-29],[-29,-54],[-28,-59],[-33,-23],[-49,-19],[-27,-18],[-35,9],[-44,-1],[-22,-21],[1,-15],[13,-18],[39,-28],[43,-24],[-5,-22],[-23,-25],[-146,-61],[-44,-37],[-15,-24],[16,-41],[116,-122],[20,-14],[17,-71],[103,-30],[42,-44],[36,-11],[79,4],[31,-17],[18,13],[11,23],[66,61],[22,26],[-13,37],[-15,28],[41,56],[48,55],[25,-2],[42,-34],[34,-47],[5,-36],[6,-26],[32,-57],[21,-19],[57,-12],[13,-22],[-10,-82],[8,-27],[60,-1],[62,6],[22,-3],[23,17],[35,19],[50,-7]],[[47085,65786],[-5,-1],[-2,3],[2,5],[4,1],[1,-8]],[[37266,78562],[-118,-132],[-47,24],[-41,-13],[-11,4],[23,48],[27,110],[49,44],[62,114],[49,32],[17,-5],[11,-11],[22,-128],[-31,-45],[-12,-42]],[[52732,72552],[56,8],[2,-1],[13,-5]],[[52803,72554],[9,-48],[2,-3],[13,-32],[13,-43],[19,-31],[43,-14],[56,-39],[37,-74]],[[52995,72270],[55,-31],[3,-1],[11,4],[40,2],[7,-15],[32,-36],[12,-32],[-6,-34],[5,-38],[12,-13]],[[53166,72076],[-14,-26],[-102,-129],[-40,-34],[-27,-7],[-41,14],[-43,-10],[-39,-28],[-35,-9],[-27,-32],[-35,-70],[-42,-60],[-43,-36],[-23,-33],[-2,-114],[-24,-33],[-32,-33],[-18,-29],[-49,-173],[-37,-55],[-35,-43],[-6,-39],[1,-44],[-40,-89],[-52,-92],[-10,-38],[11,-51],[-50,-59],[-29,-28],[-24,-13],[-15,-37],[-24,-90],[6,-40],[1,-37],[-42,-21],[-13,-41],[-11,-50],[-17,-23],[-48,-41],[-118,18],[-45,-14],[-13,-30],[-3,-24],[-15,-23],[-27,-28],[-27,-12],[-62,34],[-132,-35],[-23,-25]],[[51631,70164],[-18,18],[-29,16],[-132,21],[-53,-17],[-69,7],[-65,18]],[[51265,70227],[-48,-15],[-43,-70],[-21,-24]],[[51153,70118],[-17,-15],[-36,-23],[-31,-26],[-40,-19],[-36,2],[-35,31],[-12,-7],[-11,-28],[-18,-24],[-52,-30],[-13,1],[-3,0],[-39,-22],[-65,-12],[-32,9],[-59,-98],[-18,-18],[-56,-30],[-46,-15],[-40,12],[-15,1],[-175,5],[-92,21],[-58,38],[-39,43],[-19,47],[-46,29],[-71,10],[-56,47],[-40,83],[-54,67],[-68,49],[-54,68],[-40,90],[-72,80],[-103,71],[-32,16]],[[49460,70571],[-6,23],[-51,88],[-21,33],[2,44],[-11,25],[-18,17],[-10,63],[-6,48],[-14,30],[-111,6]],[[49214,70948],[93,113],[46,32],[53,-6],[18,11],[4,16],[9,37],[5,34],[5,33],[-6,19],[-26,5],[-13,81],[14,30],[13,22],[-16,98],[5,33],[41,5],[35,21],[28,24],[8,30],[24,62],[-22,76],[-121,49],[-6,19],[28,21],[30,31],[17,24],[24,3],[33,-12],[58,-55],[22,-8],[22,16],[23,4],[65,-2],[54,12],[-12,59],[0,42],[-9,34],[5,37],[22,29],[7,66],[34,44]],[[49828,72137],[16,6],[60,-8],[14,-12],[9,-2],[95,-108],[90,-80],[74,-42],[108,-3],[116,-4],[192,14],[145,11],[9,20],[22,48],[-17,42],[1,48],[24,64],[71,52],[205,23],[118,39],[17,54],[39,53],[36,10],[49,-24],[58,-46],[52,-25],[30,16],[104,78],[120,77],[82,207],[9,33],[89,24],[130,-4],[67,-27],[50,-15],[75,5],[109,45],[40,-1],[31,-32],[34,-27],[23,-34],[17,-46],[10,-18],[15,-24],[27,-33],[27,-9],[200,57],[12,13]],[[58489,70263],[80,-51],[-82,13],[-180,48],[-79,46],[-21,51],[-11,69],[44,-73],[31,-32],[218,-71]],[[62103,71186],[-21,-12],[-204,16],[-166,-22],[-119,-164],[-70,1],[-100,-43],[-67,-53],[-80,-115],[-62,51],[-76,-1],[-74,-32],[-89,-76],[-49,-14],[-99,22],[-115,-44],[-249,-253],[-84,-184],[-30,-36],[-42,-45],[-45,-23],[-24,2],[119,131],[36,49],[6,37],[1,58],[-36,73],[-97,-180],[-55,-27],[-70,-54],[-3,-121],[8,-89],[29,-113],[67,-185],[139,-264],[66,-97],[49,-39],[58,-6],[113,82],[48,13],[104,-32],[38,55],[54,30],[70,4],[79,-25],[87,-41],[-36,-93],[-37,-74],[-13,-83],[-20,-91],[-95,-41],[-102,5],[-108,-27],[-39,36],[-26,33],[-47,32],[-63,18],[-57,-22],[-67,-125],[-118,-85],[-39,-97],[-116,21],[-100,-17],[-144,-88],[-110,-191],[-120,-119],[-96,-38],[-90,12],[-58,36],[-120,125],[7,45],[17,22],[22,65],[48,236],[-6,77],[-27,120],[-95,94],[-76,-18],[-43,25],[-157,160],[-85,11],[-94,-32],[-34,23],[-26,56],[186,197],[184,162],[80,17],[108,75],[116,114],[-16,89],[-25,66],[-56,-18],[-40,-22],[-97,70],[-36,52],[-151,-54],[-85,8],[-186,-49],[-86,48],[-171,136],[-65,27],[-54,-5],[-30,44],[36,23],[43,2],[44,17],[13,23],[-3,45],[-89,34],[-83,9],[-52,40],[-40,46],[94,1],[94,-35],[148,-13],[134,-35],[33,44],[78,77],[15,25],[-131,-53],[-132,34],[-48,47],[-41,69],[-17,78],[11,74],[-14,132],[-44,117],[-15,65],[-46,58],[45,-131],[17,-87],[27,-80],[-6,-213],[-17,-75],[-54,-18],[-72,11],[-73,23],[19,117],[-39,-40],[-55,-114],[-48,-17],[-107,12],[-198,-75],[-14,-82],[-30,-111],[-29,-65],[-9,-39],[-84,-168],[-11,-16],[-160,-232],[-20,-17],[-103,-54],[-62,-48],[-47,-21],[-79,24],[-33,-34],[-15,-41],[-1,-86],[41,-62],[33,-205],[-13,-87],[-31,56],[-49,59],[-96,51],[-105,-17],[-114,-86],[-78,-32],[-40,22],[-25,-1],[-9,-24],[2,-21],[12,-15],[-1,-12]],[[56611,69261],[-16,-7],[-181,61],[-78,57],[-61,107],[31,35],[26,15],[94,9],[16,11],[2,25],[7,32],[-3,47],[-10,50],[41,73],[61,60],[36,61],[6,88],[64,44],[58,74],[14,80],[20,51],[-37,117],[-7,76],[-2,65],[18,35],[53,41],[56,31],[24,-3],[8,-20],[2,-131],[11,-2],[18,16],[30,77],[20,-22],[31,-9],[23,20],[15,-2]],[[57001,70523],[19,-20],[37,-28],[35,-10],[29,19],[25,33],[26,-11],[50,-91],[24,10],[115,19],[18,24],[14,23],[-120,120],[6,90],[4,102],[-14,61],[-24,49],[-92,56],[-71,58],[-15,26],[-2,34],[-3,53],[-28,45],[-2,39],[18,59],[4,64],[-6,25],[-16,21],[-32,2]],[[57000,71395],[-43,37],[-29,49],[-77,72],[-24,11],[-14,36],[-7,42],[16,53],[20,80],[15,76],[0,45],[-9,112],[-41,85],[-19,12],[-32,-24],[-38,-20],[-29,19],[-33,46],[-54,129],[-100,25],[-42,7],[-39,-63],[-12,19],[-11,40]],[[56398,72283],[-21,16],[-27,-18]],[[56350,72281],[-8,17],[12,54],[-33,26],[-77,0],[-41,20],[-5,40],[-24,26],[-44,13],[-42,33],[-42,53],[-61,35],[-82,16],[-7,5],[-7,8],[-53,-36],[-32,-28],[-39,17],[-63,-63],[-128,-4],[-63,4],[-31,16],[-121,-97],[-12,-35],[-27,-12],[-76,-20]],[[55244,72369],[-80,-27],[-17,-94],[-23,-51],[-43,-74],[-148,-26],[-128,-37],[-131,-22],[-172,-92],[-56,-80],[-55,-23],[-50,-6],[-32,45],[-109,120],[-42,57],[-55,16],[-60,-9],[-58,-28],[-61,-5],[-68,40],[-8,-4],[-26,-5],[-171,48],[-16,8],[-7,2],[-24,4]],[[53604,72126],[-128,-6],[-120,98],[-37,3],[-28,-40],[-21,-44],[-83,-44],[-21,-17],[-12,13],[-5,38],[6,34],[-12,32],[-32,36],[-7,15],[-40,-2],[-11,-4],[-3,1],[-55,31]],[[52995,72270],[-37,74],[-56,39],[-43,14],[-19,31],[-13,43],[-13,32],[-2,3],[-9,48]],[[52803,72554],[-13,5],[-2,1],[-56,-8],[7,169],[88,122],[22,62],[33,134],[25,62],[30,52],[24,50],[8,43],[24,4],[71,-38],[63,-20],[18,19],[7,24],[-3,20]],[[53149,73255],[-51,57],[-31,36],[-2,23],[11,50],[6,56],[-7,61],[-35,135],[-6,58],[33,69],[107,167],[36,62],[49,76],[133,181],[84,105],[57,58],[83,101],[37,52],[152,34],[19,49],[27,54],[22,23],[3,90],[-28,110],[-23,38],[-17,27],[11,25]],[[53819,75052],[17,7],[21,3],[25,27],[-5,28],[-65,71],[-27,54],[-44,139],[-88,144],[-28,47]],[[53625,75572],[-4,44],[13,44],[-12,57],[-31,71],[5,8]],[[53596,75796],[-3,89],[22,19],[35,13],[49,-5],[43,-13],[50,-41],[16,7],[87,76],[89,114],[25,67],[23,30],[77,16],[68,7],[43,-2],[106,12],[62,12],[54,20],[117,8],[182,-14],[120,-1]],[[54861,76210],[82,-10],[199,-61],[74,-11],[34,-32],[66,-12],[121,-33],[104,-17],[71,7],[39,-9],[75,-144],[15,-17],[30,-3],[61,12],[87,-5],[52,-30]],[[55971,75845],[-8,-86],[14,-12],[24,5],[27,48],[24,50],[17,16],[89,-34],[40,5],[38,38],[22,7],[63,-27],[78,-19],[62,-1],[39,-21],[29,-90],[25,-18],[23,-6],[37,80],[32,31],[46,23],[29,10],[21,29],[27,27],[24,2],[20,-10],[23,-39],[32,-86],[40,-88],[28,-31],[72,26],[48,28],[89,5],[119,19],[90,25],[56,-4],[35,-28],[52,-54],[14,-77],[68,-53]],[[57579,75535],[55,-10],[19,56],[32,38],[-12,53],[-5,68],[-25,62],[-16,68],[30,96],[32,84],[16,46],[52,85],[52,60],[79,97],[58,32],[51,-15],[29,-13],[75,57],[133,3],[110,-7]],[[58344,76395],[11,-2],[54,-30],[58,-25],[39,-2],[47,6],[55,34],[39,32],[46,165],[17,23],[26,13],[42,1],[80,-30],[94,-28],[54,4],[145,88],[81,13],[96,-20],[94,-2],[71,13],[49,-30],[60,-67],[54,-99],[57,-184],[166,-207],[3,-40],[-14,-26],[-81,-25],[-69,-14],[-3,-36],[18,-38],[31,-56],[5,-73],[-1,-67],[13,-59],[27,-24],[3,-29],[-31,-36],[-8,-23],[12,-12],[149,-7],[74,-35],[55,-32],[28,-3],[63,21],[71,13],[43,1],[17,-23],[13,-63],[25,-62],[23,-18],[42,3],[25,-3],[13,-23],[-15,-36],[3,-38],[19,-48],[21,-109],[20,-33],[13,-41],[0,-48],[-16,-41],[-12,-33],[12,-74],[45,-83],[33,-21],[26,-74],[49,-23],[71,62],[55,32],[68,-18],[63,-11],[43,-43],[31,-58],[37,-32],[37,17],[76,-17],[35,-48],[35,-26],[44,38],[37,47],[134,50],[83,12],[23,10],[49,36],[51,23],[47,-6],[45,-74],[48,-51],[13,-80],[58,-110],[143,-150],[56,-46],[38,8],[20,12],[10,16],[8,73],[19,27],[29,1],[112,-91],[59,-10],[55,-2],[75,-71],[83,-62],[64,-7],[51,24],[34,15],[22,-23],[20,-54],[33,-41],[38,-12],[55,-3],[96,-80],[89,-82],[56,-5],[48,24],[42,7],[29,-21],[9,-36],[-22,-47],[0,-68],[40,-65],[1,-64],[-11,-58],[-23,-54],[-55,-73],[-50,-68],[-76,-29],[-42,-30],[11,-50],[28,-47],[64,-38],[73,-27],[8,-31],[-11,-15],[-47,-14],[-64,14],[-22,-26],[-30,-45],[-20,-80],[-15,-74],[71,-20],[40,-30],[13,-61],[15,-68],[4,-61],[-23,-30],[-2,-30],[11,-15],[31,-6],[23,-14],[2,-32],[-45,-73],[-41,-138],[-22,-74],[1,-80],[-25,-44],[-45,-4],[-156,-8],[-135,4],[-59,12],[-92,7],[-45,-19],[-60,-128],[-46,-50],[-75,-45],[-83,-13],[-48,-53],[-16,-83],[-2,-73],[-7,-37],[-18,-32],[-7,-23],[4,-25],[19,-9],[24,-12],[0,-18],[-9,-23],[-26,-25],[-12,-39],[3,-41],[5,-46]],[[50096,66691],[80,-71],[-233,93],[26,9],[25,2],[102,-33]],[[49539,66928],[107,-29],[79,13],[72,-18],[44,-33],[11,-16],[-58,-2],[-65,13],[-74,-33],[-65,18],[-25,21],[-17,28],[-9,38]],[[50131,66824],[42,19],[36,-13],[23,-60],[45,-39],[74,-69],[46,-52],[105,-95],[25,-13],[52,-28]],[[50579,66474],[1,-39],[23,-43],[23,-50],[-107,98],[-101,111],[-196,170],[-139,41],[-190,137],[-124,48],[47,11],[54,0],[294,-182],[-33,48]],[[49855,67062],[-41,-11],[-259,8],[-75,22],[-84,56],[-17,17],[84,16],[79,-16],[24,-41],[212,-32],[77,-19]],[[49617,67213],[-92,-3],[-80,19],[-39,32],[3,27],[12,46],[89,-6],[136,-32],[33,-38],[-11,-17],[-51,-28]],[[48793,67944],[39,-77],[-37,16],[-38,47],[-23,52],[59,-38]],[[48711,68036],[10,-37],[-73,69],[-28,46],[-5,21],[96,-99]],[[48687,67890],[8,-15],[-1,-10],[-30,14],[-8,-4],[-143,227],[-15,44],[51,-53],[138,-203]],[[48687,68320],[-15,-27],[-38,51],[-35,36],[-24,43],[-49,53],[-16,62],[-73,124],[-11,34],[36,-50],[31,-32],[24,-8],[64,-79],[62,-103],[74,-89],[-16,-2],[-14,-13]],[[48479,68760],[14,-46],[-55,42],[-49,16],[-10,31],[7,25],[10,25],[38,-3],[5,-25],[40,-65]],[[48279,68657],[-5,-40],[-35,51],[-18,92],[-45,147],[-6,42],[24,41],[-2,42],[-31,129],[26,21],[16,3],[6,-90],[15,-52],[42,-63],[-8,-105],[9,-150],[8,-33],[4,-35]],[[48466,68987],[-72,-22],[-34,40],[-9,32],[-59,11],[-35,45],[-8,20],[51,51],[27,81],[34,-49],[42,-91],[22,-26],[41,-92]],[[50852,69980],[-2,-25],[-5,-44],[-31,-31],[32,-71],[31,-116],[-17,-57],[20,-45],[60,-32],[5,-13],[-18,-13],[-15,-38],[-2,-69],[52,-65],[104,-61],[34,-10],[13,-24],[17,-15],[11,-19],[0,-24],[-7,-17],[-50,-6],[-57,0],[-40,30],[-3,-22],[-1,-24],[-39,-15],[22,-170],[-9,-49],[-14,-17],[-14,7],[-16,2],[-8,-16],[7,-36]],[[50912,68875],[-39,-4],[-61,19],[-28,32],[-5,34],[0,31],[-20,52],[-48,52],[-102,9],[-37,17],[-39,19],[-42,15],[-39,-2],[-47,-14],[-82,23],[-28,-31],[-43,-36],[-36,1],[-72,84],[-21,5],[-63,-43],[-25,-2],[-20,14],[-84,31],[-38,7],[-28,-15],[-50,17],[-120,109],[-75,-83],[-151,20],[-45,-57],[-52,-107],[-42,-52],[-36,19],[-43,47],[-75,122],[-38,22],[-44,5],[-38,-13],[-20,-25],[-15,-178],[-14,-157],[-1,-95],[84,-87],[98,-150],[32,-17],[15,-49],[23,-127],[26,-142],[50,-94],[45,-68],[56,-59],[69,-93],[56,-102],[15,-38],[110,-135],[106,-138],[96,-48],[15,-25],[1,-106],[10,-40],[63,-111],[130,-162],[15,-38],[4,-27],[-8,-22],[-34,-22]],[[50083,66867],[-28,25],[-121,159],[-116,100],[-132,188],[-177,75],[-120,82],[-73,-12],[-80,-26],[-50,-1],[-35,15],[-25,51],[4,39],[-5,52],[-70,83],[-96,78],[-91,101],[-183,274],[-37,88],[36,17],[28,-2],[30,18],[50,1],[59,-18],[-52,58],[-65,58],[-168,228],[-50,108],[-6,116],[12,159],[-30,114],[-130,148],[-47,77],[-96,47],[-43,-5],[-25,-57],[-19,-128],[-85,-169],[-28,-73],[-45,-95],[-38,-7],[-23,9],[-69,160],[-66,121],[-9,58],[-6,71],[-50,260],[35,36],[22,-41],[153,-51]],[[47923,69456],[34,23],[20,34],[0,21],[13,7],[54,-33],[44,7],[71,2],[51,-5],[33,25],[45,93],[17,52],[21,12],[13,-6],[10,-43],[24,-40],[49,-65],[34,-32],[32,-11],[31,26],[31,8]],[[48550,69531],[91,-51],[77,-10],[57,27],[-8,36],[-21,41],[-4,40],[4,34],[39,34],[-2,15],[-47,60],[2,16],[103,67],[100,38],[16,29],[9,44],[4,83],[-5,67],[-40,63],[-3,32],[10,34],[15,29],[40,13],[47,22],[37,25],[50,20],[39,29],[38,69],[23,11]],[[49221,70448],[71,-10],[15,17],[-10,99],[13,25],[25,14],[12,14],[62,-11],[51,-25],[32,-16],[103,-71],[72,-80],[40,-90],[54,-68],[68,-49],[54,-67],[40,-83],[56,-47],[71,-10],[46,-29],[19,-47],[39,-43],[58,-38],[92,-21],[175,-5],[15,-1],[40,-12],[46,15],[56,30],[18,18],[59,98],[32,-9],[65,12],[39,22],[3,0]],[[53735,59170],[39,-8],[54,1],[13,7],[34,60],[42,2],[19,-60],[-43,-28],[-9,-16],[8,-12],[33,-25],[45,9],[1,-47],[10,-39],[22,-23],[24,-4],[53,6],[52,16],[54,30],[55,16],[164,-16],[59,-65],[112,-8],[105,-35],[54,23],[94,21],[15,-23],[-12,-148],[5,-43],[27,-20],[27,10],[33,48],[78,38],[82,0],[68,98],[21,6],[-13,-49],[-10,-114],[-15,-66],[-7,-53],[-45,-27],[-70,-4],[-126,11],[-128,-19],[-236,-49],[-236,-26],[-32,17],[-1,66],[-5,45],[-15,32],[-73,28],[-70,47],[-274,64],[-64,25],[-105,-13],[-38,1],[-27,23],[-18,40],[-8,125],[13,124],[23,33],[10,-38],[27,-17],[25,38],[0,57],[12,52],[20,-22],[13,-81],[35,-21]],[[55671,59097],[-22,-59],[-23,49],[10,57],[-26,90],[50,134],[1,65],[38,33],[-10,-110],[-29,-89],[30,-73],[15,-84],[-34,-13]],[[53269,59850],[-6,-45],[-60,31],[-17,46],[-3,104],[16,50],[10,16],[28,-58],[58,-85],[-26,-59]],[[56060,59579],[-42,-22],[-15,3],[-17,48],[24,117],[-23,74],[-1,32],[34,44],[24,66],[58,71],[149,84],[35,8],[-1,-66],[-50,-167],[-44,-83],[12,-67],[-72,-19],[-71,-123]],[[54684,60061],[-27,-55],[-38,20],[16,21],[9,27],[1,39],[-10,24],[7,8],[34,-40],[8,-44]],[[55254,60261],[-46,-24],[-29,-53],[-36,37],[0,51],[39,-16],[28,29],[-8,32],[30,-15],[22,-41]],[[56070,60229],[-13,-17],[-29,48],[-1,24],[29,29],[15,6],[5,-19],[-1,-41],[-5,-30]],[[54133,60447],[1,-61],[-4,-22],[-119,-30],[11,70],[7,23],[39,-33],[15,17],[6,19],[44,17]],[[54626,60354],[-10,-17],[-44,66],[-17,38],[21,32],[64,-74],[-14,-45]],[[55539,60409],[-18,-1],[22,50],[61,69],[90,60],[29,7],[51,-38],[-93,-62],[-24,-33],[-69,-7],[-49,-45]],[[54904,60475],[-51,-9],[-17,8],[32,18],[22,19],[10,23],[52,41],[34,52],[38,-36],[-47,-24],[-73,-92]],[[54241,60611],[-11,-5],[-15,44],[-3,41],[6,24],[20,2],[27,-77],[-24,-29]],[[55580,60650],[-58,-14],[10,82],[-28,65],[45,-36],[29,-44],[14,-9],[-3,-26],[-9,-18]],[[54566,60764],[-46,-81],[-39,9],[-16,37],[24,75],[51,43],[24,-11],[-2,-56],[4,-16]],[[54721,60659],[-51,-40],[-36,57],[-20,90],[95,131],[23,-12],[14,-34],[-2,-118],[-23,-74]],[[54126,60823],[-22,-16],[-36,23],[10,57],[25,24],[26,-19],[4,-25],[-7,-44]],[[54075,61051],[-34,-32],[11,72],[-16,38],[15,32],[21,26],[10,-27],[19,-43],[-26,-66]],[[54370,61206],[-3,-108],[-15,1],[-9,16],[-1,42],[7,65],[21,-16]],[[54638,61128],[-56,-6],[4,79],[20,21],[67,-40],[-3,-25],[-32,-29]],[[55003,61243],[-27,-4],[8,42],[52,72],[73,3],[67,36],[15,2],[-32,-57],[-54,-53],[-102,-41]],[[54552,61316],[-21,-67],[-37,10],[-60,72],[-21,33],[-12,32],[25,4],[31,-34],[78,-18],[17,-32]],[[54028,61292],[-39,-50],[-7,76],[25,79],[35,5],[12,-35],[-26,-75]],[[55466,61536],[72,-34],[20,4],[34,-13],[9,-63],[-45,-9],[-78,-58],[-33,13],[-39,50],[-63,5],[-18,14],[33,59],[61,30],[47,2]],[[52008,61530],[61,-101],[-49,25],[-53,-70],[-67,82],[-40,82],[-9,34],[42,77],[39,-80],[47,-12],[29,-37]],[[54399,61482],[-18,-70],[-45,82],[-50,55],[-19,49],[-30,29],[-8,65],[37,27],[15,3],[38,-79],[59,-10],[-5,-49],[19,-63],[7,-39]],[[53559,61655],[-23,-25],[-26,1],[-18,9],[-10,21],[12,10],[13,41],[13,11],[18,-5],[12,-17],[9,-46]],[[51847,62131],[7,-120],[41,-23],[55,-108],[-5,-55],[-11,-19],[-91,51],[-21,-23],[-27,9],[-16,60],[2,21],[-15,36],[-12,16],[-36,-48],[-22,-9],[-1,44],[33,119],[16,21],[27,-40],[22,15],[17,65],[1,64],[7,19],[29,-95]],[[51932,62075],[-29,-11],[-36,99],[-14,69],[16,4],[14,-8],[16,-26],[0,-27],[6,-28],[16,-34],[11,-38]],[[55041,61959],[-56,-59],[-62,85],[-10,28],[45,34],[23,53],[-18,65],[-64,96],[-3,68],[97,29],[57,-59],[29,-4],[-11,-57],[5,-19],[5,-172],[-27,-24],[-5,-47],[-5,-17]],[[51890,62365],[-22,-8],[-20,6],[-18,-5],[-17,-20],[2,83],[20,102],[25,59],[35,28],[14,-47],[-2,-167],[-17,-31]],[[54214,62574],[-62,-26],[-16,4],[14,32],[1,14],[-62,58],[8,76],[7,20],[45,-40],[10,-66],[55,-72]],[[53480,62729],[33,-113],[31,-38],[65,-45],[30,-6],[111,-81],[128,-16],[17,-23],[16,-63],[26,-49],[7,-38],[-14,-43],[19,-130],[32,-123],[49,-60],[61,-18],[58,3],[15,-25],[-6,-108],[-25,-42],[-20,-10],[-17,11],[-16,25],[-17,13],[-33,2],[-24,43],[-62,59],[-11,36],[-2,55],[-26,40],[-24,77],[-23,21],[-13,38],[-1,17],[-90,11],[-74,0],[-63,44],[-19,114],[-38,30],[-28,33],[-23,44],[-59,83],[-65,68],[-63,46],[-67,29],[-54,-35],[-32,9],[-6,23],[67,48],[93,90],[66,30],[31,3],[60,-79]],[[53692,62891],[-26,-35],[-40,15],[-42,118],[108,-98]],[[53755,62937],[-27,-12],[28,82],[48,43],[-18,-69],[-31,-44]],[[55225,63115],[-10,-62],[80,-102],[28,-65],[10,-63],[-7,-18],[-30,34],[-25,11],[8,-45],[26,-39],[-46,-22],[-46,1],[-133,54],[-31,57],[80,87],[16,35],[-56,-4],[-61,-102],[-97,45],[-29,41],[-7,22],[38,91],[68,-3],[37,21],[44,28],[0,44],[107,9],[36,-55]],[[51536,63222],[12,-58],[-72,36],[-54,52],[-43,129],[-93,146],[-2,43],[36,32],[76,23],[31,-24],[20,-24],[6,-28],[-43,-57],[-9,-25],[33,-51],[0,-20],[14,-98],[16,-37],[42,-29],[30,-10]],[[54658,63795],[-22,-36],[-16,-60],[-9,-87],[-34,-2],[-20,18],[-7,33],[-1,41],[-15,-2],[-12,-45],[-11,-20],[-34,-4],[-37,27],[1,60],[-7,69],[3,25],[103,6],[30,-52],[36,30],[15,32],[44,20],[-7,-53]],[[54803,64255],[-66,-27],[-73,86],[71,34],[32,-25],[23,-29],[13,-39]],[[54272,64452],[-75,-38],[-76,71],[1,41],[40,85],[22,25],[56,-7],[31,-58],[8,-27],[-10,-47],[3,-45]],[[51713,63607],[-1,40],[-21,51],[-20,63],[0,30],[16,12],[27,27],[14,33],[28,17]],[[51756,63880],[41,3],[46,15],[30,36],[5,36],[18,98],[12,48],[20,44],[11,59],[21,56],[44,23]],[[52004,64298],[40,28],[30,72],[17,61],[0,38],[-25,61],[-19,60]],[[52047,64618],[5,78],[79,6],[28,7],[102,5],[47,41],[33,-4],[67,-36],[30,29],[89,56],[87,163],[38,25],[84,10],[27,19],[31,-4],[95,-33],[54,-5],[64,22],[71,40],[17,140],[17,20],[44,5],[33,-1],[64,-11],[76,-3],[49,65],[77,5],[36,9],[59,-13],[58,1],[74,27],[69,45],[54,-4],[22,8],[13,9],[13,61],[102,4],[34,-6],[57,-2],[59,33],[18,-3],[29,-88],[16,-26],[32,-24],[72,-66],[12,17],[30,23],[86,-31],[81,-51],[69,-75],[76,22],[84,36],[55,11],[60,5],[36,16],[80,-19],[84,40],[40,37],[11,51],[-6,90],[-19,90],[-20,33],[-6,35],[11,32],[13,22],[54,19],[70,-28],[52,-21],[31,-35],[18,-31],[29,-27],[22,-6],[16,-93],[9,-115],[-13,-49],[-38,-12],[-120,-108],[-3,-99],[1,-48],[3,-34],[12,-29],[0,-41],[-13,-45],[-52,-74],[-37,-59],[-40,-80],[-23,-9],[-18,-14],[-17,44],[-90,78],[-209,45],[-100,58],[-44,-11],[-85,64],[-58,-28],[-123,-114],[-67,12],[-71,69],[-46,12],[-55,-36],[-87,-132],[-88,-64],[-80,25],[-106,-1],[-12,-73],[21,-51],[58,-87],[-27,-65],[20,-66],[38,-13],[58,4],[106,-85],[46,-90],[30,-98],[-65,71],[-43,67],[-60,25],[-83,57],[-52,10],[-56,-40],[-4,-45],[60,-85],[55,-52],[29,-42],[19,-94],[-11,-31],[-20,-30],[-65,59],[-100,210],[-139,41],[-23,-43],[27,-111],[20,-43],[121,-120],[-10,-25],[-17,-11],[-135,68],[-40,104],[-9,132],[-125,91],[-117,100],[-27,94],[25,35],[17,69],[-65,-12],[-40,-44],[-66,-43],[-2,-69],[10,-65],[-22,-94],[-21,-163],[13,-86],[142,-245],[49,-179],[35,-68],[72,-74],[76,-139],[32,-73],[23,-118],[-64,-73],[-37,-3],[-20,32],[28,81],[-4,49],[-98,76],[-42,-25],[-48,-50],[28,-92],[31,-61],[15,-84],[59,8],[-79,-94],[-75,-48],[-73,-3],[-47,-9],[-16,-24],[38,-17],[31,-2],[50,-50],[144,-61],[68,-77],[67,-7],[68,-141],[117,-38],[67,-142],[88,-28],[76,-53],[23,-50],[11,-90],[5,-192],[16,-143],[1,-45],[-4,-68],[-21,-33],[-28,-1],[-55,105],[-84,111],[-89,131],[-25,23],[-21,3],[-47,-45],[-132,-34],[-62,-48],[-23,-11],[-7,-25],[29,-26],[36,-61],[0,-82],[29,-100],[38,-25],[50,2],[28,-19],[7,-39],[29,-47],[19,-34],[-1,-25],[-138,-65],[-29,-30],[-24,-15],[-36,31],[-2,80],[-47,42],[-44,37],[-52,16],[-44,55],[-29,-45],[23,-155],[50,-106],[84,-286],[38,-169],[8,-82],[-19,-135],[41,-101],[28,-103],[-31,4],[-27,36],[-45,43],[-88,165],[-30,103],[-37,8],[-63,-15],[-70,-220],[1,-126],[-36,30],[-31,40],[4,138],[-4,58],[-84,187],[-39,21],[-18,64],[-31,68],[-40,-13],[-32,-28],[-10,-102],[-3,-92],[-24,-69],[-90,131],[-91,227],[-2,124],[66,113],[-8,81],[-62,160],[-91,103],[-50,30],[-24,110],[-49,56],[-39,27],[-8,39],[12,28],[95,113],[56,176],[28,8],[56,-42],[64,11],[53,103],[44,56],[75,-7],[169,-137],[182,-79],[91,-69],[51,-68],[28,-14],[43,-10],[-2,51],[-14,45],[36,25],[97,-1],[18,24],[18,38],[-20,44],[-32,22],[-35,5],[-23,14],[-36,-14],[-57,34],[-30,28],[-17,29],[-100,58],[-94,97],[-21,-55],[-38,-30],[-54,-4],[-153,62],[-93,-47],[-51,-13],[-39,-1],[-48,-21],[-56,-13],[-48,90],[-20,70],[-14,13],[-1,-65],[-16,-53],[-70,-29],[-40,40],[-31,124],[-40,156],[-69,127],[-56,33],[-5,70],[5,55],[68,14],[105,-58],[22,11],[24,27],[-5,59],[-15,53],[-29,3],[-20,-7],[-65,11],[-84,-29],[-38,28],[-13,33],[-70,84],[-60,112],[-98,74],[-63,228],[-54,99],[-57,71],[12,1],[22,-12],[41,-39],[45,-8],[24,25],[14,24],[9,39],[3,45],[7,15],[34,-5],[11,12]],[[38373,73684],[-20,-68],[-54,23],[-4,18],[61,40],[12,0],[5,-13]],[[39216,74928],[-49,-36],[-15,-42],[-12,-17],[-32,-11],[-32,0],[-122,84],[-28,-3],[28,38],[75,32],[43,41],[98,-40],[46,-46]],[[37392,77664],[24,-20],[62,3],[-21,-43],[-67,-48],[-46,-47],[-55,-40],[-27,45],[-31,-1],[-47,87],[-9,131],[62,34],[86,-2],[69,-99]],[[35631,79505],[23,-37],[46,-9],[40,34],[49,106],[34,6],[37,-8],[74,13],[130,50],[58,0],[83,-26],[61,1],[54,-76],[29,-119],[68,-118],[89,-103],[4,-63],[-32,-33],[-67,-42],[1,-45],[44,23],[37,10],[91,-10],[32,-46],[22,-68],[12,-56],[-8,-61],[-25,20],[-25,54],[-27,25],[-32,14],[14,-75],[-6,-100],[14,-9],[44,-2],[-29,-102],[-59,-28],[-69,-11],[-16,-36],[-13,-47],[-36,-69],[-47,-40],[-59,8],[-57,31]],[[36862,79876],[-73,-1],[-27,9],[-31,25],[-36,143],[13,50],[14,25],[16,19],[39,8],[39,-27],[14,-25],[32,-96],[6,-83],[-6,-47]],[[36266,80377],[21,-134],[20,-83],[2,-28],[-19,-39],[-97,-53],[-30,0],[-1,13],[22,53],[-19,60],[9,46],[-9,9],[-19,-7],[-68,-73],[-23,-7],[-3,15],[17,60],[2,40],[11,26],[18,23],[23,17],[17,3],[20,-18],[55,50],[51,27]],[[36358,80256],[-12,-11],[-29,3],[-11,17],[-6,25],[-1,48],[18,33],[75,52],[-34,18],[-1,12],[20,43],[81,66],[22,12],[21,-2],[-42,-117],[-101,-199]],[[36470,80807],[-232,-58],[-80,5],[-7,29],[16,18],[66,19],[27,139],[-100,64],[-5,18],[8,30],[11,14],[61,32],[25,8],[21,-5],[43,-37],[48,-78],[65,-13],[43,-33],[-10,-152]],[[35987,81057],[-33,-6],[-3,15],[58,70],[37,12],[13,-7],[-27,-41],[-45,-43]],[[35515,81453],[-51,-15],[-19,9],[-3,13],[12,36],[39,12],[28,-19],[5,-18],[-11,-18]],[[36178,81452],[-17,-14],[-22,3],[-21,17],[-29,49],[64,34],[26,-20],[10,-22],[0,-26],[-11,-21]],[[35613,81609],[-25,-6],[-32,5],[-20,16],[-20,64],[-4,39],[9,72],[-2,86],[67,3],[17,-13],[11,-255],[-1,-11]],[[36257,82014],[-1,-46],[-10,-54],[13,-58],[3,-41],[25,-13],[15,-19],[109,-21],[101,6],[20,-17],[2,-26],[-16,-30],[-58,-54],[-69,-87],[-20,-18],[-23,-1],[-16,8],[-11,155],[-75,-20],[-60,2],[-33,19],[-23,37],[-47,93],[-136,37],[-38,51],[-11,32],[4,17],[29,38],[35,-14],[22,9],[13,17],[0,14],[-19,33],[0,11],[138,42],[13,66],[30,5],[34,-21],[47,-69],[13,-83]],[[35639,82199],[65,-59],[-52,-97],[-80,1],[-114,71],[0,14],[9,21],[17,17],[18,4],[28,-11],[39,18],[31,-6],[39,27]],[[36225,82906],[-74,-181],[-29,-5],[-25,-45],[-79,-50],[69,-1],[19,-17],[1,-36],[-14,-20],[-89,-84],[-61,-31],[-66,-87],[-33,-1],[-33,-55],[-28,-24],[-15,-1],[-17,13],[-41,54],[74,53],[7,30],[51,31],[-5,10],[-80,43],[-32,30],[3,15],[39,34],[-19,4],[-12,19],[-22,7],[-7,17],[-4,44],[6,46],[23,20],[10,22],[9,6],[37,-11],[37,-37],[43,14],[50,-7],[1,9],[-37,90],[7,18],[19,21],[116,64],[144,107],[35,17],[10,-14],[15,-56],[-3,-75]],[[38025,83064],[5,-85],[-7,-25],[-14,-32],[-44,-60],[-115,-84],[-213,-195],[-125,-97],[-17,-47],[-9,-64],[75,-13],[29,-22],[-18,-33],[-111,-114],[-33,-104],[85,4],[70,20],[140,64],[131,48],[63,2],[123,-38],[28,-1],[52,17],[53,3],[356,-11],[99,22],[66,-27],[55,-67],[52,-123],[-2,-21],[-31,-56],[-58,-70],[-50,-97],[-15,-53],[-10,-57],[-16,-53],[-99,-249],[-97,-137],[-43,-98],[-54,-78],[-51,-49],[-55,-33],[-159,-35],[-44,-25],[-53,-43],[-56,-21],[66,2],[64,24],[118,9],[135,-82],[-12,-68],[-55,-53],[-123,-8],[-116,-119],[-52,-36],[-55,-18],[-69,5],[-125,32],[-55,33],[50,-54],[56,-29],[326,-66],[19,7],[104,70],[138,1],[264,-129],[76,-99],[109,-142],[59,-55],[42,-50],[27,-75],[51,-248],[58,-243],[76,-262],[35,-73],[45,-51],[231,-118],[51,-39],[89,-113],[86,-120],[80,-93],[87,-75],[-42,-39],[-29,-61],[22,-83],[35,-80],[69,-127],[61,-139],[-22,21],[-24,11],[-32,-3],[-32,7],[-58,43],[-56,53],[-112,-21],[-62,10],[-54,-2],[102,-31],[112,-2],[246,-233],[83,-138],[49,-182],[-33,-82],[-53,-53],[-49,-61],[-45,-69],[136,-101],[29,4],[30,14],[29,34],[49,83],[26,30],[84,11],[72,-7],[71,-18],[62,6],[126,-36],[64,-32],[160,-146],[35,-79],[16,-103],[2,-114],[-27,-104],[-31,-94],[-19,-121],[-14,-44],[-19,-34],[-84,-96],[-57,-39],[-24,17],[-25,-2],[-3,-23],[27,-49],[0,-59],[-50,-44],[-50,-19],[-86,24],[-118,-82],[85,-41],[17,-45],[-21,-78],[-53,-35],[-60,-15],[-60,-4],[-51,-19],[-48,-37],[61,20],[42,-18],[26,-65],[24,-19],[118,-28],[73,0],[141,16],[68,-1],[24,-11],[1,-55],[-11,-134],[-18,-28],[-188,-112],[-38,-79],[-11,-47],[-109,8],[-51,-50],[-89,-34],[-68,-35],[-67,-45],[-56,-14],[-238,54],[-144,-5],[-195,-46],[-50,8],[-75,44],[-77,30],[-89,13],[-76,42],[47,-80],[-106,-76],[-49,-15],[-51,2],[-103,-20],[-96,10],[14,-54],[26,-47],[-21,-21],[-22,-5],[-183,36],[-26,-7],[-23,-33],[-67,18],[-64,55],[-69,38],[-72,17],[-58,-6],[-236,-87],[-47,-88],[-23,-125],[-35,-110],[-55,-86],[-66,-11],[-63,59],[-118,65],[-40,44],[-13,3],[-13,-16],[-47,-20],[-48,-1],[-74,-17],[-129,-53],[-52,-36],[-112,-99],[-23,-27],[-40,-100],[-63,-18],[-56,64],[-65,23],[-69,-22],[-41,-34],[-19,27],[-1,57],[50,68],[133,51],[117,133],[57,80],[23,46],[28,29],[37,11],[18,50],[163,202],[13,47],[8,83],[14,79],[132,52],[63,168],[17,13],[184,31],[137,-3],[135,-32],[70,-3],[70,11],[54,45],[94,164],[53,71],[60,65],[57,75],[91,137],[-62,-47],[-74,-75],[-44,-44],[-138,-44],[-59,-45],[-104,-101],[-20,-8],[-157,24],[-116,131],[-75,54],[-31,6],[-32,-16],[-68,-16],[-69,3],[35,60],[48,34],[-108,23],[-30,19],[-34,42],[-84,8],[-41,-11],[-68,-56],[-107,-60],[-130,83],[-25,36],[0,70],[-19,55],[-36,20],[46,72],[55,48],[122,48],[185,113],[104,49],[96,83],[40,51],[29,69],[29,86],[41,69],[-40,16],[-18,53],[5,53],[18,47],[-16,59],[-29,61],[1,48],[8,51],[-74,-2],[-74,-16],[-68,-37],[-65,-49],[-58,-9],[1,39],[25,49],[66,70],[70,58],[25,44],[20,51],[35,41],[92,77],[175,87],[27,5],[69,-10],[67,13],[60,32],[59,6],[133,-90],[-40,140],[59,33],[85,-126],[32,-13],[67,18],[-26,21],[-30,2],[-39,19],[-34,40],[-55,129],[3,76],[37,79],[42,73],[-35,15],[-28,28],[-7,73],[10,64],[74,57],[22,87],[9,95],[-12,43],[-73,-7],[-36,-17],[-32,-28],[-33,1],[-90,105],[-52,80],[-93,168],[-13,101],[74,217],[115,139],[135,48],[-26,9],[-206,2],[-68,-17],[-63,-56],[-35,-18],[-37,-6],[-34,-28],[-34,-40],[-34,-25],[-69,7],[-33,-9],[-24,23],[-20,38],[-26,10],[-30,-12],[-62,-50],[-62,-30],[-76,32],[-99,59],[-20,-22],[-22,-55],[-13,-86],[-70,75],[-60,100],[-20,63],[-2,70],[33,28],[35,-25],[53,167],[105,219],[37,64],[26,83],[-4,55],[-24,46],[-97,105],[1,85],[10,97],[27,58],[11,11],[130,-2],[-51,30],[-101,87],[2,31],[24,80],[-11,-8],[-22,-37],[-41,-90],[-25,-21],[-71,-21],[-13,-45],[-12,-11],[-35,-5],[-11,-42],[-8,-2],[-10,44],[-1,74],[14,68],[27,53],[104,121],[-50,-37],[-116,-112],[-59,-73],[-15,-25],[-5,-21],[0,-24],[26,-129],[-7,-60],[-100,-396],[-18,-40],[-18,-20],[-16,-5],[-49,7],[-22,30],[0,34],[9,50],[42,188],[18,52],[26,48],[59,85],[-2,6],[-39,-17],[-16,6],[-12,16],[7,252],[32,83],[12,121],[27,103],[32,75],[24,96],[37,43],[9,65],[41,71],[32,74],[-17,-7],[-202,-193],[-51,-35],[-71,9],[-53,22],[-42,46],[-19,87],[-52,2],[-44,16],[1,11],[57,48],[91,16],[86,77],[-76,51],[6,17],[67,44],[84,147],[17,136],[-40,63],[-15,42],[-81,46],[-13,60],[9,33],[27,33],[39,25],[63,24],[-57,26],[-21,31],[-16,44],[-1,26],[29,114],[17,47],[33,60],[151,-3],[18,26],[17,1],[77,-24],[-11,26],[-127,143],[-11,27],[36,77],[3,34],[-6,37],[11,28],[40,13],[122,-1],[30,13],[-14,37],[-28,48],[-6,41],[7,36],[1,73],[6,32],[29,49],[24,14],[30,8],[67,-16],[25,-19],[29,-46],[22,3],[84,50],[25,7],[34,-57],[142,46],[192,20],[115,31],[122,11],[113,34],[120,-16],[4,-20],[-6,-27],[-31,-77]],[[38130,83300],[-5,-4],[-22,19],[-35,69],[55,13],[26,-8],[-9,-29],[-10,-60]],[[37993,83354],[-33,-14],[-33,1],[-52,61],[-20,43],[4,29],[22,10],[50,-14],[25,-50],[4,-33],[6,-13],[31,-12],[-4,-8]],[[38056,83599],[-8,-26],[44,1],[64,-22],[39,-3],[32,-27],[-17,-51],[-20,-14],[-22,-3],[-76,51],[-100,-21],[-20,7],[-13,14],[-6,17],[0,35],[-5,11],[-36,-34],[-16,4],[-9,16],[-4,34],[4,48],[21,68],[36,14],[54,-8],[61,-39],[19,-24],[-1,-19],[-21,-29]],[[38352,83809],[-66,-1],[34,61],[40,15],[74,-6],[-13,-28],[-69,-41]],[[38247,83762],[-50,-25],[-22,21],[-5,67],[-60,29],[-29,17],[-22,34],[5,10],[39,14],[67,-61],[27,-49],[49,-15],[6,-8],[-5,-34]],[[39075,85167],[12,-73],[30,19],[45,-71],[24,0],[38,28],[-8,-65],[-40,-182],[-11,-31],[-7,-55],[-8,-11],[-12,-111],[-27,-37],[-22,-88],[-9,-8],[-33,34],[33,133],[13,78],[-8,41],[-19,36],[-50,1],[-42,-17],[-9,22],[-2,29],[-10,9],[-56,-2],[-16,8],[-11,27],[-2,21],[50,16],[48,-6],[70,42],[-44,141],[-57,13],[-14,14],[11,24],[32,13],[49,72],[29,11],[36,-2],[-3,-73]],[[39230,85142],[-15,-12],[-57,106],[42,121],[51,-4],[8,-32],[-5,-29],[-26,-2],[-2,-9],[8,-56],[0,-66],[-4,-17]],[[39386,85452],[0,-12],[-30,-87],[0,-34],[-49,3],[-7,11],[-10,50],[7,54],[6,14],[15,5],[15,-10],[24,27],[13,-1],[16,-20]],[[49467,80751],[-30,-52],[-26,3],[-18,70],[-4,180],[11,88],[127,321],[56,26],[80,196],[22,87],[34,79],[21,70],[17,28],[37,-13],[17,-13],[-40,-41],[5,-53],[-3,-22],[-99,-232],[-26,-150],[-35,-37],[-146,-535]],[[50952,82358],[-48,-25],[-29,-73],[-39,-13],[-37,-24],[-13,-232],[68,-88],[-38,-13],[-34,-26],[-24,-39],[-25,-84],[-94,-48],[-36,-35],[-53,-78],[-27,-114],[-53,-49],[-60,-11],[35,93],[46,76],[-44,52],[-27,82],[-34,62],[27,70],[-13,115],[4,111],[40,57],[46,46],[71,106],[77,76],[107,35],[49,-32],[21,70],[35,16],[32,-17],[70,-66]],[[50999,82448],[-11,-65],[-30,5],[-28,48],[56,73],[85,-4],[30,-15],[-102,-42]],[[50567,83598],[-26,-9],[-12,3],[16,48],[11,21],[40,19],[12,-3],[-41,-79]],[[50672,84057],[-15,-34],[-15,42],[6,8],[10,42],[29,23],[45,-14],[-1,-10],[-43,-34],[-16,-23]],[[53911,90644],[-154,-24],[-116,49],[-58,-25],[-101,-1],[-115,-19],[-39,-37],[-30,-15],[-107,53],[-101,88],[-73,-67],[-48,-13],[-43,61],[-37,9],[-20,-20],[-18,-53],[-28,-42],[-7,-27],[-5,-108],[-8,-25],[-97,14],[6,-28],[21,-14],[8,-18],[-35,-24],[-97,3],[-10,-25],[27,-40],[-21,-34],[-20,-14],[-116,-22],[-67,5],[-19,-22],[-5,-29],[12,-29],[30,-15],[10,-18],[-2,-39],[-25,-7],[-70,69],[-21,-4],[16,-36],[40,-39],[23,-40],[20,-48],[-4,-36],[-87,-118],[-76,-74],[-57,-67],[-34,-71],[39,-36],[43,-51],[31,-99],[36,-89],[74,-84],[-15,-49],[-17,-38],[-122,-84],[-138,-126],[-150,-322],[-49,-43],[-131,-55],[-48,-53],[-97,-63],[-169,-54],[-77,-75],[-35,-78],[-38,-5],[-39,30],[-51,23],[-7,-51],[3,-37],[-82,55],[-39,-51],[-30,-84],[-118,-114],[-126,20],[-15,-20],[34,-15],[5,-18],[-23,-9],[-35,1],[-53,-23],[-36,2],[-17,-54],[-27,-66],[-72,-27],[-37,-5],[-18,-37],[110,-8],[-9,-32],[-2,-31],[-11,-34],[-126,-48],[-19,-39],[-26,-24],[-56,2],[2,22],[9,25],[-83,-2],[-26,55],[-15,-14],[9,-45],[22,-46],[24,-68],[-20,-42],[-22,-22],[16,-19],[45,-15],[18,-27],[-53,-23],[-66,-79],[-68,-2],[-41,-52],[-44,1],[-36,32],[-58,27],[-18,-47],[-3,-38],[32,-95],[62,-74],[57,-32],[-41,-22],[-31,-47],[-37,-150],[-20,-59],[-22,-103],[14,-88],[11,-43],[28,-58],[-76,7],[-80,34],[11,-71],[-50,-84],[10,-73],[10,-49],[-15,-79],[23,-25],[12,-48],[-20,-35],[9,-30],[3,-107],[16,-167],[-6,-35],[45,-145],[-11,-51],[-6,-65],[64,-63],[56,1],[58,1],[22,-15],[22,-44],[17,-53],[48,5],[75,42],[49,10],[32,-81],[88,-108],[52,-48],[87,-25],[92,-87],[-13,-105],[38,-35],[108,-41],[39,-56],[18,-48],[29,-39],[33,-119],[-12,-73],[-43,-26],[-103,-78],[-46,-59],[-36,-36],[-103,-79],[-37,-14],[-36,-41],[-35,-18],[-31,11],[-116,-74],[9,-32],[89,-13],[45,16],[35,37],[39,9],[34,-8],[37,30],[29,11],[30,-14],[34,-70],[-70,-36],[-49,-2],[-24,-115],[-30,-49],[-21,-24],[-109,-49],[-72,-62],[-85,-50],[-37,11],[-56,-51],[-124,-60],[-63,-81],[-143,-72],[-73,-59],[-197,-3],[-189,12],[-59,-28],[61,-8],[42,-28],[51,12],[119,-14],[62,-15],[79,-96],[-58,-35],[-101,-26],[38,-137],[31,-92],[-41,-55],[-3,-253],[-57,-5],[-24,-105],[18,-53],[-1,-124],[12,-76],[28,-71],[-13,-73],[-90,-172],[2,-80],[16,-48],[12,-77],[-41,-146],[-29,-123],[-34,-104],[-77,-124],[-39,-92],[-89,-290],[-45,-57],[-55,-44],[-60,41],[-56,22],[-68,-3],[-107,-33],[-160,22],[-157,-11],[-40,-29],[24,-105],[-58,-13],[-56,29],[-50,-35],[-42,-39],[-81,-93],[-28,-57],[-7,-108],[43,-96],[38,-113],[-98,-137],[-54,-4],[-160,38],[-282,-86],[-254,68],[32,73],[-1,53],[14,83],[9,84],[-3,57],[-18,60],[-63,79],[-141,266],[-42,112],[-29,47],[21,2],[116,-60],[27,8],[29,22],[-35,86],[-29,40],[-21,58],[68,16],[49,-4],[37,66],[-21,106],[-53,33],[-44,14],[-85,167],[-88,86],[-157,334],[-57,228],[-54,-21],[-26,99],[-18,95],[-4,69],[-84,40],[-3,48],[-15,218],[-90,29],[-58,121],[-10,231],[-60,42],[-47,-12],[2,57],[11,54],[-27,212],[-10,194],[-22,59],[-13,68],[11,60],[17,34],[58,9],[54,-53]],[[46472,83606],[48,-132],[43,-17],[58,34],[40,97],[23,144],[27,138],[-32,147],[-34,129],[-2,38],[89,109],[28,89],[29,84],[33,29],[49,7],[56,15],[72,57],[64,76],[49,69],[17,137],[0,69],[22,52],[21,100],[-20,98],[-64,150],[-76,211],[-12,115],[35,21],[66,19],[126,6],[13,13],[13,50],[28,69],[30,49],[21,72],[10,64],[-72,97],[-94,100],[-64,33],[-113,83],[-80,70],[46,267],[34,198],[5,48],[2,75],[-110,318],[4,71],[10,64],[-11,108],[-7,98],[19,29],[45,55],[-43,85],[-3,7],[-81,211],[123,208],[-21,108],[74,78],[134,180],[76,100],[16,18],[60,44],[113,53],[126,25],[56,0],[216,-36],[169,-27],[25,28],[35,57],[45,81],[4,90],[-16,132],[-25,80],[-119,51],[-130,71],[160,224],[111,155],[139,234],[43,97],[31,39],[40,358],[27,100],[23,53],[0,54],[-14,90],[-39,205],[218,26],[71,14],[66,25],[129,63],[64,56],[-36,191],[78,65],[191,225],[206,216],[97,82],[10,40],[7,64],[-42,101],[-46,62],[-90,118],[38,83],[66,16],[88,32],[68,71],[7,9],[115,277],[225,141],[90,76],[140,-57],[205,-87],[91,128],[31,47],[30,70],[-12,121],[-6,157],[10,63],[81,28],[44,7],[228,-65],[58,2],[107,-9],[120,-29],[252,-75],[104,-32],[59,-6],[50,35],[107,91],[-158,67],[104,68],[54,68],[46,85],[17,98],[-6,53],[-32,36],[-97,90],[219,13],[76,4]],[[51853,94005],[159,-60],[7,-13],[1,-30],[5,-32],[155,-82],[44,-43],[95,-65],[25,-35],[88,-42],[63,-44],[73,-36],[86,-55],[115,-45],[97,-14],[245,-76],[42,-25],[71,-52],[71,-62],[49,-125],[80,-7],[21,-43],[69,-75],[96,-65],[-3,-22],[-77,-60],[-8,-82],[8,-104],[23,-86],[-2,-24],[-19,-30],[-23,-46],[-8,-40],[2,-20],[8,-10],[40,-1],[72,-10],[43,-18],[24,-98],[-9,-18],[-60,-45],[-18,-35],[-2,-52],[11,-57],[21,-64],[47,-68],[65,-71],[42,-58],[20,-42],[7,-28],[-29,-37],[-26,-71],[-5,-82],[-12,-54],[-56,-73],[-39,-26],[-12,-39],[-4,-65],[11,-80],[4,-53],[12,-39],[18,-25],[91,-45],[51,-91],[31,-74],[62,-192]],[[49460,70571],[-51,25],[-62,11],[-12,-14],[-25,-14],[-13,-25],[10,-99],[-15,-17],[-71,10]],[[49221,70448],[-23,-11],[-38,-69],[-39,-29],[-50,-20],[-37,-25],[-47,-22],[-40,-13],[-15,-29],[-10,-34],[3,-32],[40,-63],[5,-67],[-4,-83],[-9,-44],[-16,-29],[-100,-38],[-103,-67],[-2,-16],[47,-60],[2,-15],[-39,-34],[-4,-34],[4,-40],[21,-41],[8,-36],[-57,-27],[-77,10],[-91,51]],[[48550,69531],[-31,-8],[-31,-26],[-32,11],[-34,32],[-49,65],[-24,40],[-10,43],[-13,6],[-21,-12],[-17,-52],[-45,-93],[-33,-25],[-51,5],[-71,-2],[-44,-7],[-54,33],[-13,-7],[0,-21],[-20,-34],[-34,-23]],[[47923,69456],[-153,51],[-22,41],[35,20],[48,54],[33,-6],[40,11],[17,23],[-25,68]],[[47896,69718],[-64,85],[-34,31]],[[47798,69834],[-47,22],[-8,22],[26,133],[-8,19],[-53,-7],[-12,14],[-5,23],[4,32],[36,51],[40,46],[10,26],[-1,20],[-51,20],[-31,21],[-24,7],[-17,-12]],[[47657,70271],[-13,14],[-12,38],[12,58],[46,54],[50,47],[43,35],[25,15],[11,60]],[[47819,70592],[26,-6],[51,-4],[57,-13],[53,-17],[46,-21],[98,-22],[89,-13],[27,-13],[22,1],[26,-18],[16,14],[12,24],[48,29],[45,37],[31,47],[18,37],[31,27],[32,7],[30,14],[126,17],[130,-14],[62,26],[50,46],[75,13],[4,0],[111,-35],[8,21],[5,9],[-2,99],[35,45],[33,19]],[[35933,86110],[12,-31],[-14,3],[-39,36],[-68,86],[-24,71],[-4,32],[17,-3],[14,-29],[65,-20],[17,-14],[0,-35],[22,-42],[2,-54]],[[35978,86486],[-12,-39],[-15,0],[-55,49],[-44,26],[-14,22],[-13,39],[26,5],[29,-9],[75,-35],[21,-37],[2,-21]],[[35649,86832],[53,-40],[18,-28],[-30,-28],[-36,-7],[-44,7],[-73,29],[-25,69],[50,-2],[59,13],[28,-13]],[[35973,86925],[-14,-140],[-24,1],[-42,38],[-32,8],[-10,-20],[2,-25],[16,-16],[51,-93],[5,-28],[-7,-13],[-49,27],[-119,121],[-92,200],[124,31],[91,-52],[100,-39]],[[36104,86957],[-27,-75],[-42,11],[-11,8],[-9,20],[4,56],[-1,80],[47,-66],[39,-34]],[[52969,73246],[-8,-43],[-24,-50],[-30,-52],[-25,-62],[-33,-134],[-22,-62],[-88,-122],[-7,-169]],[[49828,72137],[-36,34],[-10,46],[-56,119],[-62,197],[-2,56],[24,65],[23,49],[3,39],[3,11]],[[49715,72753],[19,81],[45,108],[42,63],[31,21],[63,-19],[108,-16],[84,15],[77,48],[42,42],[36,44],[12,29],[16,14],[64,25],[21,30],[8,56],[6,63],[13,47],[17,34],[118,82],[11,29],[19,28],[35,31],[34,45],[36,28],[47,-3],[43,6],[33,16],[15,1]],[[50810,73701],[61,-13],[12,-52],[6,-54],[105,4],[59,116],[31,14],[48,40],[33,36],[22,-23],[32,-74],[34,-60],[20,-24],[2,-18],[19,-11],[39,-7],[25,-18],[8,-56],[1,-50],[-12,-36],[-7,-32],[27,-13],[39,12],[27,18],[83,-41],[29,93],[32,47],[43,22],[38,29],[36,21],[24,-1],[10,8],[31,-2],[35,-9],[47,10],[66,-22],[41,-43],[40,-15],[46,3],[31,24],[46,81],[33,-1],[52,13],[73,-1],[168,-17],[43,-32],[103,-40],[46,-46],[20,-55],[10,-38],[106,-59],[158,-74],[38,-9]],[[72348,31],[-83,-31],[-57,11],[-114,88],[-30,59],[-45,165],[10,58],[36,102],[81,41],[85,-15],[38,-28],[45,-120],[58,-121],[-10,-145],[-14,-64]],[[66162,8726],[-37,-8],[-17,27],[-11,66],[11,63],[3,51],[-30,88],[29,50],[25,-58],[14,-4],[38,-41],[-11,-75],[2,-25],[-17,-75],[1,-59]],[[4161,38742],[-33,-4],[-14,9],[-5,63],[25,43],[15,10],[22,-48],[5,-40],[-15,-33]],[[3951,38864],[-47,-47],[-23,15],[-29,89],[-20,249],[16,41],[11,15],[62,-30],[26,-36],[26,-22],[-13,-45],[6,-187],[-15,-42]],[[4104,39096],[-68,-11],[-45,9],[-11,74],[23,63],[-16,77],[10,45],[23,30],[38,-39],[6,-58],[24,-52],[106,-111],[-90,-27]],[[45361,66729],[-15,-153],[11,-44],[21,-32],[9,-34],[18,-407],[-3,-33],[-72,-163],[-16,-48],[-3,-203],[-12,-54],[-25,-54],[-45,-174],[-40,-78],[-106,95],[-63,41],[-31,45],[-20,31],[13,40],[28,43],[5,33],[-68,38],[-30,25],[0,45],[23,69],[-10,57],[-39,-3],[-30,8],[-4,30],[22,38],[29,49],[-1,55],[-35,23],[-31,45],[-13,60],[24,41],[40,27],[-29,62],[-20,1],[-15,13],[13,29],[30,43],[43,128],[59,61],[105,39],[28,17],[26,45],[29,29],[35,-4],[33,-18],[19,-18],[15,19],[15,56],[-9,49],[5,135],[18,76],[31,5],[28,-42],[-2,-38],[11,-88],[1,-57]],[[39150,69951],[-20,-91],[-39,84],[-52,73],[-11,68],[0,18],[60,-49],[62,-103]],[[43210,73730],[20,-35],[45,-16],[16,-12],[18,-24],[31,-10],[36,10],[27,32],[35,14],[36,-5],[20,-17],[40,-26]],[[43534,73641],[22,6],[44,-16],[44,-50],[19,-51],[5,-27],[19,-30],[74,-136],[24,-7],[26,21],[17,29],[24,6],[39,-13],[25,-16],[12,-58],[9,-12],[17,13],[30,3],[48,-15],[66,17],[53,24],[27,-1],[44,-68],[50,-26],[109,-20],[118,-32],[46,-27],[32,-12],[3,-91],[-10,-14],[-117,-181],[-49,-65],[-25,-93],[-18,-142],[-34,-135],[-52,-129],[-19,-96],[14,-64],[-9,-101],[-32,-137],[-5,-104],[21,-70],[29,-14]],[[44274,71707],[-70,-47],[-16,-42],[-28,-54],[-45,-23],[-45,-8],[-36,7],[-21,22],[1,21],[-19,17],[-48,-1],[-50,-37],[-39,-62],[12,-34],[36,-9],[10,-13],[0,-18],[-13,-21],[-15,-37],[-77,-108],[-77,-109],[-13,-33],[-24,-23],[-98,-58],[-11,-24],[-5,-97]],[[43583,70916],[-11,-80],[-73,-75],[-72,-75],[-19,-46],[-13,-53],[-23,-59],[-4,-32],[37,-52],[-5,-42],[-11,-61],[-35,-43],[-39,-24],[1,-66],[21,-9],[46,5],[66,47],[43,62],[-25,58],[-3,12],[6,14],[50,63],[63,38],[87,8],[105,-23],[10,-9],[-5,-39],[10,-58],[19,-40],[-26,-115],[19,-35],[31,-43],[23,-39],[33,-36],[29,-61],[10,-34]],[[44203,67729],[-32,-17],[-1,11],[-13,10],[-11,-6],[-9,-12],[-1,-23],[-68,-37],[-47,-38],[-184,-230],[-87,-67],[-17,-41],[-17,-76],[-51,-65],[-44,-31],[-110,-31],[-111,-69],[-49,29],[-129,-3],[-80,83],[-155,53],[-50,121],[-71,8],[-46,-4],[-27,19],[-7,41],[-1,40],[-49,-19],[-37,0],[-22,-16],[-18,-18],[-21,12],[-12,-4],[1,-24],[-45,-6],[-48,15],[-128,62],[-19,10],[-89,24],[-36,25],[-29,62],[-22,19],[-13,12],[-82,-31],[-29,-49],[-45,-57],[-306,-279],[-56,-117],[-65,-172],[-5,-80],[28,-257],[62,-135],[8,-31]],[[41708,66340],[-34,0],[-58,17],[-49,20],[-45,-11],[-45,-28],[-38,-17],[-28,-5],[-18,-16],[-9,-32],[-2,-22],[-49,5],[-113,46],[-101,32],[-59,-36],[-39,-34],[-27,5],[-20,36],[-14,35],[-39,32],[-90,48]],[[40831,66415],[5,23],[15,32],[-1,20],[-17,30],[-82,32],[-39,8],[-25,-22],[-18,-27]],[[40669,66511],[-46,99],[-33,20],[-49,3],[-57,30],[-59,38],[-143,62],[-39,7],[-16,-9],[-10,-37],[-6,-104],[-6,-11],[-66,-4],[-82,15],[-38,-8],[-33,0],[-32,27],[-141,-31],[-24,15],[-34,47],[-38,38],[-29,19],[-25,23],[-23,3],[-35,-21],[-48,-9],[-40,2],[-22,-3],[-89,115],[-13,32],[-45,8],[-55,2],[-141,74],[-64,40],[-9,24],[0,19],[-10,-4],[-20,-34],[-11,-28],[-13,-5],[-21,5],[-18,15],[-12,20],[13,35],[21,46],[9,50],[-2,45],[-36,29],[-52,12],[-38,3],[-50,26],[-24,18],[-23,50],[0,36]],[[38792,67355],[94,32],[86,131],[81,474],[58,561],[44,106],[54,29],[-44,78],[-27,-39],[-12,-42],[-15,-21],[33,515],[23,188],[40,198],[81,-79],[67,-79],[35,-69],[44,-230],[34,-48],[49,-48],[-19,52],[-35,41],[-53,306],[-34,87],[-52,73],[-169,153],[-15,30],[-8,59],[56,-3],[48,-29],[-6,33],[-14,35],[-23,124],[-18,291],[2,49],[-8,62],[-54,13],[-43,3],[-46,24],[-230,171],[-79,177],[-80,130],[-19,57],[1,58],[42,122],[-37,77],[-36,15],[-31,38],[28,63],[24,41],[47,11],[61,-13],[59,-37],[46,-10],[-136,99],[-220,-34],[-47,13],[-41,22],[-15,72],[31,33],[28,60],[-32,43],[-41,16],[-65,-1],[-61,-13],[-16,24],[37,67],[-31,25],[-42,-12],[-61,-13],[-58,21],[-56,76],[-36,-1],[-25,-9],[-37,29],[-40,8],[-28,-10],[-37,44],[-229,87],[-99,11],[-91,-40],[-50,14],[-36,57],[-31,95],[-146,73],[29,49],[68,11],[78,33],[28,43],[-61,50],[-45,12],[-19,18],[-19,45],[27,20],[19,-10],[55,-7],[95,11],[-36,45],[-36,10],[-17,12],[-76,4],[-35,-15],[-79,6],[-17,49],[-8,42],[24,93],[111,83],[275,91],[118,-13],[82,16],[99,58],[43,49],[140,29],[133,-52],[123,-198],[58,-66],[144,115],[213,-3],[44,-65],[18,55],[40,64],[31,-29],[16,-40],[225,11],[36,12],[-61,47],[-49,112],[-10,413],[-63,115],[-72,184],[-33,109],[-3,38],[11,54],[88,-3],[69,-14],[129,42],[63,-29],[-4,-85],[19,-107],[22,-52],[33,-60],[104,6],[113,-35],[142,-5],[209,-60],[88,35],[86,74],[164,48],[13,26],[-94,-10],[-87,47],[-11,51],[10,46],[35,105],[250,166],[179,50],[188,91],[94,94],[62,121],[20,27],[26,22],[-24,44],[16,463],[18,83],[36,68],[56,53],[84,57],[311,79],[46,32]],[[41308,75351],[7,-50],[22,-63],[16,-35],[-13,-45],[10,-37],[42,-67],[53,-64],[47,-40],[13,4],[34,12],[59,41],[49,13],[28,-31],[16,-18],[31,-72],[8,-74],[14,-62],[25,-25],[94,-9],[69,-23],[18,-21],[24,-137],[13,-20],[17,16],[17,23],[23,4],[41,-9],[53,-3],[55,-15],[76,-78],[-3,-25],[-14,-46],[-6,-36],[13,-14],[21,-37],[-5,-43],[-20,-30],[-8,-25],[0,-16],[8,-14],[15,-11],[112,-16],[103,16],[65,44],[11,46],[18,52],[39,44],[27,14],[24,-18],[-41,-183],[30,-47],[4,-70],[11,-61],[37,1],[44,-11],[32,-23],[37,-37],[53,-33],[37,-12],[13,-28],[30,-32],[47,-68],[43,-46],[20,1],[40,17],[58,12],[46,-1]],[[52324,69211],[20,-21]],[[52344,69190],[14,-25],[1,-27],[-14,-13],[-19,-36],[-8,-44],[-15,-11],[-14,-1],[-11,-13],[3,-19],[12,-18],[19,-16],[36,-16],[35,-24],[0,-19],[-7,-21],[-46,-8],[-33,-3],[-16,-9],[2,-36],[95,-38],[43,-36],[22,-47],[61,-31],[99,-15],[68,-48],[39,-81],[63,19],[87,120],[85,31],[85,-57],[45,-47],[8,-37],[-19,-15],[-47,7],[-39,-23],[-30,-53],[-4,-56],[21,-60],[29,-41],[39,-23],[21,-31],[2,-40]],[[53056,68229],[10,-11],[-22,-18],[-24,-27],[-13,-47],[-3,-77],[-75,-59],[-28,-11],[-13,-40],[-20,-111],[3,-84],[10,-43],[4,-35],[25,-43],[22,-65],[14,-87],[33,-67],[83,-66],[41,-38],[30,-56],[23,-50],[69,-67],[-6,-48],[-15,-47],[-15,-22],[-34,-60],[-34,-34]],[[53121,66916],[-54,-105],[-86,-6],[-21,-9],[-33,-28],[-16,-53],[16,-43],[-2,-43],[-15,-83],[20,-90],[31,-41],[5,-23],[-6,-42],[-45,-85],[-14,-32],[-45,-15],[-16,8],[-23,29],[-22,9],[-54,-35],[-55,-21],[-44,16],[-42,2],[-30,-14],[-23,-5]],[[52547,66207],[-44,-37],[-70,-27],[-33,6],[-12,35],[-13,49],[7,22]],[[52382,66255],[46,39],[5,38],[65,179],[13,58],[0,19],[-17,13],[-35,-1],[-159,73],[8,83],[-47,45],[-50,40],[-9,45],[-55,90],[-41,51],[-52,25],[-45,37],[-27,23],[-12,42],[0,25],[-13,24],[-22,-3],[-37,-33],[-45,-29],[-8,-21],[17,-50],[11,-32],[-5,-30],[-14,-38],[-87,-85],[-10,-29],[17,-47],[-11,-22],[-72,-32],[2,26],[-5,42],[-41,44],[-59,35],[-131,117],[-50,16],[-44,13],[-65,57]],[[51298,67102],[-33,10],[-36,40],[-80,136],[-68,74],[-46,37]],[[51035,67399],[-13,37],[-3,37],[2,13]],[[51021,67486],[35,53],[27,8],[34,1],[23,-27],[30,-5],[17,34],[9,50],[-4,63],[-72,147],[-63,102],[-7,23],[14,19],[21,10],[24,-8],[60,-8],[59,10],[20,25],[0,33],[-22,32],[-68,84],[-53,74],[-63,57],[-46,23],[-14,29],[-6,30],[6,57],[3,72],[11,45],[41,86],[41,91],[24,87],[13,81],[-4,23],[-21,17],[-45,18],[-61,-15],[-52,-30],[-20,-2]],[[50852,69980],[13,-1],[52,30],[18,24],[11,28],[12,7],[35,-31],[36,-2],[40,19],[31,26],[36,23],[17,15]],[[51153,70118],[21,24],[43,70],[48,15]],[[51265,70227],[65,-18],[69,-7],[53,17],[132,-21],[29,-16],[18,-18],[35,-61],[33,-78],[46,-36],[55,-43],[29,-31],[41,-94],[33,-46],[11,3],[11,12],[8,9],[9,-8],[0,-29],[2,-63],[-8,-67],[12,-63],[0,-20],[-8,-18],[1,-16],[12,-18],[44,-42],[42,-64],[48,-46],[44,-29],[28,-2],[46,-52],[90,-38],[29,-13]],[[52439,84720],[-51,-10],[-32,30],[12,22],[36,25],[38,-3],[8,-29],[-11,-35]],[[52558,84754],[-58,-36],[-22,9],[5,60],[35,28],[58,3],[-18,-64]],[[52757,84994],[74,-25],[31,9],[36,-55],[-60,-34],[-4,-43],[23,-27],[8,-39],[-59,0],[-29,33],[-12,41],[-28,29],[-37,23],[18,29],[11,43],[28,16]],[[52652,84958],[-42,-4],[-60,51],[-8,20],[24,12],[-16,41],[5,19],[46,-33],[25,-38],[-24,-9],[42,-40],[8,-19]],[[52335,85159],[-8,-49],[-39,6],[-40,-9],[-33,48],[-17,81],[6,17],[25,19],[19,-45],[87,-68]],[[52200,87978],[6,-19],[34,5],[46,36],[33,-17],[-4,-50],[-22,2],[-6,8],[-29,-29],[-5,-17],[-33,-12],[-60,50],[-38,81],[88,0],[-8,-19],[-2,-19]],[[54315,89798],[-87,-35],[-70,22],[-1,67],[43,32],[79,13],[107,-32],[16,-18],[-62,-13],[-25,-36]],[[56714,93989],[-39,-13],[-120,-50],[-74,-34],[-88,-25],[23,-34],[147,-7],[22,-9],[17,-17],[2,-27],[-14,-44],[-159,-243],[-5,-52],[52,-142],[73,-168],[220,-75],[163,-58],[105,-138],[174,-182],[92,-68],[5,-21],[-28,-126],[-111,-126],[-104,-106],[-107,-128],[-84,-109],[-91,-131],[-11,-42],[-1,-40],[15,-44],[117,-160],[45,-82],[55,-88],[46,-96],[27,-86],[47,-84],[29,-43],[48,-60],[58,-89],[20,-71],[88,-246],[9,-63],[-5,-46],[-38,-12],[-86,-7],[-92,-30],[-5,-11],[60,-58],[-53,-99],[-7,-142],[-57,-74],[-6,-17],[3,-15],[10,-11],[105,-20],[9,-20],[1,-42],[-10,-39],[-52,-28],[-57,-43],[-13,-39],[2,-35],[19,-59],[38,-68],[47,-43],[169,-41],[22,-34],[9,-46],[-3,-45],[-79,-91],[1,-35],[32,-84],[39,-80],[164,-87],[57,-48],[15,-38],[8,-61],[-1,-66],[-13,-59],[-51,-76],[-120,-150],[-120,-58],[-7,-13],[37,-48],[212,-192],[137,-90],[187,-122],[120,-96],[39,-69],[52,-77],[58,-63],[42,-54],[16,-35],[-2,-38],[-56,-113],[-32,-88],[-56,-129],[-58,-90],[-146,-164],[-216,-204],[-50,-61],[-101,-108],[-173,-216],[-44,-47],[-142,-172],[-64,-55],[-51,-51],[-140,-163],[-151,-123],[-148,-115],[-44,-58],[-56,-45],[-65,-42],[-28,-23],[-149,-157],[-207,-219]],[[56033,85165],[-21,-3],[-53,-35],[-84,-9],[-37,-27],[-128,77],[-22,5],[-75,-19],[-73,-56],[-134,-17],[-66,-18],[-42,-26],[-9,61],[18,78],[30,51],[2,34],[-21,-4],[-43,-75],[-23,-89],[-46,-44],[-101,-18],[-98,71],[-47,-1],[30,-51],[19,-56],[-2,-31],[-52,6],[-59,-34],[-51,-49],[-25,0],[-34,68],[-63,-31],[-54,-43],[-110,-14],[-65,-56],[-115,-38],[-64,1],[-144,-46],[-48,-71],[-43,-26],[-60,22],[-185,-34],[-176,-46],[-76,3],[-75,19],[-80,-63],[-84,-84],[-94,-30],[-33,10],[27,45],[61,45],[43,62],[6,52],[-29,20],[-40,6],[-50,53],[-48,116],[-26,6],[-14,-30],[-14,-89],[-15,-25],[-26,-20],[-30,-21],[-30,-10],[-107,1],[-14,45],[0,19],[19,59],[-17,10],[16,46],[25,-2],[30,7],[15,23],[-1,29],[-42,7],[-2,20],[37,80],[5,23],[-14,4],[-23,-8],[-153,25],[-189,103],[-46,6],[-29,92],[-46,-12],[-66,-54],[-50,41],[-53,27],[-15,42],[1,63],[-5,73],[-14,86],[-11,122],[10,95],[43,71],[16,45],[20,115],[4,135],[-11,46],[3,30],[34,0],[-7,27],[-15,14],[-17,30],[14,16],[41,1],[3,10],[5,14],[-32,78],[-3,38],[-44,113],[-50,107],[-75,78],[27,128],[30,115],[-6,56],[-12,68],[-92,74],[-13,105],[-23,112],[9,69],[15,53],[30,53],[152,165],[10,87],[103,6],[-48,78],[-11,43],[-3,51],[149,35],[56,-29],[131,35],[116,69],[-2,37],[-18,33],[-25,63],[18,17],[42,-13],[-19,32],[3,33],[46,-14],[76,93],[3,70],[130,37],[150,144],[70,45],[67,32],[143,144],[61,7],[32,97],[121,129],[37,16],[57,117],[149,134],[94,171],[53,61],[16,65],[58,6],[52,47],[114,33],[112,-9],[46,-22],[43,7],[-4,58],[-31,36],[25,35],[60,26],[-7,58],[-12,35],[-50,46],[25,104],[6,114],[23,131],[-62,70],[-234,119],[-44,-4],[-52,14],[-54,90],[24,78],[3,28],[-22,0],[-34,-38],[-75,-43],[-97,33],[-48,-8]],[[51853,94005],[31,34],[124,2],[103,-31],[23,13],[13,27],[-44,110],[8,29],[46,34],[71,28],[113,4],[78,-4],[16,-3],[115,-121],[99,-118],[53,-50],[128,-143],[49,-82],[16,-59],[52,0],[181,-26],[152,-21],[42,-33],[105,6],[81,30],[142,38],[38,46],[48,49],[83,-7],[92,-39],[103,-52],[93,-23],[123,-38],[58,-48],[81,-14],[85,49],[50,130],[45,59],[62,42],[73,19],[55,7],[41,33],[59,74],[12,89],[-11,162],[10,53],[49,87],[65,231],[29,67],[35,40],[49,24],[89,70],[126,139],[34,11],[91,7],[113,-5],[102,-24],[11,2],[46,13],[82,43],[142,85],[91,24],[83,-4],[92,-93],[129,-105],[83,-50],[227,-95],[199,-63],[111,-206],[-55,-82],[-27,-28],[-97,-82],[-105,-116],[-8,-60],[35,-61],[43,-40]],[[53015,83174],[41,-25],[39,8],[38,18],[84,-17],[192,-127],[17,-34],[-114,-15],[-26,-39],[-27,-27],[-33,-9],[-55,-55],[-74,-52],[-16,-32],[-135,6],[-74,-20],[-60,-58],[-24,-114],[-44,-88],[-44,-32],[-46,-5],[-11,33],[4,33],[98,125],[20,41],[-49,18],[-40,43],[-89,51],[-16,41],[21,3],[19,12],[24,34],[11,39],[-71,115],[36,18],[45,-4],[47,-33],[51,39],[21,6],[36,-14],[36,75],[85,25],[42,24],[41,-7]],[[53438,83101],[-48,-11],[-115,74],[27,50],[32,20],[98,-31],[14,-76],[-8,-26]],[[53194,83388],[-48,-51],[-29,20],[-15,25],[-61,-116],[-70,-20],[-40,23],[3,43],[-39,114],[-60,34],[-85,3],[-62,47],[237,32],[24,54],[49,57],[36,6],[31,-13],[5,-45],[8,-17],[108,-25],[41,-74],[16,-89],[-49,-8]],[[56159,84072],[31,-33],[39,-52],[10,-29],[-13,-18],[-39,-15],[-9,-16],[-17,-27],[-46,-5],[-23,-20],[-28,-88],[-54,-147],[-79,-111],[-63,-61],[-29,-47],[-17,-56],[-4,-56],[60,-310],[0,-56],[-15,-57],[-10,-59],[8,-50],[40,-87],[43,-129],[17,-83],[28,-30],[28,-22],[5,-14],[-1,-15],[-14,-16],[-122,-43],[-16,-37],[-14,-41],[-53,-60],[-17,-56],[-10,-65],[-1,-23]],[[55774,82038],[-15,-3],[-81,13],[-90,42],[-39,32],[-39,0],[-46,-21],[-168,-60],[-41,14],[-95,59]],[[55160,82114],[-49,64],[-107,127],[-9,31],[-14,24],[-115,32],[-43,47],[-35,6]],[[54788,82445],[-52,24],[-134,100],[-34,10],[-8,-17],[2,-24]],[[54562,82538],[-8,-14],[-17,1],[-32,37],[-37,32],[-116,-61],[-42,-16],[-37,-4],[-185,-80],[-56,-44],[-23,5],[5,41],[77,204],[14,161],[28,23],[8,22],[-12,52],[-80,33],[-32,-5],[-29,-56],[-30,-40],[-70,-24],[-61,42],[-142,57],[-36,75],[-8,75],[-75,73],[-31,86],[12,60],[68,40],[20,34],[-86,-6],[-17,9],[-4,31],[-38,105],[33,41],[15,40],[-27,35],[7,39],[21,39],[-13,92],[85,48],[83,34],[175,18],[-17,83],[71,4],[119,101],[119,-18],[171,69],[330,-1],[45,40],[-8,40],[1,43],[62,-12],[104,7],[389,-84],[95,0],[132,-85],[72,-22],[210,0],[325,-38],[63,58],[7,15]],[[29414,51136],[-56,-169],[-71,63],[-17,21],[-14,35],[68,7],[69,85],[21,-42]],[[30864,51487],[-4,-79],[14,-81],[-4,-123],[-27,-67],[-72,-66],[-56,12],[-32,27],[-56,107],[-2,111],[52,73],[22,93],[134,-17],[12,18],[10,5],[9,-13]],[[29824,51357],[-24,-9],[-28,26],[-30,83],[21,61],[18,27],[26,-4],[49,-45],[15,-46],[2,-29],[-49,-64]],[[30320,51729],[-49,-237],[-46,-93],[-27,-31],[-67,-26],[-80,147],[-41,150],[-23,48],[36,38],[53,-6],[114,32],[23,12],[116,152],[113,18],[3,-49],[-125,-155]],[[31565,51510],[-79,-118],[-79,28],[-14,19],[80,30],[72,90],[46,198],[72,219],[15,93],[28,36],[40,4],[17,-7],[17,-49],[0,-110],[-20,-183],[-38,-162],[-157,-88]],[[29446,51847],[-15,-8],[-13,82],[-69,202],[42,89],[76,3],[31,-63],[10,-64],[-14,-38],[4,-75],[-8,-49],[-44,-79]],[[31845,52282],[-39,-69],[-45,25],[21,150],[21,44],[81,66],[67,26],[19,70],[22,27],[24,-42],[-18,-48],[-14,-150],[-45,-48],[-94,-51]],[[40766,62431],[-14,-14],[-38,13],[-58,0],[-2,42],[9,29],[11,30],[35,-58],[56,-11],[1,-31]],[[40679,62688],[-21,-64],[-89,22],[-19,26],[19,72],[25,9],[2,51],[27,52],[125,42],[29,-35],[6,-51],[-75,-110],[-29,-14]],[[41670,63594],[55,-35],[59,31],[32,-10],[30,-16],[8,-66],[-27,-74],[-39,-74],[-32,-82],[-28,-94],[-53,-55],[-48,-34],[-100,70],[-59,17],[-17,27],[-14,104],[-27,33],[-38,14],[-34,-26],[-45,-55],[-23,55],[-38,10],[-14,33],[1,43],[241,251],[69,56],[148,64],[23,-10],[-19,-38],[1,-17],[19,-19],[-5,-29],[-19,-26],[-7,-48]],[[42339,63647],[-11,-12],[-179,121],[-59,13],[-14,18],[1,63],[5,27],[120,13],[97,-44],[52,-120],[4,-21],[-16,-58]],[[40669,66511],[-8,-49],[4,-19],[5,-34],[-1,-38],[12,-25],[22,-3],[28,8],[30,15],[54,42],[16,7]],[[41708,66340],[17,-66],[28,-25],[11,-57],[-52,-30],[-30,-4],[-9,-98],[14,-27],[29,-26],[8,-30],[5,-143],[-59,-87],[-82,-97],[-405,-313],[-96,-152],[-37,-34],[-300,-96],[-210,-102],[-101,-37],[-126,-177],[-60,-71],[48,-20],[55,-85],[-18,-38],[-81,-58],[-35,-17],[-20,9],[-18,-8],[-135,-307],[-120,-221],[-67,-97],[-69,-143],[-147,-370],[-1,-107],[73,-369],[41,-97],[58,-81],[110,-69],[27,-68],[-38,-65],[-110,-116],[-191,-156],[-82,-123],[-17,-118],[-56,-54],[-21,-166],[-34,-110],[-7,-37],[-36,-84],[-5,-61],[60,-83],[-30,-37],[-29,-16],[-68,-9],[-227,-11],[-182,-181],[-91,-160],[-83,-299],[-100,-176],[-45,-32],[-68,77],[-86,12],[-83,-26],[-44,-61],[-68,-34],[-67,29],[-144,16],[-64,-2],[-100,-50],[-86,33],[-145,17],[-314,-40],[-40,-18],[-39,-74],[-100,-128],[-153,-4],[-137,-82],[-35,-52],[-57,-143],[-19,-105],[-12,-1],[-15,26],[-21,-9],[-11,-80],[-52,-36],[-43,-13],[-106,65],[-89,97],[-47,7],[-75,151],[-33,96],[-23,104],[5,40],[-7,33],[-67,42],[-16,96],[49,124],[40,52],[25,16],[-61,-6],[-44,-80],[-56,128],[-228,249],[14,58],[-2,30],[-39,-66],[-26,-17],[-117,11],[-134,-31]],[[35522,60879],[-36,259],[-17,99],[-4,64],[35,149],[38,60],[50,125],[62,104],[66,25],[29,15],[24,80],[14,69],[-10,6],[-77,-13],[-138,287],[5,46],[17,68],[11,86],[3,67],[36,58],[55,59],[47,83],[23,82],[5,74],[-27,52],[-75,30],[-78,211],[-17,132],[-16,13],[-48,61],[-46,112],[-7,18],[48,20],[196,1],[41,25],[6,8],[36,88],[37,145],[9,88],[-12,36],[-65,89],[-3,27],[11,42],[38,45],[53,51],[28,44],[-7,34],[-15,36],[-2,34],[9,41],[3,142],[7,36],[-10,128],[-13,105],[-41,136],[8,30],[19,26],[62,47],[50,111],[72,93],[95,74],[66,83],[27,63],[18,17],[-5,29],[-13,43],[-37,42],[-49,25],[-54,-1],[-34,8],[-10,33],[4,89],[-3,88],[-10,40],[-25,31],[-50,-9],[-43,25],[-32,6],[-19,-19],[-96,5],[-40,14],[-28,18],[-18,-10],[-10,-17],[-2,-27],[-7,-35],[-34,-32],[-79,-32],[-63,2],[-59,23],[-18,16],[-28,16],[-119,-19],[-14,14],[-41,-33],[-60,-40],[-34,-2],[-12,8],[-5,18],[-25,61],[6,33],[49,94],[-5,23],[-20,31],[-18,44],[-5,23],[-31,3],[-33,-23],[-126,-47],[-30,-18],[-54,-46],[-55,-70]],[[34723,65830],[-44,-14],[-15,20],[-5,165],[67,109],[47,67],[-22,13],[-51,-2],[4,51],[23,25],[23,56],[-27,24],[-21,36],[2,96],[6,39],[-7,42],[-103,-57],[-26,9],[-1,71],[57,109],[5,33],[-66,16],[-50,53],[-31,48],[-32,68],[0,62],[33,143],[48,42],[42,26],[88,99],[121,-18],[75,21],[67,51],[39,11],[62,44],[-2,60],[-22,44],[19,42],[70,51],[77,68],[88,13],[91,60],[60,-38],[53,13],[61,-46],[80,-105],[117,-43],[93,33],[165,7],[83,-14],[146,26],[84,-9],[136,52],[106,-65],[204,-30],[122,-54],[340,-89],[122,-1],[173,50],[74,38],[67,-23],[99,43],[47,-8],[61,-62],[217,-83],[57,71],[43,15],[156,-44],[157,-88],[82,-6],[120,24],[95,58],[20,7]],[[47122,67960],[7,-38],[-17,-53],[-35,-8],[-17,42],[26,50],[36,7]],[[46457,79296],[103,-64],[70,4],[47,-27],[11,-42],[4,-91],[-49,-27],[-55,9],[-75,-35],[-246,150],[3,125],[10,49],[117,12],[60,-63]],[[45946,79250],[-39,-10],[-45,22],[-73,86],[-9,22],[38,-14],[48,-45],[39,-9],[53,-38],[-12,-14]],[[47149,79373],[-22,-15],[-90,11],[-101,-72],[-38,23],[15,46],[10,17],[34,19],[23,29],[8,45],[21,-24],[63,-11],[30,-14],[26,-21],[21,-33]],[[45699,79291],[-60,-15],[-31,26],[-57,9],[-21,160],[6,10],[29,-11],[98,-75],[34,-82],[2,-22]],[[46091,79150],[-26,-6],[-35,84],[-4,26],[41,54],[27,61],[69,94],[39,110],[16,-2],[-18,-97],[-91,-273],[-18,-51]],[[48628,79432],[-22,-18],[-96,29],[-117,72],[17,142],[30,61],[214,-159],[3,-59],[-29,-68]],[[46039,80043],[25,-54],[30,-116],[47,-129],[-20,-54],[14,-70],[-14,-72],[-94,-84],[-105,-4],[-110,40],[-155,79],[-12,44],[-22,24],[-42,133],[1,165],[78,21],[170,78],[40,-12],[41,-40],[47,-3],[68,57],[13,-3]],[[47217,80029],[-55,-44],[-12,2],[-18,61],[29,37],[17,31],[12,-1],[17,-33],[10,-53]],[[46017,80223],[-10,-18],[-36,19],[-4,67],[14,61],[-17,54],[18,34],[52,-80],[15,-38],[-20,-46],[-12,-53]],[[47160,80225],[2,-104],[-15,-30],[-23,-20],[-58,-21],[-50,-30],[-45,-52],[-17,-74],[35,-54],[64,-30],[17,-103],[-53,-51],[-136,-51],[-14,-123],[4,-97],[-2,-71],[-11,-97],[-109,-44],[-71,148],[-1,59],[-21,70],[-4,59],[-25,94],[-104,26],[-40,3],[-56,-17],[-14,7],[-67,129],[11,142],[-36,72],[-5,33],[1,36],[-30,29],[-36,16],[-17,80],[41,20],[102,-10],[30,6],[27,16],[82,132],[-2,29],[9,38],[89,14],[40,-51],[-8,-81],[5,-105],[54,-28],[21,-5],[22,78],[16,37],[21,21],[8,71],[-13,43],[-27,32],[101,87],[104,69],[61,4],[61,-17],[57,-23],[31,-21],[17,-32],[-38,-77],[-10,-42],[25,-139]],[[46277,81751],[-24,-24],[-80,34],[35,48],[88,23],[52,-8],[-57,-47],[-14,-26]],[[45512,79228],[-9,0],[-37,9],[-26,22],[-69,-16],[-91,-35],[-51,1],[-40,38],[-165,55],[-26,4],[-109,2],[0,1]],[[44889,79309],[-5,85],[-14,62],[-38,93],[56,22],[-10,180],[-21,93],[-158,96],[-124,93],[29,313],[12,84],[-47,164],[5,189],[20,297],[39,11],[29,-1],[112,-53],[46,-6],[32,-47],[38,-20],[27,51],[10,86],[89,112],[62,41],[42,20],[43,-45],[32,-51],[8,111],[26,212],[-84,33],[-68,-29],[-68,-134],[-61,-168],[-98,-16],[-79,-47],[-71,49],[-45,44],[-2,64],[11,38],[83,137],[112,132],[112,-1],[82,42],[49,5],[153,-9],[78,29],[71,60],[152,256],[86,107],[172,37],[160,123],[45,2],[-75,-92],[-12,-35],[-9,-55],[53,-118],[-11,-72],[4,-141],[-51,-74],[-57,-157],[-25,-23],[-5,-183],[5,-44],[-8,-167],[59,-68],[62,-36],[207,1],[22,-30],[25,-51],[-18,-88],[-22,-66],[-60,-56],[-78,-41],[-47,-2],[-66,79],[-31,-26],[-32,-40],[-53,-216],[-26,-145],[-14,-12],[-30,21],[-52,2],[-67,-35],[34,-31],[36,-53],[-14,-27],[-58,-29],[-52,-59],[-22,-45],[-65,-52],[-41,-67],[20,-83],[9,-73],[18,-80],[-16,-64],[-81,-92],[-30,-80],[69,1],[43,-18],[25,-24],[26,-33],[-16,-42],[20,-106]],[[48110,78285],[9,-50],[-25,4],[-72,-12],[-71,16],[-14,63],[12,60],[-29,41],[-27,24],[-3,35],[4,36],[123,-97],[100,-87],[-7,-33]],[[46411,78804],[-89,-2],[-35,41],[-34,11],[18,51],[25,19],[86,-34],[27,-65],[2,-21]],[[47825,78767],[14,-70],[-15,-35],[-66,59],[-66,-1],[-39,-91],[-29,-4],[-102,83],[-16,40],[-3,34],[14,116],[-3,37],[32,40],[5,58],[57,61],[50,2],[16,-51],[24,-36],[84,-40],[13,-18],[7,-25],[-39,-49],[-13,-25],[12,-41],[63,-44]],[[44841,79110],[-23,-25],[-55,3],[-32,24],[11,25],[29,20],[24,3],[37,-12],[9,-38]],[[45512,79228],[3,-20],[86,-27],[36,-44],[39,-67],[4,-96],[-51,-70],[-42,-44],[160,17],[16,-40],[24,-43],[87,31],[216,-127],[131,62],[33,3],[30,-102],[-33,-103],[-115,-111],[25,-68],[37,-15],[109,15],[172,-67],[36,21],[139,154],[56,33],[184,24],[33,60],[74,60],[48,66],[115,125],[119,-22],[69,-24],[76,-12],[69,-134],[176,-147],[160,13],[58,-140],[25,-172],[49,-54],[44,-36],[131,-37],[5,-2],[4,-23],[8,-86],[11,-71],[68,-284],[-2,-69],[0,-19],[-25,-97],[-44,-82],[-58,-46],[-32,-51],[-6,-57],[73,-100],[152,-142],[61,-122],[-29,-101],[-9,-74],[12,-48],[24,-38],[37,-28],[15,-45],[-7,-59],[7,-42],[28,-29],[-3,-12],[-14,-41],[-18,-76],[-11,-55],[-42,-76],[13,-64],[33,-75],[26,-38],[8,-36],[-17,-86],[8,-21],[106,-63],[17,-30],[10,-60],[37,-129],[-30,-164]],[[48556,75349],[-27,-90],[-60,-143],[-3,-13],[-7,-17],[-18,-25],[-25,-4],[-38,19],[-26,24],[6,61],[-17,4],[-21,38],[-8,40],[-22,17],[-82,17],[-28,12],[-21,-9],[-16,-28],[10,-26],[16,-26],[45,-40],[-5,-16],[-97,-39],[-62,-40],[-57,-22],[-58,-41],[-115,-47],[-84,-12],[-18,-13],[-31,-79],[-21,-16],[-21,9],[-15,12],[-20,-10],[-20,-26],[-21,-11],[-19,1],[-33,-69]],[[47517,74741],[-96,-21]],[[47421,74720],[-11,-36],[-18,-41],[-14,-10],[-43,16],[-60,9],[-35,-23],[-41,-12],[-50,-4],[-56,-45],[-55,-80],[-31,-70]],[[47007,74424],[-17,-25],[-26,66],[-33,45],[-24,23],[-20,0],[-6,-9],[0,-35],[22,-57],[28,-39],[4,-29],[15,-53],[40,-57],[63,-46],[42,-44],[32,-62],[0,-19]],[[47127,74083],[-8,-26],[-15,-24],[-13,-31],[-35,-63],[11,-27],[28,-35],[25,-42],[33,-67],[44,-118],[29,-49],[39,-50],[38,-38],[60,1],[62,-73],[68,-106],[51,-49],[36,-15],[29,-38],[26,-54],[10,-32],[23,-23],[63,4],[80,-86],[49,-63],[26,-51],[-7,-20],[-3,-64],[1,-67],[-8,-36],[-36,-47],[-18,-10],[-10,-10],[-110,61],[-9,-10],[-7,-8],[-29,-177],[-20,-34],[-30,-31]],[[47600,72475],[-63,-31]],[[47537,72444],[-44,-12],[-34,-16],[-107,-74],[-49,-44],[-31,-56],[0,-33],[52,-94],[60,-98],[1,-87],[-27,-64],[-6,-25],[18,-9],[33,-4],[28,-11],[12,-45],[-4,-79],[-9,-74],[-10,-31],[-27,-3],[-52,32],[-41,37],[-15,23],[-1,27],[9,18],[-15,33],[-50,32],[-53,-14],[-39,-21],[-26,1],[-27,30],[-43,23],[-55,15],[-34,16],[-7,-9],[4,-65],[-11,-28],[-273,-38],[-83,-35],[-61,-45],[-45,-20],[-11,-28],[-44,-37],[-50,-11],[-12,12],[-33,-17],[-54,-17],[-36,6],[-17,29],[-34,46],[-13,31],[1,20],[-76,5],[-49,24],[-102,-6],[-25,10],[-6,-11],[-15,-129],[-20,-53],[-33,-55],[-42,-30],[-34,-6],[2,40],[8,48],[-24,12],[-36,5],[-18,15],[5,36],[-9,21],[-15,26],[-36,33],[-77,49],[-53,24],[-19,-26],[-38,-26],[-59,9],[-15,-10],[-101,77],[-98,75],[-32,0],[-143,-15],[-5,7],[-25,42],[-22,14],[-13,-7],[-9,-13],[-15,2],[-65,69],[-26,10]],[[44832,71897],[-37,-9],[-43,-37],[-19,-45],[6,-26],[22,-12],[59,8],[9,-8],[2,-14],[-7,-15],[-47,-11],[-14,-18],[-14,-4],[-9,-2],[-51,18],[-75,0],[-61,-32],[-97,-13],[-134,6],[-48,24]],[[43534,73641],[2,62],[17,91],[17,47],[22,38],[23,27],[6,49],[-4,45]],[[43617,74000],[-27,8],[-68,33],[-40,36],[-30,45],[-39,61],[-16,63],[-1,62],[5,28]],[[43401,74336],[3,19],[31,97],[110,87],[-12,87],[-1,54],[-27,35],[-54,14],[-14,24],[-6,24],[39,53],[-47,43],[-21,43],[-66,55],[-7,19]],[[43329,74990],[32,161],[-24,47],[-30,24],[-35,11],[-16,23],[-6,25],[6,16],[41,-5],[13,17],[99,94],[4,18],[-14,10],[-18,6],[-5,20],[1,26],[53,136],[15,58],[4,41],[-4,40],[-30,64],[-29,51],[-1,40],[-21,21],[-61,109],[0,41],[34,33],[48,21],[16,17],[29,11],[76,-32],[34,-27],[10,6],[31,29],[53,-4],[131,59],[20,28],[14,31],[1,13],[-50,58],[-2,22],[7,24],[14,19],[30,13],[32,26],[71,72],[25,63],[8,68],[1,51],[-19,40],[-20,26],[-27,-4],[-52,2],[-49,23],[-27,37],[-6,32],[12,20],[4,25],[-8,25],[3,21],[22,17],[154,-1],[12,19],[10,97],[39,148],[36,82],[6,35],[0,195],[4,99]],[[44030,77623],[-26,46],[-57,51],[12,106],[19,83],[58,101],[46,28],[200,16],[222,-6],[92,-154],[-35,-78],[54,-37],[26,13],[20,69],[13,76],[19,23],[68,-57],[24,-39],[2,-125],[25,169],[-19,119],[13,115],[28,59],[25,38],[162,-41],[180,21],[67,-44],[154,-221],[51,-36],[65,-12],[-89,47],[-186,270],[-56,33],[-86,10],[-53,26],[-34,41],[-9,36],[1,271],[-32,41],[-41,14],[-26,-19],[-53,0],[-11,61],[13,46],[106,31],[71,41],[3,74],[-45,58],[-53,106],[-62,100],[-7,116]],[[44677,79187],[-13,-20],[6,147],[64,156],[27,-3],[-27,-43],[-8,-29],[-12,-59],[6,-31],[145,-9],[-17,-27],[-147,-18],[-24,-64]],[[48466,75103],[50,3],[51,26],[4,42],[-3,79],[5,12],[77,-23],[77,-35],[11,-79],[21,-39],[24,-35],[24,-16],[40,-3],[105,-46],[50,-10],[52,-32],[44,-33],[31,-7],[15,-36],[20,-25],[34,19],[126,27],[45,-36],[31,-38],[4,-12],[-16,-33],[-8,-26],[-13,-17],[-43,-18],[-24,-29],[-18,-32],[12,-31],[35,-23],[25,-6],[10,-22],[80,-101],[63,-131],[25,-21],[23,-5],[27,20],[31,42],[37,31],[31,16],[55,36],[2,24],[-46,89],[-26,72],[6,13],[59,-11],[100,-40],[153,-128],[27,0],[54,10],[59,21],[27,23],[11,-9],[9,-70],[-16,-39],[-69,-37],[4,-19],[17,-24],[32,-16],[38,-46],[26,-52],[23,-24],[26,-12],[63,28],[18,22],[8,16],[13,-4],[22,-25],[7,-16],[61,-29],[36,-36],[23,-16],[25,16],[98,-29],[26,-23],[9,-40],[-5,-24],[15,-63],[124,-150],[13,-76],[2,-31]],[[49715,72753],[-15,23],[-26,86],[-29,11],[-40,8],[-30,13],[-65,49],[-34,15],[-38,4],[-37,-29],[-28,-34],[-86,0],[-94,16],[-135,114],[-35,1],[-38,-5],[-59,27],[-114,74],[-54,17],[-34,-10],[-31,-17],[-22,-2],[-13,24],[-42,30],[-43,3],[-12,-18],[-15,-162],[-14,-59],[-59,3],[-21,-28],[-46,-78],[-9,-76],[-80,15],[-38,13],[-34,-10],[-37,-41],[-103,2],[-82,25],[-35,93],[-38,37],[-47,33],[-17,8]],[[47886,72928],[-26,51],[-49,63],[-80,86],[-63,-4],[-23,23],[-10,32],[-26,54],[-29,38],[-36,15],[-51,49],[-68,106],[-62,73],[-60,-1],[-38,38],[-39,50],[-29,49],[-44,118],[-33,67],[-25,42],[-28,35],[-11,27],[35,63],[13,31],[15,24],[8,26]],[[47127,74083],[0,19],[-32,62],[-42,44],[-63,46],[-40,57],[-15,53],[-4,29],[-28,39],[-22,57],[0,35],[6,9],[20,0],[24,-23],[33,-45],[26,-66],[17,25]],[[47007,74424],[31,70],[55,80],[56,45],[50,4],[41,12],[35,23],[60,-9],[43,-16],[14,10],[18,41],[11,36]],[[47517,74741],[33,69],[19,-1],[21,11],[20,26],[20,10],[15,-12],[21,-9],[21,16],[31,79],[18,13],[84,12],[115,47],[58,41],[57,22],[62,40],[97,39],[5,16],[-45,40],[-16,26],[-10,26],[16,28],[21,9],[28,-12],[82,-17],[22,-17],[8,-40],[21,-38],[17,-4],[-6,-61],[26,-24],[38,-19],[25,4],[18,25],[7,17]],[[67795,69519],[-9,-19],[-28,95],[-2,59],[18,30],[23,-97],[-2,-68]],[[53102,78740],[-20,-7],[-328,10],[-312,18],[-287,16],[-278,15],[-266,15],[-165,13],[-163,14],[-23,13],[89,89],[59,92],[50,121],[5,84],[12,94],[78,37],[168,-6],[72,46],[93,112],[97,134],[31,57]],[[52048,79699],[-57,-99],[-154,-209],[48,-28],[56,-9],[66,-39],[63,-7],[113,34],[20,179],[7,163]],[[60705,89996],[19,-41],[6,-67],[-18,-43],[9,-36],[-37,-26],[-58,84],[-34,1],[-37,36],[-17,60],[33,17],[14,-11],[70,42],[50,-16]],[[56275,69479],[61,-107],[78,-57],[181,-61],[16,7]],[[56611,69261],[1,12],[-12,15],[-2,21],[9,24],[25,1],[40,-22],[78,32],[114,86],[105,17],[96,-51],[49,-59],[31,-56],[-9,-69],[-7,-43],[-25,-179],[-17,-67],[-28,-75],[-297,-89],[19,43],[-7,75],[-12,57],[28,51],[-67,19],[-29,-29],[-23,-49],[20,-113],[-32,-62],[-13,-35],[-1,-83],[-20,-35],[-3,-39],[47,10],[-21,-72],[-89,-137],[-32,-81],[8,-325],[-39,-194],[-4,-57]],[[56492,67703],[-94,-2],[-28,5],[-89,29],[-101,51],[-58,100],[-38,72],[-85,-32],[-16,8],[-23,35],[-64,23],[-79,0],[-178,131],[-20,22],[-139,-22],[-209,-65],[-159,-79],[-165,-142],[-67,-108],[-77,-58],[-110,-42],[-197,16],[-204,54],[-220,58],[-119,-32],[-161,24],[-242,70],[-181,21],[-178,-41],[-30,31],[-7,36],[7,51],[25,41],[44,31],[22,31],[3,32],[-49,51],[-99,71],[-41,44]],[[53066,68218],[-10,11]],[[53056,68229],[-2,40],[-21,31],[-39,23],[-29,41],[-21,60],[4,56],[30,53],[39,23],[47,-7],[19,15],[-8,37],[-45,47],[-85,57],[-85,-31],[-87,-120],[-63,-19],[-39,81],[-68,48],[-99,15],[-61,31],[-22,47],[-43,36],[-95,38],[-2,36],[16,9],[33,3],[46,8],[7,21],[0,19],[-35,24],[-36,16],[-19,16],[-12,18],[-3,19],[11,13],[14,1],[15,11],[8,44],[19,36],[14,13],[-1,27],[-14,25]],[[52324,69211],[-29,13],[-90,38],[-46,52],[-28,2],[-44,29],[-48,46],[-42,64],[-44,42],[-12,18],[-1,16],[8,18],[0,20],[-12,63],[8,67],[-2,63],[0,29],[-9,8],[-8,-9],[-11,-12],[-11,-3],[-33,46],[-41,94],[-29,31],[-55,43],[-46,36],[-33,78],[-35,61]],[[53166,72076],[21,17],[83,44],[21,44],[28,40],[37,-3],[120,-98],[128,6]],[[53604,72126],[24,-4],[7,-2],[16,-8],[171,-48],[26,5],[8,4],[68,-40],[61,5],[58,28],[60,9],[55,-16],[42,-57],[109,-120],[32,-45],[50,6],[55,23],[56,80],[172,92],[131,22],[128,37],[148,26],[43,74],[23,51],[17,94],[80,27]],[[55244,72369],[76,20],[27,12]],[[55347,72401],[55,3],[43,-8],[66,-46],[46,-58],[19,-47],[40,-65],[41,-92],[46,-122],[10,-62],[18,-67],[34,-81],[65,-90],[10,-17],[29,-64],[57,-140],[48,-57],[42,-61],[20,-61],[30,-56],[70,-75],[57,-67],[46,-194],[32,-89],[20,-68],[-10,-138],[13,-59],[-26,-108],[-47,-217],[-12,-173],[9,-93],[1,-60],[11,-38],[12,-79],[2,-68],[-16,-20],[-24,-16],[-9,-14],[22,-31],[29,-58],[29,-66]],[[29821,56397],[79,-55],[73,26],[90,-70],[47,-16],[-41,-51],[-42,-63],[-106,15],[-89,61],[-32,47],[-9,42],[30,64]],[[25255,60651],[-3,-19],[-33,7],[-42,-5],[-22,55],[20,23],[47,5],[23,-24],[10,-42]],[[24892,61567],[37,-7],[186,15],[49,-11],[-5,-77],[-35,-30],[-109,-21],[-172,50],[-58,65],[-9,49],[2,22],[36,18],[78,-73]],[[23437,62203],[48,-42],[-73,-8],[-24,-21],[-59,30],[-71,-5],[-45,56],[-10,58],[22,36],[63,1],[149,-105]],[[23149,62278],[-60,-3],[-57,80],[84,41],[25,-25],[18,-29],[11,-37],[-21,-27]],[[23652,62310],[-28,-13],[-155,81],[-56,36],[-71,92],[202,-112],[108,-84]],[[24061,62401],[-11,-9],[-121,28],[-35,38],[-14,71],[21,24],[53,14],[77,-13],[50,-51],[0,-65],[-20,-37]],[[21695,63195],[-26,-50],[-45,18],[-14,19],[13,107],[35,25],[36,-43],[1,-76]],[[35522,60879],[-51,-12],[-199,-169],[-61,0],[-115,75],[-203,24],[-66,22],[-82,-49],[-64,1],[-50,-62],[-37,17],[42,139],[65,275],[-2,168],[15,146],[-18,145],[-32,90],[44,234],[-5,121],[-41,153],[124,-24],[-38,61],[-38,37],[-36,-8],[-31,2],[-106,-59],[-53,-18],[-15,10],[6,95],[-28,122],[42,32],[50,10],[42,52],[25,58],[-13,104],[36,99],[85,83],[-44,-12],[-50,-52],[-80,-189],[-26,-95],[-68,-32],[-61,-15],[-31,10],[-37,24],[-3,71],[2,56],[26,112],[10,158],[35,141],[-2,38],[-10,56],[32,55],[40,36],[60,121],[84,289],[97,307],[-8,38],[-21,28],[8,83],[59,361],[23,47],[28,105],[6,171],[11,117],[-3,59],[-8,71],[-38,136],[-39,286],[-3,96],[33,48],[-53,7],[-24,62],[5,70],[59,113]],[[53520,78307],[67,-355],[111,-341],[41,-165],[16,-88],[13,-128],[4,-89],[-1,-50],[-8,-70],[-33,-41],[-212,-117],[-40,-37],[-63,-91],[-58,-94],[-13,-32],[-4,-21],[13,-31],[76,-51],[76,-40],[25,-30],[56,-39],[21,-35],[11,-30],[-1,-70],[-25,-97],[11,-74],[-26,-48],[-21,-55],[-4,-95],[39,-105]],[[53591,75788],[31,-71],[12,-57],[-13,-44],[4,-44]],[[53625,75572],[28,-47],[88,-144],[44,-139],[27,-54],[65,-71],[5,-28],[-25,-27],[-21,-3],[-17,-7]],[[53819,75052],[-11,-25],[17,-27],[23,-38],[28,-110],[-3,-90],[-22,-23],[-27,-54],[-19,-49],[-152,-34],[-37,-52],[-83,-101],[-57,-58],[-84,-105],[-133,-181],[-49,-76],[-36,-62],[-107,-167],[-33,-69],[6,-58],[35,-135],[7,-61],[-6,-56],[-11,-50],[2,-23],[31,-36],[51,-57]],[[53149,73255],[3,-20],[-7,-24],[-18,-19],[-63,20],[-71,38],[-24,-4]],[[48466,75103],[3,13],[60,143],[27,90]],[[48556,75349],[30,164],[-37,129],[-10,60],[-17,30],[-106,63],[-8,21],[17,86],[-8,36],[-26,38],[-33,75],[-13,64],[42,76],[11,55],[18,76],[14,41],[3,12],[-28,29],[-7,42],[7,59],[-15,45],[-37,28],[-24,38],[-12,48],[9,74],[29,101],[-61,122],[-152,142],[-73,100],[6,57],[32,51],[58,46],[44,82],[25,97],[0,19],[2,69],[-68,284],[-11,71],[-8,86],[-4,23],[133,-60],[56,-34],[-7,38],[-11,33],[7,48],[-3,72],[-121,37],[-80,13],[-9,50],[7,33],[22,-20],[79,-7],[193,97],[334,127],[356,118],[83,13],[84,25],[31,45],[31,29],[48,78],[108,122],[189,44],[71,58],[149,81],[338,90],[142,20],[138,3],[124,-72],[130,-88],[24,-53],[-71,33],[-103,79],[-38,4],[88,-242],[48,-85],[97,-64],[82,-21],[251,39],[89,50],[26,26],[23,-13],[163,-14],[165,-13],[266,-15],[278,-15],[287,-16],[312,-18],[328,-10],[20,7],[33,41],[41,-6],[49,-25],[22,-19],[10,-21],[6,-25],[26,-4],[48,-19],[66,-43],[51,-41],[48,-60],[17,-67],[0,-76],[-3,-49],[4,-19]],[[45386,71636],[18,-14],[42,-46],[-10,-78],[-48,-126]],[[45419,71150],[23,0],[73,-21],[58,-31],[12,-32],[7,-40],[70,-55],[79,-35],[27,11],[99,128],[38,-21],[23,-68],[-1,-36]],[[45927,70950],[-27,-135],[-5,-73],[24,-48],[2,-37],[-7,-34],[-39,-3],[-53,18],[-45,59],[-33,-7],[-30,-15],[-15,-56],[-13,-66],[4,-37],[21,-28],[16,-60],[12,-78],[9,-36],[-10,-16],[-28,-10],[-23,10],[-40,93],[-19,36],[-32,6],[-56,-22],[-87,-53],[-34,1],[-30,10],[-28,44],[-23,86],[-8,53],[-16,-1],[-56,15],[-26,-21],[0,-87],[-5,-109],[-28,-70]],[[45199,70279],[-77,-122],[-28,-53],[-11,-38],[-3,-33],[12,-57],[16,-55],[-13,-31],[-41,-16],[-29,33],[-11,59],[-62,81],[28,67]],[[44975,70131],[-103,35],[-44,51],[-63,89],[-11,39],[2,125],[-3,30],[-9,15],[-30,-1],[-42,-44],[-39,-64],[-79,-73],[-8,-16],[26,-71],[-1,-28],[-64,-113],[-13,-38],[-82,-71],[-37,-27],[-114,53],[-32,6],[-50,-35],[-72,-33]],[[44107,69960],[-116,-34],[-43,25],[-20,23],[-10,34],[-29,61],[-33,36],[-23,39],[-31,43],[-19,35],[26,115],[-19,40],[-10,58],[5,39],[-10,9],[-105,23],[-87,-8],[-63,-38],[-50,-63],[-6,-14],[3,-12],[25,-58],[-43,-62],[-66,-47],[-46,-5],[-21,9],[-1,66],[39,24],[35,43],[11,61],[5,42],[-37,52],[4,32],[23,59],[13,53],[19,46],[72,75],[73,75],[11,80]],[[43583,70916],[5,97],[11,24],[98,58],[24,23],[13,33],[77,109],[77,108],[15,37],[13,21],[0,18],[-10,13],[-36,9],[-12,34],[39,62],[50,37],[48,1],[19,-17],[-1,-21],[21,-22],[36,-7],[45,8],[45,23],[28,54],[16,42],[70,47],[48,-24],[134,-6],[97,13],[61,32],[75,0],[51,-18],[9,2],[14,4],[14,18],[47,11],[7,15],[-2,14],[-9,8],[-59,-8],[-22,12],[-6,26],[19,45],[43,37],[37,9]],[[44832,71897],[26,-10],[65,-69],[15,-2],[9,13],[13,7],[22,-14],[25,-42],[5,-7],[143,15],[32,0],[98,-75],[101,-77]],[[42800,84928],[2,-124],[-54,10],[-24,47],[-7,30],[5,72],[-13,73],[16,37],[20,5],[34,-66],[21,-84]],[[42726,85736],[-51,-13],[-42,11],[15,99],[22,16],[31,6],[34,-53],[-9,-66]],[[44558,88078],[-57,0],[-68,16],[-42,34],[-7,30],[78,37],[79,22],[37,-41],[2,-68],[-22,-30]],[[44773,88421],[-67,-2],[-41,23],[96,46],[150,45],[15,28],[18,3],[26,-34],[3,-48],[-17,-23],[-183,-38]],[[46381,89668],[-31,-29],[-67,23],[-134,-18],[-54,28],[42,55],[121,58],[65,-3],[67,-71],[-9,-43]],[[46810,90459],[-38,-33],[-72,10],[-8,27],[21,55],[43,23],[57,-4],[18,-23],[-21,-55]],[[47126,90745],[-47,-3],[0,42],[27,39],[43,26],[54,7],[61,3],[19,-21],[-35,-29],[-122,-64]],[[47074,90892],[-54,-7],[9,46],[43,43],[17,30],[9,35],[38,27],[55,-34],[1,-58],[-27,-52],[-91,-30]],[[47395,92796],[-86,-55],[31,100],[47,102],[64,58],[32,-23],[-15,-49],[1,-48],[-14,-23],[-60,-62]],[[47920,93202],[35,-17],[90,5],[18,-7],[-12,-29],[-40,-33],[-82,-19],[-37,-50],[-27,-16],[-71,-1],[-42,-11],[-52,-44],[-41,33],[-12,-23],[-7,-41],[-23,-12],[-72,-15],[-17,95],[33,35],[25,41],[40,7],[35,-4],[64,89],[87,26],[56,3],[52,-12]],[[48697,93907],[76,-105],[35,-61],[-28,-115],[-74,-59],[-113,-10],[-80,5],[-50,28],[-7,31],[-29,10],[-76,-41],[-53,-5],[-68,31],[-18,50],[72,63],[33,49],[79,-4],[20,-16],[45,-9],[28,59],[-7,40],[20,29],[97,-21],[0,111],[37,8],[15,-5],[28,-23],[18,-40]],[[49020,93510],[7,-7],[79,100],[88,31],[6,35],[34,34],[-4,55],[17,44],[45,12],[28,15],[31,9],[56,-36],[32,-41],[39,-89],[-16,-87],[-106,-68],[-84,-31],[-84,-77],[-43,-64],[-37,-14],[-23,5],[-20,16],[-43,0],[-48,-55],[-142,-45],[-56,13],[-3,55],[-33,-5],[-54,-66],[-52,-22],[-35,-7],[-65,25],[-173,-112],[-163,-21],[-54,13],[0,69],[105,88],[86,61],[297,42],[185,182],[45,197],[44,71],[-21,40],[-50,7],[-3,62],[26,67],[97,93],[54,40],[88,111],[42,25],[48,0],[48,-29],[-9,-60],[-71,-108],[-105,-92],[13,-66],[42,-54],[10,-93],[2,-89],[-79,-121],[-18,-58]],[[50035,94586],[70,-59],[32,18],[62,7],[46,-21],[38,-38],[44,-2],[28,-49],[15,-64],[-33,-48],[-46,-22],[-12,-56],[17,-80],[-103,-27],[-120,-12],[-47,38],[-95,-70],[-95,-108],[-46,-13],[-3,35],[-68,23],[-87,2],[3,25],[15,18],[76,27],[15,54],[-14,98],[13,48],[3,33],[47,38],[162,-18],[20,37],[-12,23],[-84,40],[13,27],[60,24],[57,4],[18,41],[3,18],[8,9]],[[57291,94795],[-111,-31],[-12,25],[24,39],[29,80],[46,-3],[46,-31],[36,-36],[-58,-43]],[[51944,95099],[-31,-24],[-49,-10],[-25,15],[-37,10],[-41,-4],[-35,44],[4,37],[47,51],[95,28],[76,-12],[20,-14],[-24,-121]],[[51056,95075],[52,-56],[45,5],[14,21],[31,11],[64,-30],[-9,-51],[-88,-64],[-63,-92],[-80,-21],[-38,11],[-72,-53],[-57,-55],[-60,-69],[-4,-36],[-9,-28],[-218,-27],[-80,-18],[-84,23],[-39,46],[12,25],[84,10],[3,43],[21,26],[27,14],[20,55],[33,14],[62,-13],[42,39],[24,7],[29,-33],[13,45],[-13,41],[7,28],[80,72],[34,52],[50,34],[48,-6],[14,50],[-14,51],[5,33],[43,81],[46,3],[22,-71],[3,-117]],[[51355,95231],[29,-12],[30,8],[24,-11],[49,-55],[52,-21],[3,-28],[-48,-27],[-64,-8],[-68,10],[-20,34],[-20,57],[-57,56],[-9,49],[50,8],[49,-60]],[[53597,95577],[10,-48],[5,-40],[-55,-59],[-125,-76],[7,-20],[-43,-20],[-65,-14],[-34,14],[4,65],[-10,20],[-49,-26],[-52,33],[0,33],[14,29],[47,44],[79,31],[53,-12],[174,117],[18,-25],[22,-46]],[[53831,95596],[-111,-41],[-64,35],[-27,37],[-4,81],[15,50],[52,25],[33,-18],[10,-16],[60,-15],[71,-51],[-35,-87]],[[53495,95854],[-12,-32],[-19,-32],[-48,-34],[-138,-132],[-81,-22],[-26,-20],[-33,-13],[-100,18],[-30,-27],[-28,-18],[-73,-6],[-43,5],[-110,50],[-66,53],[-36,45],[102,0],[37,11],[69,-10],[41,47],[87,-6],[167,32],[62,-18],[140,109],[44,-3],[68,31],[26,-28]],[[57823,94781],[32,-137],[-1,-48],[-15,-46],[-21,-24],[-42,-10],[-101,4],[-137,54],[-89,51],[-27,2],[-12,-6],[21,-51],[-6,-39],[-13,-43],[-19,-39],[-25,-33],[-55,-42],[-94,-33],[-259,-65],[-20,-28],[-84,-181],[-22,-26],[-31,-23],[-89,-29]],[[46472,83606],[-1,31],[-12,40],[-136,40],[-24,-1],[-53,23],[-32,7],[-64,13],[-54,117],[-57,97],[-8,40],[2,182],[-17,80],[-6,88],[-35,-71],[20,-113],[-44,-48],[-55,-23],[5,-66],[23,-13],[4,-68],[-13,-102],[-110,-226],[-22,-25],[-15,-30],[-56,20],[-72,-63],[-68,-10],[-25,71],[-96,95],[-45,-6],[40,-46],[40,-61],[-22,-40],[-23,-26],[-39,-13],[-141,-80],[50,-53],[-42,-60],[-49,-9],[-26,-28],[-9,-39],[-146,-109],[-237,-280],[-122,-79],[-85,-82],[-75,2],[-94,-70],[-239,-62],[-158,28],[-111,-24],[-59,48],[-7,33],[3,19],[9,23],[-20,8],[-43,4],[-19,-23],[-2,-53],[-21,-14],[-82,31],[-21,27],[30,55],[50,49],[-9,11],[-10,30],[-24,3],[-74,-7],[-59,9],[-195,111],[-46,60],[-157,95],[-70,101],[-40,110],[3,100],[19,158],[33,40],[141,-56],[143,-93],[22,5],[45,73],[87,58],[-25,16],[-129,-67],[-48,37],[-75,76],[0,39],[35,39],[12,53],[-19,50],[9,67],[57,72],[87,73],[62,70],[64,43],[-7,15],[-73,-28],[-70,-47],[-82,-78],[-100,-63],[-74,-25],[-36,-20],[-54,-20],[-56,-91],[-62,-39],[-110,-4],[-24,67],[31,236],[33,115],[37,81],[57,14],[41,60],[33,0],[29,-28],[112,-27],[56,76],[72,12],[131,76],[-3,14],[-89,-17],[-54,-2],[-77,-19],[-41,13],[-19,58],[31,51],[124,124],[43,54],[24,50],[-4,35],[21,71],[121,124],[99,57],[32,-49],[-27,-153],[0,-63],[78,223],[34,53],[40,37],[94,25],[27,35],[-110,-11],[-268,-85],[-113,-76],[-30,-58],[-78,-88],[-37,-57],[-16,-84],[-44,-46],[-60,-17],[-82,-106],[-37,-85],[-82,-68],[-52,-53],[-17,-18],[-28,-52],[-24,-4],[-20,31],[-4,66],[9,106],[39,76],[19,75],[-26,70],[18,43],[35,-1],[65,-20],[68,3],[113,55],[-18,32],[-48,5],[-92,-5],[-76,54],[-60,107],[-27,142],[18,41],[221,145],[59,66],[-34,7],[-83,-80],[-119,-50],[-74,69],[-39,75],[-23,157],[9,80],[-10,107],[51,34],[56,-18],[56,-7],[127,9],[279,64],[179,-38],[73,3],[112,55],[98,6],[73,-42],[40,-48],[5,-64],[34,-43],[23,14],[-18,51],[-4,79],[294,89],[35,35],[-117,12],[-34,81],[62,124],[-6,16],[-65,-65],[-31,-92],[12,-73],[-13,-34],[-59,-16],[-135,-5],[-86,31],[-80,17],[-28,23],[10,52],[-16,11],[-33,-47],[-29,-93],[-64,-22],[-175,35],[-254,-21],[-114,-47],[-74,6],[-127,83],[-49,65],[-19,133],[8,58],[99,24],[50,-2],[47,32],[-42,20],[-58,40],[-40,80],[-60,26],[-40,68],[-10,103],[11,71],[33,23],[76,-16],[203,12],[191,-72],[130,-41],[263,20],[154,65],[-29,18],[-166,-37],[-155,1],[-272,73],[-111,24],[-120,-10],[-63,22],[-37,72],[28,139],[57,30],[30,-36],[38,-3],[37,58],[36,33],[29,75],[108,71],[45,6],[65,32],[42,-9],[27,-33],[34,-27],[73,3],[216,57],[23,17],[42,46],[-137,-20],[-114,-33],[-73,-10],[-10,42],[27,36],[42,39],[21,67],[47,28],[50,-1],[104,12],[74,17],[126,-12],[188,-25],[121,-62],[46,6],[48,16],[22,23],[-95,25],[-6,37],[12,27],[155,51],[170,12],[-29,41],[-371,-62],[-97,42],[-77,0],[-50,-25],[-143,-29],[-26,21],[27,72],[86,117],[7,29],[39,28],[222,69],[107,79],[48,10],[47,-6],[73,10],[140,-23],[64,-99],[58,-31],[182,-124],[-8,35],[-158,168],[-60,42],[-45,82],[16,78],[50,52],[180,28],[33,30],[3,52],[-28,36],[-66,-3],[-55,22],[-15,56],[22,38],[104,69],[57,22],[98,24],[171,-54],[13,-29],[-48,-68],[5,-39],[42,-4],[97,116],[115,15],[48,25],[55,16],[79,-105],[34,-33],[26,-14],[25,-87],[25,-4],[34,43],[63,23],[89,15],[146,-23],[66,17],[32,-2],[-31,78],[-19,23],[30,69],[32,28],[101,48],[96,22],[63,47],[84,42],[-13,34],[-24,40],[-54,3],[-23,21],[70,51],[95,57],[-17,23],[-71,25],[-54,-19],[-81,-44],[-94,-70],[31,-20],[47,-59],[-66,-78],[-347,-207],[-165,-60],[-77,9],[-18,57],[-35,41],[-38,87],[-64,-2],[-37,-20],[-16,29],[28,92],[54,73],[92,55],[43,66],[41,106],[132,100],[192,248],[156,79],[58,87],[92,38],[79,68],[61,6],[112,61],[64,73],[-42,4],[-98,-47],[-56,-19],[4,78],[27,79],[81,73],[391,211],[39,-35],[46,-62],[118,14],[134,120],[103,130],[-55,-23],[-61,-53],[-119,-74],[-55,-12],[-31,10],[-18,49],[-41,16],[-37,-11],[-38,35],[-7,87],[49,129],[39,85],[42,64],[165,183],[35,100],[75,53],[97,-12],[29,15],[-33,66],[-106,52],[-6,32],[351,86],[167,-3],[50,43],[91,27],[69,52],[-35,23],[-171,-48],[-106,-22],[-48,1],[-37,-17],[-136,-6],[-30,208],[21,113],[51,-3],[12,108],[58,64],[81,14],[41,27],[58,55],[98,-13],[100,13],[-25,26],[-124,33],[-31,58],[44,32],[48,24],[41,4],[83,113],[51,48],[56,-9],[78,50],[78,-17],[74,32],[102,22],[373,8],[11,46],[-78,11],[-277,12],[-142,-1],[-60,-12],[-21,16],[3,27],[52,44],[24,48],[103,118],[121,78],[92,-20],[98,-75],[70,-9],[33,-24],[51,-104],[24,-3],[-11,99],[68,81],[-18,22],[-101,-29],[-78,30],[-61,61],[-18,55],[38,55],[36,27],[-24,32],[-153,-86],[-109,-20],[-43,12],[24,78],[-13,62],[145,152],[50,18],[82,-12],[73,-43],[62,7],[67,23],[-9,41],[-145,16],[-38,34],[14,34],[99,35],[99,64],[114,19],[91,48],[18,-11],[15,-19],[33,-179],[81,-146],[30,-6],[-31,125],[29,36],[37,27],[12,31],[-43,10],[-34,45],[-50,142],[17,37],[107,76],[135,17],[143,-53],[51,-1],[83,15],[141,43],[83,17],[43,0],[11,22],[-40,14],[-13,14],[-32,8],[-130,-24],[-360,7],[-34,26],[-7,43],[38,63],[42,34],[136,62],[144,9],[151,110],[58,82],[32,127],[93,103],[231,59],[9,26],[-24,53],[2,96],[63,113],[42,39],[20,4],[49,-36],[61,-78],[95,-45],[124,-8],[33,22],[-96,45],[-73,58],[-6,58],[35,31],[53,-3],[68,6],[63,40],[9,27],[3,38],[16,38],[92,91],[286,59],[20,-24],[-15,-175],[-33,-114],[1,-83],[56,83],[74,227],[56,107],[63,61],[45,14],[45,31],[59,19],[18,-24],[19,-57],[-32,-198],[3,-63],[-35,-84],[-136,-187],[6,-24],[31,9],[52,31],[169,178],[147,-22],[2,14],[-47,52],[-58,50],[-18,62],[8,165],[45,66],[127,-7],[76,9],[35,-30],[77,2],[53,118],[104,11],[92,-78],[110,-53],[89,-76],[25,21],[-48,177],[-53,64],[-113,33],[-121,79],[-31,36],[5,26],[107,25],[140,-29],[126,66],[34,-18],[96,35],[60,-47],[37,14],[21,62],[153,39],[98,-36],[52,-37],[24,-71],[37,-140],[76,-76],[47,-37],[56,-10],[27,38],[-52,45],[-14,43],[25,107],[29,41],[164,159],[138,82],[82,7],[144,184],[41,33],[37,8],[-9,45],[-79,29],[-3,55],[104,68],[126,114],[62,8],[39,-32],[123,-51],[75,-59],[55,-30],[35,6],[29,45],[35,20],[78,-11],[47,-29],[36,-4],[33,-17],[8,-38],[-68,-41],[-115,-109],[-113,-125],[-38,-65],[-36,-172],[-89,-110],[-7,-77],[36,-37],[98,29],[120,103],[31,109],[301,296],[142,164],[160,135],[90,28],[43,-89],[-34,-117],[-69,-75],[51,-34],[-10,-89],[-16,-49],[-10,-52],[1,-46],[47,13],[188,93],[48,101],[45,75],[21,66],[73,62],[138,0],[5,24],[-167,86],[-19,39],[56,51],[155,99],[79,-11],[48,-22],[190,-17],[146,-71],[-6,-110],[-32,-46],[-32,-28],[-187,-84],[-31,-41],[59,-14],[126,41],[33,-37],[-41,-95],[-6,-142],[-15,-83],[0,-76],[16,-40],[51,161],[17,41],[74,60],[28,123],[72,146],[82,85],[48,23],[158,-3],[67,-32],[60,-71],[45,-29],[140,-30],[49,-38],[9,-22],[34,-5],[95,54],[62,9],[100,-84],[-20,-62],[6,-20],[122,4],[101,-24],[192,-128],[20,-59],[-9,-73],[-277,-79],[-120,-76],[-197,-30],[-666,51],[13,-55],[464,-120],[27,-34],[-15,-73],[0,-58],[9,-40],[34,-37],[57,-17],[115,9],[57,-20],[39,30],[15,99],[33,22],[65,-29],[28,-106],[18,-11],[33,76],[64,-6],[70,7],[90,-13]],[[54745,96194],[156,-40],[53,1],[77,-75],[41,7],[-8,-45],[-78,-22],[-122,-13],[-18,-9],[-103,7],[-59,61],[-97,15],[0,20],[63,46],[95,47]],[[34620,95879],[-54,-7],[-31,23],[79,63],[258,120],[103,114],[200,39],[13,-64],[-14,-78],[-174,-63],[-195,-42],[-185,-105]],[[51035,99572],[-70,-41],[-106,61],[-70,78],[38,30],[187,4],[46,-41],[7,-23],[-32,-68]],[[52427,103944],[80,-25],[174,5],[95,-176],[54,-186],[87,-14],[166,26],[149,13],[76,-14],[135,-55],[58,-38],[-50,-30],[-124,-34],[-21,-100],[125,-35],[206,-86],[116,-11],[207,35],[194,-67],[192,-81],[-450,-102],[-39,-29],[-63,-75],[-66,-63],[-61,-37],[-135,-63],[-72,-22],[-163,5],[-61,-25],[-56,-51],[-57,-38],[-145,-9],[-74,51],[25,16],[10,30],[-26,72],[138,74],[31,41],[-27,14],[-38,-4],[-100,23],[-30,-1],[-83,-43],[-115,-29],[-117,-7],[-470,-56],[-71,20],[-32,110],[191,56],[29,95],[48,63],[57,42],[103,108],[26,8],[-258,86],[-102,55],[-111,111],[-34,90],[-150,76],[19,98],[-110,-8],[-84,68],[78,39],[399,43],[238,43],[89,-2]],[[55496,103999],[-85,-2],[-157,76],[-30,67],[28,27],[75,1],[119,-91],[127,-27],[-77,-51]],[[46392,103960],[7,-72],[94,7],[112,-76],[122,-41],[35,-28],[26,-36],[74,-72],[35,-76],[-89,-8],[-121,109],[-99,61],[-125,53],[-101,2],[-45,23],[-164,189],[-30,43],[-93,70],[-42,87],[1,68],[125,-16],[109,-42],[95,-97],[17,-30],[-43,-40],[44,-47],[56,-31]],[[56761,104273],[174,-7],[175,17],[30,-18],[-225,-54],[-250,29],[-226,7],[-266,-61],[-86,25],[135,58],[147,19],[24,36],[56,6],[195,4],[117,-61]],[[49618,105307],[30,-2],[29,11],[22,29],[24,16],[147,-18],[209,-59],[62,-29],[87,-59],[71,-99],[-56,-72],[-74,-68],[-26,-38],[27,-54],[-11,-53],[-27,-46],[112,53],[239,170],[36,10],[37,-5],[108,-35],[97,-87],[21,-29],[18,-35],[10,-44],[-6,-50],[-9,-34],[-51,-23],[-24,-21],[55,-1],[63,-27],[57,-57],[65,-23],[233,19],[152,-30],[83,-94],[128,21],[1,50],[28,22],[172,-17],[89,-24],[91,-49],[-155,-81],[128,-78],[215,-56],[130,-59],[23,-25],[21,-33],[-84,-42],[-86,-24],[-217,-4],[-196,-31],[-361,-21],[-53,-14],[-13,-12],[-21,-37],[-139,-86],[-134,-104],[-55,-63],[-42,-88],[-15,-54],[30,-52],[-8,-53],[-101,-41],[-64,-2],[-80,8],[-79,-23],[-5,-36],[4,-51],[-20,-154],[-24,-116],[-37,-108],[-41,-58],[-53,-16],[-169,-11],[-131,-101],[-105,-181],[-55,-71],[-114,-112],[21,-40],[35,-43],[-62,-78],[-96,-86],[1,-34],[33,-61],[16,-64],[-75,-55],[-136,-28],[-139,32],[-68,36],[-63,59],[-66,39],[-70,23],[-267,131],[-246,206],[-225,81],[-146,38],[-71,37],[-69,49],[-59,56],[-55,70],[-27,44],[-5,65],[17,39],[27,19],[178,16],[64,-9],[64,-34],[57,-13],[132,170],[748,97],[241,17],[242,-1],[-38,46],[-32,58],[-36,15],[-182,-33],[-280,-34],[-136,0],[-140,22],[-140,-12],[-145,-50],[-145,-32],[-142,-12],[-299,5],[-75,26],[-100,60],[-24,30],[-20,38],[-20,113],[22,30],[30,18],[32,11],[65,0],[65,-19],[151,-64],[-34,69],[435,83],[202,72],[103,13],[105,-6],[-23,39],[-1,35],[74,30],[53,12],[160,14],[365,-2],[132,20],[98,49],[-105,-17],[-105,-3],[-49,10],[-112,43],[-50,57],[144,114],[50,53],[-146,-8],[-50,-19],[-168,-104],[-124,-47],[-154,-22],[-153,2],[-33,14],[-47,70],[-15,36],[6,20],[49,57],[25,60],[-4,52],[-36,11],[-57,-51],[-51,-71],[-71,-35],[-72,9],[-31,28],[-27,41],[-29,16],[-31,0],[-65,-16],[-65,-31],[23,-47],[5,-52],[-27,-41],[-21,-50],[66,-32],[54,-49],[-81,-23],[-79,-34],[-73,-52],[-74,-41],[-119,-4],[-147,-23],[-294,-8],[-138,67],[-26,31],[-27,21],[-92,35],[-134,102],[-103,116],[-70,11],[-102,38],[-57,34],[-53,43],[-16,52],[5,48],[62,21],[-146,53],[-143,70],[53,23],[53,11],[424,-82],[28,10],[47,41],[-17,13],[-71,10],[-96,-1],[-24,9],[-38,44],[-32,54],[-14,36],[-6,42],[72,63],[40,57],[-62,26],[-174,-2],[-58,-8],[21,-81],[-55,-56],[-106,-44],[-77,21],[-58,108],[-77,74],[-29,47],[-22,68],[-31,50],[-57,59],[-7,37],[7,27],[43,62],[-33,51],[-40,45],[-2,26],[37,31],[34,11],[36,-2],[107,-38],[59,-45],[20,3],[38,67],[54,16],[209,22],[233,-87],[60,-19],[49,-6],[-25,38],[-15,50],[35,19],[188,-45],[88,3],[206,58],[341,31],[129,-46],[7,-25],[-3,-33],[-8,-10],[-75,-38],[-431,-31],[-282,-121],[385,20],[69,-14],[29,-98],[28,-10],[99,-14],[67,-29],[68,-56],[72,-37],[42,4],[16,41],[-17,48],[-9,54],[5,59],[11,49],[81,35],[117,111],[125,76],[139,-34],[128,-94],[116,-135],[112,-145],[126,-178],[61,-63],[55,-15],[254,-186],[29,-5],[-53,141],[-131,239],[-89,184],[-20,71],[-15,98],[6,29],[11,25],[65,106],[84,51],[-26,72],[22,56],[89,44],[82,3],[80,-34],[153,-118]],[[58788,105528],[-552,-39],[-56,27],[896,115],[46,11],[166,14],[143,-26],[-42,-20],[-601,-82]],[[50757,105717],[-126,-57],[-212,44],[26,45],[50,28],[132,-11],[130,-49]],[[52013,105664],[59,-12],[321,5],[61,-26],[25,-61],[49,-22],[68,-6],[170,-76],[58,-11],[51,42],[38,105],[2,123],[-16,59],[19,38],[57,15],[72,-4],[70,21],[61,38],[65,5],[142,-28],[37,-23],[-38,-46],[-15,-66],[-64,-135],[139,-9],[195,29],[49,39],[105,63],[111,-10],[53,8],[27,28],[10,32],[61,-6],[84,-62],[39,-10],[72,16],[29,0],[70,-25],[329,-45],[114,-25],[49,-22],[50,-14],[349,1],[248,-16],[91,-36],[76,-69],[29,-159],[-69,-43],[-500,-195],[-126,-63],[-60,-58],[-102,-126],[-50,-39],[-234,-60],[-55,-6],[-176,29],[-54,-3],[-214,-65],[-74,-40],[-72,-50],[-108,-22],[-110,12],[-498,26],[-67,35],[-54,67],[99,87],[-556,-32],[-612,17],[-33,12],[-26,33],[-210,23],[-158,27],[-133,46],[-131,60],[41,28],[44,16],[113,7],[100,-8],[179,0],[41,60],[71,18],[57,43],[-188,27],[-197,4],[-131,-36],[-152,-16],[-138,-2],[-267,10],[-127,25],[-173,67],[-60,36],[-23,29],[-17,44],[197,39],[77,30],[76,42],[-299,24],[-125,35],[-124,52],[101,29],[402,23],[106,-19],[106,-38],[116,-23],[113,49],[-106,23],[-95,81],[-20,40],[12,31],[50,5],[37,-14],[141,-76],[106,-24],[30,71],[5,33],[-20,28],[-50,51],[-45,62],[70,16],[68,-7],[148,-43],[148,-30],[68,-30],[127,-76],[119,-51]],[[96,34848],[-28,-117],[-16,52],[-3,93],[-12,36],[-24,22],[-13,31],[1,46],[87,-73],[8,-90]],[[3166,40412],[-14,-22],[-13,2],[-8,21],[-1,35],[12,-10],[4,-5],[4,-7],[16,-14]],[[2994,40544],[-5,-3],[-8,9],[2,17],[6,7],[4,-5],[4,-13],[-3,-12]],[[42299,75652],[-8,-40],[-23,-43],[-77,-62],[-80,-41],[-42,5],[-28,21],[-16,23],[-43,21],[-59,11],[-37,-23],[-26,-22],[-23,3],[-17,19],[-14,28],[-17,90]],[[41789,75642],[44,17],[95,6],[74,-31],[98,-16],[74,43],[59,-36],[66,27]],[[42138,76019],[57,-57],[12,-18],[4,-20],[-72,-22],[-77,69],[-51,-16],[-19,33],[0,21],[53,17],[93,-7]],[[42684,77403],[-58,-74],[-35,21],[-10,17],[18,57],[85,96],[0,-117]],[[42814,77650],[-108,-77],[-9,12],[69,67],[48,-2]],[[42299,75652],[-51,15],[-77,44],[-107,-36],[-75,43],[-62,4],[-39,33],[-42,57],[30,37],[29,13],[113,8],[83,-23],[149,-123],[37,1],[40,15],[-20,34],[-37,16],[-56,33],[-44,46],[104,15],[-14,24],[-14,41],[-109,144],[18,38],[28,83],[34,69],[27,19],[45,49],[98,143],[62,117],[46,139],[68,382],[20,64],[32,72],[41,-13],[29,-21],[101,54],[173,142],[51,122],[50,57],[199,111],[110,33],[170,8],[122,20],[147,7],[57,-68],[32,-50],[52,-28],[81,-19]],[[43329,74990],[-114,5],[-29,5],[-32,15],[0,1]],[[43154,75016],[-14,32],[-17,39],[5,24],[51,68],[8,19],[-5,10],[5,30],[40,102],[5,40],[-18,29],[-25,17],[-84,30],[-40,43],[-18,37],[-19,10],[-27,-12],[-70,-14],[-56,20],[-67,70],[-15,63],[-8,48],[-17,17],[-22,-25],[-28,-39],[-56,-5],[-16,9],[-3,22],[-3,21],[-16,25],[-16,14],[-71,-72],[-26,0],[-34,28],[-16,27],[-37,-15],[-32,-34],[11,-63],[-18,-11],[-40,6],[-46,26]],[[42940,77730],[-54,-8],[-25,15],[131,41],[83,13],[15,-6],[-150,-55]],[[43292,77806],[-115,-16],[-39,12],[-7,12],[32,8],[98,1],[30,-10],[1,-7]],[[43527,77860],[-82,-35],[-19,8],[5,10],[71,22],[25,-5]],[[43761,77935],[-54,-3],[15,27],[51,21],[27,0],[-39,-45]],[[56238,80597],[79,-90]],[[56317,80507],[19,-4],[44,36],[9,2],[91,3],[42,-31],[32,-61],[29,-50],[31,-13],[89,62],[50,20],[32,0],[114,-56],[54,-30]],[[56953,80385],[12,-27],[1,-33],[-15,-48],[-11,-52],[35,-62],[40,-42],[86,69],[32,19],[35,1],[46,26],[34,38],[32,14],[62,-9],[111,9],[130,-61],[11,-19],[65,-71],[22,-35]],[[57681,80102],[22,-11],[34,-35],[46,-22],[32,7],[16,-12],[14,-27],[1,-47],[-5,-133],[-22,-38],[-24,-32],[-6,-24],[2,-29],[37,-58],[47,-89],[11,-52],[0,-39],[-64,-114],[-22,-26],[-15,-57],[-7,-57],[4,-23],[108,-91],[80,-50],[18,-24],[2,-15],[-43,-97],[-4,-26],[64,-41],[35,-64],[32,-104],[60,-99],[131,-88],[96,-58],[20,-26],[6,-31],[-7,-68],[-24,-84],[-17,-46],[39,-19],[99,5],[122,-16],[145,-92],[1,-41]],[[58745,78009],[-15,-38],[10,-39],[16,-34],[126,-103],[12,-29],[2,-50],[-4,-37],[-35,-8],[-38,-17],[-64,-44],[-25,-62],[-102,-85],[-63,-39],[-51,-2],[-120,18]],[[58394,77440],[-42,42],[-17,39],[-46,17],[-62,2],[-84,-7],[-17,-11],[-14,-48],[-36,-81],[-26,-46],[21,-28],[34,-59],[52,-74],[54,-66],[17,-41],[0,-29],[-26,-34],[4,-68],[52,-90],[-17,-15]],[[58241,76843],[-6,-110],[1,-119],[14,-28],[28,-24],[24,-43],[39,-99],[3,-25],[-110,7],[-133,-3],[-75,-57],[-29,13],[-51,15],[-58,-32],[-79,-97],[-52,-60],[-52,-85],[-16,-46],[-32,-84],[-30,-96],[16,-68],[25,-62],[5,-68],[12,-53],[-32,-38],[-19,-56],[-55,10]],[[57579,75535],[-68,53],[-14,77],[-52,54],[-35,28],[-56,4],[-90,-25],[-119,-19],[-89,-5],[-48,-28],[-72,-26],[-28,31],[-40,88],[-32,86],[-23,39],[-20,10],[-24,-2],[-27,-27],[-21,-29],[-29,-10],[-46,-23],[-32,-31],[-37,-80],[-23,6],[-25,18],[-29,90],[-39,21],[-62,1],[-78,19],[-63,27],[-22,-7],[-38,-38],[-40,-5],[-89,34],[-17,-16],[-24,-50],[-27,-48],[-24,-5],[-14,12],[8,86]],[[55971,75845],[-52,30],[-87,5],[-61,-12],[-30,3],[-15,17],[-75,144],[-39,9],[-71,-7],[-104,17],[-121,33],[-66,12],[-34,32],[-74,11],[-199,61],[-82,10]],[[54861,76210],[-120,1],[-182,14],[-117,-8],[-54,-20],[-62,-12],[-106,-12],[-43,2],[-68,-7],[-77,-16],[-23,-30],[-25,-67],[-89,-114],[-87,-76],[-16,-7],[-50,41],[-43,13],[-49,5],[-35,-13],[-22,-19],[3,-89]],[[53596,75796],[-5,-8]],[[53520,78307],[44,-21],[102,-8],[80,24],[42,4],[38,-8],[55,14],[51,6],[27,-32],[47,-28],[94,40],[82,50],[86,-5],[13,24],[21,126],[25,27],[103,-12],[38,22],[40,62],[61,38],[50,0],[53,44],[26,-29],[13,-52],[-18,-42],[8,-16],[36,-20]],[[54737,78515],[63,0],[40,17],[9,24],[0,43],[-10,40],[-26,35],[-50,18],[-35,0],[-6,22],[12,47],[31,87],[38,78],[23,30],[4,27],[-5,48],[-1,85],[34,120],[46,89],[61,29],[75,16],[48,42],[24,49],[9,42],[11,35],[24,16],[180,-10],[28,77],[15,22],[35,23],[24,27],[-9,21],[-46,14],[-108,12],[-22,25],[7,31],[29,79],[27,102],[14,79],[2,47]],[[55332,80103],[15,13],[89,15],[29,15],[76,108],[58,19],[150,-28],[69,2],[18,-3],[69,-4],[7,10],[31,107],[30,31],[118,140],[79,59],[50,13],[18,-3]],[[51021,67486],[-18,2],[-30,-8],[-19,-10],[-30,15],[-32,10],[-13,-16],[-6,-31],[19,-57],[37,-88],[-6,-68],[-28,-7],[-26,56],[-22,9],[-26,-2],[-60,-65],[-43,-55],[-11,-38],[-15,-42],[-5,-30],[1,-101],[-79,-16],[-16,-15],[-10,-30],[7,-130],[6,-69]],[[50596,66700],[45,-107],[2,-34],[-7,-23],[-31,-42],[-16,-16],[-10,-4]],[[50131,66824],[-48,43]],[[56492,67703],[-13,-250],[-56,-117],[-85,39],[-109,-32],[-57,-133],[-33,-39],[-29,-46],[-19,-172],[-4,-282],[-41,-34],[-38,-11],[-157,-248],[90,-70],[40,-53],[66,-147],[94,-167],[19,-82],[-79,19],[-28,-6],[-17,-26],[-37,6],[-45,-1],[-47,-29],[-27,-13],[-35,27],[-65,82],[-39,56],[-30,14],[-30,-16],[-105,-20],[-26,-33],[-48,-36],[-50,-17],[-70,-13],[-37,2],[-21,-18],[-18,-53],[-12,-52],[-10,-21],[-88,-26],[-19,-30],[-6,-29],[2,-29],[-70,28],[-54,-19],[-13,-22],[-11,-32],[6,-35],[20,-33],[19,-90],[6,-90],[-11,-51],[-40,-37],[-84,-40],[-80,19],[-36,-16],[-60,-5],[-55,-11],[-84,-36],[-76,-22],[-69,75],[-81,51],[-86,31],[-30,-23],[-12,-17],[-72,66],[-32,24],[-16,26],[-29,88],[-18,3],[-59,-33],[-57,2],[-34,6],[-102,-4],[-13,-61],[-13,-9],[-22,-8],[-54,4],[-69,-45],[-74,-27],[-58,-1],[-59,13],[-36,-9],[-77,-5],[-49,-65],[-76,3],[-64,11]],[[53189,65201],[8,21],[13,259],[31,116],[-1,24],[-7,18],[-28,19],[-20,62],[-42,165],[-24,33],[-66,35],[-58,48],[-49,62],[-90,155]],[[52856,66218],[45,15],[14,32],[45,85],[6,42],[-5,23],[-31,41],[-20,90],[15,83],[2,43],[-16,43],[16,53],[33,28],[21,9],[86,6],[54,105]],[[53121,66916],[34,34],[34,60],[15,22],[15,47],[6,48],[-69,67],[-23,50],[-30,56],[-41,38],[-83,66],[-33,67],[-14,87],[-22,65],[-25,43],[-4,35],[-10,43],[-3,84],[20,111],[13,40],[28,11],[75,59],[3,77],[13,47],[24,27],[22,18]],[[43154,75016],[1,6],[79,29],[36,-59],[59,-2]],[[43401,74336],[-4,3],[-12,32],[-20,-1],[-46,14],[-64,-88],[-29,-73],[-17,-53],[-25,-44],[-5,-45],[3,-20],[-9,-24],[0,-26],[36,-52],[10,-28],[44,-90],[-14,-34],[-11,-36],[-13,-25],[-15,-16]],[[41308,75351],[254,175],[154,89],[73,27]],[[47819,70592],[-122,36],[-81,3],[-106,15],[-212,56],[-61,22],[-59,7],[-70,19],[-53,31],[-34,60],[-36,79],[-66,103],[-14,52],[20,45],[21,34],[-2,15],[-16,7],[-117,-44],[-113,-56]],[[46698,71076],[-44,-1],[-43,12],[-57,1],[-55,-15],[-110,-8],[-65,-41],[-41,-80],[-22,-65],[-19,-20],[-38,-8],[-58,6],[-40,19],[-41,55],[-64,7],[-58,2],[-16,10]],[[45386,71636],[15,10],[59,-9],[38,26],[19,26],[53,-24],[77,-49],[36,-33],[15,-26],[9,-21],[-5,-36],[18,-15],[36,-5],[24,-12],[-8,-48],[-2,-40],[34,6],[42,30],[33,55],[20,53],[15,129],[6,11],[25,-10],[102,6],[49,-24],[76,-5],[-1,-20],[13,-31],[34,-46],[17,-29],[36,-6],[54,17],[33,17],[12,-12],[50,11],[44,37],[11,28],[45,20],[61,45],[83,35],[273,38],[11,28],[-4,65],[7,9],[34,-16],[55,-15],[43,-23],[27,-30],[26,-1],[39,21],[53,14],[50,-32],[15,-33],[-9,-18],[1,-27],[15,-23],[41,-37],[52,-32],[27,3],[10,31],[9,74],[4,79],[-12,45],[-28,11],[-33,4],[-18,9],[6,25],[27,64],[-1,87],[-60,98],[-52,94],[0,33],[31,56],[49,44],[107,74],[34,16],[44,12]],[[47600,72475],[30,31],[20,34],[29,177],[7,8],[9,10],[110,-61],[10,10],[18,10],[36,47],[8,36],[-1,67],[3,64],[7,20]],[[51035,67399],[46,-37],[68,-74],[80,-136],[36,-40],[33,-10]],[[51298,67102],[65,-57],[44,-13],[50,-16],[131,-117],[59,-35],[41,-44],[5,-42],[-2,-26]],[[51527,66461],[-10,2],[-62,-45],[-47,-21],[-41,-10],[-20,21],[-10,30],[2,85],[-7,28],[-15,14],[-28,-20],[-33,-66],[-31,-76],[-47,-80],[-38,-76],[-41,-96],[-28,-80],[29,-45],[18,-63],[-5,-47],[5,-27],[-9,-82],[-2,-52]],[[51107,65755],[-91,83],[-37,116],[-133,197],[-152,134],[-9,21],[9,26],[7,20],[-32,1],[-22,-16],[-21,5],[-23,50],[-23,43],[-1,39]],[[50579,66474],[10,4],[16,16],[31,42],[7,23],[-2,34],[-45,107]],[[50596,66700],[-6,69],[-7,130],[10,30],[16,15],[79,16],[-1,101],[5,30],[15,42],[11,38],[43,55],[60,65],[26,2],[22,-9],[26,-56],[28,7],[6,68],[-37,88],[-19,57],[6,31],[13,16],[32,-10],[30,-15],[19,10],[30,8],[18,-2],[-2,-13],[3,-37],[13,-37]],[[48324,59500],[-19,-34],[-57,1],[-49,53],[0,110],[56,-22],[52,-74],[17,-34]],[[48177,59681],[-35,-16],[-35,32],[-8,18],[49,16],[23,-14],[10,-27],[-4,-9]],[[53189,65201],[-33,1],[-44,-5],[-17,-20],[-17,-140],[-71,-40],[-64,-22],[-54,5],[-95,33],[-31,4],[-27,-19],[-84,-10],[-38,-25],[-87,-163],[-89,-56],[-30,-29],[-67,36],[-33,4],[-47,-41],[-102,-5],[-28,-7],[-79,-6]],[[52052,64696],[-3,22],[-15,33],[-37,15],[-75,-13],[-19,24],[-31,139],[-24,22],[-27,47],[-46,150],[-1,66],[3,58],[-26,135],[16,34],[24,21],[0,55],[-7,82],[28,162],[8,12]],[[52400,66149],[33,-6],[70,27],[44,37]],[[52547,66207],[23,5],[30,14],[42,-2],[44,-16],[55,21],[54,35],[22,-9],[23,-29],[16,-8]],[[40831,66415],[-16,-7],[-54,-42],[-30,-15],[-28,-8],[-22,3],[-12,25],[1,38],[-5,34],[-4,19],[8,49],[18,27],[25,22],[39,-8],[82,-32],[17,-30],[1,-20],[-15,-32],[-5,-23]],[[55347,72401],[12,35],[121,97],[31,-16],[63,-4],[128,4],[63,63],[39,-17],[32,28],[53,36],[7,-8],[7,-5],[82,-16],[61,-35],[42,-53],[42,-33],[44,-13],[24,-26],[5,-40],[41,-20],[77,0],[33,-26],[-12,-54],[8,-17]],[[56350,72281],[27,18],[21,-16]],[[56398,72283],[11,-40],[12,-19],[39,63],[42,-7],[100,-25],[54,-129],[33,-46],[29,-19],[38,20],[32,24],[19,-12],[41,-85],[9,-112],[0,-45],[-15,-76],[-20,-80],[-16,-53],[7,-42],[14,-36],[24,-11],[77,-72],[29,-49],[43,-37]],[[57000,71395],[32,-2],[16,-21],[6,-25],[-4,-64],[-18,-59],[2,-39],[28,-45],[3,-53],[2,-34],[15,-26],[71,-58],[92,-56],[24,-49],[14,-61],[-4,-102],[-6,-90],[120,-120],[-14,-23],[-18,-24],[-115,-19],[-24,-10],[-50,91],[-26,11],[-25,-33],[-29,-19],[-35,10],[-37,28],[-19,20]],[[57001,70523],[-15,2],[-23,-20],[-31,9],[-20,22],[-30,-77],[-18,-16],[-11,2],[-2,131],[-8,20],[-24,3],[-56,-31],[-53,-41],[-18,-35],[2,-65],[7,-76],[37,-117],[-20,-51],[-14,-80],[-58,-74],[-64,-44],[-6,-88],[-36,-61],[-61,-60],[-41,-73],[10,-50],[3,-47],[-7,-32],[-2,-25],[-16,-11],[-94,-9],[-26,-15],[-31,-35]],[[51846,84650],[-4,-24],[-48,-6],[-20,22],[-44,-3],[-8,11],[18,22],[36,14],[46,-6],[24,-30]],[[51293,84803],[3,-24],[-22,6],[-17,-8],[-12,-29],[-25,11],[-10,41],[19,62],[45,2],[19,-61]],[[51484,84973],[18,0],[8,9],[31,-6],[47,-41],[9,-22],[33,-11],[11,-22],[-37,-71],[-24,-1],[-17,9],[-30,-8],[-18,-13],[-6,-29],[1,-62],[-137,-12],[-31,18],[-43,139],[9,36],[29,16],[24,3],[4,-75],[36,7],[12,50],[2,35],[-10,17],[-24,14],[-15,23],[21,38],[38,16],[33,-50],[26,-7]],[[44171,67712],[-35,-20],[1,23],[9,12],[11,6],[13,-10],[1,-11]],[[52052,64696],[-5,-78]],[[52047,64618],[19,-60],[25,-61],[0,-38],[-17,-61],[-30,-72],[-40,-28]],[[52004,64298],[-44,-23],[-21,-56],[-11,-59],[-20,-44],[-12,-48],[-18,-98],[-5,-36],[-30,-36],[-46,-15],[-41,-3]],[[51756,63880],[-28,-17],[-14,-33],[-27,-27],[-16,-12],[0,-30],[20,-63],[21,-51],[1,-40]],[[51713,63607],[-11,-12],[-34,5],[-7,-15],[-3,-45],[-9,-39],[-14,-24],[-24,-25],[-45,8],[-41,39],[-22,12],[-12,-1],[-3,95],[-18,74],[-66,178],[-214,173],[-51,78],[-22,65],[-22,62],[21,2],[21,-16],[27,-18],[11,30],[-12,68],[-55,158],[-4,43],[27,132],[45,148],[-3,180],[14,135],[-15,88],[-8,108],[33,144],[28,35],[18,46],[1,153],[-64,71],[-73,13]],[[55332,80103],[-30,5],[-82,33],[-70,48],[-42,64],[-72,89],[-48,45],[-74,56],[-124,115],[-45,26],[-221,50],[-80,23],[-73,130],[-24,76]],[[54347,80863],[-36,13],[-40,-16],[-43,-15],[-99,-88],[-32,-13],[-62,-1],[-144,-19],[-65,32],[-114,35],[-62,6],[-55,-1],[-243,35],[-44,-38],[-45,-7],[-43,58],[-54,17],[-60,-20],[-109,-2],[-128,18],[-164,15],[-25,-6],[-182,-78],[-44,-12],[-198,-132],[-156,-122],[-19,196],[10,393],[23,194],[109,114],[54,88],[32,118],[9,109],[22,90],[157,258],[125,28],[168,72],[189,60],[36,-76],[18,-58],[227,-212],[58,-71],[87,-243],[210,-124],[166,39],[71,60],[133,111],[59,81],[12,78],[-24,333],[-36,144],[13,90],[23,-5],[56,44],[185,80],[37,4],[42,16],[116,61],[37,-32],[32,-37],[17,-1],[8,14]],[[54562,82538],[-2,24],[8,17],[34,-10],[134,-100],[52,-24]],[[54788,82445],[35,-6],[43,-47],[115,-32],[14,-24],[9,-31],[107,-127],[49,-64]],[[55160,82114],[95,-59],[41,-14],[168,60],[46,21],[39,0],[39,-32],[90,-42],[81,-13],[15,3],[68,-5],[25,-16],[16,-81],[78,-65],[72,-53],[18,-24],[6,-48],[-5,-55],[-9,-29],[-30,-33],[-26,-84],[-4,-79],[-42,-138],[10,-2],[87,24],[25,-14],[19,-30],[6,-87],[29,-38],[29,-61],[10,-47],[55,-57],[5,-36],[34,-129],[13,-74],[6,-57],[-17,-73],[-14,-50]],[[58344,76395],[-3,25],[-39,99],[-24,43],[-28,24],[-14,28],[-1,119],[6,110]],[[58241,76843],[17,15],[-52,90],[-4,68],[26,34],[0,29],[-17,41],[-54,66],[-52,74],[-34,59],[-21,28],[26,46],[36,81],[14,48],[17,11],[84,7],[62,-2],[46,-17],[17,-39],[42,-42]],[[58394,77440],[120,-18],[51,2],[63,39],[102,85],[25,62],[64,44],[38,17],[35,8],[4,37],[-2,50],[-12,29],[-126,103],[-16,34],[-10,39],[15,38]],[[58745,78009],[-1,41],[-145,92],[-122,16],[-99,-5],[-39,19],[17,46],[24,84],[7,68],[-6,31],[-20,26],[-96,58],[-131,88],[-60,99],[-32,104],[-35,64],[-64,41],[4,26],[43,97],[-2,15],[-18,24],[-80,50],[-108,91],[-4,23],[7,57],[15,57],[22,26],[64,114],[0,39],[-11,52],[-47,89],[-37,58],[-2,29],[6,24],[24,32],[22,38],[5,133],[-1,47],[-14,27],[-16,12],[-32,-7],[-46,22],[-34,35],[-22,11]],[[57681,80102],[-22,35],[-65,71],[-11,19],[-130,61],[-111,-9],[-62,9],[-32,-14],[-34,-38],[-46,-26],[-35,-1],[-32,-19],[-86,-69],[-40,42],[-35,62],[11,52],[15,48],[-1,33],[-12,27]],[[56953,80385],[-54,30],[-114,56],[-32,0],[-50,-20],[-89,-62],[-31,13],[-29,50],[-32,61],[-42,31],[-91,-3],[-9,-2],[-44,-36],[-19,4]],[[56317,80507],[-79,90],[14,50],[17,73],[-6,57],[-13,74],[-34,129],[-5,36],[-55,57],[-10,47],[-29,61],[-29,38],[-6,87],[-19,30],[-25,14],[-87,-24],[-10,2],[42,138],[4,79],[26,84],[30,33],[9,29],[5,55],[-6,48],[-18,24],[-72,53],[-78,65],[-16,81],[-25,16],[-68,5]],[[56159,84072],[30,72],[-11,97],[-19,81],[26,59],[43,5],[47,-64],[71,-34],[52,44],[18,83],[37,37],[50,-33],[84,-12],[69,5],[47,18],[20,27],[19,49],[38,61],[40,41],[304,-46],[264,-85],[20,32],[9,54],[-65,48],[-49,24],[-61,99],[-88,77],[-88,7],[-116,-27],[-176,16],[-149,146],[-99,45],[-70,112],[-18,60],[76,-51],[10,54],[6,70],[-42,44],[-38,25],[-194,-110],[-223,-37]],[[57823,94781],[105,-15],[235,-83],[55,8],[70,25],[71,99],[53,16],[69,-23],[19,27],[-36,82],[9,41],[237,-88],[101,-65],[220,-57],[38,-31],[3,-54],[-10,-46],[-47,-25],[-94,4],[-336,71],[-50,-43],[41,-37],[99,-44],[27,-79],[151,11],[144,-30],[68,10],[12,-25],[-46,-65],[21,-17],[162,63],[75,17],[40,-17],[6,-51],[-27,-66],[-3,-50],[-49,-120],[-77,-36],[-32,-50],[112,30],[59,34],[112,165],[33,22],[318,3],[72,-11],[298,-78],[85,-7],[96,10],[34,36],[33,11],[331,-87],[443,-196],[648,-324],[365,-288],[43,-62],[132,-35],[28,24],[73,-21],[430,-263],[148,-14],[-19,56],[-26,52],[37,-12],[50,-37],[82,-104],[100,-76],[101,-114],[85,-44],[76,-16],[64,-33],[116,-30],[55,-280],[43,-61],[0,-124],[74,-50],[57,-9],[-3,-92],[-46,-215],[-50,-92],[-389,-395],[-244,-152],[-474,-175],[-370,-65],[-149,-5],[-290,32],[-159,36],[-194,99],[-181,49],[-125,22],[-231,9],[-501,97],[-87,35],[-314,189],[-125,-53],[-74,-10],[-51,65],[20,18],[12,22],[-178,54],[-147,4],[-78,46],[-95,35],[-43,-21],[-23,0],[-194,82],[-86,67],[-90,118],[22,41],[26,27],[-309,68],[-294,10],[51,-33],[127,-18],[81,-47],[94,-66],[-22,-91],[130,-91],[100,-85],[2,-27],[39,-18],[147,-25],[25,-79],[-24,-31],[20,-44],[110,-50],[65,-13],[81,-30],[-37,-60],[-67,-39],[-68,-18],[32,-15],[88,6],[318,-100],[167,-101],[170,-183],[55,-91],[4,-50],[-9,-50],[-25,-54],[-11,-54],[-58,-161],[-42,-55],[-80,-63],[76,-123],[78,-114],[77,-190],[14,-76],[3,-117],[70,-46],[-27,-18],[-28,-33],[7,-152],[97,-125],[144,-81],[87,-16],[125,33],[90,-45],[201,-152],[91,-161],[36,-33],[204,-60],[152,-37],[231,-96],[41,-4],[112,83],[194,58],[60,80],[-5,68],[-49,121],[-14,117],[-64,48],[-60,32],[-181,-24],[-82,4],[-62,32],[-83,84],[-158,204],[-85,68],[-26,42],[-30,58],[4,95],[69,-3],[78,54],[56,192],[98,25],[52,-2],[226,-89],[280,-239],[62,-25],[66,-4],[107,6],[17,-31],[58,-37],[42,-5],[257,-75],[299,-149],[111,6],[44,83],[9,35],[122,84],[85,13],[119,-30],[21,25],[-40,122],[-55,106],[-81,68],[-143,199],[-57,99],[-29,102],[19,90],[20,66],[298,160],[108,95],[104,125],[48,25],[176,35],[233,106],[178,142],[176,214],[74,56],[60,-5],[80,-34],[88,-62],[120,-11],[116,10],[132,-6],[185,-98],[31,-31],[29,-42],[-60,-81],[-5,-52],[48,24],[66,13],[62,-17],[58,-46],[43,-50],[51,-43],[16,58],[8,50],[-29,127],[72,179],[56,78],[101,197],[-30,128],[-5,149],[-15,69],[-65,99],[-127,71],[-127,22],[-43,68],[8,78],[35,114],[105,241],[110,338],[4,79],[-11,43],[8,43],[-13,103],[-21,77],[-445,292],[-27,29],[-15,39],[47,8],[34,-2],[336,-136],[74,-7],[162,11],[266,-1172],[-4,-13],[21,-65],[0,0],[1574,-6944],[-2590,-18427],[-62,40],[-52,63],[-5,43],[-59,43],[-75,39],[-59,-11],[-55,-4],[-85,71],[-81,4],[-92,-21],[-20,-9],[-22,-9],[-274,30],[-70,60],[-59,59],[-161,43],[-82,45],[-82,64],[-89,56],[-75,-22],[-103,32],[-112,28],[-38,-18],[-36,-71],[-26,-67],[-61,55],[-208,265],[-109,176],[-357,407],[-48,31],[-188,58],[-76,48],[-193,290],[-85,-39],[-77,10],[-45,25],[-49,42],[-34,55],[-40,121],[-46,70],[-152,101],[-171,59],[-14,26],[-5,36],[148,69],[40,39],[-76,53],[-29,8],[-24,25],[43,39],[42,18],[65,-45],[74,-84],[64,-32],[29,40],[223,69],[15,55],[0,61],[-22,-2],[-14,13],[1,68],[33,93],[100,151],[54,211],[47,47],[35,-31],[-2,-50],[5,-36],[31,71],[30,95],[75,1],[51,-16],[54,11],[-103,157],[-139,159],[-58,-12],[-37,24],[-61,131],[-25,108],[59,-2],[58,-17],[112,76],[41,11],[66,-24],[92,-15],[-8,71],[-28,84],[111,63],[100,34],[189,122],[84,21],[11,28],[3,37],[-29,97],[-28,72],[-101,4],[-55,-101],[-152,-33],[-67,7],[53,64],[54,25],[15,27],[-108,-24],[-54,-66],[-157,-87]]],"objects":{"ne_50m_admin_v3_lessCols_I40":{"type":"GeometryCollection","geometries":[{"arcs":[[0]],"type":"Polygon","properties":{"sovereignt":"Luxembourg","type":"Sovereign country","admin":"Luxembourg","name":"Luxembourg","name_long":"Luxembourg","formal_en":"Grand Duchy of Luxembourg","mapcolor7":1,"mapcolor8":7,"mapcolor9":3,"mapcolor13":7,"iso_a2":"LU","iso_a3":"LUX","iso_n3":"442","continent":"Europe"}},{"arcs":[[[1,2]],[[3,4,5,6]]],"type":"MultiPolygon","properties":{"sovereignt":"Lithuania","type":"Sovereign country","admin":"Lithuania","name":"Lithuania","name_long":"Lithuania","formal_en":"Republic of Lithuania","mapcolor7":6,"mapcolor8":3,"mapcolor9":3,"mapcolor13":9,"iso_a2":"LT","iso_a3":"LTU","iso_n3":"440","continent":"Europe"}},{"arcs":[[7,8]],"type":"Polygon","properties":{"sovereignt":"Liechtenstein","type":"Sovereign country","admin":"Liechtenstein","name":"Liechtenstein","name_long":"Liechtenstein","formal_en":"Principality of Liechtenstein","mapcolor7":2,"mapcolor8":4,"mapcolor9":2,"mapcolor13":9,"iso_a2":"LI","iso_a3":"LIE","iso_n3":"438","continent":"Europe"}},{"arcs":[[9,10,11,12,13]],"type":"Polygon","properties":{"sovereignt":"Kosovo","type":"Sovereign country","admin":"Kosovo","name":"Kosovo","name_long":"Kosovo","formal_en":"Republic of Kosovo","mapcolor7":2,"mapcolor8":2,"mapcolor9":3,"mapcolor13":11,"iso_a2":"-99","iso_a3":"-99","iso_n3":"-99","continent":"Europe"}},{"arcs":[[14]],"type":"Polygon","properties":{"sovereignt":"United Kingdom","type":"Country","admin":"Jersey","name":"Jersey","name_long":"Jersey","formal_en":"Bailiwick of Jersey","mapcolor7":6,"mapcolor8":6,"mapcolor9":6,"mapcolor13":3,"iso_a2":"JE","iso_a3":"JEY","iso_n3":"832","continent":"Europe"}},{"arcs":[[[15]],[[16]],[[17]],[[18]],[[19]],[[20]],[[21]],[[22,23,24,25,26,27,28,29,30,31],[32]]],"type":"MultiPolygon","properties":{"sovereignt":"Italy","type":"Sovereign country","admin":"Italy","name":"Italy","name_long":"Italy","formal_en":"Italian Republic","mapcolor7":6,"mapcolor8":7,"mapcolor9":8,"mapcolor13":7,"iso_a2":"IT","iso_a3":"ITA","iso_n3":"380","continent":"Europe"}},{"arcs":[[33]],"type":"Polygon","properties":{"sovereignt":"Iceland","type":"Sovereign country","admin":"Iceland","name":"Iceland","name_long":"Iceland","formal_en":"Republic of Iceland","mapcolor7":1,"mapcolor8":4,"mapcolor9":4,"mapcolor13":9,"iso_a2":"IS","iso_a3":"ISL","iso_n3":"352","continent":"Europe"}},{"arcs":[[[34]],[[35,36]]],"type":"MultiPolygon","properties":{"sovereignt":"Ireland","type":"Sovereign country","admin":"Ireland","name":"Ireland","name_long":"Ireland","formal_en":"Ireland","mapcolor7":2,"mapcolor8":3,"mapcolor9":2,"mapcolor13":2,"iso_a2":"IE","iso_a3":"IRL","iso_n3":"372","continent":"Europe"}},{"arcs":[[37]],"type":"Polygon","properties":{"sovereignt":"Vatican","type":"Sovereign country","admin":"Vatican","name":"Vatican","name_long":"Vatican","formal_en":"State of the Vatican City","mapcolor7":1,"mapcolor8":3,"mapcolor9":4,"mapcolor13":2,"iso_a2":"VA","iso_a3":"VAT","iso_n3":"336","continent":"Europe"}},{"arcs":[[38]],"type":"Polygon","properties":{"sovereignt":"United Kingdom","type":"Country","admin":"Isle of Man","name":"Isle of Man","name_long":"Isle of Man","formal_en":null,"mapcolor7":6,"mapcolor8":6,"mapcolor9":6,"mapcolor13":3,"iso_a2":"IM","iso_a3":"IMN","iso_n3":"833","continent":"Europe"}},{"arcs":[[39,40,41,42,43,44,45,46,47,48]],"type":"Polygon","properties":{"sovereignt":"Hungary","type":"Sovereign country","admin":"Hungary","name":"Hungary","name_long":"Hungary","formal_en":"Republic of Hungary","mapcolor7":4,"mapcolor8":6,"mapcolor9":1,"mapcolor13":5,"iso_a2":"HU","iso_a3":"HUN","iso_n3":"348","continent":"Europe"}},{"arcs":[[[49]],[[50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67]]],"type":"MultiPolygon","properties":{"sovereignt":"Ukraine","type":"Sovereign country","admin":"Ukraine","name":"Ukraine","name_long":"Ukraine","formal_en":"Ukraine","mapcolor7":5,"mapcolor8":1,"mapcolor9":6,"mapcolor13":3,"iso_a2":"UA","iso_a3":"UKR","iso_n3":"804","continent":"Europe"}},{"arcs":[[[68]],[[69]],[[70,71]],[[72]],[[73]],[[74]],[[75]],[[76]],[[77]],[[78]],[[79]],[[80]],[[81,82,83,84,85,86]]],"type":"MultiPolygon","properties":{"sovereignt":"Croatia","type":"Sovereign country","admin":"Croatia","name":"Croatia","name_long":"Croatia","formal_en":"Republic of Croatia","mapcolor7":5,"mapcolor8":4,"mapcolor9":5,"mapcolor13":1,"iso_a2":"HR","iso_a3":"HRV","iso_n3":"191","continent":"Europe"}},{"arcs":[[[87]],[[88]],[[89]],[[90]],[[91]],[[92]],[[93]],[[94]],[[95]],[[96]],[[97]],[[98]],[[99]],[[100]],[[101]],[[102]],[[103]],[[104]],[[105]],[[106]],[[107]],[[108]],[[109]],[[110]],[[111]],[[112]],[[113]],[[114]],[[115]],[[116]],[[117]],[[118]],[[119]],[[120]],[[121]],[[122]],[[123]],[[124]],[[125]],[[126,127,128,129]]],"type":"MultiPolygon","properties":{"sovereignt":"Greece","type":"Sovereign country","admin":"Greece","name":"Greece","name_long":"Greece","formal_en":"Hellenic Republic","mapcolor7":2,"mapcolor8":2,"mapcolor9":2,"mapcolor13":9,"iso_a2":"GR","iso_a3":"GRC","iso_n3":"300","continent":"Europe"}},{"arcs":[[130]],"type":"Polygon","properties":{"sovereignt":"United Kingdom","type":"Country","admin":"Guernsey","name":"Guernsey","name_long":"Guernsey","formal_en":"Bailiwick of Guernsey","mapcolor7":6,"mapcolor8":6,"mapcolor9":6,"mapcolor13":3,"iso_a2":"GG","iso_a3":"GGY","iso_n3":"831","continent":"Europe"}},{"arcs":[[[131]],[[132]],[[-37,133]],[[134]],[[135]],[[136]],[[137]],[[138]],[[139]],[[140]],[[141]],[[142]],[[143]],[[144]],[[145]],[[146]],[[147]],[[148]],[[149]],[[150]],[[151]],[[152]],[[153]]],"type":"MultiPolygon","properties":{"sovereignt":"United Kingdom","type":"Country","admin":"United Kingdom","name":"United Kingdom","name_long":"United Kingdom","formal_en":"United Kingdom of Great Britain and Northern Ireland","mapcolor7":6,"mapcolor8":6,"mapcolor9":6,"mapcolor13":3,"iso_a2":"GB","iso_a3":"GBR","iso_n3":"826","continent":"Europe"}},{"arcs":[[[154]],[[155]],[[156]],[[157]],[[158]],[[159,160,161]]],"type":"MultiPolygon","properties":{"sovereignt":"Sweden","type":"Sovereign country","admin":"Sweden","name":"Sweden","name_long":"Sweden","formal_en":"Kingdom of Sweden","mapcolor7":1,"mapcolor8":4,"mapcolor9":2,"mapcolor13":4,"iso_a2":"SE","iso_a3":"SWE","iso_n3":"752","continent":"Europe"}},{"arcs":[[162,163,164,165,166,167,168,169,-47]],"type":"Polygon","properties":{"sovereignt":"Slovenia","type":"Sovereign country","admin":"Slovenia","name":"Slovenia","name_long":"Slovenia","formal_en":"Republic of Slovenia","mapcolor7":2,"mapcolor8":3,"mapcolor9":2,"mapcolor13":12,"iso_a2":"SI","iso_a3":"SVN","iso_n3":"705","continent":"Europe"}},{"arcs":[[[170]],[[171]],[[172]],[[173]],[[174]]],"type":"MultiPolygon","properties":{"sovereignt":"Denmark","type":"Dependency","admin":"Faroe Islands","name":"Faeroe Is.","name_long":"Faeroe Islands","formal_en":"F?royar Is. (Faeroe Is.)","mapcolor7":4,"mapcolor8":1,"mapcolor9":3,"mapcolor13":12,"iso_a2":"FO","iso_a3":"FRO","iso_n3":"234","continent":"Europe"}},{"arcs":[[175,-49,176,177,178]],"type":"Polygon","properties":{"sovereignt":"Slovakia","type":"Sovereign country","admin":"Slovakia","name":"Slovakia","name_long":"Slovakia","formal_en":"Slovak Republic","mapcolor7":2,"mapcolor8":4,"mapcolor9":4,"mapcolor13":9,"iso_a2":"SK","iso_a3":"SVK","iso_n3":"703","continent":"Europe"}},{"arcs":[[[179]],[[180]],[[181]],[[182]],[[183]],[[184]],[[185]],[[186,187,188,189,-26,190,191,192,193,194,195]]],"type":"MultiPolygon","properties":{"sovereignt":"France","type":"Country","admin":"France","name":"France","name_long":"France","formal_en":"French Republic","mapcolor7":7,"mapcolor8":5,"mapcolor9":9,"mapcolor13":11,"iso_a2":"FR","iso_a3":"FRA","iso_n3":"250","continent":"Europe"}},{"arcs":[[196,197,198,199,200,201,202,203,204,-82,205,206,207]],"type":"Polygon","properties":{"sovereignt":"Republic of Serbia","type":"Sovereign country","admin":"Republic of Serbia","name":"Serbia","name_long":"Serbia","formal_en":"Republic of Serbia","mapcolor7":3,"mapcolor8":3,"mapcolor9":2,"mapcolor13":10,"iso_a2":"RS","iso_a3":"SRB","iso_n3":"688","continent":"Europe"}},{"arcs":[[[208]],[[209]],[[210]],[[211]],[[212]],[[213]],[[214]],[[215,216,-162,217]]],"type":"MultiPolygon","properties":{"sovereignt":"Finland","type":"Country","admin":"Finland","name":"Finland","name_long":"Finland","formal_en":"Republic of Finland","mapcolor7":4,"mapcolor8":1,"mapcolor9":4,"mapcolor13":6,"iso_a2":"FI","iso_a3":"FIN","iso_n3":"246","continent":"Europe"}},{"arcs":[[[218]],[[219]],[[220]],[[221,222,223,224,225]]],"type":"MultiPolygon","properties":{"sovereignt":"Estonia","type":"Sovereign country","admin":"Estonia","name":"Estonia","name_long":"Estonia","formal_en":"Republic of Estonia","mapcolor7":3,"mapcolor8":2,"mapcolor9":1,"mapcolor13":10,"iso_a2":"EE","iso_a3":"EST","iso_n3":"233","continent":"Europe"}},{"arcs":[[[226]],[[227]],[[228]],[[229]],[[230]],[[231]],[[232]],[[233]],[[234]],[[235]],[[236]],[[-194,237,-192,238,239,240]]],"type":"MultiPolygon","properties":{"sovereignt":"Spain","type":"Sovereign country","admin":"Spain","name":"Spain","name_long":"Spain","formal_en":"Kingdom of Spain","mapcolor7":4,"mapcolor8":5,"mapcolor9":5,"mapcolor13":5,"iso_a2":"ES","iso_a3":"ESP","iso_n3":"724","continent":"Europe"}},{"arcs":[[241]],"type":"Polygon","properties":{"sovereignt":"San Marino","type":"Sovereign country","admin":"San Marino","name":"San Marino","name_long":"San Marino","formal_en":"Republic of San Marino","mapcolor7":2,"mapcolor8":3,"mapcolor9":1,"mapcolor13":6,"iso_a2":"SM","iso_a3":"SMR","iso_n3":"674","continent":"Europe"}},{"arcs":[[[242]],[[243]],[[244]],[[245]],[[246]],[[247]],[[248]],[[249]],[[250]],[[251]],[[252]],[[253,254]]],"type":"MultiPolygon","properties":{"sovereignt":"Denmark","type":"Country","admin":"Denmark","name":"Denmark","name_long":"Denmark","formal_en":"Kingdom of Denmark","mapcolor7":4,"mapcolor8":1,"mapcolor9":3,"mapcolor13":12,"iso_a2":"DK","iso_a3":"DNK","iso_n3":"208","continent":"Europe"}},{"arcs":[[[255]],[[256]],[[257]],[[258]],[[259,260,261,262,263,264,265,266,267,-188,268,269,270,271,272,-254]],[[273]]],"type":"MultiPolygon","properties":{"sovereignt":"Germany","type":"Sovereign country","admin":"Germany","name":"Germany","name_long":"Germany","formal_en":"Federal Republic of Germany","mapcolor7":2,"mapcolor8":5,"mapcolor9":5,"mapcolor13":1,"iso_a2":"DE","iso_a3":"DEU","iso_n3":"276","continent":"Europe"}},{"arcs":[[274,-178,275,276,277,278,-262,279]],"type":"Polygon","properties":{"sovereignt":"Czech Republic","type":"Sovereign country","admin":"Czech Republic","name":"Czech Rep.","name_long":"Czech Republic","formal_en":"Czech Republic","mapcolor7":1,"mapcolor8":1,"mapcolor9":2,"mapcolor13":6,"iso_a2":"CZ","iso_a3":"CZE","iso_n3":"203","continent":"Europe"}},{"arcs":[[[280]],[[-5,281,-2,282]],[[283]]],"type":"MultiPolygon","properties":{"sovereignt":"Russia","type":"Sovereign country","admin":"Russia","name":"Russia","name_long":"Russian Federation","formal_en":"Russian Federation","mapcolor7":2,"mapcolor8":5,"mapcolor9":7,"mapcolor13":7,"iso_a2":"RU","iso_a3":"RUS","iso_n3":"643","continent":"Europe"}},{"arcs":[[284,285,286,287,288,-197,289,-43,290,291,292,293]],"type":"Polygon","properties":{"sovereignt":"Romania","type":"Sovereign country","admin":"Romania","name":"Romania","name_long":"Romania","formal_en":"Romania","mapcolor7":1,"mapcolor8":4,"mapcolor9":3,"mapcolor13":13,"iso_a2":"RO","iso_a3":"ROU","iso_n3":"642","continent":"Europe"}},{"arcs":[[[294]],[[295]],[[296]],[[297]],[[298]],[[299]],[[300]],[[301]],[[302,-240]]],"type":"MultiPolygon","properties":{"sovereignt":"Portugal","type":"Sovereign country","admin":"Portugal","name":"Portugal","name_long":"Portugal","formal_en":"Portuguese Republic","mapcolor7":1,"mapcolor8":7,"mapcolor9":1,"mapcolor13":4,"iso_a2":"PT","iso_a3":"PRT","iso_n3":"620","continent":"Europe"}},{"arcs":[[303,304,305,306,307,-179,-275,308,309]],"type":"Polygon","properties":{"sovereignt":"Poland","type":"Sovereign country","admin":"Poland","name":"Poland","name_long":"Poland","formal_en":"Republic of Poland","mapcolor7":3,"mapcolor8":7,"mapcolor9":1,"mapcolor13":2,"iso_a2":"PL","iso_a3":"POL","iso_n3":"616","continent":"Europe"}},{"arcs":[[310,-8,311,312,313,-29,314,315,316,317]],"type":"Polygon","properties":{"sovereignt":"Switzerland","type":"Sovereign country","admin":"Switzerland","name":"Switzerland","name_long":"Switzerland","formal_en":"Swiss Confederation","mapcolor7":5,"mapcolor8":2,"mapcolor9":7,"mapcolor13":3,"iso_a2":"CH","iso_a3":"CHE","iso_n3":"756","continent":"Europe"}},{"arcs":[[[318]],[[319]],[[320]],[[321]],[[322]],[[323]],[[324]],[[325]],[[326]],[[327]],[[328]],[[329]],[[330]],[[331]],[[332]],[[333]],[[334]],[[335]],[[336]],[[337]],[[338,-218,-161,339]],[[340]],[[341]],[[342]],[[343]],[[344]],[[345]],[[346]],[[347]],[[348]],[[349]],[[350]]],"type":"MultiPolygon","properties":{"sovereignt":"Norway","type":"Sovereign country","admin":"Norway","name":"Norway","name_long":"Norway","formal_en":"Kingdom of Norway","mapcolor7":5,"mapcolor8":3,"mapcolor9":8,"mapcolor13":12,"iso_a2":"NO","iso_a3":"NOR","iso_n3":"578","continent":"Europe"}},{"arcs":[[[351]],[[352]],[[353]],[[354,355]],[[356]],[[357]],[[358]],[[359,-272,360,361]],[[362]],[[363]],[[364]],[[365]]],"type":"MultiPolygon","properties":{"sovereignt":"Netherlands","type":"Country","admin":"Netherlands","name":"Netherlands","name_long":"Netherlands","formal_en":"Kingdom of the Netherlands","mapcolor7":4,"mapcolor8":2,"mapcolor9":2,"mapcolor13":9,"iso_a2":"NL","iso_a3":"NLD","iso_n3":"528","continent":"Europe"}},{"arcs":[[366,367,368,369,370,371,372,373,374,375,376,-304,377,378,379]],"type":"Polygon","properties":{"sovereignt":"Belarus","type":"Sovereign country","admin":"Belarus","name":"Belarus","name_long":"Belarus","formal_en":"Republic of Belarus","mapcolor7":1,"mapcolor8":1,"mapcolor9":5,"mapcolor13":11,"iso_a2":"BY","iso_a3":"BLR","iso_n3":"112","continent":"Europe"}},{"arcs":[[-205,380,381,-71,382,-83]],"type":"Polygon","properties":{"sovereignt":"Bosnia and Herzegovina","type":"Sovereign country","admin":"Bosnia and Herzegovina","name":"Bosnia and Herz.","name_long":"Bosnia and Herzegovina","formal_en":"Bosnia and Herzegovina","mapcolor7":1,"mapcolor8":1,"mapcolor9":1,"mapcolor13":2,"iso_a2":"BA","iso_a3":"BIH","iso_n3":"070","continent":"Europe"}},{"arcs":[[383,384,385,386,-287]],"type":"Polygon","properties":{"sovereignt":"Bulgaria","type":"Sovereign country","admin":"Bulgaria","name":"Bulgaria","name_long":"Bulgaria","formal_en":"Republic of Bulgaria","mapcolor7":4,"mapcolor8":5,"mapcolor9":1,"mapcolor13":8,"iso_a2":"BG","iso_a3":"BGR","iso_n3":"100","continent":"Europe"}},{"arcs":[[387,-271,388,-196,389,-355,-362]],"type":"Polygon","properties":{"sovereignt":"Belgium","type":"Sovereign country","admin":"Belgium","name":"Belgium","name_long":"Belgium","formal_en":"Kingdom of Belgium","mapcolor7":3,"mapcolor8":2,"mapcolor9":1,"mapcolor13":8,"iso_a2":"BE","iso_a3":"BEL","iso_n3":"056","continent":"Europe"}},{"arcs":[[-177,-48,-170,390,391,-312,-9,-311,392,-266,393,-276]],"type":"Polygon","properties":{"sovereignt":"Austria","type":"Sovereign country","admin":"Austria","name":"Austria","name_long":"Austria","formal_en":"Republic of Austria","mapcolor7":3,"mapcolor8":1,"mapcolor9":3,"mapcolor13":4,"iso_a2":"AT","iso_a3":"AUT","iso_n3":"040","continent":"Europe"}},{"arcs":[[394,395,-12,396,397,398,399]],"type":"Polygon","properties":{"sovereignt":"Montenegro","type":"Sovereign country","admin":"Montenegro","name":"Montenegro","name_long":"Montenegro","formal_en":"Montenegro","mapcolor7":4,"mapcolor8":1,"mapcolor9":4,"mapcolor13":5,"iso_a2":"ME","iso_a3":"MNE","iso_n3":"499","continent":"Europe"}},{"arcs":[[[400]],[[401]]],"type":"MultiPolygon","properties":{"sovereignt":"Malta","type":"Sovereign country","admin":"Malta","name":"Malta","name_long":"Malta","formal_en":"Republic of Malta","mapcolor7":1,"mapcolor8":4,"mapcolor9":1,"mapcolor13":8,"iso_a2":"MT","iso_a3":"MLT","iso_n3":"470","continent":"Europe"}},{"arcs":[[-385,402,403,-10,404,405]],"type":"Polygon","properties":{"sovereignt":"Macedonia","type":"Sovereign country","admin":"Macedonia","name":"Macedonia","name_long":"Macedonia","formal_en":"Former Yugoslav Republic of Macedonia","mapcolor7":5,"mapcolor8":3,"mapcolor9":7,"mapcolor13":3,"iso_a2":"MK","iso_a3":"MKD","iso_n3":"807","continent":"Europe"}},{"arcs":[[406]],"type":"Polygon","properties":{"sovereignt":"Andorra","type":"Sovereign country","admin":"Andorra","name":"Andorra","name_long":"Andorra","formal_en":"Principality of Andorra","mapcolor7":1,"mapcolor8":4,"mapcolor9":1,"mapcolor13":8,"iso_a2":"AD","iso_a3":"AND","iso_n3":"020","continent":"Europe"}},{"arcs":[[-294,407,408,409,410,411]],"type":"Polygon","properties":{"sovereignt":"Moldova","type":"Sovereign country","admin":"Moldova","name":"Moldova","name_long":"Moldova","formal_en":"Republic of Moldova","mapcolor7":3,"mapcolor8":5,"mapcolor9":4,"mapcolor13":12,"iso_a2":"MD","iso_a3":"MDA","iso_n3":"498","continent":"Europe"}},{"arcs":[[[412]],[[413]],[[414]]],"type":"MultiPolygon","properties":{"sovereignt":"Finland","type":"Country","admin":"Aland","name":"Aland","name_long":"Aland Islands","formal_en":"?land Islands","mapcolor7":4,"mapcolor8":1,"mapcolor9":4,"mapcolor13":6,"iso_a2":"AX","iso_a3":"ALA","iso_n3":"248","continent":"Europe"}},{"arcs":[[415]],"type":"Polygon","properties":{"sovereignt":"Monaco","type":"Sovereign country","admin":"Monaco","name":"Monaco","name_long":"Monaco","formal_en":"Principality of Monaco","mapcolor7":1,"mapcolor8":1,"mapcolor9":2,"mapcolor13":12,"iso_a2":"MC","iso_a3":"MCO","iso_n3":"492","continent":"Europe"}},{"arcs":[[-11,-404,416,417,418,419,420,-397]],"type":"Polygon","properties":{"sovereignt":"Albania","type":"Sovereign country","admin":"Albania","name":"Albania","name_long":"Albania","formal_en":"Republic of Albania","mapcolor7":1,"mapcolor8":4,"mapcolor9":1,"mapcolor13":6,"iso_a2":"AL","iso_a3":"ALB","iso_n3":"008","continent":"Europe"}},{"arcs":[[-380,421,422,423,424,425]],"type":"Polygon","properties":{"sovereignt":"Latvia","type":"Sovereign country","admin":"Latvia","name":"Latvia","name_long":"Latvia","formal_en":"Republic of Latvia","mapcolor7":4,"mapcolor8":7,"mapcolor9":6,"mapcolor13":13,"iso_a2":"LV","iso_a3":"LVA","iso_n3":"428","continent":"Europe"}},{"arcs":[[-68,426,427,428,429,430,431,432,-222,433,-216,-339,434]],"type":"Polygon","properties":{"sovereignt":"Russia2","type":"Sovereign country","admin":"Russia","name":"Russia","name_long":"Russian Federation","formal_en":"Russian Federation","mapcolor7":2,"mapcolor8":5,"mapcolor9":7,"mapcolor13":7,"iso_a2":"RU","iso_a3":"RUS","iso_n3":"643","continent":"Europe"}}]}},"crs":{"type":"name","properties":{"name":"urn:ogc:def:crs:OGC:1.3:CRS84"}}};
