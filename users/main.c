

#include "users.h"
#include <stdio.h>
#include <stdlib.h>
extern int mainMenu();

int main(void) {
  struct user *localUser = NULL;
  localUser = (struct user *)malloc(sizeof(struct user));
  if (localUser == NULL) {
    fputs("Can't Allocate memory for lacal User", stderr);
    goto freeMemory;
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

  printf("main Before print Local User\n");
  printf("main name %s\n", localUser->name);
  printf("main surname %s\n", localUser->surname);
  printf("main username %s\n", localUser->username);

freeMemory:

  free(localUser);

  return 0;
}
