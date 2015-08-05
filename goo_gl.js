(function ($) {

/**
 * Update the summary for the module's vertical tab.
 */
Drupal.behaviors.vertical_tabs_exampleFieldsetSummaries = {
  attach: function (context) {

    var path = $(location).attr('pathname');

    // 1. node type form
    if (path.indexOf('admin/structure/types/manage') >= 0) {

      // Use the fieldset class to identify the vertical tab element
      $('fieldset#edit-goo-gl', context).drupalSetSummary(function (context) {
        // Depending on the checkbox status, the settings will be customized
        if ($('#edit-goo-gl-type', context).attr('checked')) {
          // return Drupal.checkPlain($('#edit-goo-gl-custom-setting', context).val());
          return Drupal.t('Enabled');
        } else {
          return Drupal.t('Disabled');
        }
      });

    // 2. node add/edit form
    } else if (path.indexOf('node/add') >= 0 || (path.indexOf('node/') >= 0 && path.indexOf('/edit') >= 0)) {

      $('fieldset#edit-goo-gl', context).drupalSetSummary(function (context) {
        var enabled = Drupal.settings.goo_gl.enabled;
        if (enabled === true) {
          return Drupal.t('Enabled');
        } else {
          return Drupal.t('Disabled');
        }
      });
    
    }

  }
};

})(jQuery);