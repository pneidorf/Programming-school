#include "../s21_string.h"
// c# Exceptions

// ArgumentNullException
// value is null.

// ArgumentOutOfRangeException
// startIndex is negative or greater than the length of this instance.

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (str != s21_NULL && src != s21_NULL) {
    if (start_index <= s21_strlen(src)) {
      s21_size_t comb_len = s21_strlen(src) + s21_strlen(str), counter = 0;
      result = (char *)malloc((comb_len) + sizeof(char) + 1);
      char *ptr = result;
      while (counter < start_index) {
        *ptr = *src;
        ptr++;
        src++;
        counter++;
      }
      while (*str) {
        *ptr = *str;
        ptr++;
        str++;
      }
      while (*src) {
        *ptr = *src;
        ptr++;
        src++;
      }
      *ptr = '\0';
    }
  }
  return (char *)result;
}
