<?php
/**
 * @file
 * ipwa_projekt_.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ipwa_projekt__ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ipwa_projekt__node_info() {
  $items = array(
    'projekt' => array(
      'name' => t('Projekt'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
