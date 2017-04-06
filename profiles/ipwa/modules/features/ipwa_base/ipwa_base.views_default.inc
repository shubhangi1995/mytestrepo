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
  $handler->display->display_options['title'] = 'Dokumente und Publikationen';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['id'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['table'] = 'field_data_field_dokumente_und_publikatione';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['field'] = 'field_dokumente_und_publikatione_target_id';
  /* Field: Content: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Kommende Veranstaltungen */
  $handler = $view->new_display('block', 'Kommende Veranstaltungen', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Kommende Veranstaltungen';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_veranstaltungen_target_id']['id'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['relationships']['field_veranstaltungen_target_id']['table'] = 'field_data_field_veranstaltungen';
  $handler->display->display_options['relationships']['field_veranstaltungen_target_id']['field'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['relationships']['field_veranstaltungen_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Datum */
  $handler->display->display_options['fields']['field_event_datum']['id'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['table'] = 'field_data_field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['field'] = 'field_event_datum';
  $handler->display->display_options['fields']['field_event_datum']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['fields']['field_event_datum']['label'] = '';
  $handler->display->display_options['fields']['field_event_datum']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_datum']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Ort */
  $handler->display->display_options['fields']['field_ort']['id'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['table'] = 'field_data_field_ort';
  $handler->display->display_options['fields']['field_ort']['field'] = 'field_ort';
  $handler->display->display_options['fields']['field_ort']['relationship'] = 'field_veranstaltungen_target_id';
  $handler->display->display_options['fields']['field_ort']['label'] = '';
  $handler->display->display_options['fields']['field_ort']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Kommende Veranstaltungen';

  /* Display: Dokumente und Publikationen */
  $handler = $view->new_display('block', 'Dokumente und Publikationen', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['id'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['table'] = 'field_data_field_dokumente_und_publikatione';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['field'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['relationships']['field_dokumente_und_publikatione_target_id']['required'] = TRUE;
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: File: Extension */
  $handler->display->display_options['fields']['extension']['id'] = 'extension';
  $handler->display->display_options['fields']['extension']['table'] = 'file_managed';
  $handler->display->display_options['fields']['extension']['field'] = 'extension';
  $handler->display->display_options['fields']['extension']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['extension']['label'] = '';
  $handler->display->display_options['fields']['extension']['element_label_colon'] = FALSE;
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['filesize']['label'] = '';
  $handler->display->display_options['fields']['filesize']['element_label_colon'] = FALSE;
  /* Field: Content: Datei ist nicht barrierefrei */
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['id'] = 'field_datei_ist_nicht_barrierefr';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['table'] = 'field_data_field_datei_ist_nicht_barrierefr';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['field'] = 'field_datei_ist_nicht_barrierefr';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['relationship'] = 'field_dokumente_und_publikatione_target_id';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['label'] = '';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['alter']['text'] = 'datei ist nicht barrierefrei';
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_datei_ist_nicht_barrierefr']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Dokumente und Publikationen';
  $translatables['related_content'] = array(
    t('Master'),
    t('Dokumente und Publikationen'),
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
    t('File'),
    t('Content entity referenced from field_dokumente_und_publikatione'),
    t('Datum'),
    t('All'),
    t('Kommende Veranstaltungen'),
    t('Content entity referenced from field_veranstaltungen'),
    t('datei ist nicht barrierefrei'),
  );
  $export['related_content'] = $view;

  return $export;
}
