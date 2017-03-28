<?php
/**
 * @file
 * ipwa_akteur.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ipwa_akteur_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node__akteur';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node__akteur'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node__akteur';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node__akteur'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node__akteur';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node__akteur'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type__akteur';
  $strongarm->value = '0';
  $export['language_content_type__akteur'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options__akteur';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options__akteur'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent__akteur';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent__akteur'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options__akteur';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options__akteur'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview__akteur';
  $strongarm->value = '1';
  $export['node_preview__akteur'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted__akteur';
  $strongarm->value = 1;
  $export['node_submitted__akteur'] = $strongarm;

  return $export;
}
