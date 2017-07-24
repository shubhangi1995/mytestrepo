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
      'Chefredakteur' => 'Chefredakteur',
      'External editor' => 'External editor',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access site map'.
  $permissions['access site map'] = array(
    'name' => 'access site map',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'site_map',
  );

  // Exported permission: 'subscribe to newsletters'.
  $permissions['subscribe to newsletters'] = array(
    'name' => 'subscribe to newsletters',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'simplenews',
  );

  // Exported permission: 'view paragraph content flie_text_bereich'.
  $permissions['view paragraph content flie_text_bereich'] = array(
    'name' => 'view paragraph content flie_text_bereich',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content flie_text_mit_bild_links'.
  $permissions['view paragraph content flie_text_mit_bild_links'] = array(
    'name' => 'view paragraph content flie_text_mit_bild_links',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content flie_text_mit_bild_rechts'.
  $permissions['view paragraph content flie_text_mit_bild_rechts'] = array(
    'name' => 'view paragraph content flie_text_mit_bild_rechts',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'paragraphs_bundle_permissions',
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

  // Exported permission: 'view paragraph content topic_teaser_paragraph'.
  $permissions['view paragraph content topic_teaser_paragraph'] = array(
    'name' => 'view paragraph content topic_teaser_paragraph',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content views'.
  $permissions['view paragraph content views'] = array(
    'name' => 'view paragraph content views',
    'roles' => array(
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  return $permissions;
}
