<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

/**
 * Implements theme_preprocess_node().
 *
 * Theme preprocess function for node.tpl.php
 *
 * @params $variables
 *
 */
function ipwa_preprocess_node(&$variables) {
  if ($variables['type'] == 'bild') {
    // Don't show title
    $variables['title'] = '';
  }
  // Display view 'Kommende Veranstaltungen' instaed of field 'Veranstaltungen'
  if (!empty($variables['field_veranstaltungen'])) {
    $views = views_get_view_result("related_content", "block_1", $variables['nid']);
    $related_event_view = '';
    if (!empty($views)) {
      $related_event_view = '<h2 class="view-title">' . t('Kommende Veranstaltungen') . '</h2>';
      //for embedding view Kommende Veranstaltungen
      $related_event_view .= views_embed_view("related_content", "block_1", $variables['nid']);
      $variables['content']['related_event']['#markup'] = $related_event_view;
      $variables['content']['related_event']['#weight'] = isset($variables['elements']['#fieldgroups']['group_related_event']) ? $variables['elements']['#fieldgroups']['group_related_event']->weight : -1;
    }
  }

  // display view 'Dokumente und Publikation' instead of field 'Dokumente und Publikationen'
  if (!empty($variables['field_dokumente_und_publikatione'])) {
    $view = views_get_view_result("related_content", "block_2", $variables['nid']);
    $related_doc_view = '';
    if (!empty($view)) {
      $related_doc_view = '<h2 class="view-title">' . t('Dokumente und Publikationen') . '</h2>';
      //for embedding view Dokumente und Publikation
      $related_doc_view .= views_embed_view("related_content", "block_2", $variables['nid']);
      $variables['content']['related_doc']['#markup'] = $related_doc_view;
      $variables['content']['related_doc']['#weight'] = isset($variables['elements']['#fieldgroups']['group_related_doc']) ? $variables['elements']['#fieldgroups']['group_related_doc']->weight : -1;
    }
  }

  // display view 'Publikationen' instead of field 'Publikation'
  if (!empty($variables['field_publication'])) {
    $view = views_get_view_result("related_content", "block_3", $variables['nid']);
    $related_pub_view = '';
    if (!empty($view)) {
      $related_pub_view = '<h2 class="view-title">' . t('Publikation') . '</h2>';
      //for embedding view publikation
      $related_pub_view .= views_embed_view("related_content", "block_3", $variables['nid']);
      $variables['content']['rel_pub']['#markup'] = $related_pub_view;
      $variables['content']['rel_pub']['#weight'] = isset($variables['elements']['#fieldgroups']['group_rel_pub']) ? $variables['elements']['#fieldgroups']['group_rel_pub']->weight : -1;
    }
  }

  // Change position of title field
  // (mostly will be displayed under date field)
  if (isset($variables['title']) && $variables['title']) {
    $variables['content']['title'] = array(
      '#markup' => '<h1 class="page-title">' . $variables['title'] . '</h1>',
      '#weight' => isset($variables['elements']['#fieldgroups']['group_title']) ? $variables['elements']['#fieldgroups']['group_title']->weight : -1);
  }


  if ($variables['type'] == 'termin') {
    // Display of Ort field
    if(isset($variables['content']['field_ort']) && !empty($variables['content']['field_ort'])) {
      $variables['content']['rel_ort'] = '';
      $variables['content']['rel_ort']['#markup'] = $variables['content']['field_ort'][0]['#markup'];
      $variables['content']['rel_ort']['#weight'] = isset($variables['elements']['#fieldgroups']['group_related_ort']) ? $variables['elements']['#fieldgroups']['group_related_ort']->weight : -1;

      // show field 'Ort' appended with value of  field 'Zusätzliche Informationen zum Ort' if provided
      if (!empty($variables['field_zus_tzliche_informationen_'])) {
        $variables['content']['field_ort'][0]['#markup'] = $variables['content']['field_ort'][0]['#markup'] . ' ' . $variables['field_zus_tzliche_informationen_']['und'][0]['value'];
      }
    }

    // replace of 'to' with'-' for field 'datum' in CT termin
    if(!empty($variables['content']['field_event_datum'])){
      if (strpos($variables['content']['field_event_datum'][0]['#markup'], 'to') !== false) {
        $variables['content']['field_event_datum'][0]['#markup'] = str_replace('to','-',$variables['content']['field_event_datum'][0]['#markup']);
      }
    }
  }
}

/**
 * Implements ipwa_preprocess_field().
 *
 * Theme preprocess function for field.tpl.php
 *
 * @params $variables
 *
 */
function ipwa_preprocess_field(&$variables) {
  $fields = array("field_meldungen_zum_thema", "field_initiatoren_zum_thema", "field_projekte_zum_thema", "field_f_rderbekanntmachungen", "field_publikation");
  if (in_array($variables['element']['#field_name'], $fields)) {
    foreach ($variables['items'] as $key => $item) {
      // alter field value to link to respective node.
      $variables['items'][$key]['#markup'] = l($item['#markup'], 'node/' . $variables['element']['#items'][$key]['target_id']);
    }
  }
}

/**
 * Implements theme_preprocess_page().
 *
 * Theme preprocess function for page.tpl.php
 *
 * @params $variables
 *
 */
function ipwa_preprocess_page(&$variables) {
  if (arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $term = taxonomy_term_load(arg(2));
    $variables['theme_hook_suggestions'][] = 'page__vocabulary__' . $term->vocabulary_machine_name;
  }
}
