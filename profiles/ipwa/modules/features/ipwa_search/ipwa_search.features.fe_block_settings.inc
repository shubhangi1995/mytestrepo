<?php
/**
 * @file
 * ipwa_search.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ipwa_search_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['ipwa_search-search_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'search_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'ipwa_search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ipwa' => array(
        'region' => 'navigation',
        'status' => 1,
        'theme' => 'ipwa',
        'weight' => 0,
      ),
      'stark' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'stark',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
