<?php
/**
 * @file
 * ipwa_f_rderbekanntmachung.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ipwa_f_rderbekanntmachung_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_f_rderbekanntmachung';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_f_rderbekanntmachung';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_f_rderbekanntmachung';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__f_rderbekanntmachung';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'paragraph' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_f_rderbekanntmachung';
  $strongarm->value = '0';
  $export['language_content_type_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_f_rderbekanntmachung';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_f_rderbekanntmachung';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_f_rderbekanntmachung';
  $strongarm->value = array(
    0 => 'promote',
    1 => 'revision',
  );
  $export['node_options_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_f_rderbekanntmachung';
  $strongarm->value = '0';
  $export['node_preview_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_f_rderbekanntmachung';
  $strongarm->value = 0;
  $export['node_submitted_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_f_rderbekanntmachung';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_f_rderbekanntmachung'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_f_rderbekanntmachung';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_f_rderbekanntmachung'] = $strongarm;

  return $export;
}
