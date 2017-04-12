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

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_action_status_code_301';
  $strongarm->value = '3';
  $export['linkchecker_action_status_code_301'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_check_links_interval';
  $strongarm->value = '86400';
  $export['linkchecker_check_links_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_check_links_types';
  $strongarm->value = '0';
  $export['linkchecker_check_links_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_a';
  $strongarm->value = 1;
  $export['linkchecker_extract_from_a'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_audio';
  $strongarm->value = 1;
  $export['linkchecker_extract_from_audio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_embed';
  $strongarm->value = 1;
  $export['linkchecker_extract_from_embed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_iframe';
  $strongarm->value = 1;
  $export['linkchecker_extract_from_iframe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_img';
  $strongarm->value = 1;
  $export['linkchecker_extract_from_img'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_object';
  $strongarm->value = 1;
  $export['linkchecker_extract_from_object'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_extract_from_video';
  $strongarm->value = 1;
  $export['linkchecker_extract_from_video'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_filter_blacklist';
  $strongarm->value = array(
    'filter_autop' => 'filter_autop',
    'media_filter' => 0,
    'filter_url' => 0,
    'filter_htmlcorrector' => 0,
    'filter_html_escape' => 0,
    'media_filter_paragraph_fix' => 0,
    'filter_html' => 0,
  );
  $export['linkchecker_filter_blacklist'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'linkchecker_scan_blocks';
  $strongarm->value = 1;
  $export['linkchecker_scan_blocks'] = $strongarm;

  return $export;
}
