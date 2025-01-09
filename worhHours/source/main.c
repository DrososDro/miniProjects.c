

#include "../headers/workHours.h"
#include "users/users.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  struct user *localUser = NULL;
  localUser = (struct user *)malloc(sizeof(struct user) + 10 * sizeof(void));
  if (localUser == NULL) {
    exit(1);
  }
  int choice = 0;
  choice = mainMenu();

  switch (choice) {
  case 1:
    createUser(localUser);
    break;
  case 2:
    break;
  }

  printf("i am here\n");
  printf("main %s\n", *(localUser)->name);

  free(localUser);

  return 0;
}
