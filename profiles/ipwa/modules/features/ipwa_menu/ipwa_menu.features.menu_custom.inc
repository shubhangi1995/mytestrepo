<?php
/**
 * @file
 * ipwa_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ipwa_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer-navigation.
  $menus['menu-footer-navigation'] = array(
    'menu_name' => 'menu-footer-navigation',
    'title' => '<none>',
    'description' => '',
  );
  // Exported menu: menu-meta-navigation.
  $menus['menu-meta-navigation'] = array(
    'menu_name' => 'menu-meta-navigation',
    'title' => 'meta_navigation',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('<none>');
  t('meta_navigation');

  return $menus;
}
