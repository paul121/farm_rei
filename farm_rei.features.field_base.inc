<?php

/**
 * @file
 * farm_rei.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function farm_rei_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_farm_rei'.
  $field_bases['field_farm_rei'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_farm_rei',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
