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
  if ($variables['type'] == 'bild') {
    // Don't show title
    $variables['title'] = '';
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
      $variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['group_middle_wrapper']['ical']['#weight'] = isset($variables['elements']['#fieldgroups']['group_ical']) ? $variables['elements']['#fieldgroups']['group_ical']->weight : -1;

    }
  }
  if ($variables['type'] == 'termin') {
    // Display of Ort field
    if (isset($variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['field_ort']) && !empty($variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['field_ort'])) {
      $variables['content']['group_page_info']['rel_ort'] = '';
      $variables['content']['group_page_info']['rel_ort']['#markup'] = $variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['field_ort'][0]['#markup'];
      $variables['content']['group_page_info']['rel_ort']['#weight'] = isset($variables['elements']['#fieldgroups']['group_related_ort']) ? $variables['elements']['#fieldgroups']['group_related_ort']->weight : -1;

    }

    // replace of 'to' with'-' for field 'datum' in CT 'termin'
    if(!empty($variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['group_middle_wrapper']['field_event_datum'])){
      if (strpos($variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['group_middle_wrapper']['field_event_datum'][0]['#markup'], 'to') !== false) {
        $variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['group_middle_wrapper']['field_event_datum'][0]['#markup'] = str_replace('to','-',$variables['content']['group_page_info']['group_top_wrapper']['group_left_top_wrapper']['group_middle_wrapper']['field_event_datum'][0]['#markup']);
      }
    }
  }
/** for putting content of field 'descrition to field 'copyright' and to hide field 'description' */
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
  $view = $vars['view'];
  foreach($view->result as $id => $value) {
    $vars['node_nid'][$id] = $value->nid;
  }
  $vars['name'] = $view->name;
  $vars['display_id'] = $view->current_display;

  $view = $vars['view'];
  foreach($view->result as $id => $value) {
  $vars['node_type'][$id] = $value->node_type;
  }
$view = $vars['view'];
  foreach($view->result as $id => $value) {
    $vars['solr_id'][$id]= $value->entity;
  }
  $view = $vars['view'];
  foreach($view->result as $id => $value) {
    $vars['solr_type'][$id]=$value->_entity_properties['type'];
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

