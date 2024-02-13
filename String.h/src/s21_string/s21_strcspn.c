#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int break_flag = 1;
  for (s21_size_t i = 0; i < s21_strlen(str1) && break_flag; i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2) && break_flag; j++) {
      if (str1[i] == str2[j]) break_flag = 0;
    }
    if (break_flag) result++;
  }
  return result;
}