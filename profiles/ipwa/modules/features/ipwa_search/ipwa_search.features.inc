<?php
/**
 * @file
 * ipwa_search.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function ipwa_search_default_search_api_index() {
  $items = array();
  $items['ipwa_solr_index'] = entity_import('search_api_index', '{
    "name" : "IPWA solr index",
    "machine_name" : "ipwa_solr_index",
    "description" : null,
    "server" : null,
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 0,
      "cron_limit" : "50"
    },
    "enabled" : "0",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ipwa_search_default_search_api_server() {
  $items = array();
  $items['ipwa_solr_server'] = entity_import('search_api_server', '{
    "name" : "IPWA solr server",
    "machine_name" : "ipwa_solr_server",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/drupal",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "log_query" : 0,
      "log_response" : 0,
      "commits_disabled" : 0
    },
    "enabled" : "1"
  }');
  return $items;
}
