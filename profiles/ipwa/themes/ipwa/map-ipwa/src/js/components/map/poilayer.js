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
        console.log(data);
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

