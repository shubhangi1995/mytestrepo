<?php
/**
 * @file
 * ipwa_protagonist.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ipwa_protagonist_taxonomy_default_vocabularies() {
  return array(
    'akteurstypen' => array(
      'name' => 'Akteurstypen',
      'machine_name' => 'akteurstypen',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
