<?php
/**
 * @file
 * ipwa_base.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ipwa_base_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paragraphs_item-flie_text_bereich-field_flie_text_bereich'.
  $field_instances['paragraphs_item-flie_text_bereich-field_flie_text_bereich'] = array(
    'bundle' => 'flie_text_bereich',
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
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_flie_text_bereich',
    'label' => 'Fließtext-Bereich',
    'required' => 1,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-flie_text_mit_bild_links_-field_bild_ref'.
  $field_instances['paragraphs_item-flie_text_mit_bild_links_-field_bild_ref'] = array(
    'bundle' => 'flie_text_mit_bild_links_',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'use_content_language' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_bild_ref',
    'label' => '© Bildquelle',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-flie_text_mit_bild_links_-field_flie_text_bereich'.
  $field_instances['paragraphs_item-flie_text_mit_bild_links_-field_flie_text_bereich'] = array(
    'bundle' => 'flie_text_mit_bild_links_',
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
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_flie_text_bereich',
    'label' => 'Fließtext-Bereich',
    'required' => 1,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-flie_text_mit_bild_rechts_-field_bild_ref'.
  $field_instances['paragraphs_item-flie_text_mit_bild_rechts_-field_bild_ref'] = array(
    'bundle' => 'flie_text_mit_bild_rechts_',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'use_content_language' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_bild_ref',
    'label' => '© Bildquelle',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'paragraphs_item-flie_text_mit_bild_rechts_-field_flie_text_bereich'.
  $field_instances['paragraphs_item-flie_text_mit_bild_rechts_-field_flie_text_bereich'] = array(
    'bundle' => 'flie_text_mit_bild_rechts_',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_flie_text_bereich',
    'label' => 'Fließtext-Bereich',
    'required' => 1,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-views-field_paragraph_view'.
  $field_instances['paragraphs_item-views-field_paragraph_view'] = array(
    'bundle' => 'views',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_paragraph_view',
    'label' => 'View',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'Maillog' => 0,
        'admin_views_file' => 0,
        'admin_views_user' => 0,
        'aktuelles' => 0,
        'alles_zum_thema' => 0,
        'clone_of_administration_nodes' => 0,
        'media_default' => 0,
        'neueste_informationen' => 0,
        'related_content' => 0,
        'revisioning_content_revisions_summary' => 0,
        'revisioning_content_summary' => 0,
        'rss' => 0,
        'scheduled_publications' => 0,
        'termin' => 0,
        'test' => 0,
        'themenzuweisung_flyouts' => 0,
        'webform_analysis' => 0,
        'webform_results' => 0,
        'webform_submissions' => 0,
        'webform_webforms' => 0,
      ),
      'force_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Fließtext-Bereich');
  t('View');
  t('© Bildquelle');

  return $field_instances;
}
