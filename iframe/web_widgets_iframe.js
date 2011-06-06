// Test for minimal Javascript required by Drupal.
if (document.getElementsByTagName && document.createElement && document.createTextNode && document.documentElement && document.getElementById) {
  var DrupalEmbed = DrupalEmbed || [];
  DrupalEmbed[DrupalEmbed.length] = {
    src: widgetContext['url'],
    wid: widgetContext['widgetid'],
    width: widgetContext['width'],
    height: widgetContext['height'],
    scrolling: widgetContext['scrolling']
  };

  for (var i in DrupalEmbed) {
    if (!DrupalEmbed[i]['processed']) {
      DrupalEmbed[i]['processed'] = true;
      
      var separator = DrupalEmbed[i].src.indexOf('?') == -1 ? '?' : '&';
      
      if (undefined===window.widget_count){
        window.widget_count = 0;
      }
      else {
        widget_count++;
      }
      
      var script = document.getElementById(DrupalEmbed[i].wid);
      script.setAttribute('id', DrupalEmbed[i].wid);
      
      var iframe = document.createElement('iframe');
      iframe.setAttribute('id', 'widgets-' + widget_count);
      iframe.setAttribute('frameBorder', '0');
      iframe.setAttribute('width', DrupalEmbed[i].width);
      iframe.setAttribute('height', DrupalEmbed[i].height);
      iframe.setAttribute('src', DrupalEmbed[i].src);
      iframe.setAttribute('scrolling', DrupalEmbed[i].scrolling);
      
      script.parentNode.insertBefore(iframe, script);
    }
  }
}
