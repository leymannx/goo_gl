<?php

/**
 * @file
 * Admin page callbacks for the goo_gl module.
 */

/**
 * System settings form builder.
 */
function goo_gl_apikey() {

  $form['goo_gl_api_key'] = array(
    '#type'             => 'textfield',
    '#size'             => 40,
    '#title'            => t('Google API Key'),
    '#default_value'    => variable_get('goo_gl_api_key'),
    '#element_validate' => array('goo_gl_validate_apikey'),
    '#description'      => t('<p>Ensure to use a valid API key here, otherwise<br>URL shortening may very likely not work due to limited use.</p>
                              <p>Get an API key at <a href="https://console.developers.google.com/">Google Developer Console.</a></p>
                              <p>Please read the <a href="https://developers.google.com/url-shortener/v1/getting_started" target="blank">Documentation</a>.</p>')
  );

  return system_settings_form($form);
}

/**
 * API key textfield element validate function.
 */
function goo_gl_validate_apikey($element, &$form_state) {

  if (!empty($element['#value'])) {
    if (strlen($element['#value']) != 39) {
      form_set_error('strlen', 'This doesn\'t look like a valid key. Please get one at <a href="https://console.developers.google.com/">Google Developer Console.</a>');
    }
  }
}

/**
 * System settings form builder.
 */
function goo_gl_analytics() {

  $form['goo_gl_analytics'] = array(
    '#markup' => _goo_gl_analytics_table(),
  );

  return $form;
}

/**
 * Helper function to @return markup for a report table used in custom_usp_form()
 */
function _goo_gl_analytics_table() {

  $output = '<table class="system-status-report">';

  $result = db_select('goo_gl_url', 'ggu')
    ->fields('ggu')
    ->execute()
    ->fetchAll();

  foreach($result as $row) {
    $output .= '<tr class="ok"><td>' . $row->nid . '</td><td>' . $row->url . '</td><td>' . _goo_gl_get_clicks(_goo_gl_get_statistics($row->url)) . '</td>';
    $output .= '</tr>';
  }

  $output .= '</table>';
  return $output;
}

/**
 * Helper to retrieve analytics from given goo.gl short URL.
 *
 * @param $goo_gl_url string
 * @return mixed analytics data
 */
function _goo_gl_get_statistics($goo_gl_url) {

  $api_key = variable_get('goo_gl_api_key');

  // No need to modify any of the code below.
  $final_url = 'https://www.googleapis.com/urlshortener/v1/url?shortUrl=' . urlencode($goo_gl_url) . '&projection=FULL&key=' . $api_key;
  $curlObj = curl_init($final_url);

  curl_setopt($curlObj, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($curlObj, CURLOPT_SSL_VERIFYPEER, 0);
  curl_setopt($curlObj, CURLOPT_HEADER, 0);
  curl_setopt($curlObj, CURLOPT_HTTPHEADER, array('Content-type:application/json'));

  $response = curl_exec($curlObj);
  //change the response json string to object
  $json = json_decode($response);
  curl_close($curlObj);

  return $json;
}

function _goo_gl_get_clicks($object) {
//  dpm($object);
  return $object->analytics->allTime->shortUrlClicks;
}



/**
 * Helper function to @return a Drupal class string based on a boolean argument.
 *
 * That class is used to color settings table rows like on admin/reports/status
 */
function _return_class($boolean) {
  return $boolean ? 'ok' : 'error';
}
