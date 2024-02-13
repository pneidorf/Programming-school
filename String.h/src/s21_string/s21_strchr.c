#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  s21_size_t len = s21_strlen(str);
  for (s21_size_t i = 0; i < len + 1; i++) {
    if (*str == (char)c) {
      result = (char *)str;
      break;
    }
    str++;
  }
  return result;
}