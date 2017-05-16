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
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
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
 * Implements hook_image_default_styles().
 */
function ipwa_base_image_default_styles() {
  $styles = array();

  // Exported image style: main_image_870_489.
  $styles['main_image_870_489'] = array(
    'label' => 'Main Image 870x489',
    'effects' => array(
      2 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 870,
          'height' => 489,
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

  // Exported image style: themen_icon_36x36.
  $styles['themen_icon_36x36'] = array(
    'label' => 'Themen icon (36x36)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 36,
          'height' => 36,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
    'flie_text_mit_bild_links' => array(
      'name' => 'Fließtext mit Bild (links)',
      'bundle' => 'flie_text_mit_bild_links',
      'locked' => '1',
    ),
    'flie_text_mit_bild_rechts' => array(
      'name' => 'Fließtext mit Bild (rechts)',
      'bundle' => 'flie_text_mit_bild_rechts',
      'locked' => '1',
    ),
  );
  return $items;
}
