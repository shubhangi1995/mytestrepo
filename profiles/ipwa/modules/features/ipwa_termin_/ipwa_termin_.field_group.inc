<?php
/**
 * @file
 * ipwa_termin_.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ipwa_termin__field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_body_container|node|termin|default';
  $field_group->group_name = 'group_body_container';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Body Container',
    'weight' => '1',
    'children' => array(
      0 => 'group_body_sub_wrapper',
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
  $field_groups['group_body_container|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_body_sub_wrapper|node|termin|default';
  $field_group->group_name = 'group_body_sub_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_body_container';
  $field_group->data = array(
    'label' => 'Body Sub Wrapper',
    'weight' => '16',
    'children' => array(
      0 => 'body',
      1 => 'field_bild_ref',
      2 => 'field_kurztext',
      3 => 'field_videoquelle',
      4 => 'field_videounterschrift',
      5 => 'field_youtube_url',
      6 => 'field_anzuzeigende_seitenmodule',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Body Sub Wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-body-sub-wrapper field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_body_sub_wrapper|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_left_top_wrapper|node|termin|default';
  $field_group->group_name = 'group_left_top_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_top_wrapper';
  $field_group->data = array(
    'label' => 'Left top wrapper',
    'weight' => '19',
    'children' => array(
      0 => 'field_ort',
      1 => 'field_zeit',
      2 => 'group_middle_wrapper',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Left top wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-left-top-wrapper field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_left_top_wrapper|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_middle_wrapper|node|termin|default';
  $field_group->group_name = 'group_middle_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_left_top_wrapper';
  $field_group->data = array(
    'label' => 'Middle Wrapper',
    'weight' => '29',
    'children' => array(
      0 => 'field_event_datum',
      1 => 'group_ical',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Middle Wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-middle-wrapper field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_middle_wrapper|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_bottom|node|termin|default';
  $field_group->group_name = 'group_page_bottom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page Bottom',
    'weight' => '2',
    'children' => array(
      0 => 'field_dokumente_und_publikatione',
      1 => 'field_f_rderbekanntmachungen',
      2 => 'field_initiatoren_zum_thema',
      3 => 'field_meldungen_zum_thema',
      4 => 'field_projekte_zum_thema',
      5 => 'field_veranstaltungen',
      6 => 'field_weiterf_hrende_links',
      7 => 'group_related_doc',
      8 => 'group_related_event',
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
  $field_groups['group_page_bottom|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_info|node|termin|default';
  $field_group->group_name = 'group_page_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page info',
    'weight' => '0',
    'children' => array(
      0 => 'field_quellenangabe',
      1 => 'field_themenzuweisung',
      2 => 'field_untertitel',
      3 => 'group_related_ort',
      4 => 'group_title',
      5 => 'group_top_wrapper',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Page info',
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
  $field_groups['group_page_info|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rel_pub|node|termin|default';
  $field_group->group_name = 'group_rel_pub';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related publication',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Related publication',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-rel-pub field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_rel_pub|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_doc|node|termin|default';
  $field_group->group_name = 'group_related_doc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_page_bottom';
  $field_group->data = array(
    'label' => 'Related doc',
    'weight' => '11',
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
  $field_groups['group_related_doc|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_right_top_wrapper|node|termin|default';
  $field_group->group_name = 'group_right_top_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_top_wrapper';
  $field_group->data = array(
    'label' => 'Right top wrapper',
    'weight' => '21',
    'children' => array(
      0 => 'field_link_zur_anmeldung',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Right top wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-right-top-wrapper field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_right_top_wrapper|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_title|node|termin|default';
  $field_group->group_name = 'group_title';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
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
  $field_groups['group_title|node|termin|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_top_wrapper|node|termin|default';
  $field_group->group_name = 'group_top_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'termin';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_page_info';
  $field_group->data = array(
    'label' => 'top wrapper',
    'weight' => '5',
    'children' => array(
      0 => 'group_left_top_wrapper',
      1 => 'group_right_top_wrapper',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'top wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-top-wrapper field-group-html-element',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_top_wrapper|node|termin|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Body Container');
  t('Body Sub Wrapper');
  t('Left top wrapper');
  t('Middle Wrapper');
  t('Page Bottom');
  t('Page info');
  t('Related doc');
  t('Related publication');
  t('Right top wrapper');
  t('title');
  t('top wrapper');

  return $field_groups;
}
