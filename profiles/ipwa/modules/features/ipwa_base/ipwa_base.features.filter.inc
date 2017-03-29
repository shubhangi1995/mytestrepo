<?php
/**
 * @file
 * ipwa_base.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function ipwa_base_filter_default_formats() {
  $formats = array();

  // Exported format: wysiwyg.
  $formats['wysiwyg'] = array(
    'format' => 'wysiwyg',
    'name' => 'wysiwyg',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_autop' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
