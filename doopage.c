#include "doopage.h"

gchar *json_object_to_string(JsonObject *json_object) {
  JsonGenerator *generator;
  JsonNode *root;
  gchar *string;

  root = json_node_new(JSON_NODE_OBJECT);
  json_node_set_object(root, json_object);

  generator = json_generator_new();
  json_generator_set_root(generator, root);

  string = json_generator_to_data(generator, NULL);

  g_object_unref(generator);
  json_node_free(root);

  return string;
}

JsonObject *event_json_object(gchar *event) {
  JsonObject *object = json_object_new();

  json_object_set_string_member(object, "event", event);

  return object;
}

JsonObject *event_item_json_object(gchar *event, gchar *item) {
  JsonObject *object = event_json_object(event);

  json_object_set_string_member(object, "item", item);

  return object;
}

JsonObject *event_result_json_object(gchar *event, JsonObject *result) {
  JsonObject *object = event_json_object(event);

  json_object_set_object_member(object, "result", result);

  return object;
}

JsonObject *event_item_result_json_object(gchar *event, gchar *item, JsonObject *result) {
  JsonObject *object = event_json_object(event);

  json_object_set_string_member(object, "item", item);
  json_object_set_object_member(object, "result", result);

  return object;
}

JsonObject *success_json_object() {
  JsonObject *object = json_object_new();

  json_object_set_boolean_member(object, "success", 1);

  return object;
}

JsonObject *failed_json_object(gchar *reason) {
  JsonObject *object = json_object_new();

  json_object_set_boolean_member(object, "success", 0);
  json_object_set_string_member(object, "reason", reason);

  return object;
}
