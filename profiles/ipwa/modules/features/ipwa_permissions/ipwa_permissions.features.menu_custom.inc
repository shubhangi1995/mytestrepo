<?php
/**
 * @file
 * ipwa_permissions.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ipwa_permissions_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-taxonomy.
  $menus['menu-taxonomy'] = array(
    'menu_name' => 'menu-taxonomy',
    'title' => 'Taxonomy',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Management');
  t('Taxonomy');
  t('The <em>Management</em> menu contains links for administrative tasks.');

  return $menus;
}
