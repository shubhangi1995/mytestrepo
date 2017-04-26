<?php
/**
 * @file
 * ipwa_doorpage.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function ipwa_doorpage_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'paragraphs_item';
  $panelizer->panelizer_key = 'frontpage_map_teaser_paragraph';
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->name = 'paragraphs_item:frontpage_map_teaser_paragraph:default:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c4ad95b4-0a95-4b19-bdcf-16370457e8c5';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'paragraphs_item:frontpage_map_teaser_paragraph:default:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-190003a8-cc6c-4f84-b40e-2bc9b18b4114';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'paragraphs_item:field_bild';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_image_image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'map_teaser_icon_68x68',
      'image_link' => '',
    ),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '190003a8-cc6c-4f84-b40e-2bc9b18b4114';
  $display->content['new-190003a8-cc6c-4f84-b40e-2bc9b18b4114'] = $pane;
  $display->panels['left'][0] = 'new-190003a8-cc6c-4f84-b40e-2bc9b18b4114';
  $pane = new stdClass();
  $pane->pid = 'new-27f4da71-a6d9-4e11-b260-df441af7a89c';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'paragraphs_item:field_paragraph_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '27f4da71-a6d9-4e11-b260-df441af7a89c';
  $display->content['new-27f4da71-a6d9-4e11-b260-df441af7a89c'] = $pane;
  $display->panels['left'][1] = 'new-27f4da71-a6d9-4e11-b260-df441af7a89c';
  $pane = new stdClass();
  $pane->pid = 'new-525c3dac-619d-41da-bceb-f480be099ffe';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'paragraphs_item:field_flie_text_bereich';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '525c3dac-619d-41da-bceb-f480be099ffe';
  $display->content['new-525c3dac-619d-41da-bceb-f480be099ffe'] = $pane;
  $display->panels['left'][2] = 'new-525c3dac-619d-41da-bceb-f480be099ffe';
  $pane = new stdClass();
  $pane->pid = 'new-fc428ab0-ec21-4745-85db-993bed8cd010';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'paragraphs_item:field_quellenangabe';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'fc428ab0-ec21-4745-85db-993bed8cd010';
  $display->content['new-fc428ab0-ec21-4745-85db-993bed8cd010'] = $pane;
  $display->panels['left'][3] = 'new-fc428ab0-ec21-4745-85db-993bed8cd010';
  $pane = new stdClass();
  $pane->pid = 'new-b094f3b9-39e1-48d2-8f14-cbf6e55bafbc';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'right_front_map_teaser';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'context' => array(
      0 => 'panelizer.item-id',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b094f3b9-39e1-48d2-8f14-cbf6e55bafbc';
  $display->content['new-b094f3b9-39e1-48d2-8f14-cbf6e55bafbc'] = $pane;
  $display->panels['right'][0] = 'new-b094f3b9-39e1-48d2-8f14-cbf6e55bafbc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['paragraphs_item:frontpage_map_teaser_paragraph:default:default'] = $panelizer;

  return $export;
}
