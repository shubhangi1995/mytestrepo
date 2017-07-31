<?php
/**
 * @file
 * ipwa_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ipwa_permissions_user_default_roles() {
  $roles = array();

  // Exported role: Chefredakteur.
  $roles['Chefredakteur'] = array(
    'name' => 'Chefredakteur',
    'weight' => 4,
  );

  // Exported role: Redakteur (ext.).
  $roles['Redakteur (ext.)'] = array(
    'name' => 'Redakteur (ext.)',
    'weight' => 2,
  );

  // Exported role: Redakteur (int.).
  $roles['Redakteur (int.)'] = array(
    'name' => 'Redakteur (int.)',
    'weight' => 3,
  );

  return $roles;
}
