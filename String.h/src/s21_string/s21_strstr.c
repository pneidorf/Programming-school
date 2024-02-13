#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == s21_NULL || needle == s21_NULL) return s21_NULL;
  if (s21_strlen(needle) == 0) return (char *)haystack;

  char *result = s21_NULL;
  s21_size_t cmp_symb = 0;
  s21_size_t pos_first = 0;

  for (s21_size_t i = 0; i < s21_strlen(haystack); i++) {
    if (haystack[i] == needle[cmp_symb]) {
      if (cmp_symb == 0) {
        pos_first = i;
      }
      cmp_symb++;
      if (cmp_symb == s21_strlen(needle)) {
        result = (char *)(haystack + pos_first);
        break;
      }
    } else
      cmp_symb = 0;
  }
  return result;
}
