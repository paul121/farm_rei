<?php
/**
 * @file
 * Farm Map hooks implemented by the farm rei module.
 */

/**
 * Implements hook_farm_map_behaviors().
 */
function farm_rei_farm_map_behaviors() {
  return array(
    'active_rei' => array(
      'js' => 'js/farmOS.map.behaviors.active_rei.js',
    ),
  );
}

/**
 * Implements hook_farm_map_view().
 */
function farm_rei_farm_map_view($name, $element) {

  // Add the active_rei behavior to all farm_areas maps.
  if ($name == 'farm_areas') {
    farm_map_add_behavior('active_rei');
  }
}
