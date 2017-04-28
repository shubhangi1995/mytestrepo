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
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <div class="row-container">
      <?php print $row; ?>
    </div>
  </div>
<?php endforeach; ?>