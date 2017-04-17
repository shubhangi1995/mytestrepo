<?php
/**
 * @file
 * ipwa_topic.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ipwa_topic_taxonomy_default_vocabularies() {
  return array(
    'themenzuweisung' => array(
      'name' => 'Themenzuweisung',
      'machine_name' => 'themenzuweisung',
      'description' => 'vocabulary for article content type',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
