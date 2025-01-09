#include "strUtils/strUtils.h"
#include "users.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *fullPathName = "Data/userData.txt";

static char *parseUserData(char *displayMessage, int mode);
static FILE *getOrCreateFile(void);
void writeUserToFile(struct user *localUser);
static bool isValidUserName(char *username);

void writeUserToFile(struct user *localUser) {
  int id;
  FILE *fp = NULL;
  fp = getOrCreateFile();
  rewind(fp);
  fscanf(fp, "%d", &id);
  id += 1;

  fseek(fp, 0, SEEK_END);
  printf("\nid: %d\n", id);
  localUser->id = id;
  fprintf(fp, "%s,%d,%s,%s,%s", localUser->username, localUser->id,
          localUser->name, localUser->surname, localUser->password);
  fclose(fp);
}

static char *getPassword(void) {
  size_t password_s, password2_s;
  char *password = NULL;
  char *password2 = NULL;
  bool isValidPassword = false;

  while (!isValidPassword) {
    printf("Enter Password");
    getline(&password, &password_s, stdin);
    printf("Verify Password");
    getline(&password2, &password2_s, stdin);

    if ((password_s == password2_s) && (strcmp(password, password2) == 0)) {
      isValidPassword = true;
    }
  }
  if (password != NULL) {

    free(password2);
  }

  return password;
}

static FILE *getOrCreateFile(void) {

  FILE *fp = NULL;
  if ((fp = fopen(fullPathName, "r+")) != NULL)
    return fp;

  char *tempFullPath =
      (char *)malloc((strlen(fullPathName) * sizeof(char)) + 1);
  strcpy(tempFullPath, fullPathName);
  tempFullPath = strtok(tempFullPath, "/");

  char command[100];

  sprintf(command, "mkdir -p %s\n", tempFullPath);
  if (system(command) != 0) {
    printf("Can't create dir:\n%s", tempFullPath);
    exit(1);
  }
  free(tempFullPath);
  fp = fopen(fullPathName, "w+");
  if (fp == NULL) {
    fprintf(stderr, "Can't open %s\n", fullPathName);
    exit(1);
  }
  fprintf(fp, "%d\n", -1);
  fclose(fp);
  fp = fopen(fullPathName, "r+");
  if (fp == NULL) {
    puts("Can't Create folder exiting the program.");
    exit(1);
  }
  return fp;
}

void createUser(struct user *local) {
  local->name = parseUserData("Enter your Name: ", 1);
  local->surname = parseUserData("Enter your Surname: ", 1);
  local->username = parseUserData("Enter your Username: ", 2);
  local->password = getPassword();
}

// parse user data from input;
// moded 1 for isStrAlpha 2 for is username you can have alphanumeics;
static char *parseUserData(char *displayMessage, int mode) {

  size_t size = 20;
  char *buff = NULL;
  char *p = NULL;
  bool isValid = false;

  while (!isValid) {

    printf("%s ", displayMessage);
    if (getline(&buff, &size, stdin) == -1) {
      fputs("Failed to Allocate memory for new user Exitting", stderr);
      exit(1);
    }
    p = trim(buff);

    if (mode == 1) {
      isValid = isStrAlpha(p);
    } else if (mode == 2) {
      isValid = isValidUserName(p);
    }
  };
  size = strlen(p);

  char *data = (char *)malloc((size + 1) * sizeof(char));
  if (data == NULL) {
    fputs("Failed to Allocate memory for data. Exitting... ", stderr);
    exit(1);
  }
  if (strcpy(data, p) == NULL) {
    fputs("Failed to copy string for data Exitting... ", stderr);
    exit(1);
  }

  free(buff);
  return data;
}

static bool isValidUserName(char *username) {
  /*for (; *username !='\0'; username++){*/
  /*  if(!isalpha(*username) || !isalnum(*username));*/
  /*}*/
  while (*username != '\0') {
    /*if (!isalpha(*username) && !isdigit(*username)) {*/
    if (!isalnum(*username)) {
      return false;
    }
    username++;
  }
  return true;
}
