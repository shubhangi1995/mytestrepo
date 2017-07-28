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
    urls: ['https://sg.geodatenzentrum.de/wmts_webatlasde_grau__100bb4b7-d715-8456-a79c-3aed1caab5c3?'],
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
