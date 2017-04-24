<?php
/**
 * @file
 * ipwa_menu.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ipwa_menu_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-footer-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-navigation',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
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
        'weight' => -21,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu-menu-meta-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-meta-navigation',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
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
        'weight' => -7,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tb_megamenu-menu-footer-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-navigation',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tb_megamenu',
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
        'weight' => -19,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['tb_megamenu-menu-meta-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-meta-navigation',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'tb_megamenu',
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
        'weight' => -22,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-themenzuweisung_flyouts-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'themenzuweisung_flyouts-block',
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
        'weight' => 9,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-themenzuweisung_flyouts-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'themenzuweisung_flyouts-block_1',
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
        'weight' => 10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-themenzuweisung_flyouts-block_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'themenzuweisung_flyouts-block_2',
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
        'weight' => 8,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-themenzuweisung_flyouts-block_3'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'themenzuweisung_flyouts-block_3',
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
        'weight' => 7,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
