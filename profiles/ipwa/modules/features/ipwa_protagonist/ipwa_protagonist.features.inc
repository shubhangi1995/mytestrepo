<?php
/**
 * @file
 * ipwa_protagonist.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ipwa_protagonist_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ipwa_protagonist_image_default_styles() {
  $styles = array();

  // Exported image style: akteur_logo.
  $styles['akteur_logo'] = array(
    'label' => 'Akteur logo',
    'effects' => array(
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 750,
          'height' => 422,
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
function ipwa_protagonist_node_info() {
  $items = array(
    'protagonist' => array(
      'name' => t('Akteur'),
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
