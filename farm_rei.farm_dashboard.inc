<?php
/**
 * @file
 * Farm dashboard hooks implemented by farm rei module.
 */

/**
 * Implements hook_farm_dashboard_panes().
 */
function farm_rei_farm_dashboard_panes() {
  return array(
    'farm_rei_active_rei' => array(
      'view' => 'farm_rei',
      'view_display_id' => 'block_active_rei',
      // Display above the plans pane.
      'group' => 'plans',
      'weight' => '-5',
    ),
  );
}
