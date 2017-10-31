<?php
/**
 * @file
 * ipwa_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ipwa_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access broken links report'.
  $permissions['access broken links report'] = array(
    'name' => 'access broken links report',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access site map'.
  $permissions['access site map'] = array(
    'name' => 'access site map',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'site_map',
  );

  // Exported permission: 'administer newsletters'.
  $permissions['administer newsletters'] = array(
    'name' => 'administer newsletters',
    'roles' => array(),
    'module' => 'simplenews',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer path breadcrumbs'.
  $permissions['administer path breadcrumbs'] = array(
    'name' => 'administer path breadcrumbs',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'path_breadcrumbs_ui',
  );

  // Exported permission: 'administer simplenews subscriptions'.
  $permissions['administer simplenews subscriptions'] = array(
    'name' => 'administer simplenews subscriptions',
    'roles' => array(),
    'module' => 'simplenews',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'path',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create bild content'.
  $permissions['create bild content'] = array(
    'name' => 'create bild content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create document content'.
  $permissions['create document content'] = array(
    'name' => 'create document content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create doorpage content'.
  $permissions['create doorpage content'] = array(
    'name' => 'create doorpage content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create f_rderbekanntmachung content'.
  $permissions['create f_rderbekanntmachung content'] = array(
    'name' => 'create f_rderbekanntmachung content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create nachricht content'.
  $permissions['create nachricht content'] = array(
    'name' => 'create nachricht content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create projekt content'.
  $permissions['create projekt content'] = array(
    'name' => 'create projekt content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create protagonist content'.
  $permissions['create protagonist content'] = array(
    'name' => 'create protagonist content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create publikation content'.
  $permissions['create publikation content'] = array(
    'name' => 'create publikation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create simplenews content'.
  $permissions['create simplenews content'] = array(
    'name' => 'create simplenews content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create termin content'.
  $permissions['create termin content'] = array(
    'name' => 'create termin content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any bild content'.
  $permissions['delete any bild content'] = array(
    'name' => 'delete any bild content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document content'.
  $permissions['delete any document content'] = array(
    'name' => 'delete any document content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any doorpage content'.
  $permissions['delete any doorpage content'] = array(
    'name' => 'delete any doorpage content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any f_rderbekanntmachung content'.
  $permissions['delete any f_rderbekanntmachung content'] = array(
    'name' => 'delete any f_rderbekanntmachung content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any nachricht content'.
  $permissions['delete any nachricht content'] = array(
    'name' => 'delete any nachricht content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any projekt content'.
  $permissions['delete any projekt content'] = array(
    'name' => 'delete any projekt content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any protagonist content'.
  $permissions['delete any protagonist content'] = array(
    'name' => 'delete any protagonist content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any publikation content'.
  $permissions['delete any publikation content'] = array(
    'name' => 'delete any publikation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any simplenews content'.
  $permissions['delete any simplenews content'] = array(
    'name' => 'delete any simplenews content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any termin content'.
  $permissions['delete any termin content'] = array(
    'name' => 'delete any termin content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own bild content'.
  $permissions['delete own bild content'] = array(
    'name' => 'delete own bild content',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document content'.
  $permissions['delete own document content'] = array(
    'name' => 'delete own document content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own doorpage content'.
  $permissions['delete own doorpage content'] = array(
    'name' => 'delete own doorpage content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own f_rderbekanntmachung content'.
  $permissions['delete own f_rderbekanntmachung content'] = array(
    'name' => 'delete own f_rderbekanntmachung content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own nachricht content'.
  $permissions['delete own nachricht content'] = array(
    'name' => 'delete own nachricht content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own projekt content'.
  $permissions['delete own projekt content'] = array(
    'name' => 'delete own projekt content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own protagonist content'.
  $permissions['delete own protagonist content'] = array(
    'name' => 'delete own protagonist content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own publikation content'.
  $permissions['delete own publikation content'] = array(
    'name' => 'delete own publikation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own simplenews content'.
  $permissions['delete own simplenews content'] = array(
    'name' => 'delete own simplenews content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own termin content'.
  $permissions['delete own termin content'] = array(
    'name' => 'delete own termin content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any bild content'.
  $permissions['edit any bild content'] = array(
    'name' => 'edit any bild content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document content'.
  $permissions['edit any document content'] = array(
    'name' => 'edit any document content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any doorpage content'.
  $permissions['edit any doorpage content'] = array(
    'name' => 'edit any doorpage content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any f_rderbekanntmachung content'.
  $permissions['edit any f_rderbekanntmachung content'] = array(
    'name' => 'edit any f_rderbekanntmachung content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any nachricht content'.
  $permissions['edit any nachricht content'] = array(
    'name' => 'edit any nachricht content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any projekt content'.
  $permissions['edit any projekt content'] = array(
    'name' => 'edit any projekt content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any protagonist content'.
  $permissions['edit any protagonist content'] = array(
    'name' => 'edit any protagonist content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any publikation content'.
  $permissions['edit any publikation content'] = array(
    'name' => 'edit any publikation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any simplenews content'.
  $permissions['edit any simplenews content'] = array(
    'name' => 'edit any simplenews content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any termin content'.
  $permissions['edit any termin content'] = array(
    'name' => 'edit any termin content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own bild content'.
  $permissions['edit own bild content'] = array(
    'name' => 'edit own bild content',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document content'.
  $permissions['edit own document content'] = array(
    'name' => 'edit own document content',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own doorpage content'.
  $permissions['edit own doorpage content'] = array(
    'name' => 'edit own doorpage content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own f_rderbekanntmachung content'.
  $permissions['edit own f_rderbekanntmachung content'] = array(
    'name' => 'edit own f_rderbekanntmachung content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own nachricht content'.
  $permissions['edit own nachricht content'] = array(
    'name' => 'edit own nachricht content',
    'roles' => array(
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own projekt content'.
  $permissions['edit own projekt content'] = array(
    'name' => 'edit own projekt content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own protagonist content'.
  $permissions['edit own protagonist content'] = array(
    'name' => 'edit own protagonist content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own publikation content'.
  $permissions['edit own publikation content'] = array(
    'name' => 'edit own publikation content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own simplenews content'.
  $permissions['edit own simplenews content'] = array(
    'name' => 'edit own simplenews content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own termin content'.
  $permissions['edit own termin content'] = array(
    'name' => 'edit own termin content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'Administrator' => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'send newsletter'.
  $permissions['send newsletter'] = array(
    'name' => 'send newsletter',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
    ),
    'module' => 'simplenews',
  );

  // Exported permission: 'subscribe to newsletters'.
  $permissions['subscribe to newsletters'] = array(
    'name' => 'subscribe to newsletters',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'simplenews',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Administrator' => 'Administrator',
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view paragraph content flie_text_bereich'.
  $permissions['view paragraph content flie_text_bereich'] = array(
    'name' => 'view paragraph content flie_text_bereich',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content flie_text_mit_bild_links'.
  $permissions['view paragraph content flie_text_mit_bild_links'] = array(
    'name' => 'view paragraph content flie_text_mit_bild_links',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content flie_text_mit_bild_rechts'.
  $permissions['view paragraph content flie_text_mit_bild_rechts'] = array(
    'name' => 'view paragraph content flie_text_mit_bild_rechts',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content frontpage_map_teaser_paragraph'.
  $permissions['view paragraph content frontpage_map_teaser_paragraph'] = array(
    'name' => 'view paragraph content frontpage_map_teaser_paragraph',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content topic_teaser_paragraph'.
  $permissions['view paragraph content topic_teaser_paragraph'] = array(
    'name' => 'view paragraph content topic_teaser_paragraph',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view paragraph content views'.
  $permissions['view paragraph content views'] = array(
    'name' => 'view paragraph content views',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'paragraphs_bundle_permissions',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Chefredakteur' => 'Chefredakteur',
      'Redakteur (ext.)' => 'Redakteur (ext.)',
      'Redakteur (int.)' => 'Redakteur (int.)',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'system',
  );

  return $permissions;
}
