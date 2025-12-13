#include <assert.h>
#include <bare.h>
#include <js.h>
#include <log.h>
#include <stdio.h>
#include <stdlib.h>
#include <utf.h>

static js_value_t *
bare_logger_debug(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *argv[1];
  size_t argc = 1;

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  size_t data_len;
  err = js_get_value_string_utf8(env, argv[0], NULL, 0, &data_len);
  assert(err == 0);

  data_len += 1 /* NULL */;

  utf8_t *data = malloc(data_len);
  err = js_get_value_string_utf8(env, argv[0], data, data_len, NULL);
  assert(err == 0);

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  log_debug("%s", data);

  free(data);

  return NULL;
}

static js_value_t *
bare_logger_info(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *argv[1];
  size_t argc = 1;

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  size_t data_len;
  err = js_get_value_string_utf8(env, argv[0], NULL, 0, &data_len);
  assert(err == 0);

  data_len += 1 /* NULL */;

  utf8_t *data = malloc(data_len);
  err = js_get_value_string_utf8(env, argv[0], data, data_len, NULL);
  assert(err == 0);

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  log_info("%s", data);

  free(data);

  return NULL;
}

static js_value_t *
bare_logger_warn(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *argv[1];
  size_t argc = 1;

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  size_t data_len;
  err = js_get_value_string_utf8(env, argv[0], NULL, 0, &data_len);
  assert(err == 0);

  data_len += 1 /* NULL */;

  utf8_t *data = malloc(data_len);
  err = js_get_value_string_utf8(env, argv[0], data, data_len, NULL);
  assert(err == 0);

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  log_warn("%s", data);

  free(data);

  return NULL;
}

static js_value_t *
bare_logger_error(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *argv[1];
  size_t argc = 1;

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  size_t data_len;
  err = js_get_value_string_utf8(env, argv[0], NULL, 0, &data_len);
  assert(err == 0);

  data_len += 1 /* NULL */;

  utf8_t *data = malloc(data_len);
  err = js_get_value_string_utf8(env, argv[0], data, data_len, NULL);
  assert(err == 0);

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  log_error("%s", data);

  free(data);

  return NULL;
}

static js_value_t *
bare_logger_fatal(js_env_t *env, js_callback_info_t *info) {
  int err;

  js_handle_scope_t *scope;
  err = js_open_handle_scope(env, &scope);
  assert(err == 0);

  js_value_t *argv[1];
  size_t argc = 1;

  err = js_get_callback_info(env, info, &argc, argv, NULL, NULL);
  assert(err == 0);

  assert(argc == 1);

  size_t data_len;
  err = js_get_value_string_utf8(env, argv[0], NULL, 0, &data_len);
  assert(err == 0);

  data_len += 1 /* NULL */;

  utf8_t *data = malloc(data_len);
  err = js_get_value_string_utf8(env, argv[0], data, data_len, NULL);
  assert(err == 0);

  err = js_close_handle_scope(env, scope);
  assert(err == 0);

  log_fatal("%s", data);

  free(data);

  exit(1);

  return NULL;
}

static js_value_t *
bare_logger_exports(js_env_t *env, js_value_t *exports) {
  int err;

#define V(name, fn) \
  { \
    js_value_t *val; \
    err = js_create_function(env, name, -1, fn, NULL, &val); \
    assert(err == 0); \
    err = js_set_named_property(env, exports, name, val); \
    assert(err == 0); \
  }

  V("debug", bare_logger_debug)
  V("info", bare_logger_info)
  V("warn", bare_logger_warn)
  V("error", bare_logger_error)
  V("fatal", bare_logger_fatal)
#undef V

  return exports;
}

BARE_MODULE(bare_logger, bare_logger_exports)
