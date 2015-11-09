<?php

/**
 * Common mappings for the Drupal 6 node migrations.
 */
abstract class CustomNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

      $this->addFieldMapping('is_new')->defaultValue(TRUE);
      $this->addFieldMapping('nid', 'nid');

    $this->addFieldMapping('field_legacy_nid', 'nid')
         ->description('We have a common field to save the D6 nid');
  }

}

/**
 * Mappings for Events Landing Page
 */
class CustomPageMigration extends CustomNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  //  $this->addFieldMapping('field_parent_path', 'field_parent_path');
  //  $this->addFieldMapping('field_left_callout_html', 'field_left_callout_html');

  }
}
