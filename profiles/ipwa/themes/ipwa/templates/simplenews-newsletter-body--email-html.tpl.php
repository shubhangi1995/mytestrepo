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
</head>

<body leftmargin="0" marginwidth="0" topmargin="0" marginheight="0" offset="0">
    <table align="center" border="0" cellpadding="0" cellspacing="0" height="100%" width="550" id="bodyTable" style="font-family:Arial,Helvetica, sans-serif;margin:20px; font-size:16px;color:#000;">
	<tbody>
		<tr>
			<td>
			<div style = "float:left;font-weight:bold;">Datum : 29/03/1990</div>
			<div style = "float:right;font-weight:bold;">Articles</div>
			</td>
		</tr>
		<tr>
		<td>
			<h1 style="font-size:30px;margin:30px 0 20px;">Page Header</h1>
			<p style="margin:5px 0;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla venenatis eleifend nulla, ac ultricies urna lacinia quis. Phasellus varius sapien ut mauris imperdiet, placerat varius felis vehicula. Pellentesque libero neque, imperdiet ut massa in, auctor dignissim dui. Morbi ullamcorper mi quis sem sollicitudin, congue iaculis risus rhoncus. Aliquam auctor vitae nibh ut vehicula. Nunc in sagittis enim, ut faucibus erat. Nunc placerat ornare aliquam. Proin volutpat nisl in ligula interdum, sit amet elementum nisi tempor. Praesent varius, arcu varius aliquam pretium, magna odio auctor dolor, non dignissim nisi mi vel diam. Sed at leo consequat, iaculis mauris vel, rutrum metus. Vestibulum eget aliquam purus.</p>
			<h2 style="font-size:22px;margin:15px 0">Sub heading</h2>
			<p style="margin:5px 0;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla venenatis eleifend nulla, ac ultricies urna lacinia quis. Phasellus varius sapien ut mauris imperdiet, placerat varius felis vehicula. Pellentesque libero neque, imperdiet ut massa in, auctor dignissim dui. Morbi ullamcorper mi quis sem sollicitudin, congue iaculis risus rhoncus. Aliquam auctor vitae nibh ut vehicula. Nunc in sagittis enim, ut faucibus erat. Nunc placerat ornare aliquam. Proin volutpat nisl in ligula interdum, sit amet elementum nisi tempor</p>
		</td>
		</tr>
		<tr>
			<td>
				<h2 style="font-size:25px;background:#eee;padding:20px;margin-bottom:20px;">Aktualles</h2>
				<div style="background:#eee;padding:30px 20px ;">
					<div><a href="#" style="color:#000;margin:20px 0;font-weight:bold;text-decoration:none;font-size:24px;">Some Title</a></div>
					<p style="margin:5px 0;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla venenatis eleifend nulla, ac ultricies urna lacinia quis. Phasellus varius sapien ut mauris imperdiet, placerat varius felis vehicula. Pellentesque libero neque, imperdiet ut massa in, auctor dignissim dui. Morbi ullamcorper mi quis sem sollicitudin, congue iaculis risus rhoncus. Aliquam auctor vitae nibh ut vehicula. Nunc in sagittis enim, ut faucibus erat. Nunc placerat ornare aliquam. Proin volutpat nisl in ligula interdum, sit amet elementum nisi tempor</p>
					<div><a href="#" style="color:#000;font-weight:bold;text-decoration:none;font-size:24px;">Some Title</a></div>
					<p style="margin:5px 0;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla venenatis eleifend nulla, ac ultricies urna lacinia quis. Phasellus varius sapien ut mauris imperdiet, placerat varius felis vehicula. Pellentesque libero neque, imperdiet ut massa in, auctor dignissim dui. Morbi ullamcorper mi quis sem sollicitudin, congue iaculis risus rhoncus. Aliquam auctor vitae nibh ut vehicula. Nunc in sagittis enim, ut faucibus erat. Nunc placerat ornare aliquam. Proin volutpat nisl in ligula interdum, sit amet elementum nisi tempor</p>
					<div style="margin:10px 0;"><a href="#" style="color:#000;font-weight:bold;text-decoration:none;font-size:24px;">Some Title</a></div>
					<div style="margin:10px 0;">
					<div style="float:left;margin-right:10px;"><a href="#" style="color:#000;font-weight:bold;text-decoration:none;font-size:24px;">Some Title</a></div>
					<div style="margin-top:5px;display:inline-block;"><a href="#"> > more</a></div>
					</div>
					<div style="margin:10px 0;"><a href="#" style="color:#000;font-weight:bold;text-decoration:none;font-size:24px;">Some Title</a></div>
					<div style="margin:10px 0;">
					<div style="float:left;margin-right:10px;"><a href="#" style="color:#000;font-weight:bold;text-decoration:none;font-size:24px;">Some Title</a></div>
					<div style="margin-top:5px;display:inline-block;"><a href="#"> > more</a></div>
					</div>
				</div>
				<h2 style="font-size:25px;background:#eee;padding:20px;margin-bottom:20px;">Digital Project</h2>
				<div style="background:#eee;padding:30px 20px ;">
				<div><a href="#" style="color:#000;margin:20px 0;font-weight:bold;text-decoration:none;font-size:24px;">Some Title</a></div>
				<p style="margin:5px 0;">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla venenatis eleifend nulla, ac ultricies urna lacinia quis. Phasellus varius sapien ut mauris imperdiet, placerat varius felis vehicula. Pellentesque libero neque, imperdiet ut massa in, auctor dignissim dui. Morbi ullamcorper mi quis sem sollicitudin, congue iaculis risus rhoncus. Aliquam auctor vitae nibh ut vehicula. Nunc in sagittis enim, ut faucibus erat. Nunc placerat ornare aliquam. Proin volutpat nisl in ligula interdum, sit amet elementum nisi tempor <a href="#"> > more</a></p>
				</div>
				<h2 style="font-size:25px;background:#eee;padding:20px;margin-bottom:20px;">Termine</h2>
				<div style="background:#eee;padding:30px 20px ;">
				<div style="margin-bottom:50px;">
				<div style="margin:20px 0;">Ort text Location</div>
				<div><a href="#" style="color:#000;margin:20px 0;font-weight:bold;text-decoration:none;font-size:24px;">Some Title</a></div>
				<div style="margin:10px 0;">Datum : 29/03/1990</div>
				<div><a href="#"> > more</a></div>
				</div>
				<div style="margin-bottom:50px;">
				<div style="margin:20px 0;">Ort text Location</div>
				<div><a href="#" style="color:#000;margin:20px 0;font-weight:bold;text-decoration:none;font-size:24px;">Some Title</a></div>
				<div style="margin:10px 0;">Datum : 29/03/1990</div>
				<div><a href="#"> > more</a></div>
				</div>
				</div>
			</td>
		</tr>
		</tbody>
    </table>
</body>
</html>