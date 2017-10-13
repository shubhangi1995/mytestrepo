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

    var _center = ol.proj.fromLonLat([this.conf.initialExtent.center.lon, this.conf.initialExtent.center.lat],
      this.conf.projection);

    this.map = new ol.Map({
      target: 'footer_map',
      controls: [],
      interactions: [],
      view: new ol.View({
        projection: projection,
        center: _center,
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

    IPWA_MAP.Map.poiLayer.init(this.map, this.conf.projection, this.conf.detailInitialExtent.zoom,
      _center);
    IPWA_MAP.Map.poiStyle.init();
    IPWA_MAP.Map.poiLayer.setStyle(function (cluster, resolution) {
      return IPWA_MAP.Map.poiStyle.styleFunction(cluster, resolution);
    });

    var markerLabel = '';
    IPWA_MAP.Map.popup.init(this.map, markerLabel, this.conf.maxZoom);

    var _this = this;
    this.map.on('pointermove', function (evt) {
      console.log('halli hallo!!!!');
      _this.map.getTargetElement().style.cursor =
          _this.map.hasFeatureAtPixel(evt.pixel) ? 'pointer' : '';
    });
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

