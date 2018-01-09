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
<?php $views1=array("themenzuweisung_flyouts","right_front_map_teaser","related_content","map-teaser","map_teaser","alle_themen_teaser","search_list","event_on_calendar","event_calendar","project_single_view"); ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php if (!(in_array($view->name,$views1))): ?>
      <?php if (isset($node_nid[$id]) && $node_nid[$id]): ?>
        <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $node_nid[$id]); ?>" >
          <div class="row-container <?php if (isset($node_type)) {print ($node_type[$id] == 'projekt') ? 'project-blue' : '' ; }?>">
          <?php print $row; ?>
          </div>
        </a>
      <?php endif; ?>
    <?php else:?>
    <div class="row-container <?php if (isset($node_type)) {print ($node_type[$id] == 'projekt') ? 'project-blue' : '' ; }?>">
      <?php print $row; ?>
    </div>
    <?php endif; ?>
  </div>
<?php endforeach; ?>


