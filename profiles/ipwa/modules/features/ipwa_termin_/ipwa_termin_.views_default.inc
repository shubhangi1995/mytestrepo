<?php
/**
 * @file
 * ipwa_termin_.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ipwa_termin__views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'event_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'event calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = '- keine -';
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
    'field_themenzuweisung_tid' => array(
      'bef_format' => 'bef_links',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
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
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Kopfbereich: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[subheadline]

<a href="/termin">zur Listensicht</a>';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Feld: Inhalt: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['label'] = '';
  $handler->display->display_options['fields']['field_event_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_event_datum']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['delta_offset'] = '0';
  /* Feld: Inhalt: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'field_data_field_ort';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  /* Sort criterion: Inhalt: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'A-Z';
  /* Sort criterion: Inhalt: Datum -  start date (field_event_datum) */
  $handler->display->display_options['sorts']['field_event_datum_value']['id'] = 'field_event_datum_value';
  $handler->display->display_options['sorts']['field_event_datum_value']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['sorts']['field_event_datum_value']['field'] = 'field_event_datum_value';
  $handler->display->display_options['sorts']['field_event_datum_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_event_datum_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_event_datum_value']['expose']['label'] = 'Datum -  start date (field_event_datum)';
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'termin' => 'termin',
  );
  /* Filter criterion: Inhalt: Dieser Artikel gehört zu (field_themenzuweisung) */
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['id'] = 'field_themenzuweisung_tid';
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['field'] = 'field_themenzuweisung_tid';
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['value'] = array(
    1 => '1',
    11 => '11',
  );
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['expose']['operator_id'] = 'field_themenzuweisung_tid_op';
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['expose']['operator'] = 'field_themenzuweisung_tid_op';
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['expose']['identifier'] = 'field_themenzuweisung_tid';
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['vocabulary'] = 'themenzuweisung';
  $handler->display->display_options['filters']['field_themenzuweisung_tid']['hierarchy'] = 1;

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Termine';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
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
        'autosubmit' => 0,
      ),
    ),
    'term_node_tid_depth' => array(
      'bef_format' => 'bef_links',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'Alles anzeigen',
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
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['skip_empty_pages'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '0';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['colors']['legend'] = 'type';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[subheadline]
<div class="calendar-link">
<a href="/termine">zur Listensicht</a>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Feld: Inhalt: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['label'] = '';
  $handler->display->display_options['fields']['field_event_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_event_datum']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['delta_offset'] = '0';
  /* Feld: Inhalt: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'field_data_field_ort';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  /* Feld: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="#" id="trigger-[nid]" class="trigger">Icon-[field_event_datum]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Inhalt: Datum -  start date (field_event_datum) */
  $handler->display->display_options['sorts']['field_event_datum_value']['id'] = 'field_event_datum_value';
  $handler->display->display_options['sorts']['field_event_datum_value']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['sorts']['field_event_datum_value']['field'] = 'field_event_datum_value';
  $handler->display->display_options['sorts']['field_event_datum_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_event_datum_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_event_datum_value']['expose']['label'] = 'neueste zuerst';
  /* Sort criterion: Inhalt: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'A-Z';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Datum: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity_reset'] = 0;
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_datum.field_event_datum_value' => 'field_data_field_event_datum.field_event_datum_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'termin' => 'termin',
  );
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    1 => '1',
    11 => '11',
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
  /* Filter criterion: Inhalt: Datum - end date (field_event_datum:value2) */
  $handler->display->display_options['filters']['field_event_datum_value2']['id'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['filters']['field_event_datum_value2']['field'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_datum_value2']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'calendar';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Datum: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_datum.field_event_datum_value' => 'field_data_field_event_datum.field_event_datum_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-event-datum/week';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Datum: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_datum.field_event_datum_value' => 'field_data_field_event_datum.field_event_datum_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-event-datum/day';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['label'] = '';
  $handler->display->display_options['fields']['field_event_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_event_datum']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Datum: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_datum.field_event_datum_value' => 'field_data_field_event_datum.field_event_datum_value',
  );
  $handler->display->display_options['path'] = 'calendar-node-field-event-datum/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Datum: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_event_datum.field_event_datum_value' => 'field_data_field_event_datum.field_event_datum_value',
  );

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Datum: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_event_datum.field_event_datum_value' => 'field_data_field_event_datum.field_event_datum_value',
  );
  $translatables['event_calendar'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('- keine -'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Erweiterte Optionen'),
    t('Sort options'),
    t('[subheadline]

<a href="/termin">zur Listensicht</a>'),
    t('A-Z'),
    t('Datum -  start date (field_event_datum)'),
    t('Month'),
    t('Termine'),
    t('<keine>'),
    t('Alles anzeigen'),
    t('[subheadline]
<div class="calendar-link">
<a href="/termine">zur Listensicht</a>
</div>'),
    t('<a href="#" id="trigger-[nid]" class="trigger">Icon-[field_event_datum]</a>'),
    t('neueste zuerst'),
    t('Alle'),
    t('Week'),
    t('Day'),
    t('Year'),
    t('Block'),
    t('Upcoming'),
    t('Upcoming events block'),
  );
  $export['event_calendar'] = $view;

  $view = new view();
  $view->name = 'event_on_calendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Event On Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Event On Calendar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
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
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'termin' => 'termin',
  );

  /* Display: Event On Calendar */
  $handler = $view->new_display('block', 'Event On Calendar', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
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
    'term_node_tid_depth' => array(
      'bef_format' => 'bef_links',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_themenzuweisung']['separator'] = '';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['label'] = '';
  $handler->display->display_options['fields']['field_event_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_event_datum']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_datum']['separator'] = '';
  /* Feld: Inhalt: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'field_data_field_ort';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  /* Feld: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="row-container" id="trigger-[nid]">
	<div id="pop-up-[nid]" class="pop-up">
	  <div class="views-field views-field-field-themenzuweisung">        
		<div class="field-content">[field_themenzuweisung]</div>  
	  </div>  
	  <div class="views-field views-field-field-event-datum">        
		  <div class="field-content">[field_event_datum]</div>
	  </div>  
	  <div class="views-field views-field-title">
		<span class="field-content">[title]</span>  
	  </div>  
	  <div class="views-field views-field-field-ort">
		<div class="field-content">[field_ort]</div>
	  </div>
	</div>  
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Inhalt: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Inhalt: Datum -  start date (field_event_datum) */
  $handler->display->display_options['sorts']['field_event_datum_value']['id'] = 'field_event_datum_value';
  $handler->display->display_options['sorts']['field_event_datum_value']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['sorts']['field_event_datum_value']['field'] = 'field_event_datum_value';
  $handler->display->display_options['sorts']['field_event_datum_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'min' => '',
    'max' => '',
    'value' => '',
    'termin' => 'termin',
  );
  /* Filter criterion: Inhalt: Datum - end date (field_event_datum:value2) */
  $handler->display->display_options['filters']['field_event_datum_value2']['id'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['filters']['field_event_datum_value2']['field'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_datum_value2']['default_date'] = 'now';
  $translatables['event_on_calendar'] = array(
    t('Master'),
    t('Event On Calendar'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Erweiterte Optionen'),
    t('<div class="row-container" id="trigger-[nid]">
	<div id="pop-up-[nid]" class="pop-up">
	  <div class="views-field views-field-field-themenzuweisung">        
		<div class="field-content">[field_themenzuweisung]</div>  
	  </div>  
	  <div class="views-field views-field-field-event-datum">        
		  <div class="field-content">[field_event_datum]</div>
	  </div>  
	  <div class="views-field views-field-title">
		<span class="field-content">[title]</span>  
	  </div>  
	  <div class="views-field views-field-field-ort">
		<div class="field-content">[field_ort]</div>
	  </div>
	</div>  
</div>'),
  );
  $export['event_on_calendar'] = $view;

  $view = new view();
  $view->name = 'termin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Termin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Termine';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = '- keine -';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
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
      'bef_format' => 'default',
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
    'field_themenzuweisung_tid' => array(
      'bef_format' => 'bef_links',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
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
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Kopfbereich: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '[headline] 
';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Inhalt: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Sort criterion: Inhalt: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Inhalt: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'termin' => 'termin',
  );

  /* Display: Termine */
  $handler = $view->new_display('page', 'Termine', 'page');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
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
        'autosubmit' => 0,
      ),
    ),
    'term_node_tid_depth' => array(
      'bef_format' => 'bef_links',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_term_description' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'Alles anzeigen',
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_themenzuweisung']['separator'] = '';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
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
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_event_datum']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_event_datum']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_datum']['separator'] = '';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = '150';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'field_data_field_ort';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ort']['group_column'] = 'entity_id';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Inhalt: Datum -  start date (field_event_datum) */
  $handler->display->display_options['sorts']['field_event_datum_value']['id'] = 'field_event_datum_value';
  $handler->display->display_options['sorts']['field_event_datum_value']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['sorts']['field_event_datum_value']['field'] = 'field_event_datum_value';
  $handler->display->display_options['sorts']['field_event_datum_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_event_datum_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_event_datum_value']['expose']['label'] = 'neueste zuerst';
  /* Sort criterion: Inhalt: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'A-Z';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'termin' => 'termin',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Inhalt: Datum - end date (field_event_datum:value2) */
  $handler->display->display_options['filters']['field_event_datum_value2']['id'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['filters']['field_event_datum_value2']['field'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_datum_value2']['default_date'] = 'now';
  /* Filter criterion: Inhalt: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    1 => '1',
    11 => '11',
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
  $handler->display->display_options['path'] = 'termine';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['style_options']['cal_name'] = 'Termin Calander';
  $handler->display->display_options['style_options']['exclude_dtstamp'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'date_ical_fields';
  $handler->display->display_options['row_options']['date_field'] = 'field_event_datum';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['location_field'] = 'field_ort';
  $handler->display->display_options['row_options']['additional_settings'] = array(
    'skip_blank_dates' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_event_datum']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_datum']['alter']['text'] = '[field_event_datum]';
  $handler->display->display_options['fields']['field_event_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Feld: Inhalt: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'field_data_field_ort';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['path'] = 'calendar/ical/%/calendar.ics';
  $handler->display->display_options['displays'] = array(
    'block_1' => 'block_1',
    'default' => 0,
    'page' => 0,
  );

  /* Display: Calendar Block */
  $handler = $view->new_display('block', 'Calendar Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'in Kalender eintragen
';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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

  /* Display: Aktuelle Veranstaltungen */
  $handler = $view->new_display('block', 'Aktuelle Veranstaltungen', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Aktuelle Veranstaltungen';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="pane-title">Aktuelle Veranstaltungen</h2>';
  $handler->display->display_options['header']['area']['format'] = 'wysiwyg';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Fußbereich: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="link-outer-block">
	<div class="link-inner-block-1">
		<a href="/termine">Alle Termine</a>
	</div>	
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'wysiwyg';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['label'] = '';
  $handler->display->display_options['fields']['field_themenzuweisung']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_themenzuweisung']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_themenzuweisung']['separator'] = '';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
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
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_event_datum']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_event_datum']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_event_datum']['separator'] = '';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'field_data_field_ort';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Inhalt: Datum - end date (field_event_datum:value2) */
  $handler->display->display_options['sorts']['field_event_datum_value2']['id'] = 'field_event_datum_value2';
  $handler->display->display_options['sorts']['field_event_datum_value2']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['sorts']['field_event_datum_value2']['field'] = 'field_event_datum_value2';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'termin' => 'termin',
  );
  /* Filter criterion: Inhalt: Datum - end date (field_event_datum:value2) */
  $handler->display->display_options['filters']['field_event_datum_value2']['id'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['filters']['field_event_datum_value2']['field'] = 'field_event_datum_value2';
  $handler->display->display_options['filters']['field_event_datum_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_datum_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_event_datum_value2']['default_date'] = 'now';
  $translatables['termin'] = array(
    t('Master'),
    t('Termine'),
    t('more'),
    t('Apply'),
    t('Zurücksetzen'),
    t('- keine -'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Erweiterte Optionen'),
    t('Sort options'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('[headline] 
'),
    t('Dieser Artikel gehört zu'),
    t('Datum'),
    t('Alle'),
    t('<keine>'),
    t('Alles anzeigen'),
    t('neueste zuerst'),
    t('A-Z'),
    t('Feed'),
    t('[field_event_datum]'),
    t('Ort'),
    t('Calendar Block'),
    t('in Kalender eintragen
'),
    t('Aktuelle Veranstaltungen'),
    t('Sort by'),
    t('<h2 class="pane-title">Aktuelle Veranstaltungen</h2>'),
    t('<div class="link-outer-block">
	<div class="link-inner-block-1">
		<a href="/termine">Alle Termine</a>
	</div>	
</div>'),
  );
  $export['termin'] = $view;

  return $export;
}
