<?php
/**
 * @file
 * ipwa_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ipwa_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_ipwa_solr_index';
  $view->human_name = 'Search List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Solr Test';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Indexed Beitrag: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';

  /* Display: Search */
  $handler = $view->new_display('page', 'Search', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Suche';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Suchen';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = '<keine>';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'wysiwyg',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Erweiterte Optionen',
      'secondary_collapse_override' => '0',
    ),
    'sort' => array(
      'bef_format' => 'bef_links',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 1,
      ),
    ),
    'search_api_views_fulltext' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_ort' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'type_1' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => 'Alles anzeigen',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => 'Article|Artikel
Nachricht|Nachrichten
Publikation|Publikationen
Termin|Termine
Förderbekanntmachung|Förderbekanntmachungen
Projekt|Projekte
Akteur|Akteure
Document|Dokumente',
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = ' ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Beitrag: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed Beitrag: Content type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = '';
  $handler->display->display_options['fields']['type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type_1']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type_1']['format_name'] = 0;
  /* Field: Indexed Beitrag: Dokument */
  $handler->display->display_options['fields']['field_dokument']['id'] = 'field_dokument';
  $handler->display->display_options['fields']['field_dokument']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_dokument']['field'] = 'field_dokument';
  $handler->display->display_options['fields']['field_dokument']['label'] = '';
  $handler->display->display_options['fields']['field_dokument']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dokument']['alter']['path'] = '[field_dokument]';
  $handler->display->display_options['fields']['field_dokument']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_dokument']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['field_dokument']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_dokument']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dokument']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_dokument']['type'] = 'file_url_plain';
  /* Field: Indexed Beitrag: Datum */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['label'] = '';
  $handler->display->display_options['fields']['field_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Beitrag: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[title]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Beitrag: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_dokument]';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_9']['id'] = 'views_conditional_9';
  $handler->display->display_options['fields']['views_conditional_9']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_9']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_9']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_9']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_9']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_9']['if'] = 'type_1';
  $handler->display->display_options['fields']['views_conditional_9']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_9']['equalto'] = 'document';
  $handler->display->display_options['fields']['views_conditional_9']['then'] = '[title_1]';
  $handler->display->display_options['fields']['views_conditional_9']['or'] = '[title]';
  $handler->display->display_options['fields']['views_conditional_9']['strip_tags'] = 0;
  /* Field: Indexed Beitrag: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  /* Field: Indexed Beitrag: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['label'] = '';
  $handler->display->display_options['fields']['field_event_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_event_datum']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_datum']['delta_first_last'] = TRUE;
  $handler->display->display_options['fields']['field_event_datum']['separator'] = '';
  /* Field: Indexed Beitrag: Bis auf Weiteres */
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['id'] = 'field_bis_auf_weiteres';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['field'] = 'field_bis_auf_weiteres';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['label'] = '';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['element_label_colon'] = FALSE;
  /* Field: Indexed Beitrag: Datum */
  $handler->display->display_options['fields']['field_datum_1']['id'] = 'field_datum_1';
  $handler->display->display_options['fields']['field_datum_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_datum_1']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum_1']['label'] = '';
  $handler->display->display_options['fields']['field_datum_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datum_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum_1']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Beitrag: Akteurstyp */
  $handler->display->display_options['fields']['field_akteurstyp']['id'] = 'field_akteurstyp';
  $handler->display->display_options['fields']['field_akteurstyp']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_akteurstyp']['field'] = 'field_akteurstyp';
  $handler->display->display_options['fields']['field_akteurstyp']['label'] = '';
  $handler->display->display_options['fields']['field_akteurstyp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_akteurstyp']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_akteurstyp']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_akteurstyp']['bypass_access'] = 0;
  /* Field: Indexed Beitrag: Herausgeber */
  $handler->display->display_options['fields']['field_herausgeber']['id'] = 'field_herausgeber';
  $handler->display->display_options['fields']['field_herausgeber']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_herausgeber']['field'] = 'field_herausgeber';
  $handler->display->display_options['fields']['field_herausgeber']['label'] = '';
  $handler->display->display_options['fields']['field_herausgeber']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_herausgeber']['alter']['text'] = 'Herausgeber: [field_herausgeber]';
  $handler->display->display_options['fields']['field_herausgeber']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: Stichtag */
  $handler->display->display_options['fields']['field_stichtag_1']['id'] = 'field_stichtag_1';
  $handler->display->display_options['fields']['field_stichtag_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_stichtag_1']['field'] = 'field_stichtag';
  $handler->display->display_options['fields']['field_stichtag_1']['label'] = '';
  $handler->display->display_options['fields']['field_stichtag_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_stichtag_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stichtag_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
    'addtocalendar_show' => 0,
    'addtocalendar_settings' => array(
      'style' => 'blue',
      'atc_title' => array(
        'field' => 'token',
        'tokenized' => '',
      ),
      'atc_description' => array(
        'field' => 'token',
        'tokenized' => '',
      ),
      'atc_location' => array(
        'field' => 'token',
        'tokenized' => '',
      ),
      'atc_organizer' => array(
        'field' => 'token',
        'tokenized' => '',
      ),
      'atc_organizer_email' => array(
        'field' => 'token',
        'tokenized' => '',
      ),
      'atc_date_end' => array(
        'field' => 'token',
        'tokenized' => '',
      ),
      'atc_privacy' => 'public',
      'data_secure' => 'auto',
      'data_calendars' => array(
        'iCalendar' => 0,
        'Google Calendar' => 0,
        'Outlook' => 0,
        'Outlook Online' => 0,
        'Yahoo! Calendar' => 0,
      ),
    ),
  );
  /* Feld: Indexed Beitrag: Veröffentlichungsdatum */
  $handler->display->display_options['fields']['field_ver_ffentlichungsdatum']['id'] = 'field_ver_ffentlichungsdatum';
  $handler->display->display_options['fields']['field_ver_ffentlichungsdatum']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_ver_ffentlichungsdatum']['field'] = 'field_ver_ffentlichungsdatum';
  $handler->display->display_options['fields']['field_ver_ffentlichungsdatum']['label'] = '';
  $handler->display->display_options['fields']['field_ver_ffentlichungsdatum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ver_ffentlichungsdatum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_6']['id'] = 'views_conditional_6';
  $handler->display->display_options['fields']['views_conditional_6']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_6']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_6']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_6']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_6']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_6']['if'] = 'field_bis_auf_weiteres';
  $handler->display->display_options['fields']['views_conditional_6']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_6']['equalto'] = '1';
  $handler->display->display_options['fields']['views_conditional_6']['then'] = 'Bis auf Weiteres';
  $handler->display->display_options['fields']['views_conditional_6']['or'] = '[field_stichtag_1]';
  $handler->display->display_options['fields']['views_conditional_6']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_7']['id'] = 'views_conditional_7';
  $handler->display->display_options['fields']['views_conditional_7']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_7']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_7']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_7']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_7']['if'] = 'type_1';
  $handler->display->display_options['fields']['views_conditional_7']['condition'] = '7';
  $handler->display->display_options['fields']['views_conditional_7']['equalto'] = 'nachricht';
  $handler->display->display_options['fields']['views_conditional_7']['then'] = '[field_datum]';
  $handler->display->display_options['fields']['views_conditional_7']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'nachricht';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[type] [title] [views_conditional_7]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = 'projekt';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[type] [title] [field_ort]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_2']['id'] = 'views_conditional_2';
  $handler->display->display_options['fields']['views_conditional_2']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_2']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_2']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_2']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_2']['equalto'] = 'f_rderbekanntmachung';
  $handler->display->display_options['fields']['views_conditional_2']['then'] = '[type] [title] [views_conditional_6]';
  $handler->display->display_options['fields']['views_conditional_2']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_3']['id'] = 'views_conditional_3';
  $handler->display->display_options['fields']['views_conditional_3']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_3']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_3']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_3']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_3']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_3']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_3']['equalto'] = 'publikation';
  $handler->display->display_options['fields']['views_conditional_3']['then'] = '[type] [title] [field_herausgeber] [field_ver_ffentlichungsdatum]';
  $handler->display->display_options['fields']['views_conditional_3']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_4']['id'] = 'views_conditional_4';
  $handler->display->display_options['fields']['views_conditional_4']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_4']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_4']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_4']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_4']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_4']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_4']['equalto'] = 'termin';
  $handler->display->display_options['fields']['views_conditional_4']['then'] = '[type] [title] [field_event_datum] [field_ort]';
  $handler->display->display_options['fields']['views_conditional_4']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_5']['id'] = 'views_conditional_5';
  $handler->display->display_options['fields']['views_conditional_5']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_5']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_5']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_5']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_5']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_5']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_5']['equalto'] = 'protagonist';
  $handler->display->display_options['fields']['views_conditional_5']['then'] = '[type] [title] [field_akteurstyp]';
  $handler->display->display_options['fields']['views_conditional_5']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_8']['id'] = 'views_conditional_8';
  $handler->display->display_options['fields']['views_conditional_8']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_8']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_8']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_8']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_8']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_8']['if'] = 'views_conditional_6';
  $handler->display->display_options['fields']['views_conditional_8']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional_8']['then'] = 'Stichtag: [views_conditional_6]';
  $handler->display->display_options['fields']['views_conditional_8']['strip_tags'] = 0;
  /* Field: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_10']['id'] = 'views_conditional_10';
  $handler->display->display_options['fields']['views_conditional_10']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_10']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_10']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_10']['element_class'] = 'search-condition';
  $handler->display->display_options['fields']['views_conditional_10']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_10']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_10']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_10']['equalto'] = 'Förderbekanntmachung';
  $handler->display->display_options['fields']['views_conditional_10']['then'] = '[views_conditional_8]';
  $handler->display->display_options['fields']['views_conditional_10']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Beitrag: Datum */
  $handler->display->display_options['sorts']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['sorts']['field_datum']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['sorts']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['sorts']['field_datum']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_datum']['expose']['label'] = 'Neueste zuerst';
  /* Sort criterion: Indexed Beitrag: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'A-Z';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Indexed Beitrag: combinational filter */
  $handler->display->display_options['filters']['search_api_aggregation_2']['id'] = 'search_api_aggregation_2';
  $handler->display->display_options['filters']['search_api_aggregation_2']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['search_api_aggregation_2']['field'] = 'search_api_aggregation_2';
  $handler->display->display_options['filters']['search_api_aggregation_2']['group'] = 1;
  $handler->display->display_options['filters']['search_api_aggregation_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_aggregation_2']['expose']['operator_id'] = 'search_api_aggregation_2_op';
  $handler->display->display_options['filters']['search_api_aggregation_2']['expose']['operator'] = 'search_api_aggregation_2_op';
  $handler->display->display_options['filters']['search_api_aggregation_2']['expose']['identifier'] = 'search_api_aggregation_2';
  $handler->display->display_options['filters']['search_api_aggregation_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Indexed Beitrag: Content type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'protagonist' => 'protagonist',
    'f_rderbekanntmachung' => 'f_rderbekanntmachung',
    'nachricht' => 'nachricht',
    'projekt' => 'projekt',
    'publikation' => 'publikation',
    'termin' => 'termin',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = 1;
  /* Filter criterion: Indexed Beitrag: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'protagonist' => 'protagonist',
    'article' => 'article',
    'document' => 'document',
    'f_rderbekanntmachung' => 'f_rderbekanntmachung',
    'nachricht' => 'nachricht',
    'projekt' => 'projekt',
    'publikation' => 'publikation',
    'termin' => 'termin',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Beitrag: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'suche';
  $translatables['search_list'] = array(
    t('Master'),
    t('Solr Test'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Node ID'),
    t('.'),
    t(','),
    t('Search'),
    t('Suche'),
    t('Suchen'),
    t('<keine>'),
    t('Select any filter and click on Apply to see results'),
    t('Erweiterte Optionen'),
    t('Sort options'),
    t('Alles anzeigen'),
    t('Article|Artikel
Nachricht|Nachrichten
Publikation|Publikationen
Termin|Termine
Förderbekanntmachung|Förderbekanntmachungen
Projekt|Projekte
Akteur|Akteure
Document|Dokumente'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹'),
    t(' ›'),
    t('letzte Seite »'),
    t('Herausgeber: [field_herausgeber]'),
    t('Neueste zuerst'),
    t('A-Z'),
  );
  $export['search_list'] = $view;

  return $export;
}
