<?php

namespace Drupal\farm_rei\EventSubscriber;

use Drupal\log\Event\LogEvent;
use Drupal\quantity\Entity\QuantityInterface;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;

/**
 * Copy the referenced material quantity material type REI to the input log.
 */
class LogEventSubscriber implements EventSubscriberInterface {

  /**
   * {@inheritdoc}
   */
  public static function getSubscribedEvents() {
    return [
      LogEvent::PRESAVE => 'logPresave',
    ];
  }

  /**
   * Perform actions on log presave.
   *
   * @param \Drupal\log\Event\LogEvent $event
   *   The log event.
   */
  public function logPresave(LogEvent $event) {
    $log = $event->log;

    // Bail if not an input log, has no quantities, or already has an REI value.
    if ($log->bundle() !== 'input' || $log->get('quantity')->isEmpty() || !$log->get('rei')->isEmpty()) {
      return;
    }

    // Find the max REI value defined by referenced material types.
    $max_rei = NULL;
    /** @var QuantityInterface $quantity */
    foreach ($log->get('quantity')->referencedEntities() as $quantity) {

      // Only check material quantities with material_type reference.
      if ($quantity->bundle() !== 'material' || $quantity->get('material_type')->isEmpty()) {
        return;
      }

      // If the quantity does not have a material type with an REI, skip it.
      $material_types = $quantity->get('material_type')->referencedEntities();
      if ($material_type = reset($material_types)) {
        $referenced_rei = $material_type->get('rei')->first()->value;
        $max_rei = max($max_rei, $referenced_rei);
      }
    }

    // Update the REI value on the input log.
    $log->set('rei', $max_rei);
  }

}
