<?php
/**
 * @file
 * ipwa_document.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ipwa_document_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ipwa_document_node_info() {
  $items = array(
    'document' => array(
      'name' => t('Document'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Interner Titel'),
      'help' => t('Der Titel ist nur systemintern sichtbar.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
