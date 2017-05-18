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
function ipwa_preprocess_node(&$variables)
{
  //For CT 'Bild' or frontpage don't show title
  if ($variables['type'] == 'bild' || drupal_is_front_page()) {
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
      $variables['content']['group_page_bottom']['related_event']['#markup'] = $related_event_view;
      $variables['content']['group_page_bottom']['related_event']['#weight'] = isset($variables['elements']['#fieldgroups']['group_related_event']) ? $variables['elements']['#fieldgroups']['group_related_event']->weight : -1;
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
      $variables['content']['group_page_bottom']['related_doc']['#markup'] = $related_doc_view;
      $variables['content']['group_page_bottom']['related_doc']['#weight'] = isset($variables['elements']['#fieldgroups']['group_related_doc']) ? $variables['elements']['#fieldgroups']['group_related_doc']->weight : -1;
    }
  }

  // display view 'Publikationen' instead of field 'Publikation'
  if (!empty($variables['field_publikation'])) {
    $view = views_get_view_result("related_content", "block_3", $variables['nid']);
    $related_pub_view = '';
    if (!empty($view)) {
      $related_pub_view = '<h3 class="view-title">' . t('Publikation') . '</h3>';
      //for embedding view publikation
      $related_pub_view .= views_embed_view("related_content", "block_3", $variables['nid']);
      $variables['content']['group_body_container']['group_body_sub_wrapper']['rel_pub']['#markup'] = $related_pub_view;
      $variables['content']['group_body_container']['group_body_sub_wrapper']['rel_pub']['#weight'] = isset($variables['elements']['#fieldgroups']['group_rel_pub']) ? $variables['elements']['#fieldgroups']['group_rel_pub']->weight : -1;
    }
  }

  // Change position of title field
  // (mostly will be displayed under date field)
  if (isset($variables['title']) && $variables['title']) {
    $variables['content']['group_page_info']['title'] = array(
        '#markup' => '<h1 class="page-title">' . $variables['title'] . '</h1>',
        '#weight' => isset($variables['elements']['#fieldgroups']['group_title']) ? $variables['elements']['#fieldgroups']['group_title']->weight : -1);
  }

  //change the position if ical view
  if($variables['type'] == 'termin') {
    $view = views_get_view_result("termin", "block_1", $variables['nid']);
    $related_ical = '';
    if(!empty($view)) {
      $related_ical .= views_embed_view("termin", "block_1", $variables['nid']);
      $variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['group_middle_wrapper']['ical']['#markup'] = $related_ical;
      $variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['group_middle_wrapper']['ical']['#weight'] = isset($variables['elements']['#fieldgroups']['group_ical']) ? $variables['elements']['#fieldgroups']['ical']->weight : -1;

    }
  }
  if ($variables['type'] == 'termin') {
    // Display of Ort field
    if (isset($variables['content']['field_ort']) && !empty($variables['content']['field_ort'])) {
      $variables['content']['rel_ort'] = '';
      $variables['content']['rel_ort']['#markup'] = $variables['content']['field_ort'][0]['#markup'];
      $variables['content']['rel_ort']['#weight'] = isset($variables['elements']['#fieldgroups']['group_related_ort']) ? $variables['elements']['#fieldgroups']['group_related_ort']->weight : -1;

      // show field 'Ort' appended with value of  field 'Zusätzliche Informationen zum Ort' if provided
      if (!empty($variables['field_zus_tzliche_informationen'])) {
        $variables['content']['field_ort'][0]['#markup'] = $variables['content']['field_ort'][0]['#markup'] . ' ' . $variables['field_zus_tzliche_informationen']['und'][0]['value'];
      }
    }

    // replace of 'to' with'-' for field 'datum' in CT termin
    if(!empty($variables['content']['field_event_datum'])){
      if (strpos($variables['content']['field_event_datum'][0]['#markup'], 'to') !== false) {
        $variables['content']['field_event_datum'][0]['#markup'] = str_replace('to','-',$variables['content']['field_event_datum'][0]['#markup']);
      }
    }
  }
