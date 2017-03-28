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
    0 => 'status',
    1 => 'promote',
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

  return $export;
}
