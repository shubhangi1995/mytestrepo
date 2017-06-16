<?php
/**
 * Created by PhpStorm.
 * User: pram
 * Date: 4/28/2017
 * Time: 1:46 PM
 */


/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
global $base_url;
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php $views1=array("themenzuweisung_flyouts","right_front_map_teaser","related_content","map-teaser"); ?>
<?php if (!(in_array($view->name,$views1))): ?>
<?php foreach ($rows as $id => $row): ?>
<?php $path = drupal_get_path_alias("node/" . $node_nid[$id]); ?>
<div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
  <a href="<?php print $base_url . '/' . $path; ?>" >
  <div class="row-container">
    <?php print $row; ?>
  </div>
  </a>
</div>
<?php endforeach; ?>
<?php else:?>
<?php foreach ($rows as $id => $row): ?>
<div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
  <div class="row-container">
    <?php print $row; ?>
  </div>
</div>
<?php endforeach;?>
<?php endif; ?>
