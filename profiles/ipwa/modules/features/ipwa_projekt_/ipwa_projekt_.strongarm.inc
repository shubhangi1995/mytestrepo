<?php
/**
 * @file
 * ipwa_projekt_.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ipwa_projekt__strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_projekt';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_projekt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_projekt';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_projekt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_projekt';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_projekt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_projekt';
  $strongarm->value = '0';
  $export['language_content_type_projekt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_projekt';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_projekt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_projekt';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_projekt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_projekt';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_projekt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_projekt';
  $strongarm->value = '0';
  $export['node_preview_projekt'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_projekt';
  $strongarm->value = 0;
  $export['node_submitted_projekt'] = $strongarm;

  return $export;
}
