<?php
/**
 * @file
 * ipwa_topic.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ipwa_topic_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-themenzuweisung-field_anzuzeigende_seitenmodule_'.
  $field_instances['taxonomy_term-themenzuweisung-field_anzuzeigende_seitenmodule_'] = array(
    'bundle' => 'themenzuweisung',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_anzuzeigende_seitenmodule_',
    'label' => 'Anzuzeigende Seitenmodule (Paragraphen)',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'select',
      'allowed_bundles' => array(
        'flie_text_bereich' => -1,
        'flie_text_mit_bild_links_' => -1,
        'flie_text_mit_bild_rechts_' => -1,
      ),
      'bundle_weights' => array(
        'flie_text_bereich' => 2,
        'flie_text_mit_bild_links_' => 3,
        'flie_text_mit_bild_rechts_' => 4,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Paragraph',
      'title_multiple' => 'Paragraphs',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'taxonomy_term-themenzuweisung-field_kurztext'.
  $field_instances['taxonomy_term-themenzuweisung-field_kurztext'] = array(
    'bundle' => 'themenzuweisung',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_kurztext',
    'label' => 'Kurztext',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'taxonomy_term-themenzuweisung-field_untertitel'.
  $field_instances['taxonomy_term-themenzuweisung-field_untertitel'] = array(
    'bundle' => 'themenzuweisung',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_untertitel',
    'label' => 'Untertitel',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Anzuzeigende Seitenmodule (Paragraphen)');
  t('Kurztext');
  t('Untertitel');

  return $field_instances;
}
