<?php
/**
 * @file
 * ipwa_search.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ipwa_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function ipwa_search_default_search_api_index() {
  $items = array();
  $items['ipwa_solr_index'] = entity_import('search_api_index', '{
    "name" : "IPWA solr index",
    "machine_name" : "ipwa_solr_index",
    "description" : null,
    "server" : "ipwa_solr_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [
          "protagonist",
          "article",
          "document",
          "f_rderbekanntmachung",
          "nachricht",
          "projekt",
          "publikation",
          "termin"
        ]
      },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_akteurstyp" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_bis_auf_weiteres" : { "type" : "date" },
        "field_datum" : { "type" : "date" },
        "field_f_rderbekanntmachungen" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_ort" : { "type" : "string" },
        "field_plz" : { "type" : "text" },
        "field_themenzuweisung" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_themenzuweisung:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_themenzuweisung:parent" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_themenzuweisung:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_themenzuweisung:vocabulary" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "taxonomy_vocabulary"
        },
        "field_ver_ffentlichungsdatum" : { "type" : "date" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "text", "boost" : "5.0" },
        "search_api_language" : { "type" : "string" },
        "search_api_panelizer_content" : { "type" : "text" },
        "search_api_panelizer_title" : { "type" : "text" },
        "search_api_url" : { "type" : "uri" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "string", "boost" : "5.0" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "panelizer" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_themenzuweisung:parent" : "field_themenzuweisung:parent",
              "field_themenzuweisung:parents_all" : "field_themenzuweisung:parents_all"
            }
          }
        },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "Title-content",
                "type" : "fulltext",
                "fields" : [ "title" ],
                "description" : "A Fulltext aggregation of the following fields: Titel."
              }
            }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_ort" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_ort" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : { "search_api_aggregation_1" : true, "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_ort" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : { "title" : true, "field_ort" : true },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
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
      "host" : "nrw-ipwa1.dev.init",
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
