(function ($) {

/**
 * Update the summary for the module's vertical tab.
 */
Drupal.behaviors.vertical_tabs_exampleFieldsetSummaries = {
  attach: function (context) {
    // Use the fieldset class to identify the vertical tab element
    $('fieldset#edit-goo-gl', context).drupalSetSummary(function (context) {
      // Depending on the checkbox status, the settings will be customized, so
      // update the summary with the custom setting textfield string or a use a
      // default string.
      if ($('#edit-goo-gl-enabled', context).attr('checked')) {
        // return Drupal.checkPlain($('#edit-goo-gl-custom-setting', context).val());
        return Drupal.t('Enabled');
      }
      else {
        return Drupal.t('Disabled');
      }
    });
  }
};

})(jQuery);