<?php

/**
 * Farm rei active rei filter handler.
 */

class farm_rei_handler_filter_active_rei extends views_handler_filter_numeric {

  /**
   * {@inheritdoc}
   */
  public $always_multiple = FALSE;

  /**
   * {@inheritdoc}
   */
  public function operators() {
    $operators = array(
      'active' => array(
        'title' => t('Active REI'),
        'method' => 'op_simple',
        'short' => t('<'),
        'values' => 1,
      ),
    );

    return $operators;
  }

}
