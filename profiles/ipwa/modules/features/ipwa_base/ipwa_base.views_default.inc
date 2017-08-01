<?php
/**
 * @file
 * ipwa_base.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ipwa_base_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'aktuelles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Aktuelles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aktuelles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
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
    'type' => array(
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
          'filter_rewrite_values' => 'Förderbekanntmachung|Förderbekanntmachungen
Nachricht|Nachrichten
Publikation|Publikationen',
        ),
      ),
    ),
    'term_node_tid_depth' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => 'Politik & Gesellschaft',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'term_node_tid_depth_1' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => 'Wirtschaft & Arbeit',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'term_node_tid_depth_2' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => 'Infos für Unternehmen',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'term_node_tid_depth_3' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 1,
        'is_secondary' => 0,
        'any_label' => 'Infos für Beschäftigte',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Kopfbereich: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>[headline] this needs to be carified, about its content</h2>';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  /* Feld: Inhalt: Dieses Projekt gehört zu  */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_themenzuweisung']['separator'] = '';
  /* Feld: Inhalt: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['label'] = '';
  $handler->display->display_options['fields']['field_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_datum']['group_column'] = 'entity_id';
  /* Sort criterion: Inhalt: Datum (field_datum) */
  $handler->display->display_options['sorts']['field_datum_value']['id'] = 'field_datum_value';
  $handler->display->display_options['sorts']['field_datum_value']['table'] = 'field_data_field_datum';
  $handler->display->display_options['sorts']['field_datum_value']['field'] = 'field_datum_value';
  $handler->display->display_options['sorts']['field_datum_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_datum_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_datum_value']['expose']['label'] = 'neueste zuerst';
  /* Sort criterion: Inhalt: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'A-Z';
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'f_rderbekanntmachung' => 'f_rderbekanntmachung',
    'nachricht' => 'nachricht',
    'publikation' => 'publikation',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    8 => '8',
    9 => '9',
    10 => '10',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'politik';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'themenzuweisung';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_1']['id'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['value'] = array(
    12 => '12',
    14 => '14',
    15 => '15',
    16 => '16',
    17 => '17',
    19 => '19',
    20 => '20',
    21 => '21',
    22 => '22',
    23 => '23',
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator_id'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['label'] = 'wirts';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['identifier'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['vocabulary'] = 'themenzuweisung';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['depth'] = '10';
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_2']['id'] = 'term_node_tid_depth_2';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['value'] = array(
    25 => '25',
    26 => '26',
    28 => '28',
    29 => '29',
    30 => '30',
    31 => '31',
    32 => '32',
    33 => '33',
  );
  $handler->display->display_options['filters']['term_node_tid_depth_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['operator_id'] = 'term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['label'] = 'info1';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['operator'] = 'term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['identifier'] = 'term_node_tid_depth_2';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_2']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['vocabulary'] = 'themenzuweisung';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_2']['depth'] = '10';
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_3']['id'] = 'term_node_tid_depth_3';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['value'] = array(
    35 => '35',
    36 => '36',
    38 => '38',
    39 => '39',
    40 => '40',
    41 => '41',
    42 => '42',
  );
  $handler->display->display_options['filters']['term_node_tid_depth_3']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['operator_id'] = 'term_node_tid_depth_3_op';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['label'] = 'info2';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['operator'] = 'term_node_tid_depth_3_op';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['identifier'] = 'term_node_tid_depth_3';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_3']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['vocabulary'] = 'themenzuweisung';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_3']['depth'] = '10';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Dieses Projekt gehört zu  */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_themenzuweisung']['separator'] = '';
  /* Feld: Inhalt: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['label'] = '';
  $handler->display->display_options['fields']['field_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_datum']['group_column'] = 'entity_id';
  /* Feld: Inhalt: Bis auf Weiteres */
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['id'] = 'field_bis_auf_weiteres';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['table'] = 'field_data_field_bis_auf_weiteres';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['field'] = 'field_bis_auf_weiteres';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['label'] = '';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['element_label_colon'] = FALSE;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_bis_auf_weiteres';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = '1';
  $handler->display->display_options['fields']['views_conditional']['then'] = 'Stichtag: Bis auf Weiteres';
  $handler->display->display_options['fields']['views_conditional']['or'] = 'Stichtag: [field_datum]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = 'Förderbekanntmachung';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[views_conditional]';
  $handler->display->display_options['fields']['views_conditional_1']['or'] = '[field_datum]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'f_rderbekanntmachung' => 'f_rderbekanntmachung',
    'nachricht' => 'nachricht',
    'publikation' => 'publikation',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'f_rderbekanntmachung' => 'f_rderbekanntmachung',
    'nachricht' => 'nachricht',
    'publikation' => 'publikation',
  );
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    8 => '8',
    9 => '9',
    10 => '10',
    1 => '1',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'themenzuweisung';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_1']['id'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['value'] = array(
    11 => '11',
    12 => '12',
    14 => '14',
    15 => '15',
    16 => '16',
    17 => '17',
    19 => '19',
    20 => '20',
    21 => '21',
    22 => '22',
    23 => '23',
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator_id'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['identifier'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['vocabulary'] = 'themenzuweisung';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['depth'] = '10';
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_2']['id'] = 'term_node_tid_depth_2';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['value'] = array(
    24 => '24',
    25 => '25',
    26 => '26',
    28 => '28',
    29 => '29',
    30 => '30',
    31 => '31',
    32 => '32',
    33 => '33',
  );
  $handler->display->display_options['filters']['term_node_tid_depth_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['operator_id'] = 'term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['operator'] = 'term_node_tid_depth_2_op';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['identifier'] = 'term_node_tid_depth_2';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth_2']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_2']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['vocabulary'] = 'themenzuweisung';
  $handler->display->display_options['filters']['term_node_tid_depth_2']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_2']['depth'] = '10';
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_3']['id'] = 'term_node_tid_depth_3';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['value'] = array(
    34 => '34',
    35 => '35',
    36 => '36',
    38 => '38',
    39 => '39',
    40 => '40',
    41 => '41',
    42 => '42',
  );
  $handler->display->display_options['filters']['term_node_tid_depth_3']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['operator_id'] = 'term_node_tid_depth_3_op';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['operator'] = 'term_node_tid_depth_3_op';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['identifier'] = 'term_node_tid_depth_3';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth_3']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_3']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['vocabulary'] = 'themenzuweisung';
  $handler->display->display_options['filters']['term_node_tid_depth_3']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_3']['depth'] = '10';
  $handler->display->display_options['path'] = 'aktuelles';
  $translatables['aktuelles'] = array(
    t('Master'),
    t('Aktuelles'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('<keine>'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Erweiterte Optionen'),
    t('Sort options'),
    t('Alles anzeigen'),
    t('Förderbekanntmachung|Förderbekanntmachungen
Nachricht|Nachrichten
Publikation|Publikationen'),
    t('Politik & Gesellschaft'),
    t('Wirtschaft & Arbeit'),
    t('Infos für Unternehmen'),
    t('Infos für Beschäftigte'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('<h2>[headline] this needs to be carified, about its content</h2>'),
    t('neueste zuerst'),
    t('A-Z'),
    t('politik'),
    t('wirts'),
    t('info1'),
    t('info2'),
    t('Page'),
  );
  $export['aktuelles'] = $view;

  $view = new view();
  $view->name = 'clone_of_administration_nodes';
  $view->description = 'Find and manage content.';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'Clone of Administration: Nodes';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Inhalt';
  $handler->display->display_options['css_class'] = 'admin-views-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'menu';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Suchen';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'timestamp' => 'title',
    'type' => 'type',
    'name' => 'name',
    'status' => 'status',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '&nbsp;',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Kein Inhalt verfügbar.';
  /* Relationship: Inhalt: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Inhalt: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'forums' => 0,
    'tags' => 0,
  );
  /* Feld: Bulk operations: Inhalt */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change author',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Stick',
      'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unstick',
      'postpone_processing' => 0,
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Promote to front page',
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish',
      'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Demote from front page',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish',
      'postpone_processing' => 0,
    ),
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Feld: Inhalt: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  /* Feld: Inhalt: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Autor';
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Feld: Inhalt: Veröffentlicht */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Publiziert';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Feld: Inhalt: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Aktualisiert';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Feld: Inhalt: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Bearbeitung';
  /* Feld: Inhalt: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  /* Filter criterion: Inhalt: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Inhaltstyp';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  /* Filter criterion: Benutzer: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Autor';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'author';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Publiziert';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Inhalt: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Akteurstyp';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'akteurstypen';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;

  /* Display: System */
  $handler = $view->new_display('system', 'System', 'system_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content';
  $translatables['clone_of_administration_nodes'] = array(
    t('Defaults'),
    t('Inhalt'),
    t('more'),
    t('Suchen'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Kein Inhalt verfügbar.'),
    t('author'),
    t('term'),
    t('- Choose an operation -'),
    t('Change author'),
    t('Delete'),
    t('Change value'),
    t('Stick'),
    t('Unstick'),
    t('Promote to front page'),
    t('Publish'),
    t('Demote from front page'),
    t('Unpublish'),
    t('Titel'),
    t('ID'),
    t('Typ'),
    t('Autor'),
    t('Publiziert'),
    t('Aktualisiert'),
    t('Bearbeitung'),
    t('Inhaltstyp'),
    t('Akteurstyp'),
    t('System'),
  );
  $export['clone_of_administration_nodes'] = $view;

  $view = new view();
  $view->name = 'neueste_digital_projekte';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Neueste Digital-Projekte';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Kopfbereich: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="pane-title">Neueste Digital-Projekte in NRW</h2>';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  /* Fußbereich: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a href ="/schaufenster-digitales-nrw">Karte öffnen</a>';
  /* Feld: Inhalt: Dieser Akteur gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_themenzuweisung']['separator'] = '';
  /* Feld: Inhalt: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Inhalt: Datum (field_datum) */
  $handler->display->display_options['sorts']['field_datum_value']['id'] = 'field_datum_value';
  $handler->display->display_options['sorts']['field_datum_value']['table'] = 'field_data_field_datum';
  $handler->display->display_options['sorts']['field_datum_value']['field'] = 'field_datum_value';
  $handler->display->display_options['sorts']['field_datum_value']['order'] = 'DESC';
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'projekt' => 'projekt',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Dieses Projekt gehört zu  */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_themenzuweisung']['separator'] = '';
  /* Feld: Inhalt: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $translatables['neueste_digital_projekte'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h2 class="pane-title">Neueste Digital-Projekte in NRW</h2>'),
    t('<a href ="/schaufenster-digitales-nrw">Karte öffnen</a>'),
    t('Block'),
  );
  $export['neueste_digital_projekte'] = $view;

  $view = new view();
  $view->name = 'neueste_informationen';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Neueste Informationen';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Neueste Informationen';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Kopfbereich: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="pane-title">Neueste Informationen</h2>';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Inhalt: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Neueste Informationen */
  $handler = $view->new_display('block', 'Neueste Informationen', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Fußbereich: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="link-outer-block">
	<div class="link-inner-block-1">
		<a href="/aktuelles">mehr Aktuelles</a>
	</div>
	<div class="link-inner-block-2">
		<a href="/alle-themen">Themenübersicht</a>
	</div>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'wysiwyg';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Dieses Projekt gehört zu  */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_themenzuweisung']['separator'] = '';
  /* Feld: Inhalt: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['table'] = 'field_data_field_datum';
  $handler->display->display_options['fields']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['fields']['field_datum']['label'] = '';
  $handler->display->display_options['fields']['field_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datum']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  /* Feld: Inhalt: Bis auf Weiteres */
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['id'] = 'field_bis_auf_weiteres';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['table'] = 'field_data_field_bis_auf_weiteres';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['field'] = 'field_bis_auf_weiteres';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['label'] = '';
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bis_auf_weiteres']['element_label_colon'] = FALSE;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_bis_auf_weiteres';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = '1';
  $handler->display->display_options['fields']['views_conditional']['then'] = 'Stichtag: Bis auf Weiteres';
  $handler->display->display_options['fields']['views_conditional']['or'] = 'Stichtag: [field_datum]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = 'Förderbekanntmachung';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[views_conditional]';
  $handler->display->display_options['fields']['views_conditional_1']['or'] = '[field_datum]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Inhalt: Datum (field_datum) */
  $handler->display->display_options['sorts']['field_datum_value']['id'] = 'field_datum_value';
  $handler->display->display_options['sorts']['field_datum_value']['table'] = 'field_data_field_datum';
  $handler->display->display_options['sorts']['field_datum_value']['field'] = 'field_datum_value';
  $handler->display->display_options['sorts']['field_datum_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'f_rderbekanntmachung' => 'f_rderbekanntmachung',
    'nachricht' => 'nachricht',
    'publikation' => 'publikation',
  );
  $translatables['neueste_informationen'] = array(
    t('Master'),
    t('Neueste Informationen'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<h2 class="pane-title">Neueste Informationen</h2>'),
    t('<div class="link-outer-block">
	<div class="link-inner-block-1">
		<a href="/aktuelles">mehr Aktuelles</a>
	</div>
	<div class="link-inner-block-2">
		<a href="/alle-themen">Themenübersicht</a>
	</div>
</div>'),
  );
  $export['neueste_informationen'] = $view;

  $view = new view();
  $view->name = 'project_single_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_ipwa_solr_index';
  $view->human_name = 'project single view json';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'project single view json';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Feld: Indexed Beitrag: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Feld: Indexed Beitrag: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = 'Taxonomy icon';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_themenzuweisung']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_themenzuweisung']['bypass_access'] = 0;
  /* Feld: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Feld: Indexed Beitrag: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Feld: Indexed Beitrag: Datum */
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
  /* Feld: Indexed Beitrag: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: Longitude */
  $handler->display->display_options['fields']['field_longitude']['id'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_longitude']['field'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['label'] = '';
  $handler->display->display_options['fields']['field_longitude']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: Latitude */
  $handler->display->display_options['fields']['field_latitude']['id'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_latitude']['field'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['label'] = '';
  $handler->display->display_options['fields']['field_latitude']['element_label_colon'] = FALSE;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Projekt';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_ort]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_datum]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Contextual filter: Indexed Beitrag: Node ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'protagonist' => 'protagonist',
    'projekt' => 'projekt',
  );
  /* Filter criterion: Indexed Beitrag: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Beitrag: Node ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['path'] = 'project-single-view56';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'latlon';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'field_latitude';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'field_longitude';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'nid';
  $handler->display->display_options['style_options']['data_source']['name_field'] = '';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Indexed Beitrag: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Feld: Indexed Beitrag: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['list']['separator'] = ',';
  $handler->display->display_options['fields']['field_themenzuweisung']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_themenzuweisung']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_themenzuweisung']['bypass_access'] = 0;
  /* Feld: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Feld: Indexed Beitrag: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Feld: Indexed Beitrag: Datum */
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
  /* Feld: Indexed Beitrag: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: Longitude */
  $handler->display->display_options['fields']['field_longitude']['id'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_longitude']['field'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['label'] = '';
  $handler->display->display_options['fields']['field_longitude']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: Latitude */
  $handler->display->display_options['fields']['field_latitude']['id'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_latitude']['field'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['label'] = '';
  $handler->display->display_options['fields']['field_latitude']['element_label_colon'] = FALSE;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Projekt';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_ort]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_datum]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Feld: Indexed Beitrag: PLZ */
  $handler->display->display_options['fields']['field_plz']['id'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_plz']['field'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['label'] = '';
  $handler->display->display_options['fields']['field_plz']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'project-single-view-json';
  $translatables['project_single_view'] = array(
    t('Master'),
    t('project single view json'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Node ID'),
    t('.'),
    t(','),
    t('Taxonomy icon'),
    t('Alle'),
    t('Page'),
    t('Feed'),
  );
  $export['project_single_view'] = $view;

  $view = new view();
  $view->name = 'projekt_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_ipwa_solr_index';
  $view->human_name = 'projekt_map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Suchen';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'alle Filtern Zurücksetzen';
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
        'autosubmit' => 0,
      ),
    ),
    'type' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'Alle',
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
    'field_akteurstyp' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'Akteur',
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
    'field_themenzuweisung_1' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'Themen',
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
    'field_plz' => array(
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '12';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Kopfbereich: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '<div class="map_node_count">
 @total
</div>';
  /* Feld: Indexed Beitrag: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Feld: Indexed Beitrag: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_themenzuweisung']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_themenzuweisung']['bypass_access'] = 0;
  /* Feld: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Feld: Indexed Beitrag: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Feld: Indexed Beitrag: Datum */
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
  /* Feld: Indexed Beitrag: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Akteur';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_datum]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_ort]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Feld: Indexed Beitrag: Longitude */
  $handler->display->display_options['fields']['field_longitude']['id'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_longitude']['field'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['label'] = '';
  $handler->display->display_options['fields']['field_longitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_longitude']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: Latitude */
  $handler->display->display_options['fields']['field_latitude']['id'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_latitude']['field'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['label'] = '';
  $handler->display->display_options['fields']['field_latitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_latitude']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: PLZ */
  $handler->display->display_options['fields']['field_plz']['id'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_plz']['field'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['label'] = '';
  $handler->display->display_options['fields']['field_plz']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_plz']['element_label_colon'] = FALSE;
  /* Filter criterion: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'protagonist' => 'protagonist',
    'projekt' => 'projekt',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Beitrag: Akteurstyp */
  $handler->display->display_options['filters']['field_akteurstyp']['id'] = 'field_akteurstyp';
  $handler->display->display_options['filters']['field_akteurstyp']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['field_akteurstyp']['field'] = 'field_akteurstyp';
  $handler->display->display_options['filters']['field_akteurstyp']['value'] = array();
  $handler->display->display_options['filters']['field_akteurstyp']['group'] = 1;
  $handler->display->display_options['filters']['field_akteurstyp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['operator_id'] = 'field_akteurstyp_op';
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['operator'] = 'field_akteurstyp_op';
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['identifier'] = 'field_akteurstyp';
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Beitrag: Dieser Artikel gehört zu */
  $handler->display->display_options['filters']['field_themenzuweisung_1']['id'] = 'field_themenzuweisung_1';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['value'] = array();
  $handler->display->display_options['filters']['field_themenzuweisung_1']['group'] = 1;
  $handler->display->display_options['filters']['field_themenzuweisung_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['operator_id'] = 'field_themenzuweisung_1_op';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['operator'] = 'field_themenzuweisung_1_op';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['identifier'] = 'field_themenzuweisung_1';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Beitrag: PLZ */
  $handler->display->display_options['filters']['field_plz']['id'] = 'field_plz';
  $handler->display->display_options['filters']['field_plz']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['field_plz']['field'] = 'field_plz';
  $handler->display->display_options['filters']['field_plz']['group'] = 1;
  $handler->display->display_options['filters']['field_plz']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_plz']['expose']['operator_id'] = 'field_plz_op';
  $handler->display->display_options['filters']['field_plz']['expose']['operator'] = 'field_plz_op';
  $handler->display->display_options['filters']['field_plz']['expose']['identifier'] = 'field_plz';
  $handler->display->display_options['filters']['field_plz']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Indexed Beitrag: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;

  /* Display: Project map */
  $handler = $view->new_display('page', 'Project map', 'project_map');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Beitrag: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'protagonist' => 'protagonist',
    'projekt' => 'projekt',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 1;
  /* Filter criterion: Indexed Beitrag: Akteurstyp */
  $handler->display->display_options['filters']['field_akteurstyp']['id'] = 'field_akteurstyp';
  $handler->display->display_options['filters']['field_akteurstyp']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['field_akteurstyp']['field'] = 'field_akteurstyp';
  $handler->display->display_options['filters']['field_akteurstyp']['value'] = array();
  $handler->display->display_options['filters']['field_akteurstyp']['group'] = 1;
  $handler->display->display_options['filters']['field_akteurstyp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['operator_id'] = 'field_akteurstyp_op';
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['operator'] = 'field_akteurstyp_op';
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['identifier'] = 'field_akteurstyp';
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'protagonist' => 'protagonist',
    'projekt' => 'projekt',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Indexed Beitrag: Dieser Artikel gehört zu */
  $handler->display->display_options['filters']['field_themenzuweisung_1']['id'] = 'field_themenzuweisung_1';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['value'] = array(
    11 => '11',
    20 => '20',
    17 => '17',
    19 => '19',
    15 => '15',
    12 => '12',
    23 => '23',
    22 => '22',
    21 => '21',
    14 => '14',
    16 => '16',
    1 => '1',
    47 => '47',
    2 => '2',
    8 => '8',
    5 => '5',
    4 => '4',
    6 => '6',
    10 => '10',
    7 => '7',
    9 => '9',
    3 => '3',
    34 => '34',
    38 => '38',
    41 => '41',
    42 => '42',
    40 => '40',
    35 => '35',
    36 => '36',
    39 => '39',
    24 => '24',
    33 => '33',
    30 => '30',
    31 => '31',
    26 => '26',
    29 => '29',
    25 => '25',
    28 => '28',
    32 => '32',
    27 => '27',
  );
  $handler->display->display_options['filters']['field_themenzuweisung_1']['group'] = 1;
  $handler->display->display_options['filters']['field_themenzuweisung_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['operator_id'] = 'field_themenzuweisung_1_op';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['operator'] = 'field_themenzuweisung_1_op';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['identifier'] = 'field_themenzuweisung_1';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Beitrag: PLZ */
  $handler->display->display_options['filters']['field_plz']['id'] = 'field_plz';
  $handler->display->display_options['filters']['field_plz']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['field_plz']['field'] = 'field_plz';
  $handler->display->display_options['filters']['field_plz']['group'] = 1;
  $handler->display->display_options['filters']['field_plz']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_plz']['expose']['operator_id'] = 'field_plz_op';
  $handler->display->display_options['filters']['field_plz']['expose']['operator'] = 'field_plz_op';
  $handler->display->display_options['filters']['field_plz']['expose']['identifier'] = 'field_plz';
  $handler->display->display_options['filters']['field_plz']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'projekt-map';

  /* Display: Project list */
  $handler = $view->new_display('page', 'Project list', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '15';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = ' @total';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Indexed Beitrag: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Feld: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Feld: Indexed Beitrag: Akteurstyp */
  $handler->display->display_options['fields']['field_akteurstyp']['id'] = 'field_akteurstyp';
  $handler->display->display_options['fields']['field_akteurstyp']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_akteurstyp']['field'] = 'field_akteurstyp';
  $handler->display->display_options['fields']['field_akteurstyp']['label'] = '';
  $handler->display->display_options['fields']['field_akteurstyp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_akteurstyp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_akteurstyp']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_akteurstyp']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_akteurstyp']['bypass_access'] = 0;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_1']['equalto'] = 'Projekt';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '[type]';
  $handler->display->display_options['fields']['views_conditional_1']['or'] = '[field_akteurstyp]';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  /* Feld: Indexed Beitrag: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Feld: Indexed Beitrag: Datum */
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
  /* Feld: Indexed Beitrag: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'Akteur';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[field_datum]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[field_ort]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Feld: Indexed Beitrag: Longitude */
  $handler->display->display_options['fields']['field_longitude']['id'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_longitude']['field'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['label'] = '';
  $handler->display->display_options['fields']['field_longitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_longitude']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: Latitude */
  $handler->display->display_options['fields']['field_latitude']['id'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_latitude']['field'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['label'] = '';
  $handler->display->display_options['fields']['field_latitude']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_latitude']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: PLZ */
  $handler->display->display_options['fields']['field_plz']['id'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_plz']['field'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['label'] = '';
  $handler->display->display_options['fields']['field_plz']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_plz']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Beitrag: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'A-Z';
  /* Sort criterion: Indexed Beitrag: Datum */
  $handler->display->display_options['sorts']['field_datum']['id'] = 'field_datum';
  $handler->display->display_options['sorts']['field_datum']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['sorts']['field_datum']['field'] = 'field_datum';
  $handler->display->display_options['sorts']['field_datum']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_datum']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_datum']['expose']['label'] = 'neueste zuerst';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'protagonist' => 'protagonist',
    'projekt' => 'projekt',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Indexed Beitrag: Inhaltstyp */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'protagonist' => 'protagonist',
    'projekt' => 'projekt',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Beitrag: Akteurstyp */
  $handler->display->display_options['filters']['field_akteurstyp']['id'] = 'field_akteurstyp';
  $handler->display->display_options['filters']['field_akteurstyp']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['field_akteurstyp']['field'] = 'field_akteurstyp';
  $handler->display->display_options['filters']['field_akteurstyp']['value'] = array();
  $handler->display->display_options['filters']['field_akteurstyp']['group'] = 1;
  $handler->display->display_options['filters']['field_akteurstyp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['operator_id'] = 'field_akteurstyp_op';
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['operator'] = 'field_akteurstyp_op';
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['identifier'] = 'field_akteurstyp';
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_akteurstyp']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Beitrag: Dieser Artikel gehört zu */
  $handler->display->display_options['filters']['field_themenzuweisung_1']['id'] = 'field_themenzuweisung_1';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['value'] = array();
  $handler->display->display_options['filters']['field_themenzuweisung_1']['group'] = 1;
  $handler->display->display_options['filters']['field_themenzuweisung_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['operator_id'] = 'field_themenzuweisung_1_op';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['operator'] = 'field_themenzuweisung_1_op';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['identifier'] = 'field_themenzuweisung_1';
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_themenzuweisung_1']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Beitrag: PLZ */
  $handler->display->display_options['filters']['field_plz']['id'] = 'field_plz';
  $handler->display->display_options['filters']['field_plz']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['field_plz']['field'] = 'field_plz';
  $handler->display->display_options['filters']['field_plz']['group'] = 1;
  $handler->display->display_options['filters']['field_plz']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_plz']['expose']['operator_id'] = 'field_plz_op';
  $handler->display->display_options['filters']['field_plz']['expose']['operator'] = 'field_plz_op';
  $handler->display->display_options['filters']['field_plz']['expose']['identifier'] = 'field_plz';
  $handler->display->display_options['filters']['field_plz']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Indexed Beitrag: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'projekt-list';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'project_map';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'latlon';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'field_latitude';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'field_longitude';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'nid';
  $handler->display->display_options['style_options']['data_source']['name_field'] = '';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['content_type'] = 'text/json';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Indexed Beitrag: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Feld: Indexed Beitrag: Longitude */
  $handler->display->display_options['fields']['field_longitude']['id'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_longitude']['field'] = 'field_longitude';
  /* Feld: Indexed Beitrag: Latitude */
  $handler->display->display_options['fields']['field_latitude']['id'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_latitude']['field'] = 'field_latitude';
  /* Feld: Indexed Beitrag: PLZ */
  $handler->display->display_options['fields']['field_plz']['id'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_plz']['field'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['label'] = '';
  $handler->display->display_options['fields']['field_plz']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['path'] = 'map-all';

  /* Display: Feed 2 */
  $handler = $view->new_display('feed', 'Feed 2', 'feed_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'latlon';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'field_latitude';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'field_longitude';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'nid';
  $handler->display->display_options['style_options']['data_source']['name_field'] = '';
  $handler->display->display_options['style_options']['data_source']['description_field'] = '';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Indexed Beitrag: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Feld: Indexed Beitrag: Longitude */
  $handler->display->display_options['fields']['field_longitude']['id'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_longitude']['field'] = 'field_longitude';
  $handler->display->display_options['fields']['field_longitude']['label'] = '';
  $handler->display->display_options['fields']['field_longitude']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: Latitude */
  $handler->display->display_options['fields']['field_latitude']['id'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_latitude']['field'] = 'field_latitude';
  $handler->display->display_options['fields']['field_latitude']['label'] = '';
  $handler->display->display_options['fields']['field_latitude']['element_label_colon'] = FALSE;
  /* Feld: Indexed Beitrag: PLZ */
  $handler->display->display_options['fields']['field_plz']['id'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['table'] = 'search_api_index_ipwa_solr_index';
  $handler->display->display_options['fields']['field_plz']['field'] = 'field_plz';
  $handler->display->display_options['fields']['field_plz']['label'] = '';
  $handler->display->display_options['fields']['field_plz']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'map-filter';
  $translatables['projekt_map'] = array(
    t('Master'),
    t('more'),
    t('Suchen'),
    t('alle Filtern Zurücksetzen'),
    t('<keine>'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Erweiterte Optionen'),
    t('Sort options'),
    t('Alle'),
    t('Akteur'),
    t('Themen'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('<div class="map_node_count">
 @total
</div>'),
    t('.'),
    t(','),
    t('Project map'),
    t('Project list'),
    t(' @total'),
    t('A-Z'),
    t('neueste zuerst'),
    t('Feed'),
    t('Node ID'),
    t('Longitude'),
    t('Latitude'),
    t('Feed 2'),
  );
  $export['projekt_map'] = $view;

  $view = new view();
  $view->name = 'related_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publikation';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: File Usage: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['id'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['table'] = 'field_data_field_dokumente_und_publikatione';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['field'] = 'field_dokumente_und_publikatione_target_id';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_publication_node']['id'] = 'reverse_field_publication_node';
  $handler->display->display_options['relationships']['reverse_field_publication_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_publication_node']['field'] = 'reverse_field_publication_node';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_publication_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Dokument */
  $handler->display->display_options['fields']['field_dokument']['id'] = 'field_dokument';
  $handler->display->display_options['fields']['field_dokument']['table'] = 'field_data_field_dokument';
  $handler->display->display_options['fields']['field_dokument']['field'] = 'field_dokument';
  $handler->display->display_options['fields']['field_dokument']['relationship'] = 'field_publication_target_id';
  $handler->display->display_options['fields']['field_dokument']['label'] = '';
  $handler->display->display_options['fields']['field_dokument']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dokument']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dokument']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_dokument']['type'] = 'file_url_plain';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_dokument]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Contextual filter: Inhalt: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Kommende Veranstaltungen */
  $handler = $view->new_display('block', 'Kommende Veranstaltungen', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Kommende Veranstaltungen';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_veranstaltungen_target_id']['id'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['relationships']['field_veranstaltungen_target_id']['table'] = 'field_data_field_veranstaltungen';
  $handler->display->display_options['relationships']['field_veranstaltungen_target_id']['field'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['relationships']['field_veranstaltungen_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['fields']['field_event_datum']['label'] = '';
  $handler->display->display_options['fields']['field_event_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_event_datum']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_datum']['separator'] = '';
  /* Feld: Inhalt: Pfad */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_event_datum]<a href="[path]">[title]</a>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'field_data_field_ort';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Datum - end date (field_event_datum:value2) */
  $handler->display->display_options['filters']['field_event_datum_value2']['id'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['filters']['field_event_datum_value2']['field'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['filters']['field_event_datum_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_datum_value2']['default_date'] = 'now';
  $handler->display->display_options['block_description'] = 'Kommende Veranstaltungen';

  /* Display: Dokumente und Publikationen */
  $handler = $view->new_display('block', 'Dokumente und Publikationen', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['id'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['table'] = 'field_data_field_dokumente_und_publikatione';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['field'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['required'] = TRUE;
  /* Relationship: File Usage: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Dokument */
  $handler->display->display_options['fields']['field_dokument']['id'] = 'field_dokument';
  $handler->display->display_options['fields']['field_dokument']['table'] = 'field_data_field_dokument';
  $handler->display->display_options['fields']['field_dokument']['field'] = 'field_dokument';
  $handler->display->display_options['fields']['field_dokument']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['fields']['field_dokument']['label'] = '';
  $handler->display->display_options['fields']['field_dokument']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dokument']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dokument']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_dokument']['type'] = 'file_url_plain';
  /* Feld: Inhalt: Typ */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '[field_dokument]';
  $handler->display->display_options['fields']['title_1']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'type';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional']['equalto'] = 'publikation';
  $handler->display->display_options['fields']['views_conditional']['then'] = '[title]';
  $handler->display->display_options['fields']['views_conditional']['or'] = '[title_1]';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Feld: Datei: Größe */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['filesize']['label'] = '';
  $handler->display->display_options['fields']['filesize']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filesize']['element_label_colon'] = FALSE;
  /* Feld: Datei: Extension */
  $handler->display->display_options['fields']['extension']['id'] = 'extension';
  $handler->display->display_options['fields']['extension']['table'] = 'file_managed';
  $handler->display->display_options['fields']['extension']['field'] = 'extension';
  $handler->display->display_options['fields']['extension']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['extension']['label'] = '';
  $handler->display->display_options['fields']['extension']['exclude'] = TRUE;
  $handler->display->display_options['fields']['extension']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['extension']['alter']['text'] = 'PDF';
  $handler->display->display_options['fields']['extension']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Datei ist nicht barrierefrei */
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['id'] = 'field_datei_ist_nicht_barrierefr';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['table'] = 'field_data_field_datei_ist_nicht_barrierefr';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['field'] = 'field_datei_ist_nicht_barrierefr';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['label'] = '';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['hide_alter_empty'] = FALSE;
  /* Feld: Views: Views Conditional */
  $handler->display->display_options['fields']['views_conditional_2']['id'] = 'views_conditional_2';
  $handler->display->display_options['fields']['views_conditional_2']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_2']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_2']['if'] = 'field_datei_ist_nicht_barrierefr';
  $handler->display->display_options['fields']['views_conditional_2']['condition'] = '1';
  $handler->display->display_options['fields']['views_conditional_2']['equalto'] = '1';
  $handler->display->display_options['fields']['views_conditional_2']['then'] = '[extension] [filesize], Datei ist nicht barrierefrei';
  $handler->display->display_options['fields']['views_conditional_2']['or'] = '[extension] [filesize]';
  $handler->display->display_options['fields']['views_conditional_2']['strip_tags'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['block_description'] = 'Dokumente und Publikationen';

  /* Display: publikation */
  $handler = $view->new_display('block', 'publikation', 'block_3');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: Datei */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_publikation_target_id']['id'] = 'field_publikation_target_id';
  $handler->display->display_options['relationships']['field_publikation_target_id']['table'] = 'field_data_field_publikation';
  $handler->display->display_options['relationships']['field_publikation_target_id']['field'] = 'field_publikation_target_id';
  $handler->display->display_options['relationships']['field_publikation_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_publikation_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Feld: Inhalt: Dokument */
  $handler->display->display_options['fields']['field_dokument']['id'] = 'field_dokument';
  $handler->display->display_options['fields']['field_dokument']['table'] = 'field_data_field_dokument';
  $handler->display->display_options['fields']['field_dokument']['field'] = 'field_dokument';
  $handler->display->display_options['fields']['field_dokument']['relationship'] = 'field_publikation_target_id';
  $handler->display->display_options['fields']['field_dokument']['label'] = '';
  $handler->display->display_options['fields']['field_dokument']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dokument']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dokument']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_dokument']['type'] = 'file_url_plain';
  /* Feld: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Downloaden';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[field_dokument]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_publication_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['block_description'] = 'publikation';
  $translatables['related_content'] = array(
    t('Master'),
    t('Publikation'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Datei'),
    t('Inhalt entity referenced from field_dokumente_und_publikatione'),
    t('reverse_field_publication_node'),
    t('Alle'),
    t('Kommende Veranstaltungen'),
    t('Inhalt entity referenced from field_veranstaltungen'),
    t('[field_event_datum]<a href="[path]">[title]</a>'),
    t('Dokumente und Publikationen'),
    t('PDF'),
    t('publikation'),
    t('Inhalt entity referenced from field_publikation'),
    t('Downloaden'),
  );
  $export['related_content'] = $view;

  $view = new view();
  $view->name = 'rss';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Rss';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Rss';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Inhalt: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'footer_blocks';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'f_rderbekanntmachung' => 'f_rderbekanntmachung',
    'nachricht' => 'nachricht',
    'publikation' => 'publikation',
  );
  $handler->display->display_options['path'] = 'rss-feed';
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
    'page' => 0,
  );

  /* Display: RSS Block */
  $handler = $view->new_display('block', 'RSS Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $translatables['rss'] = array(
    t('Master'),
    t('Rss'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Feed'),
    t('RSS Block'),
  );
  $export['rss'] = $view;

  $view = new view();
  $view->name = 'themenzuweisung_flyouts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Themenzuweisung Flyouts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Infos für Unternehmen';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Kopfbereich: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Themen im fokus';
  $handler->display->display_options['header']['area']['content'] = 'Themen im Fokus';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  /* Feld: Taxonomie-Begriff: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Taxonomie-Begriff: Gewichtung */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'themenzuweisung' => 'themenzuweisung',
  );
  /* Filter criterion: Taxonomie-Begriff: Übergeordneter Begriff */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '34';

  /* Display: Politik & Gesellschaft right view */
  $handler = $view->new_display('block', 'Politik & Gesellschaft right view', 'block');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomie-Begriff: Gewichtung */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'themenzuweisung' => 'themenzuweisung',
  );
  /* Filter criterion: Taxonomie-Begriff: Übergeordneter Begriff */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '1';

  /* Display: Wirtschaft & Arbeit right view */
  $handler = $view->new_display('block', 'Wirtschaft & Arbeit right view', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'themenzuweisung' => 'themenzuweisung',
  );
  /* Filter criterion: Taxonomie-Begriff: Übergeordneter Begriff */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '11';

  /* Display: Infos für Unternehmen right view */
  $handler = $view->new_display('block', 'Infos für Unternehmen right view', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'themenzuweisung' => 'themenzuweisung',
  );
  /* Filter criterion: Taxonomie-Begriff: Übergeordneter Begriff */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '24';

  /* Display: Infos für Beschäftigte */
  $handler = $view->new_display('block', 'Infos für Beschäftigte', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomie-Vokabular: Systemname */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'themenzuweisung' => 'themenzuweisung',
  );
  /* Filter criterion: Taxonomie-Begriff: Übergeordneter Begriff */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '34';
  $translatables['themenzuweisung_flyouts'] = array(
    t('Master'),
    t('Infos für Unternehmen'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Themen im fokus'),
    t('Themen im Fokus'),
    t('Politik & Gesellschaft right view'),
    t('Wirtschaft & Arbeit right view'),
    t('Infos für Unternehmen right view'),
    t('Infos für Beschäftigte'),
  );
  $export['themenzuweisung_flyouts'] = $view;

  return $export;
}
