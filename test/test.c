
#include "test.h"
#include <stdlib.h>
#include <string.h>

char *parseData(char *name) {
  int len = strlen(name);
  char *local = (char *)malloc((len + 1) * sizeof(char));

  strcpy(local, name);

  return local;

  // code do something ;
}
char *createStruct(struct t *name) {
  name->arr = parseData("Hello Drosos");

  return 0;
}
