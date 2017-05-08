<?php
/**
 * @file
 * ipwa_menu.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ipwa_menu_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer copyright';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'footer_copyright';
  $fe_block_boxes->body = '© 2017 &nbsp;Ministerium&nbsp;für Wirtschaft, Energie, Industrie,&nbsp;Mittelstand und &nbsp;Handwerk des Lands Nordrhein-Westfalen
';

  $export['footer_copyright'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Infos für Beschäftigte';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'infos_fur_beschaftigte';
  $fe_block_boxes->body = '<ul>
	<li>
	<a href="/node/3">Projekte&nbsp;</a>
	</li>
	<li>
	<a href="/node/4">Beratung</a>
	</li>
	<li>
	<a href="/aktuelles?type=f_rderbekanntmachung">Förderung&nbsp;</a>
	</li>
	<li>
	<a href="/node/22">Perspektiven finden</a>
	</li>
</ul>
';

  $export['infos_fur_beschaftigte'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Infos für Unternehmen left menu';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'infos_fur_unternehmen_left_menu';
  $fe_block_boxes->body = '<ul><li><a href="/node/5">&nbsp;Projekte</a></li>

<li><a href="/node/9">&nbsp;Beratung</a></li>

<li><a href="/aktuelles?type=f_rderbekanntmachung">&nbsp;Förderung&nbsp;</a></li>

<li><a href="/node/11">&nbsp;Unternehmen als Partner finden</a></li>

<li><a href="/node/5">&nbsp;FuE-Einrichtungen als Partner finden</a></li>
';

  $export['infos_fur_unternehmen_left_menu'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Politik & Gesellschaft left block';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'politik_gesellschaft_left_block';
  $fe_block_boxes->body = '<ul>
	<li><a href="/aktuelles?type=nachricht">Nachrichten</a></li>
	<li><a href="/termine">Termine</a></li>
	<li><a href="http://ipwa.dd:8083/aktuelles?type=publikation">Publikation</a></li>
	<li class="ubersicht"><a href="taxonomy/term/1">Übersicht</a></li>
</ul>
';

  $export['politik_gesellschaft_left_block'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Wirtschaft & Arbeit left block';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'wirtschaft_arbeit_left_block';
  $fe_block_boxes->body = '<ul>
	<li><a href="/aktuelles?type=nachricht">Nachrichten&nbsp;</a></li>
	<li><a href="/termine">Termine</a></li>
	<li><a href="/aktuelles?type=publikation">Publikation</a></li>
	<li class="ubersicht"><a href="taxonomy/term/11">Übersicht</a></li>
</ul>
';

  $export['wirtschaft_arbeit_left_block'] = $fe_block_boxes;

  return $export;
}