/** for puuting content of field 'descrition to field 'copyright' and to hide field 'descrition' */
  if ($variables['type'] == 'bild') {
    if((isset($variables['content']['field_bildbeschreibung']) && !(empty($variables['content']['field_bildbeschreibung']))) || (!empty($variables['content']['field_copyright']))) {
      $variables['content']['field_copyright'][0]['#markup'] = $variables['content']['field_bildbeschreibung'][0]['#markup'] . ' <span class ="copyright">' . $variables['content']['field_copyright']['#title'] . ':  ' . $variables['content']['field_copyright'][0]['#markup'] . '</span>';
      hide($variables['content']['field_bildbeschreibung']);
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

  // show parent term icon (if child term) before term names in field 'Dieser Artikel gehört zu'
  if ($variables['element']['#field_name'] == 'field_themenzuweisung') {
    if (!empty($variables['items'])) {
      foreach ($variables['items'] as $key => $item) {
        // print_r($item);
        // alter field value to link to respective node.
        $tid = $variables['element']['#items'][$key]['tid'];
        $parent = taxonomy_get_parents($tid);
        if (!empty($parent)) {
          foreach($parent as $pid => $parent_term) {
            $icon = $parent_term->field_bild['und'][0];
          }
        }
        else {
          $icon = $variables['element']['#items'][$key]['taxonomy_term']->field_bild['und'][0];
        }
        if (!empty($icon)) {
          $icon_img = array(
            '#theme' => 'image_formatter',
            '#item' => $icon,
            '#image_style' => 'themen_icon_36x36',
            '#path' => '',
            '#access' => 1
          );
          $variables['items'][$key]['#markup'] = drupal_render($icon_img);
        }
        $variables['items'][$key]['#markup'] .= l($item['#markup'], 'taxonomy/term/' . $tid, array('html' => TRUE));
      }
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

function ipwa_preprocess_views_view_unformatted(&$vars) {
  $function_name = __FUNCTION__ . '__' . $vars['view']->name;
  if (function_exists($function_name)) {
    $function_name($vars);
  }
}

function ipwa_preprocess_views_view_unformatted__alles_zum_thema(&$vars){
  $view = $vars['view'];
  foreach($view->result as $id => $value) {
    $vars['node_type'][$id] = $value->node_type;
  }
}

/**
 * Implements theme_preprocess_views_view().
 *
 * Theme preprocess function for views-view.tpl.php
 *
 * @params $vars
 *
 */
function ipwa_preprocess_views_view(&$vars) {
  if($vars['name'] == 'latest_content_doorpage' && $vars['display_id'] == 'block_5'){
    // variable to embedd latest CT publication view
    if (!empty(views_get_view_result("latest_content_doorpage", "block_1", arg(2)))) {
      $vars['latest_publication_pg'] = views_embed_view("latest_content_doorpage", "block_1", arg(2));
    }
    // variable to embedd latest CT termin view
    if (!empty(views_get_view_result("latest_content_doorpage", "block_2", arg(2)))) {
      $vars['latest_termin_pg'] = views_embed_view("latest_content_doorpage", "block_2", arg(2));
    }
  }

  if($vars['name'] == 'latest_content_doorpage' && $vars['display_id'] == 'block_3'){
    // variable to embedd latest CT publication view
    if (!empty(views_get_view_result("latest_content_doorpage", "block_4", arg(2)))) {
      $vars['latest_publication_wa'] = views_embed_view("latest_content_doorpage", "block_4", arg(2));
    }
    // variable to embedd latest CT termin view
    if (!empty(views_get_view_result("latest_content_doorpage", "block_6", arg(2)))) {
      $vars['latest_termin_wa'] = views_embed_view("latest_content_doorpage", "block_6", arg(2));
    }

  }
}

