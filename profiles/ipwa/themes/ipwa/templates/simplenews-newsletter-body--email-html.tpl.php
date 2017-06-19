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
<?php
/**
 * Following code is for print the Date and Issue No. of Newsletter
 */
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title><?=$title;?></title>
	<style>
		body{
			display:block;
		}
		#center {
			width:auto;
		}
		* {
			margin:0;
			padding:0;
		}
		p span{
			font-size:20px !important;
			background-color:transparent !important;
		}
		p span span{
			font-size:20px !important;
			background-color:transparent !important;
		}
	</style>
</head>

<body style="width:640px;">
<table align="center" border="0" cellpadding="0" cellspacing="0" width="620" id="bodyTable" style="font-family:Arial,Helvetica, sans-serif; font-size:16px; color:#273753; width:640px;">
  
	<tr>
	<td width="620" align="center" style="width:620px;" style="color:#273753">
		<table width="620" align="center">
			<tr style="padding:10px 20px; background:#eff2f7;">
				<td align="left" style="padding:20px 10px;">
						<img src="<?php print file_create_url(drupal_get_path('theme', 'ipwa')); ?>/images/logo.png" alt="Logo1" style="height:90px;"/>
				</td>
				<td align="right" style="padding:20px 10px;">
						<img src="<?php print file_create_url(drupal_get_path('theme', 'ipwa')); ?>/images/EU_Logo.png" alt="Logo2" style = "height:90px;"/>
				</td>
			</tr>
		</table>
	</td>
	</tr>
    <tr>
	<td  style="width:620px;" style="color:#273753">
	<table style="font-family:Arial,Helvetica, sans-serif; font-size:16px; color:#273753; width:640px;">
	<tr>
	 <td align="left" style = "font-weight:bold;color:#273753">
          <?php
          /**
           * Following code is for print the Date and Issue No. of Newsletter
           */
          ?>
          <?php global $base_url; ?>
          <?php if(isset($build)) : ?>
            <?php if(isset($build['field_datum'])) : ?>
            <?php print $build['field_datum'][0]['#markup']; ?>
              <?php $build['field_datum'][0]['#markup'] = ''; ?>
            <?php endif; ?>
			</td>
			<td align="right" style = "font-weight:bold;color:#273753">
            <?php if(isset($build['field_issue_no'])) : ?>
            <?php print $build['field_issue_no'][0]['#markup']; ?>
              <?php $build['field_issue_no'][0]['#markup'] = ''; ?>
            <?php endif; ?>
          <?php endif; ?>
        </td>
	</tr>
	</table>
	</td>
	
       
    </tr>
    <tr>
        <td  style="width:620px;color:#273753">
          <?php
            /**
            * Following code is for print the Title of Newsletter
            */
            ?>
          <?php if(isset($title)) : ?>
            <?php // look up the alias from the url_alias table ?>
            <?php $source = 'node/' .$build['body']['#object']->nid; ?>
            <?php $alias = db_query("SELECT alias FROM {url_alias} WHERE source = '$source'")->fetchField(); ?>
              <h1 style="font-size:30px;margin:30px 0 20px;"><a href="<?php print $base_url.'/'.$alias; ?>"><?php  print $title; ?></a></h1>
          <?php endif; ?>
          <?php
          /**
           * Following code is for print the body of Newsletter
           */
          ?>
          <?php if(isset($build)) : ?>
            <?php if(!empty($build['body'][0])) : ?>
                  <p style="margin:5px 0;"><?php  print $build['body'][0]['#markup']; ?></p>
            <?php  endif; ?>
          <?php endif; ?>
            <!--<h2 style="font-size:22px;margin:15px 0">Sub heading</h2>
            <p style="margin:5px 0;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla venenatis eleifend nulla, ac ultricies urna lacinia quis. Phasellus varius sapien ut mauris imperdiet, placerat varius felis vehicula. Pellentesque libero neque, imperdiet ut massa in, auctor dignissim dui. Morbi ullamcorper mi quis sem sollicitudin, congue iaculis risus rhoncus. Aliquam auctor vitae nibh ut vehicula. Nunc in sagittis enim, ut faucibus erat. Nunc placerat ornare aliquam. Proin volutpat nisl in ligula interdum, sit amet elementum nisi tempor</p>-->
        </td>
    </tr>
    <tr>
        <td  style="width:620px;color:#273753">

          <?php
          /**
           * Following code is for print the Node referred in Newsletter
           */
          ?>
          <?php if(isset($build)) : ?>
            <?php if(!empty($build['#node']->field_newsletter_group)) : ?>
              <?php foreach($build['#node']->field_newsletter_group['und'] as $items): ?>
                <?php $field_data = entity_load('field_collection_item', array($items['value'])); ?>
                <?php if(!empty($field_data)) : ?>

                  <?php //Following code is for print Title of Group. ?>
                  <?php foreach($field_data[$items['value']]->field_group_heading['und'] as $group_title): ?>
                    <h2 style="font-size:25px;background:#eff2f7;padding:20px 0;text-align:center;border-bottom:20px solid #fff;border-top:20px solid #fff; color:#273753s"><?php print $group_title['value']; ?></h2>
					<table style="font-family:Arial,Helvetica, sans-serif;margin:0 auto; font-size:16px;color:#273753;width:640px; width = "620">
					<tr>
					<td style="padding:10px 20px; background:#eff2f7;color:#273753">
					<div style="background:#eff2f7; padding:30px 20px; color:#273753">
					<?php foreach ($field_data[$items['value']]->field_newsletter_content_types['und'] as $node_data): ?>
                      <?php // look up the alias from the url_alias table ?>
                      <?php $source = 'node/' .$node_data['entity']->nid; ?>
                      <?php $alias = db_query("SELECT alias FROM {url_alias} WHERE source = '$source'")->fetchField(); ?>
                      <?php $node = node_load($node_data['entity']->nid); ?>
                      <?php if($node_data['entity']->type == 'termin') : ?>
                        
                        <div>

                        <?php //print location of Termin. ?>
                        <?php if(isset($node->field_ort['und'][0])) : ?>
                          <div><?php print $node->field_ort['und'][0]['value']; ?></div>
                        <?php endif; ?>

                        <?php //print Title of Termin. ?>
                          <div><a href="<?php print $base_url.'/'.$alias; ?>" style="color:#273753;font-weight:bold;text-decoration:none;font-size:18px;">
                              <?php print $node_data['entity']->title; ?></a>
                          </div>

                        <?php //print Date of Termin. ?>
                        <?php if (!empty($node_data['entity']->field_event_datum)) : ?>
                          <?php foreach($node_data['entity']->field_event_datum as $event_date): ?>
                            <?php $occurence = count($event_date); ?>
                            <?php $startDate = date("d.m.Y", strtotime($event_date[0]['value'])); ?>
                            <?php $enddate = date("d.m.Y", strtotime($event_date[$occurence - 1]['value2'])); ?>
                            <?php if(($occurence > 1) || (($event_date[0]['value'] != $event_date[0]['value2']))) : ?>
                              <?php $output = ''; ?>
                              <?php $output = '<div class="date-repeat-rule">' . $output . '</div>'; ?>
                              <?php $output .= '<div class="date-display-range"><span class="date-display-start">' . $startDate . '</span> - <span class="date-display-end">' . $enddate . '</span></div>'; ?>
                                <div style="margin:10px 0;"><?php print $output; ?></div>
                            <?php else: ?>
                                <div style="margin:10px 0;color:#e74712;font-weight:bold;"><?php print $startDate; ?></div>
                            <?php endif; ?>
                          <?php endforeach; ?>
                             </div>
                            
                        <?php endif; ?>
                      <?php  else: ?>
                        <div>

                        <?php //print Title of Other content excluded from Termin. ?>
                          <div><a href="<?php print $base_url.'/'.$alias; ?>" style="color:#273753;font-weight:bold;text-decoration:none;font-size:18px;color:#273753">
                            <?php print $node_data['entity']->title; ?></a>
                          </div>

                        <?php //print body of Other content excluded from Termin. ?>
                        <?php if(isset($node->body['und'][0])) : ?>
                          <?php if(isset($node->body['und'][0])) : ?>
                          <?php $title_link = $base_url.'/'.$alias; ?>
                            <?php $body = (strlen($node->body['und'][0]['value']) > 200) ? substr($node->body['und'][0]['value'],0,200).
                              '...<div style="margin:10px 0;"><div style="margin-top:5px;display:inline-block;color:#273753"><a href="'.$title_link.'"> > mehr</a></div></div>' : $node->body['und'][0]['value']; ?>
                            <p style="margin:5px 0; font-size:20px !important;background:none !important;color:#273753"><?php print $body; ?></p>
                          <?php endif; ?>
                        <?php endif; ?>
                          </div>
                      <?php endif; ?>
                    <?php endforeach; ?>
					</div>
					</td>
					</tr>
					</table>
                    
                  <?php endforeach; ?>
                <?php  endif; ?>
              <?php endforeach; ?>
            <?php  endif; ?>
          <?php endif; ?>
        </td>
    </tr>
   <tr>
		<td>
			<table style="font-family:Arial,Helvetica, sans-serif; font-size:16px; color:#273753; width:640px;">
				<tr style="padding:10px 20px; background:#eff2f7;">
				<td align="left" style="color:#273753;">
				<span style="font-weight:bold;color:#273753">Folden sie uns auf :</span> <span><a href="#"><img src = "<?php print file_create_url(drupal_get_path('theme', 'ipwa')); ?>/images/fb.png" alt="FB" style="margin-right:5px;"/></a></span><span style="color:#eff2f7;font-size:8px;">12</span><span><a href="#"><img src = "<?php print file_create_url(drupal_get_path('theme', 'ipwa')); ?>/images/twitter.png" alt="Twitter" style="margin-right:5px;"/></a></span> <span style="color:#eff2f7;font-size:8px;">12</span><span><a href="#"><img src = "<?php print file_create_url(drupal_get_path('theme', 'ipwa')); ?>/images/linkedin.png" alt="LinkedIn" style="margin-right:5px;"/></a></span>
				</td>
				<td align="right" style="color:#273753;">
				<a href="#">Impressum</a><span style="color:#eff2f7;font-size:8px;">12</span><a href="<?php print $base_url.'/de/content/kontaktformular'; ?>">Contact</a>
				</td>
				</tr>
				<tr style="padding:10px 20px;">
					<td align="left" style="color:#273753;">
					<span><img src="<?php print file_create_url(drupal_get_path('theme', 'ipwa')); ?>/images/EU_Logo.png" alt = "footer_logo1" /></span> <span style="color:#eff2f7;font-size:8px;">12</span> <span><img src="<?php print file_create_url(drupal_get_path('theme', 'ipwa')); ?>/images/EFRE.NRW.png" alt = "footer_logo2" /></span> <span style="color:#eff2f7;font-size:8px;">12</span> <span><img src="<?php print file_create_url(drupal_get_path('theme', 'ipwa')); ?>/images/MWEI.png" alt = "footer_logo3" /></span>
					</td>
				</tr>
				<tr style="padding:10px 20px; background:#eff2f7;">
				<td style="color:#273753;">
					<div style="margin-bottom:25px;color:#273753;">Verantwrotlich im Sinne von $55 Abs. 2RStV ..... , Redaktion : .... , E-Mail Adresse : ....</div>
					<div style="margin-bottom:25px;color:#273753;">Sie Konnen diesen Newsletter <a href= "#">hier abbestellen.</a></div>
					<div style="color:#273753;">© 2017  Ministerium für Wirtschaft, Energie, Industrie, Mittelstand und  Handwerk des Lands Nordrhein-Westfalen</div>
				</td>
				</tr>
			</table>
		</td>
   </tr>
</table>
</body>
</html>