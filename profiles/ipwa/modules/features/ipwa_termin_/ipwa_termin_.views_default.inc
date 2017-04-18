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
  $handler->display->display_options['title'] = 'Termin';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Dieser Artikel gehört zu */
  $handler->display->display_options['fields']['field_themenzuweisung']['id'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['table'] = 'field_data_field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['field'] = 'field_themenzuweisung';
  $handler->display->display_options['fields']['field_themenzuweisung']['delta_offset'] = '0';
  /* Field: Content: Datum */
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'termin' => 'termin',
  );

  /* Display: Termin */
  $handler = $view->new_display('page', 'Termin', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Datum */
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
  /* Field: Content: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'field_data_field_ort';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'termin';

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
  /* Field: Content: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Datum */
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
  /* Field: Content: Ort */
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'in kalender eintragen';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $translatables['termin'] = array(
    t('Master'),
    t('Termin'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Dieser Artikel gehört zu'),
    t('Datum'),
    t('All'),
    t('Ort'),
    t('Feed'),
    t('[field_event_datum]'),
    t('Calendar Block'),
    t('in kalender eintragen'),
  );
  $export['termin'] = $view;

  return $export;
}
