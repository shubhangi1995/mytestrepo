<?php
/**
 * @file
 * ipwa_termin_.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ipwa_termin__default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-event_on_calendar-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'event_on_calendar-block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'calendar
calendar/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ipwa' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'ipwa',
        'weight' => -31,
      ),
      'stark' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'stark',
        'weight' => -31,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
