<?php
/**
 * @file
 * ipwa_newsletter.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ipwa_newsletter_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'subscribe to newsletters'.
  $permissions['subscribe to newsletters'] = array(
    'name' => 'subscribe to newsletters',
    'roles' => array(),
    'module' => 'simplenews',
  );

  return $permissions;
}
