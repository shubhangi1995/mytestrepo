<?php
/**
 * @file
 * ipwa_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ipwa_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_:admin/config/content/formats/%.
  $menu_links['management_:admin/config/content/formats/%'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/formats/%',
    'router_path' => 'admin/config/content/formats/%',
    'link_title' => '',
    'options' => array(
      'identifier' => 'management_:admin/config/content/formats/%',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_textformate:admin/config/content/formats',
  );


  return $menu_links;
}
