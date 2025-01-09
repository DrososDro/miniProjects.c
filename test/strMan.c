

#include "strMan.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ltrim(char *restrict s) {
  if (!s) {
    return NULL;
  }
  if (!*s) {
    return s;
  }

  while (isspace(*s))
    s++;
  return s;
}

char *rtrim(char *s) {
  /*char *back = NULL;*/
  size_t len;
  size_t size;
  size = sizeof(*s);
  printf("%d-%d\n", *(s + size), *(s + len));
  printf("%ld-%ld\n", len, size);
  /*back = s + strlen(s);*/
  /**/
  /*if (back == NULL) {*/
  /*  printf("enter null\n");*/
  /*  exit(1);*/
  /*}*/
  /**/
  /*while (isspace(*--back)) {*/
  /*  printf("!%c!\n", *back);*/
  /*}*/
  /**/
  /*printf(";%c;\n", *back);*/
  /*printf(";%s;\n", s);*/
}
