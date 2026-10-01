<?php

/**
 * @file
 * Functions to support theming in the Islandora MUNI theme.
 */

/**
 * Implements hook_preprocess_node().
 */
function islandora_muni_preprocess_node(&$variables) {

  $current_user = \Drupal::currentUser();
  if ($current_user->hasRole('content_editor') or $current_user->hasRole('administrator')) { 
    return;
  }

  $node = $variables['node'];

  // Loop through all fields of the node and check for unknown 
  // values (values starting with ':')
  foreach ($variables['content'] as $key => &$field) {

    // Check if the field exists on the node and has a value
    if ($node->hasField($key)) {
      $field_value = $node->get($key)->getValue();

      if ($field_value) {

        $field_type = $node->getFieldDefinition($key)->getType();

        if ($field_type == "string") {

          $value = $field_value[0]['value'];

          if (str_starts_with($value, ':')) {

            unset($variables['content'][$key]);
          }
        }
      }
    }
  }
}
