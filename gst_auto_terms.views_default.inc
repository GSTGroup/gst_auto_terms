<?php

/**
 * Implement hook_views_default_views().
 */
function gst_auto_terms_views_default_views() {
  $views = array();
  
  $view = _gst_auto_terms_node_list();
  $views[$view->name] = $view;
  
  $view = _gst_auto_terms_profile2_list();
  $views[$view->name] = $view;
  
  return $views;  
}

function _gst_auto_terms_node_list() {
  $view = new view;
  $view->name = 'gst_auto_terms_node_list';
  $view->description = 'GST Auto Terms - List of Node Records with Term';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'GST Auto Terms - List of Node Records with Term';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content List';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = 1;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'tags' => 'tags',
    'forums' => 0,
    'book' => 0,
    'profile_interests' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['arguments']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['arguments']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['machine_name']['title_enable'] = 1;
  $handler->display->display_options['arguments']['machine_name']['title'] = 'Content in the <em>%1</em> vocabulary';
  $handler->display->display_options['arguments']['machine_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['machine_name']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['machine_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['machine_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['machine_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['machine_name']['glossary'] = 0;
  $handler->display->display_options['arguments']['machine_name']['limit'] = '0';
  $handler->display->display_options['arguments']['machine_name']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['machine_name']['break_phrase'] = 0;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['name']['title_enable'] = 1;
  $handler->display->display_options['arguments']['name']['title'] = 'Content tagged with the term <em>%2</em>';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['glossary'] = 0;
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['name']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['name']['add_table'] = 0;
  $handler->display->display_options['arguments']['name']['require_value'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'auto_term_n';
  
  //RETURN
  return $view;
}

function _gst_auto_terms_profile2_list() {
  $view = new view;
  $view->name = 'gst_auto_terms_profile2_list';
  $view->description = 'GST Auto Terms - List of Profile2 Records with Term';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'GST Auto Terms - List of Profile2 Records with Term';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User List';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
  8 => '8',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Profile: User */
  $handler->display->display_options['relationships']['user_1']['id'] = 'user_1';
  $handler->display->display_options['relationships']['user_1']['table'] = 'profile';
  $handler->display->display_options['relationships']['user_1']['field'] = 'user';
  $handler->display->display_options['relationships']['user_1']['ui_name'] = 'Profile: User';
  $handler->display->display_options['relationships']['user_1']['required'] = 0;
  /* Relationship: GST Auto Terms */
  $handler->display->display_options['relationships']['tid']['id'] = 'tid';
  $handler->display->display_options['relationships']['tid']['table'] = 'taxonomy_index_users';
  $handler->display->display_options['relationships']['tid']['field'] = 'tid';
  $handler->display->display_options['relationships']['tid']['relationship'] = 'user_1';
  $handler->display->display_options['relationships']['tid']['ui_name'] = 'GST Auto Terms';
  $handler->display->display_options['relationships']['tid']['label'] = 'GST Auto Terms';
  $handler->display->display_options['relationships']['tid']['required'] = 0;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['pid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['pid']['format_plural'] = 0;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'user_1';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user_1';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Profile: My website */
  $handler->display->display_options['fields']['field_up_website']['id'] = 'field_up_website';
  $handler->display->display_options['fields']['field_up_website']['table'] = 'field_data_field_up_website';
  $handler->display->display_options['fields']['field_up_website']['field'] = 'field_up_website';
  $handler->display->display_options['fields']['field_up_website']['label'] = '';
  $handler->display->display_options['fields']['field_up_website']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_up_website']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_up_website']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_up_website']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_up_website']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_up_website']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_up_website']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_up_website']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_up_website']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_up_website']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_up_website']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_up_website']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_up_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_up_website']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_up_website']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_up_website']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_up_website']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_up_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_up_website']['field_api_classes'] = 0;
  /* Sort criterion: Profile: Fullname (field_up_fullname:family) */
  $handler->display->display_options['sorts']['field_up_fullname_family']['id'] = 'field_up_fullname_family';
  $handler->display->display_options['sorts']['field_up_fullname_family']['table'] = 'field_data_field_up_fullname';
  $handler->display->display_options['sorts']['field_up_fullname_family']['field'] = 'field_up_fullname_family';
  /* Contextual filter: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['arguments']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['arguments']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['arguments']['machine_name']['relationship'] = 'tid';
  $handler->display->display_options['arguments']['machine_name']['title_enable'] = 1;
  $handler->display->display_options['arguments']['machine_name']['title'] = 'People with a profile indicating their <em>%1</em>';
  $handler->display->display_options['arguments']['machine_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['machine_name']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['machine_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['machine_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['machine_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['machine_name']['glossary'] = 0;
  $handler->display->display_options['arguments']['machine_name']['limit'] = '0';
  $handler->display->display_options['arguments']['machine_name']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['machine_name']['break_phrase'] = 0;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'tid';
  $handler->display->display_options['arguments']['name']['title_enable'] = 1;
  $handler->display->display_options['arguments']['name']['title'] = 'People interested in <em>%2</em>';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['glossary'] = 0;
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['name']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['name']['add_table'] = 0;
  $handler->display->display_options['arguments']['name']['require_value'] = 0;
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['relationship'] = 'user_1';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['group'] = 0;
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['required'] = 0;
  $handler->display->display_options['filters']['realname']['expose']['multiple'] = FALSE;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'auto_term_u';
  
  //RETURN
  return $view;
}