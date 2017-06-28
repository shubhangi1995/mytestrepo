<?php
/**
 * @file
 * ipwa_permissions.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ipwa_permissions_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_confirm_subscribe_page';
  $strongarm->value = '';
  $export['simplenews_confirm_subscribe_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_confirm_unsubscribe_page';
  $strongarm->value = '';
  $export['simplenews_confirm_unsubscribe_page'] = $strongarm;

  return $export;
}
