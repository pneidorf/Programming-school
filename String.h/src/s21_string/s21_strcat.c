#include "../s21_string.h"
char *s21_strcat(char *dest, const char *src) {
  s21_size_t length = 0;
  while (*dest) {
    dest++;
    length++;
  }
  while (*src) {
    *dest = *src;
    dest++;
    src++;
    length++;
  }
  dest = dest - length;
  return dest;
}