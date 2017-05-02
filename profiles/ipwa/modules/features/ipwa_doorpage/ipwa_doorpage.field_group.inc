<?php
/**
 * @file
 * ipwa_doorpage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ipwa_doorpage_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eb_image|field_collection_item|eb_background|form';
  $field_group->group_name = 'group_eb_image';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'eb_background';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '0',
    'children' => array(
      0 => 'field_eb_image',
      1 => 'field_eb_image_style',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => '',
        'attributes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_eb_image|field_collection_item|eb_background|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_info|node|doorpage|default';
  $field_group->group_name = 'group_page_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'doorpage';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page Info',
    'weight' => '0',
    'children' => array(
      0 => 'group_title',
      1 => 'field_untertitel',
      2 => 'field_kurztext',
      3 => 'body',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-page-info field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_page_info|node|doorpage|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title|node|doorpage|default';
  $field_group->group_name = 'group_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'doorpage';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_page_info';
  $field_group->data = array(
    'label' => 'title',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-title field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_title|node|doorpage|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');
  t('Page Info');
  t('title');

  return $field_groups;
}
