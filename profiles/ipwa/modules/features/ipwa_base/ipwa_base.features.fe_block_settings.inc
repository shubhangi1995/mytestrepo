<?php
/**
 * @file
 * ipwa_base.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ipwa_base_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['ipwa_base-footer_block_icons'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'footer_block_icons',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'ipwa_base',
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
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ipwa',
        'weight' => -36,
      ),
      'stark' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'stark',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['ipwa_base-footer_print'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'footer_print',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'ipwa_base',
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
        'region' => '',
        'status' => 0,
        'theme' => 'ipwa',
        'weight' => -36,
      ),
      'stark' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'stark',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-neueste_digital_projekte-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'neueste_digital_projekte-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(
      0 => 'article',
      1 => 'nachricht',
    ),
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
        'region' => 'content',
        'status' => 1,
        'theme' => 'ipwa',
        'weight' => -25,
      ),
      'stark' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'stark',
        'weight' => -25,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-rss-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'rss-block_1',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
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
        'region' => '',
        'status' => 0,
        'theme' => 'ipwa',
        'weight' => -37,
      ),
      'stark' => array(
        'region' => 'footer',
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
