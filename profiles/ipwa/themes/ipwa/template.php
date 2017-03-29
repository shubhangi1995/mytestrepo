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

    // Label change for field 'Copyright'
    if (!empty($variables['content']['field_copyright'])) {
      $variables['content']['field_copyright']['#title'] = '© Bildquelle';
    }
  }
  // Label change for field 'Videoquelle'
  if (!empty($variables['content']['field_videoquelle'])) {
    $variables['content']['field_videoquelle']['#title'] = '© Videoquelle';
  }
}

