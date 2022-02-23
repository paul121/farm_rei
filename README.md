# farmOS REI

Provides restricted-entry interval (REI) features for farmOS.

This module is an add-on for the [farmOS](http://drupal.org/project/farm)
distribution.

## Fields

This module adds an `rei` integer field to `input` logs and `material_type`
taxonomy terms. This integer value represents the number of days of the
restricted-entry interval.

## Logic

Individual `material_type` terms should be configured with their REI value.

When an `input` log references `material` quantities that have a
`material_type` term with a configured REI, the largest REI value will be
copied to the input log. The log's REI value can be overwritten by editing
the REI value directly on the log.

TODO (for full parity with 7.x-1.0):
- Display warning message when viewing a log or asset that is a part
of an active REI.
- Display active REI on the dashboard.
- Geojson view and map integration.

## Installation

Install as you would normally install a contributed drupal module.

With composer:
```
composer require drupal/farm_rei
```

## Migration

To migrate from 7.x-1.0 to 2.x execute the two migrations in the `farm_rei`
migration group:
```
drush migrate:import --group farm_rei
```

## Maintainers

Current maintainers:
* Paul Weidner (paul121) - https://github.com/paul121

This project has been sponsored by:
* [Rothamsted Research](https://www.rothamsted.ac.uk/)
