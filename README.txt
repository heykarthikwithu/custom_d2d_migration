See https://smbjorklund.no/how-migrate-content-drupal-6-7-using-migrated2d-part-4-field-mappings for a good tutorial

Define database and root directory for Drupal 6 in settings.php
<?php
$databases = array (
  'default' =>
  array (
    'default' =>
    array (
      'database' => 'smbd7',
      'username' => 'test',
      'password' => 'test',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
  'legacy' => array(
    'default' => array(
      'database' => 'smbd6',
      'username' => 'test',
      'password' => 'test',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);
$conf['drupal_6_roo_dir'] = '/var/www/html/d6';
?>

$ drush migrate-register
You can also remove registered import tasks and groups with migrate-deregister
$ drush migrate-deregister --help

$ drush ms
Will return something like this
Group: content_migration  Total  Imported  Unprocessed  Status  Last imported
User                      51     0         51           Idle


To migrate all instances of Group Use
$ drush mi [Group]

To revert all instances of Group Use
$ drush mi [Group]


Steps for Semi Migration in Order:-
$ drush mi Role
$ drush mi User
$ drush mi File
$ drush mi Attendee

