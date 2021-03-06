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
  if (jQuery('#footer_map').length > 0) {
    IPWA_MAP.Map.mapView.init();

    // the filter will be called from html in views-view--json-map.tpl.php
    IPWA_MAP.filter.connectFilterToMap();
  }
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

      // Initialization
      _str = IPWA_MAP.filter.buildStrParameters();
      IPWA_MAP.Map.poiLayer.updateData(_str, _btn);
    }
  },

  buildStrParameters: function () {
    var _form = jQuery('#views-exposed-form-projekt-map-project-map');
    var _editType = _form.find('#edit-type');
    // console.log('_editType:  =====>>> ', _editType, _editType.val());
    var _filter = [_editType, // Inhaltstyp (Akteur or Projekt)
      _form.find('#edit-search-api-aggregation-2'), // text to search
      _form.find('#edit-field-themenzuweisung-1') // Alle Themen
    ];
    if (_editType.val() === 'protagonist') {
      _filter.push(_form.find('#edit-field-akteurstyp')); // Dieser Artikel gehört zu
    }

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
