<?php
/**
 * @file
 * ipwa_topic.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ipwa_topic_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_anzuzeigende_seitenmodule_'.
  $field_bases['field_anzuzeigende_seitenmodule_'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_anzuzeigende_seitenmodule_',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
