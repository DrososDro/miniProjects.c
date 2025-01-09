#include <string.h>

int main(void) {
  printf("void\n");
  char *new2Line;

  new2Line = test();

  /*char *test = "    Xaos     Maker      ";*/
  /*char *hasValue;*/
  /*hasValue = strchr(test, '\0');*/
  /*printf("has %p\n", hasValue);*/
  /**/
  /*size_t size = strlen(test);*/
  /**/
  /*printf("%ld\n", size);*/
  /*for (int i = 0; i < size; i++)*/
  /*  printf("%d\n", test[i]);*/
  /**/

  return 0;
}

char *test() {
  char *fromLine = NULL;
  size_t size = 60;
  strlen(const char *)

      // get string from file
      getline(fromLine, size, stdin) // from here we take (5spaces)xaos(5spaces)

      char *newLine = malloc(trimed size + 1) trim(fromLine);
  strlen(const char *) strcpy(newLine, trim(fromLine))

      return newLine
}
