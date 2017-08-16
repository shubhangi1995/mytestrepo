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

