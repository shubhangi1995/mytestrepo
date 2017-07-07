<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
<?php print render($title_prefix); ?>
<?php if ($title): ?>
  <?php print $title; ?>
<?php endif; ?>
<?php print render($title_suffix); ?>
  <div class="view-sub-wrapper">
<?php if ($header): ?>
  <div class="view-header">
    <?php print $header; ?>
  </div>
<?php endif; ?>

<?php if ($exposed): ?>
  <div class="view-filters">
    <?php print $exposed; ?>
  </div>
<?php endif; ?>

<?php if ($attachment_before): ?>
  <div class="attachment attachment-before">
    <?php print $attachment_before; ?>
  </div>
<?php endif; ?>

<?php if ($rows): ?>
  <div class="view-content">
    <?php print $rows; ?>
  </div>
<?php elseif ($empty): ?>
  <div class="view-empty">
    <?php print $empty; ?>
  </div>
<?php endif; ?>

<?php if ($pager): ?>
  <?php print $pager; ?>
<?php endif; ?>

<?php if ($attachment_after): ?>
  <div class="attachment attachment-after">
    <?php print $attachment_after; ?>
  </div>
<?php endif; ?>

<?php if ($more): ?>
  <?php print $more; ?>
<?php endif; ?>

<?php if ($footer): ?>
  <div class="view-footer">
    <?php print $footer; ?>
  </div>
<?php endif; ?>

<?php  // Code for embed map teaser block view  ?>
<?php $front_url = drupal_get_normal_path(variable_get('site_frontpage', 'node')); ?>
<?php $front_nid = explode('/', $front_url); ?>
<?php $front_nid = end($front_nid); ?>
<?php $node = node_load($front_nid); ?>

<?php if(isset($node->field_anzuzeigende_seitenmodule) && !empty($node->field_anzuzeigende_seitenmodule)): ?>
  <?php foreach ($node->field_anzuzeigende_seitenmodule['und'] as $pid): ?>
    <?php $entity_data = entity_load('paragraphs_item', array($pid['value'])); ?>
    <?php if(!empty($entity_data)): ?>
      <?php if($entity_data[$pid['value']]->bundle == 'frontpage_map_teaser_paragraph'): ?>
        <?php $id = $pid['value']; ?>
      <?php endif; ?>
    <?php endif; ?>
  <?php endforeach; ?>
<?php endif; ?>

<?php if(isset($id)): ?>
  <?php print views_embed_view('map_teaser', 'block', $id);  ?>
<?php endif; ?>
 <div class ="Schaufenster_Digitales_NRW_map">
  <?php global $base_path;?>
   <img src="/profiles/ipwa/themes/ipwa/images/Karte_Karte.png" alt="Schaufenster_Digitales_NRW_map">
 </div>
</div>
<?php if ($feed_icon): ?>
  <div class="feed-icon">
    <?php print $feed_icon; ?>
  </div>
<?php endif; ?>
</div>