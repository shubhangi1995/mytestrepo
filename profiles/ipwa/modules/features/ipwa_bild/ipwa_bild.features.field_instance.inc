<?php
/**
 * @file
 * ipwa_bild.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ipwa_bild_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-bild-field_bild'.
  $field_instances['node-bild-field_bild'] = array(
    'bundle' => 'bild',
    'deleted' => 0,
    'description' => 'Nur eine Datei möglich.
1.96 GB Limit.
Erlaubte Dateitypen: png gif jpg jpeg.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file_image_formatters',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'medium',
        ),
        'type' => 'file_image_image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bild',
    'label' => 'Bild',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '1.96 GB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'upload' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-bild-field_bildbeschreibung'.
  $field_instances['node-bild-field_bildbeschreibung'] = array(
    'bundle' => 'bild',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bildbeschreibung',
    'label' => 'Bildbeschreibung',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-bild-field_copyright'.
  $field_instances['node-bild-field_copyright'] = array(
    'bundle' => 'bild',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_copyright',
    'label' => '© Bildquelle',
    'required' => 1,
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
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Bild');
  t('Bildbeschreibung');
  t('Nur eine Datei möglich.
1.96 GB Limit.
Erlaubte Dateitypen: png gif jpg jpeg.');
  t('© Bildquelle');

  return $field_instances;
}
