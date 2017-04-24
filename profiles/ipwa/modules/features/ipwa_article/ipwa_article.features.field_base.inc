<?php
/**
 * @file
 * ipwa_article.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ipwa_article_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_anzuzeigende_seitenmodule'.
  $field_bases['field_anzuzeigende_seitenmodule'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_anzuzeigende_seitenmodule',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
