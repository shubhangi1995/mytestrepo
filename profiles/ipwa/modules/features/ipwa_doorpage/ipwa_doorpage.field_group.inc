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
  $field_group->identifier = 'group_eb_color|field_collection_item|eb_background|form';
  $field_group->group_name = 'group_eb_color';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'eb_background';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Color',
    'weight' => 0,
    'children' => array(
      0 => 'field_eb_color',
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
  $field_groups['group_eb_color|field_collection_item|eb_background|form'] = $field_group;

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
    'weight' => 0,
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
  $field_group->identifier = 'group_eb_parallax|field_collection_item|eb_background|form';
  $field_group->group_name = 'group_eb_parallax';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'eb_background';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Parallax',
    'weight' => 0,
    'children' => array(
      0 => 'field_eb_parallax_image',
      1 => 'field_eb_parallax_speed',
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
  $field_groups['group_eb_parallax|field_collection_item|eb_background|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Color');
  t('Image');
  t('Parallax');

  return $field_groups;
}
