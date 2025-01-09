#include "users.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool isValidName(char *restrict name);

char *parseUserData(char *displayMessage);
static FILE *getOrCreateFile(char *filename);
static void writeUserToFile(struct user *localUser);

static void writeUserToFile(struct user *localUser) {
  int id = -1;
  FILE *fp = NULL;
  char *filename = "./data/users";
  fp = getOrCreateFile(filename);
  if (fp == NULL) {
    fprintf(stderr, "Can't create file %s\n", filename);
  }
  rewind(fp);
  fscanf(fp, "%d", &id);
  id += 1;
  printf("\nid: %d\n", id);
  /*localUser->id = id;*/
  /*fprintf(fp, "%s-%d{%s %s %s}", localUser->username, localUser->id,*/
  /*        localUser->name, localUser->surname, localUser->password);*/
}

static FILE *getOrCreateFile(char *filename) {
  FILE *fp = NULL;
  if ((fp = fopen(filename, "r+")) != NULL)
    return fp;

  fp = fopen(filename, "w+");
  if (fp == NULL) {
    fprintf(stderr, "Can't openn %s\n", filename);
    exit(1);
  }
  fprintf(fp, "%d", -1);
  fclose(fp);
  fp = fopen(filename, "r+");
  return fp;
}

void createUser(struct user *local) {
  *(local)->name = parseUserData("Enter the Name: ");
  printf("main %s\n", *(local)->name);
}

// parse user data from input;
char *parseUserData(char *displayMessage) {

  size_t size = 20;
  char *buff = (char *)malloc(sizeof(char) * size);
  int i;
  if (buff == NULL) {
    fprintf(stderr, "Can't allocate memory exiting ");
    exit(1);
  }
  bool isValid = false;
  char *name[20];
  while (!isValid) {

    printf("%s ", displayMessage);
    i = getline(&buff, &size, stdin);
    isValid = isValidName(buff);
  };
  sscanf(buff, "%s", *name);

  free(buff);
  return *name;
}

// validate the users, name, surname username;
static bool isValidName(char *restrict name) {
  int ch = 0;
  bool space = false;
  while (*name != '\n') {
    if (isalpha(*name) && !space)
      ch++;
    else if (isalpha(*name) && space) {
      return false;
    } else if (*name == ' ')
      space = true;

    name++;
  }
  return true;
}
