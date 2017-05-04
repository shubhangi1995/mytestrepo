<?php
/**
 * @file
 * ipwa_protagonist.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ipwa_protagonist_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|protagonist|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'protagonist';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'contact',
    'weight' => '6',
    'children' => array(
      0 => 'field_weitere_details',
      1 => 'field_zur_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_contact|node|protagonist|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_doc|node|protagonist|default';
  $field_group->group_name = 'group_related_doc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'protagonist';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related doc',
    'weight' => '16',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-related-doc field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_related_doc|node|protagonist|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_event|node|protagonist|default';
  $field_group->group_name = 'group_related_event';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'protagonist';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related event',
    'weight' => '17',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-related-event field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_related_event|node|protagonist|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title|node|protagonist|default';
  $field_group->group_name = 'group_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'protagonist';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
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
  $field_groups['group_title|node|protagonist|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_weitere_details|node|protagonist|form';
  $field_group->group_name = 'group_weitere_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'protagonist';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Weitere Details',
    'weight' => '6',
    'children' => array(
      0 => 'field_weitere_details',
      1 => 'field_zur_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_weitere_details|node|protagonist|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Related doc');
  t('Related event');
  t('Weitere Details');
  t('contact');
  t('title');

  return $field_groups;
}
