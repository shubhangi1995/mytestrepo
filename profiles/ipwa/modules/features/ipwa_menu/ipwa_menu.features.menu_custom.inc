<?php

/**
 * @file
 * Tests for file.module.
 */

/**
 * Provides methods specifically for testing File module's field handling.
 */
class FileFieldTestCase extends DrupalWebTestCase
{
  protected $admin_user;

  function setUp()
  {
    // Since this is a base class for many test cases, support the same
    // flexibility that DrupalWebTestCase::setUp() has for the modules to be
    // passed in as either an array or a variable number of string arguments.
    $modules = func_get_args();
    if (isset($modules[0]) && is_array($modules[0])) {
      $modules = $modules[0];
    }
    $modules[] = 'file';
    $modules[] = 'file_module_test';
    parent::setUp($modules);
    $this->admin_user = $this->drupalCreateUser(array('access content', 'access administration pages', 'administer site configuration', 'administer users', 'administer permissions', 'administer content types', 'administer nodes', 'bypass node access', 'administer fields'));
    $this->drupalLogin($this->admin_user);
  }
}
