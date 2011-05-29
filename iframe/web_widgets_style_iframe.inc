<?php
// $Id: web_widgets_style_iframe.inc,v 1.1.2.5 2010/09/29 02:35:25 diggersf Exp $
/**
 * @file
 * Iframe-specific functions, preprocessing
 */

/**
 * Define the theme functions for the web_widgets module
 */
function web_widgets_style_iframe() {
  $definition = array(
    'theme' => array(
      // The HTML-Javascript code lines what should be pasted into the external site
      'web_widgets_iframe' => array(
        'template' => 'web_widgets_iframe',
        'arguments' => array(
          'path' => NULL,
          'width' => NULL,
          'height' => NULL,
        ),
        'path' => drupal_get_path('module', 'web_widgets') . '/iframe',
      ),
      // The html page which is used inside the iframe, usually will show up on an external site
      'web_widgets_iframe_wrapper' => array(
        'template' => 'web_widgets_iframe_wrapper',
        'arguments' => array(
          'content' => NULL,
          'title' => NULL,
          'scripts' => NULL,
          'styles' => NULL
        ),
        'path' => drupal_get_path('module', 'web_widgets') . '/iframe',
      ),
    ),
    'human_readable' => t('IFrame'),
  );
  return $definition;
}

/**
 * Process variables for web_widgets_iframe.tpl.php
 */
function template_preprocess_web_widgets_iframe(&$variables) {
  $variables['wid'] = 'web_widget_iframe_' . md5(microtime());

  // Create Javascript variables
  $widgetcontext = new stdClass();
  $widgetcontext->url = $variables['path'];
  if (empty($variables['width'])) {
    $variables['width'] = 200;
  }
  if (empty($variables['height'])) {
    $variables['height'] = 200;
  }

  $widgetcontext->width = $variables['width'];
  $widgetcontext->height = $variables['height'];
  $widgetcontext->widgetid = $variables['wid'];

  $variables['js_variables'] = drupal_json_encode($widgetcontext);
  $variables['script_url'] = $GLOBALS['base_url'] . '/' . drupal_get_path('module', 'web_widgets') . '/iframe/web_widgets_iframe.js';
}

function template_preprocess_web_widgets_iframe_wrapper(&$variables) {
  dpm(func_get_args());
  
  $variables['head'] = drupal_get_html_head();
  
  if (!empty($variables['scripts'])) {
    foreach($variables['scripts'] as $script) {
      $scripts .= '<script type="text/javascript" src="' . $script . '"></script>';
    }
    $variables['scripts'] = $scripts;    
  }

  if (!empty($variables['styles'])) {
    foreach($variables['scstylesripts'] as $style) {
      $styles .= '<style type="text/css" media="all">@import url(' . $style . ')</style>';
    }
    $variables['styles'] = $styles;    
  }  
}
