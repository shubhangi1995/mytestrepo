<?php
/**
 * @file
 * ipwa_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ipwa_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ipwa_base_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_paragraphs_info().
 */
function ipwa_base_paragraphs_info() {
  $items = array(
    'flie_text_bereich' => array(
      'name' => 'Fließtext-Bereich',
      'bundle' => 'flie_text_bereich',
      'locked' => '1',
    ),
    'flie_text_mit_bild_links_' => array(
      'name' => 'Fließtext mit Bild (links)',
      'bundle' => 'flie_text_mit_bild_links_',
      'locked' => '1',
    ),
    'flie_text_mit_bild_rechts_' => array(
      'name' => 'Fließtext mit Bild (rechts)',
      'bundle' => 'flie_text_mit_bild_rechts_',
      'locked' => '1',
    ),
  );
  return $items;
}
