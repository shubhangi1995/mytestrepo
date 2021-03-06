<?php
/**
 * @file
 * ipwa_doorpage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ipwa_doorpage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
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
 * Implements hook_image_default_styles().
 */
function ipwa_doorpage_image_default_styles() {
  $styles = array();

  // Exported image style: eb_background_1920_1080.
  $styles['eb_background_1920_1080'] = array(
    'label' => 'EB Background 1920x1080',
    'effects' => array(
      6 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 1920,
          'height' => 1080,
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

  // Exported image style: map_teaser_icon_68x68.
  $styles['map_teaser_icon_68x68'] = array(
    'label' => 'Map Teaser Icon (68x68)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 68,
          'height' => 68,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: themen_icon_54x54.
  $styles['themen_icon_54x54'] = array(
    'label' => 'Themen icon (54x54)',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 54,
          'height' => 54,
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
    'frontpage_map_teaser_paragraph' => array(
      'name' => 'Frontpage Map Teaser Paragraph',
      'bundle' => 'frontpage_map_teaser_paragraph',
      'locked' => '1',
    ),
    'topic_teaser_paragraph' => array(
      'name' => 'Topic Teaser paragraph',
      'bundle' => 'topic_teaser_paragraph',
      'locked' => '1',
    ),
  );
  return $items;
}
