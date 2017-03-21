<?php

/**
 * @file
 * Site-alias definitions for Drush.
 */

// Get the local Drupal root path from Drush.
$local_root = drush_get_context('DRUSH_DRUPAL_ROOT');
if ($local_root == NULL) {
  $local_root = drush_get_option(array('r', 'root'), drush_locate_root());
}

$aliases['local'] = array(
  'root' => $local_root,
  'uri' => 'default',
  'path-aliases' => array(
    '%dump_dir' => '/tmp/',
    '%files' => 'sites/default/files',
    '%dump' => '/tmp/dump.sql',
  ),
);

$aliases['dev'] = array(
  'parent' => '@local',
  'uri' => 'http://nrw-ipwa1.dev.init/',
  'root' => '/opt/init/ipwa/public_html/',
  'remote-host' => '10.9.241.154',
  'remote-user' => 'root',
  'ssh-options' => '-o PasswordAuthentication=yes',
  'command-specific' => array(
    'sql-sync' => array(
      'simulate' => '0',
      'structure-tables' => array(
        'common' => array(
          'cache',
          'cache_block',
          'cache_bootstrap',
          'cache_field',
          'cache_filter',
          'cache_form',
          'cache_image',
          'cache_menu',
          'cache_page',
          'cache_path',
          'cache_token',
          'cache_update',
          'cache_variable',
          'cache_views',
          'cache_views_data',
          'history',
          'search_dataset',
          'search_index',
          'search_node_links',
          'search_total',
          'sessions',
          'watchdog',
        ),
        'custom' => array(
          //'cache_apachesolr',
          //'cache_media_xml',
        ),
        'devel' => array(
          //'cache_coder',
          //'cache_hacked',
        ),
      ),
    ),
    'rsync' => array(
      'simulate' => '0',
      'mode' => 'rlptDz',
    ),
  ),
);



// Auto-generate a structure-tables key "all" as combined set of all other keys.
foreach ($aliases as &$alias) {
  if (isset($alias['command-specific']['sql-sync']['structure-tables']) && !isset($alias['command-specific']['sql-sync']['structure-tables']['all'])) {
    $all = array();
    foreach ($alias['command-specific']['sql-sync']['structure-tables'] as $tables) {
      $all = array_merge($all, $tables);
    }
    $alias['command-specific']['sql-sync']['structure-tables']['all'] = $all;
  }
}

