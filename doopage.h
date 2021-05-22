#include <stdio.h>
#include <json-glib/json-glib.h>

gchar *json_object_to_string(JsonObject *json_object);

JsonObject *event_json_object(gchar *event);

JsonObject *event_item_json_object(gchar *event, gchar *item);

JsonObject *event_result_json_object(gchar *event, JsonObject *result);

JsonObject *event_item_result_json_object(gchar *event, gchar *item, JsonObject *result);

JsonObject *success_json_object();

JsonObject *failed_json_object(gchar *reason);
