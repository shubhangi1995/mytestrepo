<?php
/**
 * @file
 * ipwa_projekt_.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ipwa_projekt__ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ipwa_projekt__image_default_styles() {
  $styles = array();

  // Exported image style: project_logo.
  $styles['project_logo'] = array(
    'label' => 'Project logo',
    'effects' => array(
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 180,
          'height' => 101,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
