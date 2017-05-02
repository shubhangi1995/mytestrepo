<?php
/**
 * @file
 * ipwa_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ipwa_article_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_body_container|node|article|default';
  $field_group->group_name = 'group_body_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Body Container',
    'weight' => '2',
    'children' => array(
      0 => 'field_bild_ref',
      1 => 'field_videoquelle',
      2 => 'field_videounterschrift',
      3 => 'field_youtube_url',
      4 => 'body',
      5 => 'field_kurztext',
      6 => 'field_anzuzeigende_seitenmodule',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-body-container field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_body_container|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entity_container|node|article|default';
  $field_group->group_name = 'group_entity_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Entity Container',
    'weight' => '3',
    'children' => array(
      0 => 'field_f_rderbekanntmachungen',
      1 => 'field_initiatoren_zum_thema',
      2 => 'field_meldungen_zum_thema',
      3 => 'field_projekte_zum_thema',
      4 => 'field_weiterf_hrende_links',
      5 => 'group_related_doc',
      6 => 'group_related_event',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-entity-container field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_entity_container|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_container|node|article|default';
  $field_group->group_name = 'group_main_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Container',
    'weight' => '0',
    'children' => array(
      0 => 'field_datum',
      1 => 'field_quellenangabe',
      2 => 'field_untertitel',
      3 => 'field_themenzuweisung',
      4 => 'group_title',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-main-container field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_main_container|node|article|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Body Container');
  t('Entity Container');
  t('Main Container');

  return $field_groups;
}
