<?php

/**
 * @file
 * Default theme implementation to format the simplenews newsletter body.
 *
 * Copy this file in your theme directory to create a custom themed body.
 * Rename it to override it. Available templates:
 *   simplenews-newsletter-body--[tid].tpl.php
 *   simplenews-newsletter-body--email-html.tpl.php
 *   simplenews-newsletter-body--[tid]--[view mode].tpl.php
 * See README.txt for more details.
 *
 * Available variables:
 * - $build: Array as expected by render()
 * - $build['#node']: The $node object
 * - $title: Node title
 * - $language: Language code
 * - $view_mode: Active view mode
 * - $simplenews_theme: Contains the path to the configured mail theme.
 * - $simplenews_subscriber: The subscriber for which the newsletter is built.
 *   Note that depending on the used caching strategy, the generated body might
 *   be used for multiple subscribers. If you created personalized newsletters
 *   and can't use tokens for that, make sure to disable caching or write a
 *   custom caching strategy implemention.
 *
 * @see template_preprocess_simplenews_newsletter_body()
 */
?>
<?php global $base_url; ?>
<?php if(isset($build)) : ?>
  <?php  print $build['field_datum'][0]['#markup']; ?>
  <?php  print $build['field_issue_no'][0]['#markup']; ?>
  <?php  $build['field_datum'][0]['#markup'] = ''; ?>
  <?php  $build['field_issue_no'][0]['#markup'] = ''; ?>
<?php endif; ?>
<?php if(isset($title)) :
  //print_r(drupal_lookup_path("alias", "node/".$build['body']['#object']->nid));
  //print_r(drupal_get_path_alias('node/'.$build['body']['#object']->nid));
  ?>
    <h1><a href="<?php print $base_url.'/node/'.$build['body']['#object']->nid; ?>"><?php  print $title; ?></a></h1>
<?php endif; ?>

<?php if(isset($build)) : ?>
  <?php if(!empty($build['#node']->field_newsletter_group)) : ?>
    <?php $field_data = entity_load('field_collection_item', array($build['#node']->field_newsletter_group['und'][0]['value'])); ?>
    <?php if(!empty($field_data)) : ?>
      <?php foreach($field_data[13]->field_group_heading['und'] as $group_title): ?>

        <?php foreach ($field_data[13]->field_newsletter_content_types['und'] as $node_data): ?>
          <?php $node = node_load($node_data['entity']->nid); ?>
              <a href="<?php print $base_url.'/node/'.$node_data['entity']->nid; ?>"><?php print $node_data['entity']->title; ?></a>
          <?php  if($node_data['entity']->type == 'termin'): ?>
            <?php  if (!empty($node_data['entity']->field_event_datum)) : ?>
              <?php  foreach($node_data['entity']->field_event_datum as $event_date): ?>
                <?php  $occurence = count($event_date); ?>
                <?php  $startDate = date("d.m.Y", strtotime($event_date[0]['value'])); ?>
                <?php  $enddate = date("d.m.Y", strtotime($event_date[$occurence - 1]['value2'])); ?>
                <?php  if (($occurence > 1) || (($event_date[0]['value'] != $event_date[0]['value2']))) { ?>
                <?php  $output = ''; ?>
                <?php  $output = '<div class="date-repeat-rule">' . $output . '</div>'; ?>
                <?php  $output .= '<div class="date-display-range"><span class="date-display-start">' . $startDate . '</span> - <span class="date-display-end">' . $enddate . '</span></div>'; ?>
                <?php  print $output; ?>
                <?php  }else{ ?>
              <?php  print $startDate; ?>
              <?php  } ?>
              <?php  endforeach; ?>
           <?php   endif; ?>
            <?php  endif; ?>
        <?php if(isset($node->field_ort['und'][0])) : ?>
          <?php print $node->field_ort['und'][0]['value']; ?>
          <?php   endif; ?>
        <?php if(isset($node->body['und'][0])) : ?>
         <h2><?php print $node->body['und'][0]['value']; ?></h2>
          <?php   endif; ?>
        <?php endforeach; ?>

     <?php endforeach; ?>
      <?php  endif; ?>

    <?php  endif; ?>
<?php endif; ?>
