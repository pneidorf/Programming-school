#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *result = s21_NULL;
  if (str) {
    result = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
    s21_strncpy(result, str, s21_strlen(str) + 1);
  }
  if (result) {
    char *ptr = result;
    while (*ptr) {
      if (*ptr >= 'A' && *ptr <= 'Z') *ptr = *ptr + 32;
      ptr++;
    }
  }
  return (char *)result;
}