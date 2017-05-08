<?php
/**
 * @file
 * Settings interface.
 */

/**
 * Callback function for db_track_settings_form().
 */
function yonodes_settings_form($form, &$form_state) {
  $form['yonodes_youtube_settings'] = array(
    '#type' => 'fieldset', 
    '#title' => t('YouTube settings.'), 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );

  $form['yonodes_youtube_settings']['yonodes_channel_id'] = array(
    '#type' => 'textfield', 
    '#title' => t('Channel ID'),
    '#description' => t('Enter YouTube channel ID.'),
    '#default_value' => trim(variable_get('yonodes_channel_id', '')),
    '#size' => 60, 
    '#maxlength' => 128, 
    '#required' => TRUE,
  );
  
  $form['yonodes_youtube_settings']['yonodes_key'] = array(
    '#type' => 'textfield', 
    '#title' => t('App key'),
    '#description' => t('Enter YouTube app key.'),
    '#default_value' => trim(variable_get('yonodes_key', '')),
    '#size' => 60, 
    '#maxlength' => 128, 
    '#required' => TRUE,
  );

  $form['yonodes_nodes_settings'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Node settings'),
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );  

  $form['yonodes_nodes_settings']['yonodes_disable_edit_yonodes'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Disable UI'),
    '#description' => t('Check this to disable editing of YouTube Video nodes original fields.'),
    '#default_value' => trim(variable_get('yonodes_disable_edit_yonodes', '')),
    '#required' => FALSE,
  );
  
  $form['yonodes_nodes_settings']['yonodes_create_youtube_link_field'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Create Youtube Link fields in new nodes'),
    '#description' => t('Requires Youtube Link module.'),
    '#default_value' => trim(variable_get('yonodes_create_youtube_link_field', '')),
    '#required' => FALSE,
  );

  $form['yonodes_nodes_settings']['yonodes_thumbs'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Check needed types of thumbnails'),    
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  ); 

  $form['yonodes_nodes_settings']['yonodes_thumbs']['yonodes_thumb_default'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Default - 120*90'),
    '#description' => t('Check this to save default thumbnail URL.'),
    '#default_value' => trim(variable_get('yonodes_thumb_default', '')),
    '#required' => FALSE,
  );

  $form['yonodes_nodes_settings']['yonodes_thumbs']['yonodes_thumb_medium'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Medium - 320*180'),
    '#description' => t('Check this to save medium thumbnail URL.'),
    '#default_value' => trim(variable_get('yonodes_thumb_medium', '')),
    '#required' => FALSE,
  );

  $form['yonodes_nodes_settings']['yonodes_thumbs']['yonodes_thumb_high'] = array(
    '#type' => 'checkbox', 
    '#title' => t('High - 480*360'),
    '#description' => t('Check this to save high thumbnail URL.'),
    '#default_value' => trim(variable_get('yonodes_thumb_high', '')),
    '#required' => FALSE,
  );

  $form['yonodes_nodes_settings']['yonodes_thumbs']['yonodes_thumb_standard'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Standard - 640*480'),
    '#description' => t('Check this to save standard thumbnail URL.'),
    '#default_value' => trim(variable_get('yonodes_thumb_standard', '')),
    '#required' => FALSE,
  );

  $form['yonodes_nodes_settings']['yonodes_thumbs']['yonodes_thumb_maxres'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Maxres - 1280*720'),
    '#description' => t('Check this to save maxres thumbnail URL.'),
    '#default_value' => trim(variable_get('yonodes_thumb_maxres', '')),
    '#required' => FALSE,
  );

  $form['yonodes_fetch_channel'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Fetch playlists or videos from YouTube channel'),
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE, 
  );

  $form['yonodes_fetch_channel']['yonodes_playlists_fetch'] = array(
    '#type' => 'submit',
    '#value' => t('Fetch all playlists'),
    '#submit' => array('_yonodes_fetch_playlists'),
    '#name' => 'yonodes_playlists_fetch'
  );

  $form['yonodes_fetch_channel']['yonodes_whole_channel_fetch'] = array(
    '#type' => 'submit',
    '#value' => t('Fetch all videos'),
    '#submit' => array('_yonodes_fetch'),
    '#name' => 'yonodes_whole_channel_fetch'
  );

  $form['yonodes_fetch_last_videos'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Fetch recent videos from YouTube channel'),
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );

  $form['yonodes_fetch_last_videos']['yonodes_recent_amount'] = array(
    '#type' => 'textfield', 
    '#title' => t('Amount of recent videos'),
    '#description' => t('Enter amount of recent videos to fetch. It should be in the range from 1 to 49.'),
    '#default_value' => trim(variable_get('yonodes_recent_amount', 1)),
    '#size' => 10, 
    '#maxlength' => 2, 
  );
    
  $form['yonodes_fetch_last_videos']['yonodes_last_channel_fetch'] = array(
    '#type' => 'submit',
    '#value' => t('Fetch last ' . variable_get('yonodes_recent_amount', 1) . ' videos from each playlist'),
    '#submit' => array('_yonodes_fetch'),
    '#name' => 'yonodes_last_channel_fetch'
  );
  
  $form['yonodes_fetch_last_videos']['yonodes_cron_enable'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Enable cron'),
    '#description' => t('Check this to enable cron for daily recent videos updating.'),
    '#default_value' => trim(variable_get('yonodes_cron_enable'), FALSE),
    '#required' => FALSE,
  );

  $form['yonodes_report_settings'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Report settings'),
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );

  $form['yonodes_report_settings']['yonodes_detailed_report'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Enable detail watchdog'),
    '#description' => t('Check this to watchdog every new YouTube Playlist and YouTube Node.'),
    '#default_value' => trim(variable_get('yonodes_detailed_report'), FALSE),
    '#required' => FALSE,
  );

  return system_settings_form($form, TRUE);
}

/**
 * Implements hook_validate().
 */
function yonodes_settings_form_validate($form, &$form_state) {
  if (($form_state['values']['yonodes_recent_amount'] > 49) || ($form_state['values']['yonodes_recent_amount']  < 1)) {
    form_set_error('yonodes_recent_amount', t('Amount of recent videos should be in the range from 1 to 49.'));  
  }
}

