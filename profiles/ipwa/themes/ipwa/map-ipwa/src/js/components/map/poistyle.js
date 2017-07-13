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
