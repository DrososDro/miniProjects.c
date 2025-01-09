#include "../headers/workHours.h"
#include <stdio.h>

int mainMenu(void) {
  int choice = 0;
  puts("Work Hours logger");
  puts("1 create user");
  puts("2 find user");
  puts("3 exit");

  do {
    printf(">: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
      ;

  } while (choice < 1 || choice > 3);

  return choice;
}
