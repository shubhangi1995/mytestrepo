<?php
/**
 * @file
 * ipwa_blocks.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ipwa_blocks_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Infos für Beschäftigte';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'infos_fur_beschaftigte';
  $fe_block_boxes->body = '<p><a href="/node/3">Projekte&nbsp;</a></p>

<p><a href="/node/4">Beratung</a></p>

<p><a href="/aktuelles?type=f_rderbekanntmachung">Förderung&nbsp;</a></p>

<p><a href="/node/22">Perspektiven finden</a></p>
';

  $export['infos_fur_beschaftigte'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Infos für Unternehmen left menu';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'infos_fur_unternehmen_left_menu';
  $fe_block_boxes->body = '<p><a href="/node/5">&nbsp;Projekte</a><br />
<a href="/node/9">&nbsp;Beratung</a><br />
<a href="/aktuelles?type=f_rderbekanntmachung">&nbsp;Förderung&nbsp;</a><br />
<a href="/node/11">&nbsp;Unternehmen als Partner finden</a><br />
<a href="/node/5">&nbsp;FuE-Einrichtungen als Partner finden</a></p>
';

  $export['infos_fur_unternehmen_left_menu'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Politik & Gesellschaft left block';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'politik_gesellschaft_left_block';
  $fe_block_boxes->body = '<p><a href="/aktuelles?type=nachricht">Nachrichten</a></p>

<p><a href="/node/2">Termine</a></p>

<p><a href="http://ipwa.dd:8083/aktuelles?type=publikation">Publikation</a></p>

<p><a href="/node/4">Übersicht</a></p>
';

  $export['politik_gesellschaft_left_block'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Wirtschaft & Arbeit left block';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'wirtschaft_arbeit_left_block';
  $fe_block_boxes->body = '<p><a href="/aktuelles?type=nachricht">Nachrichten&nbsp;</a></p>

<p><a href="/node/2">Termine</a></p>

<p><a href="/aktuelles?type=publikation">Publikation</a></p>

<p><a href="/node/4">Übersicht</a></p>
';

  $export['wirtschaft_arbeit_left_block'] = $fe_block_boxes;

  return $export;
}
