<?php
/**
 * @file user_terms.views.inc
 * Provides integration with views module.
 */

/**
 * Implementation of hook_views_data().
 */
function gst_auto_terms_views_data() {
  $data = array();     
  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['taxonomy_index_users']['table']['group']  = t('User');

  $data['taxonomy_index_users']['table']['join'] = array(
    'taxonomy_term_data' => array(
      'left_field' => 'tid',
      'field' => 'tid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // tid field
  $data['taxonomy_index_users']['tid'] = array(
    'title' => t('Term ID'),
    'help' => t('The taxonomy term ID for the user'),
    'field' => array(
      'title' => t('All terms'),
      'help' => t('Display all taxonomy terms associated with a user.'),
      'handler' => 'gst_auto_terms_handler_field_taxonomy_index_users_tid',
      'skip base' => 'taxonomy_index_users',
    ),
    'argument' => array(
      // Use the views term tid argument: this has nothing specific to nodes .
      'handler' => 'views_handler_argument_term_node_tid',
      'name table' => 'taxonomy_term_data',
      'name field' => 'name',
      'empty field name' => t('Uncategorized'),
      'numeric' => TRUE,
      'skip base' => 'taxonomy_index_users',
    ),
    'filter' => array(
      'title' => t('Term'),
      'handler' => 'views_handler_filter_term_node_tid',
      'hierarchy table' => 'term_hierarchy',
      'numeric' => TRUE,
      'skip base' => 'taxonomy_index_users',
      'allow empty' => TRUE,
    ),
    'relationship' => array(
      'title' => t('Terms'),      
      'label' => t('Terms for the user'),
      'help' => t('The terms assigned to the user. May produce multiple rows.'),
      'base' => 'taxonomy_term_data',
      'field' => 'tid',
      'handler' => 'views_handler_relationship',
      // This allows us to not show this relationship if the base is already
      // term_data so users won't create circular relationships.
      //? 'skip base' => array('taxonomy_term_data'),
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
/* Views3 Doesn't use this hook. It uses PHP's auto-loading - specify file in .info files[] section
function gst_auto_terms_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'gst_auto_terms'),
    ),
    'handlers' => array(
      'gst_auto_terms_handler_field_taxonomy_index_users_tid' => array(
        'parent' => 'views_handler_field_term_node_tid',
      ),
    ),
  );
}
*/
