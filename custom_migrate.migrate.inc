<?php
/**
 * @file custom_migrate.migrate.inc
 */

/**
 * This is example code for a Drupal 6 to Drupal 7 migration.
 */

/**
 * Implements hook_migrate_api().
 */
function custom_migrate_migrate_api() {
  /**
   * Declare the api version and migration group.
   */
  $api = array(
    'api' => 2,
    'groups' => array(
      'custom_group' => array(
        'title' => t('Drupal 6 to Drupal 7 custom migrations.'),
      ),
      'migrations' => array(),
    ),
  );

  /**
   * Alter database settings in settings.php see README.txt
   */
  $common_arguments = array(
    'source_connection' => 'legacy',
    'source_version' => 6,
    'group_name' => 'custom_group',
  );
  // Node migrations - each has its own class derived from the migrate_d2d class,
  // specifying its particular field mappings and transformations. source_type
  // and destination_type are required arguments.
 $node_arguments = array(
    'Page' => array(
      'class_name' => 'CustomPageMigration',
      'description' => t('Migration of Page content type from Drupal 6'),
      'source_type' => 'page',
      'destination_type' => 'page',
    ),
  );

  // Tell the node migrations where the users are coming from, so they can
  // set up the dependency and resolve D6->D7 uids.
  $common_node_arguments = $common_arguments + array(
      'user_migration' => 'User',
      'format_mappings' => array(
        '31' => 'filtered_html',
        '16' => 'full_html',
        '26' => 'php_code',
      ),
    );

  foreach ($node_arguments as $migration_name => $arguments) {
    $arguments = array_merge_recursive($arguments, $common_node_arguments);
    $api['migrations'][$migration_name] = $arguments;
  }

  return $api;
}

