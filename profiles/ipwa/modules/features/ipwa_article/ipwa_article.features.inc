<?php
/**
 * @file
 * ipwa_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ipwa_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ipwa_article_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Artikel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
