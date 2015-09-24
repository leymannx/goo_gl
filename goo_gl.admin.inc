<?php

/**
 * @file
 * Admin page callbacks for the goo_gl module.
 */

/**
 * Form builder.
 */
function goo_gl_api_key_form() {

  $form['goo_gl_api_key'] = array(
    '#type'           => 'textfield',
    '#size'           => 40,
    '#title'          => t('Google API Key'),
    '#default_value'  => variable_get('goo_gl_api_key'),
    '#description'    => t('Please read the <a href="https://developers.google.com/url-shortener/v1/getting_started" target="blank">Documentation</a>.')
  );

  return system_settings_form($form);
}