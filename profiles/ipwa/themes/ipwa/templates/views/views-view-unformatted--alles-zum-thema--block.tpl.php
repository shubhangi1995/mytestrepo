<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php global $base_url ;?>
<?php if (!empty($title)): ?>
    <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php if(isset($node_nid[$id]) && !empty($node_nid[$id])) :?>
    <?php $path = drupal_get_path_alias("node/" . $node_nid[$id]); ?>
  <?php endif ;?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
   <a  href="<?php print $base_url . '/' . $path; ?>" >
  <div class="row-container <?php if (isset($node_type)) {print ($node_type[$id] == 'projekt') ? 'project-blue' : '' ; }?>">
  <?php print $row; ?>
  </div>
  </a>
  </div>
<?php endforeach; ?>