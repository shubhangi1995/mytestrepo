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
  $fe_block_boxes->body = '<p>© 2017 &nbsp;<strong>Ministerium&nbsp;für Wirtschaft, Energie, Industrie,&nbsp;Mittelstand und &nbsp;Handwerk des Landes Nordrhein-Westfalen</strong></p>
';

  $export['footer_copyright'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Infos für Beschäftigte';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'infos_fur_beschaftigte';
  $fe_block_boxes->body = '<ul>
	<li><a href="schaufenster-digitales-nrw-liste?type=projekt&field_akteurstyp=All&field_themenzuweisung_1=34&field_plz=&sort_by=title&sort_by=title">Projekte&nbsp;</a></li>
	<li><a href="schaufenster-digitales-nrw-liste?type=protagonist&field_akteurstyp=43&field_themenzuweisung_1=All&field_plz=&sort_by=title&sort_by=title">Beratung</a></li>
	<li><a href="/aktuelles?type=f_rderbekanntmachung&amp;term_node_tid_depth_3=34">Förderung&nbsp;</a></li>
	<li><a href="schaufenster-digitales-nrw-liste?type=protagonist&field_akteurstyp=46&field_themenzuweisung_1=All&field_plz=&sort_by=title&sort_by=title">Perspektiven finden</a></li>
	<li><a href="/infos-fuer-beschaeftigte">Übersicht </a></li>
</ul>
';

  $export['infos_fur_beschaftigte'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Infos für Unternehmen left menu';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'infos_fur_unternehmen_left_menu';
  $fe_block_boxes->body = '<ul>
	<li><a href="schaufenster-digitales-nrw-liste?type=projekt&field_akteurstyp=All&field_themenzuweisung_1=24&field_plz=&sort_by=title&sort_by=title">&nbsp;Projekte</a></li>
	<li><a href="schaufenster-digitales-nrw-liste?type=protagonist&field_akteurstyp=43&field_themenzuweisung_1=24&field_plz=&sort_by=title&sort_by=title">&nbsp;Beratung</a></li>
	<li><a href="/aktuelles?type=f_rderbekanntmachung&amp;term_node_tid_depth_2=24">&nbsp;Förderung&nbsp;</a></li>
	<li><a href="schaufenster-digitales-nrw-liste?type=protagonist&field_akteurstyp=44&field_themenzuweisung_1=All&field_plz=&sort_by=title&sort_by=title">&nbsp;Unternehmen als Partner finden</a></li>
	<li><a href="schaufenster-digitales-nrw-liste?type=protagonist&field_akteurstyp=45&field_themenzuweisung_1=All&field_plz=&sort_by=title&sort_by=title">&nbsp;FuE-Einrichtungen als Partner finden</a></li>
	<li><a href="/infos-fuer-unternehmen">Übersicht </a></li>
</ul>
';

  $export['infos_fur_unternehmen_left_menu'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Politik & Gesellschaft left block';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'politik_gesellschaft_left_block';
  $fe_block_boxes->body = '<ul>
	<li><a href="/aktuelles?type=nachricht&amp;term_node_tid_depth=1">Nachrichten</a></li>
	<li><a href="/termine?term_node_tid_depth=1">Termine</a></li>
	<li><a href="/aktuelles?type=publikation&amp;term_node_tid_depth=1">Publikation</a></li>
	<li><a href="/politik-gesellschaft">Übersicht</a></li>
</ul>
';

  $export['politik_gesellschaft_left_block'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Wirtschaft & Arbeit left block';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'wirtschaft_arbeit_left_block';
  $fe_block_boxes->body = '<ul>
	<li><a href="/aktuelles?type=nachricht&amp;term_node_tid_depth_1=11">Nachrichten&nbsp;</a></li>
	<li><a href="/termine?term_node_tid_depth=11">Termine</a></li>
	<li><a href="/aktuelles?type=publikation&amp;term_node_tid_depth_1=11">Publikation</a></li>
	<li><a href="/wirtschaft-arbeit">Übersicht</a></li>
</ul>
';

  $export['wirtschaft_arbeit_left_block'] = $fe_block_boxes;

  return $export;
}
