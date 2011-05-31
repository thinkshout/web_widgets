<?php
/**
 * @file
 * HTML wrapper code for the iframe'ed code at the external site.
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <?php print $head ?>
    <?php !empty($styles) ? print $styles : '' ?>
    <?php !empty($scripts) ? print $scripts : '' ?>
    <title><?php print $title ?></title>
  </head>
  <body id="widget">
    <?php if ($title): ?><h1 class="page-title"><?php print $title ?></h1><?php endif; ?>
    <?php print $content ?>
  </body>
</html>
