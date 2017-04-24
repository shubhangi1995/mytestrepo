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
 * Implements hook_views_api().
 */
function ipwa_doorpage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
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

/**
 * Implements hook_paragraphs_info().
 */
function ipwa_doorpage_paragraphs_info() {
  $items = array(
    'topic_teaser_paragraph' => array(
      'name' => 'Topic Teaser paragraph',
      'bundle' => 'topic_teaser_paragraph',
      'locked' => '1',
    ),
  );
  return $items;
}
