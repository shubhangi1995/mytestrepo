<?php
/**
 * @file
 * ipwa_blocks.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ipwa_blocks_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-main-menu-flyouts.
  $menus['menu-main-menu-flyouts'] = array(
    'menu_name' => 'menu-main-menu-flyouts',
    'title' => 'menu flyouts',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('menu flyouts');

  return $menus;
}
