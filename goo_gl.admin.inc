<?php

/**
 * @file
 * Admin page callbacks for the goo_gl module.
 */

/**
 * System settings form builder.
 */
function goo_gl_api_key_form() {

  $form['goo_gl_api_key'] = array(
    '#type'             => 'textfield',
    '#size'             => 40,
    '#title'            => t('Google API Key'),
    '#default_value'    => variable_get('goo_gl_api_key'),
    '#element_validate' => array('_validate_api_key'),
    '#description'      => t('<p>Ensure to use a valid API key here, otherwise<br>URL Shortening may very likely not work due to limited use.</p>
                              <p>Get an API key at <a href="https://console.developers.google.com/">Google Developer Console.</a></p>
                              <p>Please read the <a href="https://developers.google.com/url-shortener/v1/getting_started" target="blank">Documentation</a>.</p>')
  );

  return system_settings_form($form);
}

/**
 * API key textfield element validate function.
 */
function _validate_api_key($element, &$form_state) {

  if (!empty($element['#value'])) {
    if (strlen($element['#value']) != 39) {
      form_set_error('strlen', 'That doesn\'t look like a valid key. Go get one at <a href="https://console.developers.google.com/">Google Developer Console.</a>');
    }
  }
}