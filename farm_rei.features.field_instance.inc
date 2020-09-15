<?php

/**
 * @file
 * farm_rei.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function farm_rei_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'log-farm_input-field_farm_rei'.
  $field_instances['log-farm_input-field_farm_rei'] = array(
    'bundle' => 'farm_input',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'log',
    'field_name' => 'field_farm_rei',
    'label' => 'Restricted-entry interval',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 17,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Restricted-entry interval');

  return $field_instances;
}
