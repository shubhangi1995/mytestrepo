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

<!DOCTYPE html>

<html>

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?=$title;?></title>
</head>
<!--center-->
<body>
	
<table  align="center" border="0" cellpadding="0" cellspacing="0" class="bodyTable"  style=" font-family:Arial,Helvetica, sans-serif; font-size:16px; color:#273753;">
  
	<tr style="margin-bottom:15px;">
	<td  align="center"  style="color:#273753;">
		<table  align="left" style="" class="container">
			<tr style="padding:10px 0; background:#eff2f7;">
				<td align="left" style="padding:20px 10px;">
						<img src="/sites/default/files/newsletter_logos/NRW_4_d.png" alt="Logo NRW 4.0 Wirtschaft und Arbeit 4.0" style="width:200px;" class="logo1"/>
				</td>
				<td align="right" style="padding:20px 10px;">
						<img src="/sites/default/files/newsletter_logos/EU-Logo.png" alt="Logo des Europäischen Fonds für regionale Entwicklung der Europäischen Union" style = "width:180px;" class="logo2"/>
				</td>
			</tr>
		</table>
	</td>
	</tr>
    <tr>
	<td  style="" style="color:#273753">
	<table style="font-family:Arial,Helvetica, sans-serif; font-size:16px; color:#273753;" class="container">
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
        <td  style="color:#273753">
          <?php
            /**
            * Following code is for print the Title of Newsletter
            */
            ?>
		<div class="editor_content">
          <?php if(isset($title)) : ?>
            <h1 style="font-size:27px;margin:30px 0 20px;"><?php  print $title; ?></h1>
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
		  </div>
        </td>
    </tr>
    <tr>
        <td  style="color:#273753">

          <?php
          /**
           * Following code is for print the Node referred in Newsletter
           */
          ?>
		  <div>
          <?php if(isset($build)) : ?>
            <?php if(!empty($build['#node']->field_newsletter_group)) : ?>
              <?php foreach($build['#node']->field_newsletter_group['und'] as $items): ?>
                <?php $field_data = entity_load('field_collection_item', array($items['value'])); ?>
                <?php if(!empty($field_data)) : ?>

                  <?php //Following code is for print Title of Group. ?>
                  <?php foreach($field_data[$items['value']]->field_group_heading['und'] as $group_title): ?>
                    <h2 style="font-size:22px;background:#eff2f7;padding:20px 0;text-align:center;border-bottom:20px solid #fff;border-top:20px solid #fff; color:#273753;margin-top:30px;margin-bottom:-10px;"><a href="<?php print $group_title['url']; ?>" ><?php print $group_title['title']; ?></a></h2>
					<table style="font-family:Arial,Helvetica, sans-serif;margin:0 auto; font-size:16px;color:#273753;" class="container">
					<tr>
					<td style="padding:20px 20px; background:#eff2f7;color:#273753">
					<span style="background:#eff2f7; color:#273753">
					<?php foreach ($field_data[$items['value']]->field_newsletter_content_types['und'] as $node_data): ?>
                      <?php // look up the alias from the url_alias table ?>
                      <?php $source = 'node/' .$node_data['entity']->nid; ?>
                      <?php $alias = db_query("SELECT alias FROM {url_alias} WHERE source = '$source'")->fetchField(); ?>
                      <?php $node = node_load($node_data['entity']->nid); ?>
                      <?php if($node_data['entity']->type == 'termin') : ?>
                        
                        <div style="margin-bottom:45px;">

                        <?php //print location of Termin. ?>
                        <?php if(isset($node->field_ort['und'][0])) : ?>
                          <span><?php print $node->field_ort['und'][0]['value']; ?></span>
                        <?php endif; ?>

                        <?php //print Title of Termin. ?>
                          <span><a href="<?php print $base_url.'/'.$alias; ?>" style="color:#273753;font-weight:bold;text-decoration:none;">
                              <?php print $node_data['entity']->title; ?></a>
                          </span>

                        <?php //print Date of Termin. ?>
                        <?php if (!empty($node_data['entity']->field_event_datum)) : ?>
                          <?php foreach($node_data['entity']->field_event_datum as $event_date): ?>
                            <?php $occurence = count($event_date); ?>
                            <?php $startDate = date("d.m.Y", strtotime($event_date[0]['value'])); ?>
                            <?php $enddate = date("d.m.Y", strtotime($event_date[$occurence - 1]['value2'])); ?>
                            <?php if(($occurence > 1) || (($event_date[0]['value'] != $event_date[0]['value2']))) : ?>
                              <?php $output = ''; ?>
                              <?php $output = '<span class="date-repeat-rule">' . $output . '</span>'; ?>
                              <?php $output .= '<span class="date-display-range"><span class="date-display-start">' . $startDate . '</span> - <span class="date-display-end">' . $enddate . '</span></span>'; ?>
                                <span style="margin:10px 0 0;"><?php print $output; ?></span>
                            <?php else: ?>
                                <span style="margin:10px 0 0;color:#e74712;font-weight:bold;"><?php print $startDate; ?></span>
                            <?php endif; ?>
                          <?php endforeach; ?>
                             </div>
                            
                        <?php endif; ?>
                      <?php  else: ?>
                        <span>

                        <?php //print Title of Other content excluded from Termin. ?>
                          <span><a href="<?php print $base_url.'/'.$alias; ?>" style="color:#273753;font-weight:bold;text-decoration:none;font-size:16px;color:#273753">
                            <?php print $node_data['entity']->title; ?></a>
                          </span>

                        <?php //print body of Other content excluded from Termin. ?>
                        <?php if(isset($node->body['und'][0])) : ?>
                          <?php $title_link = $base_url.'/'.$alias; ?>
                            <?php $body = (strlen(strip_tags($node->body['und'][0]['value'])) > 200) ? substr(strip_tags($node->body['und'][0]['value']),0,200).
                              ' <b>...</b> <a href="'.$title_link.'" class="more_link"> > mehr</a>' : strip_tags($node->body['und'][0]['value']); ?>
                            <p style="margin:5px 0; background:none !important;color:#273753"><?php print $body; ?></p>
                        <?php else: ?>
                          <?php $title_link = $base_url.'/'.$alias; ?>
                          <?php $body = '<a href="'.$title_link.'" class="more_link"> > mehr</a>'; ?>
                            <p style="margin:5px 0;background:none !important;color:#273753"><?php print $body; ?></p>
                        <?php endif; ?>
                          </span>
                      <?php endif; ?>
                    <?php endforeach; ?>
					</span>
					</td>
					</tr>
					</table>
                    
                  <?php endforeach; ?>
                <?php  endif; ?>
              <?php endforeach; ?>
            <?php  endif; ?>
          <?php endif; ?>
		  </div>
        </td>
    </tr>
   <tr>
		<td>
			<table style="font-family:Arial,Helvetica, sans-serif; font-size:16px; color:#273753;" class="container">
                <tr style="padding:20px 20px; background:#eff2f7;">
                    <td align="right" style="color:#273753;">
                        <a href="<?php print $base_url . '/artikel/impressum'; ?>">Impressum</a><span style="color:#eff2f7;font-size:8px;">12</span><a href="<?php print $base_url.'/content/kontakt'; ?>">Kontakt</a>
                    </td>
                </tr>
                <tr style="padding:20px 20px;">
                    <td align="left" style="color:#273753;">
                        <img src="/sites/default/files/newsletter_logos/EU_Logo.png" alt = "Logo des Europäischen Fonds für regionale Entwicklung der Europäischen Union" width="190" class="footer_image1"/>
                        <span style="color:#eff2f7;font-size:8px;">12</span>
                        <img src="/sites/default/files/newsletter_logos/EFRE.NRW.png" alt = "EFRE.NRW - Investitionen in Wachstum und Beschäftigung" width="190" class="footer_image2"/>
                        <span style="color:#eff2f7;font-size:8px;">12</span>
                        <img src="/sites/default/files/newsletter_logos/NRW_MWIDE_RGB.png" alt = "Logo des Ministeriums für Wirtschaft, Innovation, Digitalisierung und Energie des Landes Nordrhein-Westphalen" width="190" class="footer_image3"/>
                    </td>
                </tr>
				<tr style="background:#eff2f7;">
				<td style="color:#273753;padding:20px;">
					<div style="margin-bottom:25px;color:#273753;line-height:22px;"><div class="small-font">Redaktionell verantwortlich im Sinne § 5 TMG bzw. § 55 RStV: Dr. Thomas König</div>
            <div class="small-font">Redaktion: Dr. Jan Christopher Brandt, VDI Technologiezentrum GmbH, VDI-Platz 1, 40468 Düsseldorf</div>
			<div class="small-font">E-Mail: <span class="more_link">nrw40-redaktion@vdi.de</span></div>
          </div>
					<div style="margin-bottom:25px;color:#273753;line-height:22px;" class="small-font">Sie können diesen Newsletter <a class="more_link" href= "<?php print token_replace('[simplenews-subscriber:unsubscribe-url]', array('sanitize' => FALSE)); ?>">hier abbestellen.</a></div>
					<div style="color:#273753;line-height:22px;" class="small-font">© 2018 Ministerium für Wirtschaft, Innovation, Digitalisierung und Energie des Landes Nordrhein-Westfalen</div>
				</td>
				</tr>
			</table>
		</td>
   </tr>
</table>
</body>
<!--/center-->
</html>