<?php
/**
 * @file
 * ipwa_base.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ipwa_base_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_custom';
  $strongarm->value = 'd.m.Y';
  $export['date_format_custom'] = $strongarm;

  return $export;
}
