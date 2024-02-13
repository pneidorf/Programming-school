#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *new_str = s21_NULL;
  if (str != s21_NULL) {
    new_str = str;
    while (*new_str && s21_strchr(delim, *new_str)) *new_str++ = '\0';
  }
  if (new_str == s21_NULL) return str;

  if (*new_str != '\0') {
    str = new_str;
    while (*new_str && !s21_strchr(delim, *new_str)) ++new_str;
    while (*new_str && s21_strchr(delim, *new_str)) *new_str++ = '\0';
  } else
    str = s21_NULL;
  return str;
}