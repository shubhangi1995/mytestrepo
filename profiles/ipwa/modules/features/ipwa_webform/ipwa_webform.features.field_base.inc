<?php
/**
 * @file
 * ipwa_webform.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ipwa_webform_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_pflichtfeldhinweis'.
  $field_bases['field_pflichtfeldhinweis'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pflichtfeldhinweis',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
