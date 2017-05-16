<?php
/**
 * @file
 * ipwa_bild.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ipwa_bild_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ipwa_bild_image_default_styles() {
  $styles = array();

  // Exported image style: image_200x200.
  $styles['image_200x200'] = array(
    'label' => 'Image 200x200',
    'effects' => array(),
  );

  // Exported image style: image_450.
  $styles['image_450'] = array(
    'label' => 'Image 450x250',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ipwa_bild_node_info() {
  $items = array(
    'bild' => array(
      'name' => t('Bild'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Interner Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
