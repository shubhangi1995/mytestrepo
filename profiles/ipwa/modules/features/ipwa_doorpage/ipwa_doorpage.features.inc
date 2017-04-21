<?php
/**
 * @file
 * ipwa_doorpage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ipwa_doorpage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ipwa_doorpage_node_info() {
  $items = array(
    'doorpage' => array(
      'name' => t('Doorpage'),
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
