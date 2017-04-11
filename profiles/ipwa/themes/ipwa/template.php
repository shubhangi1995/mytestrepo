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
  if ($variables['type'] == 'bild') {
    // Don't show title
    $variables['title'] = '';
  }
//  print_r($variables['content'] );
//  die();
  // Display view 'Kommende Veranstaltungen' instaed of field 'Veranstaltungen'
  if (!empty($variables['field_veranstaltungen'])) {
    $views = views_get_view_result("related_content", "block_1", $variables['nid']);
    $related_event_view = '';
    if (!empty($views)) {
      $related_event_view = '<h2 class="view-title">' . t('Kommende Veranstaltungen') . '</h2>';
      //for embedding view Kommende Veranstaltungen
      $related_event_view .= views_embed_view("related_content", "block_1", $variables['nid']);
      $variables['content']['related_event']['#markup'] = $related_event_view;
      $variables['content']['related_event']['#weight'] = $variables['elements']['#fieldgroups']['group_related_event']->weight;
    }
  }

  // display view 'Dokumente und Publikationen' instead of field 'Dokumente und Publikationen'
  if (!empty($variables['field_dokumente_und_publikatione'])) {
    $view = views_get_view_result("related_content", "block_2", $variables['nid']);
    $related_doc_view = '';
    if (!empty($view)) {
      $related_doc_view = '<h2 class="view-title">' . t('Dokumente und Publikationen') . '</h2>';
      //for embedding view Kommende Veranstaltungen
      $related_doc_view .= views_embed_view("related_content", "block_2", $variables['nid']);
      $variables['content']['related_doc']['#markup'] = $related_doc_view;
      $variables['content']['related_doc']['#weight'] = $variables['elements']['#fieldgroups']['group_related_doc']->weight;
    }
  }


  if (!empty($variables['field_publication'])) {
    $view = views_get_view_result("related_content", "block_3", $variables['nid']);
    $related_pub_view = '';
    if (!empty($view)) {
      $related_pub_view = '<h2 class="view-title">' . t('Publikation') . '</h2>';
      //for embedding view Kommende Veranstaltungen
      $related_pub_view .= views_embed_view("related_content", "block_3", $variables['nid']);
      $variables['content']['rel_pub']['#markup'] = $related_pub_view;
      $variables['content']['rel_pub']['#weight'] = $variables['elements']['#fieldgroups']['group_rel_pub']->weight;
    }
  }

  // Change position of title field
  // (mostly will be displayed under date field)
  if (isset($variables['title']) && $variables['title']) {
      $variables['content']['title'] = array(
        '#markup' => '<h1 class="page-title">' . $variables['title'] . '</h1>',
        '#weight' => isset($variables['elements']['#fieldgroups']['group_title']) ? $variables['elements']['#fieldgroups']['group_title']->weight : -1);
    }
  }
  /*else {
    print_r( '<h1 class="page-title">' . $variables['title'] . '</h1>');
  }*/



  /**
   * Implements ipwa_preprocess_field().
   *
   * Theme preprocess function for field.tpl.php
   *
   * @params $variables
   *
   */

// to link the lable of referenced node with the actual node
  function ipwa_preprocess_field(&$variables)
  {
    $fields = array("field_meldungen_zum_thema", "field_initiatoren_zum_thema", "field_projekte_zum_thema", "field_f_rderbekanntmachungen", "field_publikation");
    if (in_array($variables['element']['#field_name'], $fields)) {
      foreach ($variables['items'] as $key => $item) {
        // alter field value to link to respective node.
        $variables['items'][$key]['#markup'] = l($item['#markup'], 'node/' . $variables['element']['#items'][$key]['target_id']);
      }
    }
  }

