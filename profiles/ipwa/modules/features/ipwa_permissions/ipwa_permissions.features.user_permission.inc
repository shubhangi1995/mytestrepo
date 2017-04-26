<?php
/**
 * @file
 * ipwa_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ipwa_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view paragraph content frontpage_map_teaser_paragraph'.
  $permissions['view paragraph content frontpage_map_teaser_paragraph'] = array(
    'name' => 'view paragraph content frontpage_map_teaser_paragraph',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  return $permissions;
}
