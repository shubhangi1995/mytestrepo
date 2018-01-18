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

  // Exported menu link: management_:admin/structure/views/nojs/preview/%/%.
  $menu_links['management_:admin/structure/views/nojs/preview/%/%'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/views/nojs/preview/%/%',
    'router_path' => 'admin/structure/views/nojs/preview/%/%',
    'link_title' => '',
    'options' => array(
      'identifier' => 'management_:admin/structure/views/nojs/preview/%/%',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_views:admin/structure/views',
  );


  return $menu_links;
}
