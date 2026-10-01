<?php 

$incfile = __DIR__ . '/platform_specific/lib/code_library.inc';
if (file_exists($incfile)) {
    include_once $incfile;
}


use Drupal\Core\Cache\CacheableMetadata;

/**
 * Prepares variables for `breadcrumb.html.twig`.
 */
function islandora_muni_preprocess_breadcrumb(&$variables){

//$current_path = \Drupal::service('path.current')->getPath();
//$path_alias = \Drupal::service('path_alias.manager')->getAliasByPath($current_path);

//if (str_contains($current_path, "authors")) {
//   $variables['breadcrumb'][] = array('text' => 'Authors');
//}

  // Remove 'Home' from breadcrumb trail.
  if (count($variables['breadcrumb']) == 1) {
    array_shift($variables['breadcrumb']);
  }
}

?>
