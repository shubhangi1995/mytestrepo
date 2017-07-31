<?php
/**
 * @file
 * ipwa_newsletter.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ipwa_newsletter_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['ipwa_newsletter-newsletter_subscription_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'newsletter_subscription_block',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'ipwa_newsletter',
    'node_types' => array(),
    'pages' => '<front>
termine
politik-gesellschaft
wirtschaft-arbeit
infos-fuer-unternehmen
aktuelles
infos-fuer-beschaeftigte
calendar
alle-themen
schaufenster-digitales-nrw',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ipwa' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ipwa',
        'weight' => -37,
      ),
      'stark' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'stark',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
