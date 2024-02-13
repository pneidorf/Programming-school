#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src != s21_NULL) {
    result = (char *)malloc(s21_strlen(src) * sizeof(char) + 1);
    char *ptr = result;
    const char *start_fragment = src, *end_fragment = src + s21_strlen(src),
               *tr_ch = trim_chars, *default_chars = " \t\n\v\r\f\0";
    if (!trim_chars) tr_ch = default_chars;
    if (s21_strlen(tr_ch) == 0) tr_ch = default_chars;
    while (*start_fragment && s21_strchr(tr_ch, *start_fragment) != s21_NULL) {
      start_fragment++;
    }
    while (s21_strchr(tr_ch, *end_fragment) != s21_NULL &&
           end_fragment != start_fragment) {
      end_fragment--;
    }
    end_fragment++;
    while (start_fragment != end_fragment) {
      *ptr = *start_fragment;
      ptr++;
      start_fragment++;
    }
    *ptr = '\0';
  }
  return result;
}