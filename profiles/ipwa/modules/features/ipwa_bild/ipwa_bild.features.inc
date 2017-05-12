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
    'effects' => array(
      37 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
          'anchor' => 'center-center',
          'disable_scale' => 0,
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image_450.
  $styles['image_450'] = array(
    'label' => 'Image 450x250',
    'effects' => array(
      38 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 450,
          'height' => 250,
          'anchor' => 'center-center',
          'disable_scale' => 0,
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
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
