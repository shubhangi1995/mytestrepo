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
    'weight' => '8',
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
      'label' => 'Body Container',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-body-container field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_body_container|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_bottom|node|article|default';
  $field_group->group_name = 'group_page_bottom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page Bottom',
    'weight' => '18',
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
      'label' => 'Page Bottom',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-page-bottom field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_page_bottom|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_info|node|article|default';
  $field_group->group_name = 'group_page_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page Info',
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
      'label' => 'Page Info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-page-info field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_page_info|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_doc|node|article|default';
  $field_group->group_name = 'group_related_doc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_page_bottom';
  $field_group->data = array(
    'label' => 'Related doc',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Related doc',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-related-doc field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_related_doc|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_event|node|article|default';
  $field_group->group_name = 'group_related_event';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_page_bottom';
  $field_group->data = array(
    'label' => 'Related event',
    'weight' => '8',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Related event',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-related-event field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_related_event|node|article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title|node|article|default';
  $field_group->group_name = 'group_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_page_info';
  $field_group->data = array(
    'label' => 'title',
    'weight' => '2',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'title',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-title field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_title|node|article|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Body Container');
  t('Page Bottom');
  t('Page Info');
  t('Related doc');
  t('Related event');
  t('title');

  return $field_groups;
}
