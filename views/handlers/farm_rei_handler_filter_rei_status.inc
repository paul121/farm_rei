<?php

/**
 * Farm_rei rei status filter handler.
 */

class farm_rei_handler_filter_rei_status extends views_handler_filter_boolean_operator {

  /**
   * {@inheritdoc}
   */
  public function construct() {
    parent::construct();
    $this->value_value = t('REI Status');
    $this->accept_null = FALSE;
    $this->value_options = NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function get_value_options() {

    // Define options.
    if (!isset($this->value_options)) {
      $this->value_options = array(
        'any' => t('Any'),
        'active' => t('Active'),
        'past' => t('Past'),
        'planned' => t('Planned'),
      );
    }
  }

  /**
   * {@inheritdoc}
   */
  public function admin_summary() {
    if (empty($this->value_options)) {
      $this->get_value_options();
    }
    // Return the selected value.
    return $this->value_options[$this->value];
  }


    /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";

    // Defaults
    $log_done = TRUE;
    $log_timestamp_operator = '<=';
    $rei_expiration_operator = NULL;

    // Update defaults based on filter value.
    switch ($this->value) {

      case 'any':
        $log_done = NULL;
        $log_timestamp_operator = NULL;
        $rei_expiration_operator = NULL;
        break;

      case 'active':
        $rei_expiration_operator = '>=';
        break;

      case 'past':
        $rei_expiration_operator = '<=';
        break;

      case 'planned':
        $log_done = FALSE;
        $log_timestamp_operator = '>';
        $rei_expiration_operator = '>';
        break;
    }

    // Only include logs that define an REI > 0.
    $this->query->add_where($this->options['group'], $field, 0, '>');

    // Limit the log timestamps to past or future.
    if (!empty($log_timestamp_operator)) {
      $this->query->add_where_expression($this->options['group'], 'log.timestamp ' . $log_timestamp_operator . ' ' . REQUEST_TIME);
    }

    // Limit if the log must be marked as done.
    if (!empty($log_done)) {
      $this->query->add_where_expression($this->options['group'], 'log.done = 1');
    }

    // Limit if the REI expiration is past or still in the future.
    if (!empty($rei_expiration_operator)) {
      $this->query->add_where_expression($this->options['group'], 'log.timestamp ' . $rei_expiration_operator . ' ' . REQUEST_TIME . ' - ' . $field . ' * 86400');
    }
  }


}
