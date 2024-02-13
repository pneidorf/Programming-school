#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  char *ptr = (char *)str1;
  while (*ptr && result == s21_NULL) {
    for (s21_size_t i = 0; i < s21_strlen(str2); i++) {
      if (*ptr == str2[i]) {
        result = ptr;
        break;
      }
    }
    ptr++;
  }
  return result;
}
