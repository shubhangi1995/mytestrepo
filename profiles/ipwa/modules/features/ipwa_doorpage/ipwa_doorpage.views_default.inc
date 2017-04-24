<?php
/**
 * @file
 * ipwa_doorpage.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ipwa_doorpage_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'map_teaser';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'paragraphs_item';
  $view->human_name = 'Map Teaser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Paragraphs item: Map Teaser (field_map_teaser) */
  $handler->display->display_options['relationships']['field_map_teaser_value']['id'] = 'field_map_teaser_value';
  $handler->display->display_options['relationships']['field_map_teaser_value']['table'] = 'field_data_field_map_teaser';
  $handler->display->display_options['relationships']['field_map_teaser_value']['field'] = 'field_map_teaser_value';
  $handler->display->display_options['relationships']['field_map_teaser_value']['delta'] = '-1';
  /* Field: Field: Icon */
  $handler->display->display_options['fields']['field_bild']['id'] = 'field_bild';
  $handler->display->display_options['fields']['field_bild']['table'] = 'field_data_field_bild';
  $handler->display->display_options['fields']['field_bild']['field'] = 'field_bild';
  $handler->display->display_options['fields']['field_bild']['relationship'] = 'field_map_teaser_value';
  $handler->display->display_options['fields']['field_bild']['label'] = '';
  $handler->display->display_options['fields']['field_bild']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bild']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bild']['type'] = 'file_image_image';
  $handler->display->display_options['fields']['field_bild']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Field collection item: Title */
  $handler->display->display_options['fields']['field_paragraph_title']['id'] = 'field_paragraph_title';
  $handler->display->display_options['fields']['field_paragraph_title']['table'] = 'field_data_field_paragraph_title';
  $handler->display->display_options['fields']['field_paragraph_title']['field'] = 'field_paragraph_title';
  $handler->display->display_options['fields']['field_paragraph_title']['relationship'] = 'field_map_teaser_value';
  $handler->display->display_options['fields']['field_paragraph_title']['label'] = '';
  $handler->display->display_options['fields']['field_paragraph_title']['element_label_colon'] = FALSE;
  /* Field: Field: Fließtext-Bereich */
  $handler->display->display_options['fields']['field_flie_text_bereich']['id'] = 'field_flie_text_bereich';
  $handler->display->display_options['fields']['field_flie_text_bereich']['table'] = 'field_data_field_flie_text_bereich';
  $handler->display->display_options['fields']['field_flie_text_bereich']['field'] = 'field_flie_text_bereich';
  $handler->display->display_options['fields']['field_flie_text_bereich']['relationship'] = 'field_map_teaser_value';
  $handler->display->display_options['fields']['field_flie_text_bereich']['label'] = '';
  $handler->display->display_options['fields']['field_flie_text_bereich']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_flie_text_bereich']['element_label_colon'] = FALSE;
  /* Field: Field: Quelle */
  $handler->display->display_options['fields']['field_quellenangabe']['id'] = 'field_quellenangabe';
  $handler->display->display_options['fields']['field_quellenangabe']['table'] = 'field_data_field_quellenangabe';
  $handler->display->display_options['fields']['field_quellenangabe']['field'] = 'field_quellenangabe';
  $handler->display->display_options['fields']['field_quellenangabe']['relationship'] = 'field_map_teaser_value';
  $handler->display->display_options['fields']['field_quellenangabe']['label'] = '';
  $handler->display->display_options['fields']['field_quellenangabe']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_quellenangabe']['click_sort_column'] = 'url';
  /* Contextual filter: Paragraphs item: Paragraphs item ID */
  $handler->display->display_options['arguments']['item_id']['id'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['table'] = 'paragraphs_item';
  $handler->display->display_options['arguments']['item_id']['field'] = 'item_id';
  $handler->display->display_options['arguments']['item_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['item_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['item_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['item_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['item_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Paragraphs item: Bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'paragraphs_item';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = array(
    'frontpage_map_teaser_paragraph' => 'frontpage_map_teaser_paragraph',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['map_teaser'] = array(
    t('Master'),
    t('<none>'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field collection item from field_map_teaser'),
    t('All'),
    t('Block'),
  );
  $export['map_teaser'] = $view;

  return $export;
}
