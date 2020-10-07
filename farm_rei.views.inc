<?php

/**
 * @file
 * Farm rei views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function farm_rei_views_data_alter(&$data) {
  $data['log']['field_farm_rei'] = array(
    'title' => t('Active REI filter'),
    'help' => t('Active REI for this log.'),
    'real field' => 'field_farm_rei',
    'filter' => array(
      'handler' => 'farm_rei_handler_filter_active_rei',
    ),
  );
}
