
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
extern void writeUserToFile(void);
int main(void) {
  /*FILE *fp;*/
  /*size_t line_s;*/
  /*char *line = NULL;*/
  writeUserToFile();

  /*fp = fopen("./Data/userData.txt", "r+");*/

  /**/
  /*while (getline(&line, &line_s, fp) > 0) {*/
  /*  printf("%s", line);*/
  /*}*/
  /*free(line);*/
  /*fclose(fp);*/
  /*fseek(fp, 0, SEEK_END);*/
  /*int ch;*/
  /*int i = 0;*/
  /*while (ftell(fp) > 0) {*/
  /*  fseek(fp, -2, SEEK_CUR);*/
  /**/
  /*  ch = fgetc(fp);*/
  /*  printf("%ld,%d\n", ftell(fp), ch);*/
  /*  i++;*/
  /*  if (i % 20 == 0) {*/
  /*    fgetc(stdin);*/
  /*  }*/
  /*}*/
  /**/
  return 0;
}
