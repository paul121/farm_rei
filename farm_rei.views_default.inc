<?php

/**
 * @file
 * farm_rei.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function farm_rei_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'farm_rei';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'log';
  $view->human_name = 'Farm REI';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Restricted areas';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any farm_input log entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no areas with an active restricted-entry interval.';
  $handler->display->display_options['empty']['area']['format'] = 'farm_format';
  /* Field: Log: Done */
  $handler->display->display_options['fields']['done']['id'] = 'done';
  $handler->display->display_options['fields']['done']['table'] = 'log';
  $handler->display->display_options['fields']['done']['field'] = 'done';
  $handler->display->display_options['fields']['done']['exclude'] = TRUE;
  $handler->display->display_options['fields']['done']['not'] = 0;
  /* Field: Log: Log ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Log: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'log';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Start timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['path'] = 'log/[id]';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: Field: Restricted-entry interval */
  $handler->display->display_options['fields']['field_farm_rei_1']['id'] = 'field_farm_rei_1';
  $handler->display->display_options['fields']['field_farm_rei_1']['table'] = 'field_data_field_farm_rei';
  $handler->display->display_options['fields']['field_farm_rei_1']['field'] = 'field_farm_rei';
  $handler->display->display_options['fields']['field_farm_rei_1']['label'] = 'REI (days)';
  $handler->display->display_options['fields']['field_farm_rei_1']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Log: Areas */
  $handler->display->display_options['fields']['field_farm_area']['id'] = 'field_farm_area';
  $handler->display->display_options['fields']['field_farm_area']['table'] = 'field_data_field_farm_area';
  $handler->display->display_options['fields']['field_farm_area']['field'] = 'field_farm_area';
  $handler->display->display_options['fields']['field_farm_area']['delta_offset'] = '0';
  /* Field: Log: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'log';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'log/[id]';
  /* Field: Log: Materials */
  $handler->display->display_options['fields']['field_farm_material']['id'] = 'field_farm_material';
  $handler->display->display_options['fields']['field_farm_material']['table'] = 'field_data_field_farm_material';
  $handler->display->display_options['fields']['field_farm_material']['field'] = 'field_farm_material';
  $handler->display->display_options['fields']['field_farm_material']['delta_offset'] = '0';
  /* Sort criterion: Log: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'log';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  /* Filter criterion: Log: Log type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'log';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'farm_input' => 'farm_input',
  );
  /* Filter criterion: Log: Log REI status */
  $handler->display->display_options['filters']['rei_status']['id'] = 'rei_status';
  $handler->display->display_options['filters']['rei_status']['table'] = 'field_data_field_farm_rei';
  $handler->display->display_options['filters']['rei_status']['field'] = 'rei_status';
  $handler->display->display_options['filters']['rei_status']['value'] = 'active';

  /* Display: Block Active REI */
  $handler = $view->new_display('block', 'Block Active REI', 'block_active_rei');

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'wkt';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'done';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'done';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_farm_geofield';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'field_farm_geofield';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'field_farm_area';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'nothing';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Log: Done */
  $handler->display->display_options['fields']['done']['id'] = 'done';
  $handler->display->display_options['fields']['done']['table'] = 'log';
  $handler->display->display_options['fields']['done']['field'] = 'done';
  $handler->display->display_options['fields']['done']['exclude'] = TRUE;
  $handler->display->display_options['fields']['done']['not'] = 0;
  /* Field: Log: Log ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'log';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Log: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'log';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Start timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['path'] = 'log/[id]';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: Field: Restricted-entry interval */
  $handler->display->display_options['fields']['field_farm_rei_1']['id'] = 'field_farm_rei_1';
  $handler->display->display_options['fields']['field_farm_rei_1']['table'] = 'field_data_field_farm_rei';
  $handler->display->display_options['fields']['field_farm_rei_1']['field'] = 'field_farm_rei';
  $handler->display->display_options['fields']['field_farm_rei_1']['label'] = 'REI (days)';
  $handler->display->display_options['fields']['field_farm_rei_1']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Log: Areas */
  $handler->display->display_options['fields']['field_farm_area']['id'] = 'field_farm_area';
  $handler->display->display_options['fields']['field_farm_area']['table'] = 'field_data_field_farm_area';
  $handler->display->display_options['fields']['field_farm_area']['field'] = 'field_farm_area';
  $handler->display->display_options['fields']['field_farm_area']['delta_offset'] = '0';
  /* Field: Log: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'log';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'log/[id]';
  /* Field: Log: Materials */
  $handler->display->display_options['fields']['field_farm_material']['id'] = 'field_farm_material';
  $handler->display->display_options['fields']['field_farm_material']['table'] = 'field_data_field_farm_material';
  $handler->display->display_options['fields']['field_farm_material']['field'] = 'field_farm_material';
  $handler->display->display_options['fields']['field_farm_material']['delta_offset'] = '0';
  /* Field: Field: Geometry */
  $handler->display->display_options['fields']['field_farm_geofield']['id'] = 'field_farm_geofield';
  $handler->display->display_options['fields']['field_farm_geofield']['table'] = 'field_data_field_farm_geofield';
  $handler->display->display_options['fields']['field_farm_geofield']['field'] = 'field_farm_geofield';
  $handler->display->display_options['fields']['field_farm_geofield']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_farm_geofield']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_farm_geofield']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Description';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div><strong>Restricted Entry</strong></div>
<div>Start: [timestamp]</div>
<div>Duration: [field_farm_rei_1] days</div>
<div>Details: [name]</div>
';
  $handler->display->display_options['path'] = 'farm/areas/active-rei/geojson';
  $export['farm_rei'] = $view;

  return $export;
}
