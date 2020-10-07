<?php

/**
 * @file
 * Farm rei views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function farm_rei_views_data_alter(&$data) {

  // Provide an additional REI Status filter.
  $data['field_data_field_farm_rei']['rei_status'] = array(
    'group' => 'Log',
    'title' => t('Log REI status'),
    'help' => t('Filter logs with any, active, past or planned REIs. Active and past logs must be "done".'),
    'filter' => array(
      'field' => 'field_farm_rei_value',
      'table' => 'field_data_field_farm_rei',
      'handler' => 'farm_rei_handler_filter_rei_status',
      'field name' => 'field_farm_rei',
    ),
  );
}
