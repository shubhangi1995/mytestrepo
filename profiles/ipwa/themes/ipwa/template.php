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

    if (!empty($variables['content']['field_copyright'])) {
      $variables['content']['field_copyright']['#title'] = '© Bildquelle';
    }

}
  if ($variables['type'] =='article'|| $variables['type'] =='publikation'){
    $variables['content']['field_Quellenangabe']['#title'] = 'Quelle: ';
  }
}