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
  $fe_block_boxes->body = '<p>© 2017 &nbsp;<strong>Ministerium&nbsp;für Wirtschaft, Innovation, Digitalisierung und Energie des Landes Nordrhein-Westfalen</strong></p>
';

  $export['footer_copyright'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Infos für Beschäftigte';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'infos_fur_beschaftigte';
  $fe_block_boxes->body = '<h4 class="block-title">Immer gut informiert</h4>

<ul>
	<li><a href="/schaufenster-digitales-nrw-listenansicht?type=projekt&amp;&amp;search_api_aggregation_2=&amp;Submit=Suchen">Beispiele guter Praxis </a></li>
	<li><a href="/schaufenster-digitales-nrw-listenansicht?type=protagonist&amp;field_akteurstyp=43&amp;field_themenzuweisung_1=24&amp;field_plz=&amp;sort_by=title&amp;sort_by=title&amp;Submit=Suchen">Beratung</a></li>
	<li><a href="/schaufenster-digitales-nrw-listenansicht?type=protagonist&amp;field_akteurstyp=46&amp;field_themenzuweisung_1=34&amp;field_plz=&amp;Submit=Suchen">Qualifizierungsanbieter</a></li>
	<li><a href="/aktuelles?type=f_rderbekanntmachung&amp;term_node_tid_depth_3=34">Förderung</a></li>
	<li><a href="/infos-fuer-beschaeftigte">Übersicht</a></li>
</ul>
';

  $export['infos_fur_beschaftigte'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Infos für Unternehmen left menu';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'infos_fur_unternehmen_left_menu';
  $fe_block_boxes->body = '<h3 class="block-title">Immer gut informiert</h3>

<ul>
	<li><a href="/schaufenster-digitales-nrw-listenansicht?type=projekt&amp;field_plz=&amp;sort_by=title&amp;Submit=Suchen">Beispiele guter Praxis </a></li>
	<li><a href="/schaufenster-digitales-nrw-listenansicht?type=protagonist&amp;field_akteurstyp=43&amp;field_themenzuweisung_1=24&amp;field_plz=&amp;sort_by=title&amp;sort_by=title&amp;Submit=Suchen">Beratung</a></li>
	<li><a href="/aktuelles?type=f_rderbekanntmachung&amp;term_node_tid_depth_2=24">Förderung</a></li>
	<li><a href="/schaufenster-digitales-nrw-listenansicht?type=protagonist&amp;field_akteurstyp=44&amp;field_plz=&amp;Submit=Suchen">Unternehmenspartner</a></li>
	<li><a href="/schaufenster-digitales-nrw-listenansicht?type=protagonist&amp;field_akteurstyp=45&amp;field_plz=&amp;Submit=Suchen">FuE-Partner</a></li>
	<li><a href="/infos-fuer-unternehmen">Übersicht </a></li>
</ul>
';

  $export['infos_fur_unternehmen_left_menu'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Politik & Gesellschaft left block';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'politik_gesellschaft_left_block';
  $fe_block_boxes->body = '<h3 class="block-title">Immer gut informiert</h3>

<ul>
	<li><a href="/aktuelles?type=nachricht&amp;term_node_tid_depth=1">Nachrichten</a></li>
	<li><a href="/aktuelles?type=publikation&amp;term_node_tid_depth=1">Publikationen</a></li>
	<li><a href="/termine?term_node_tid_depth=1">Termine</a></li>
	<li><a href="/strategie-internationales">Übersicht</a></li>
</ul>
';

  $export['politik_gesellschaft_left_block'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Wirtschaft & Arbeit left block';
  $fe_block_boxes->format = 'wysiwyg';
  $fe_block_boxes->machine_name = 'wirtschaft_arbeit_left_block';
  $fe_block_boxes->body = '<h3 class="block-title">Immer gut informiert</h3>

<ul>
	<li><a href="/aktuelles?type=nachricht&amp;term_node_tid_depth_1=11">Nachrichten&nbsp;</a></li>
	<li><a href="/aktuelles?type=publikation&amp;term_node_tid_depth_1=11">Publikationen</a></li>
	<li><a href="/termine?term_node_tid_depth=11">Termine</a></li>
	<li><a href="/wirtschaft-arbeit">Übersicht</a></li>
</ul>
';

  $export['wirtschaft_arbeit_left_block'] = $fe_block_boxes;

  return $export;
}
