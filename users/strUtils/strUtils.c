#include "strUtils.h"
#include <ctype.h>
#include <string.h>

char *ltrim(char *str) {
  if (!str) {
    return NULL;
  }
  if (!*str) {
    return str; // empty str;
  }
  while (isspace(*str))
    str++;

  return str;
}

char *rtrim(char *str) {
  if (!str) {
    return NULL;
  }
  if (!*str) {
    return str; // empty str;
  }

  size_t len = strlen(str);
  char *end = str + len - 1;
  while (isspace(*end) && end >= str)
    end--;

  *(end + 1) = '\0';

  return str;
}

char *trim(char *str) { return rtrim(ltrim(str)); }

bool isStrAlpha(char *restrict str) {
  for (; *str != '\0'; str++)
    if (!isalpha(*str)) {
      return false;
    }
  return true;
}
