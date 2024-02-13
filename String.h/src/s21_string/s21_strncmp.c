#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t result = 0, counter = 0;
  while (counter < n) {
    if ((*str1 != *str2) || !*str1) {
      result = *str1 - *str2;
      break;
    }
    str1++;
    str2++;
    counter++;
  }
  return result;
}