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
  isDetailMap: false,
  CLUSTER_COLOR: 'rgba(0, 69, 120, 1)',  // #004578 blue for circle
  CLUSTER_EXT_COLOR: 'rgba(0, 69, 120, 0.5)',
  CLUSTER_BORDER_WIDTH: 14,
  URL_ICON: '/profiles/ipwa/themes/ipwa/map-ipwa/dist/img/',
  URL_DETAIL_ICON: '/profiles/ipwa/themes/ipwa/map-ipwa/dist/img/',
  imgSrc: '',

  init: function (isDetailMap) {},

  styleFunction: function (cluster, resolution) {
    var size = cluster.get('features').length;
    var style = null;

    if (size > 1) {
      style = this.styleCacheCluster[size];
      if (!style) {
        style = this.getClusterStyle(size);
        this.styleCacheCluster[size] = style;
      }
    } else {
      var _type = 'notSelected';
      var _f = cluster.get('features')[0];
      if (_f.get('type') === 'selected') {
        _type = 'selected';
        style = this.styleCacheFeature[_type];
        if (!style) {
          style = this.getSelSingleStyle(_type);
          this.styleCacheFeature[_type] = style;
        }
      } else {
        style = this.styleCacheFeature[_type];
        if (!style) {
          style = this.getSingleStyle(_type);
          this.styleCacheFeature[_type] = style;
        }
      }
    }
    return style;
  },

  getSingleStyle: function () {
    var _image = null;
    var _icon = this.URL_ICON+'poi.png';
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
    var _icon = this.isDetailMap?this.URL_ICON+'poi.png':this.URL_ICON+'selPoi.png';
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
  getClusterStyle: function (size) {
    var style = [];
    var fontDim = 14 + (Math.sqrt(size) * 0.65);
    var radius = 12 + (Math.sqrt(size) * 1.3);
    style = [new ol.style.Style({
      image: new ol.style.Circle({
        radius: radius,
        stroke: new ol.style.Stroke({
          color: this.CLUSTER_EXT_COLOR,
          width: this.CLUSTER_BORDER_WIDTH
        }),
        fill: new ol.style.Fill({
          color: this.CLUSTER_COLOR
        })
      }),
      text: new ol.style.Text({
        font: 'normal ' + fontDim + 'px AleoBold, Arial, helvetica, sans-serif',
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
