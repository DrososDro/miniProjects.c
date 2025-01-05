#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int numbersInput(int *a, int *b);
static int isCorrectFormated(char *string);
int mainMenu(void);
int add(int a, int b);
int divide(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

int main(void) {
  int choice = 0;

  while ((choice = mainMenu()) != 5) {

    int a = 0;
    int b = 0;
    int result = 0;
    numbersInput(&a, &b);
    switch (choice) {
    case 1:
      result = add(a, b);
      break;

    case 2:
      result = subtract(a, b);
      break;
    case 3:
      result = divide(a, b);
      break;
    case 4:
      result = multiply(a, b);
      break;
    }

    printf("\nThe result is %d\n\n", result);
    printf("press a key to continue ....");
    getchar();
    system("clear");
  }
  return 0;
}

int add(int a, int b) { return a + b; }
int divide(int a, int b) {
  if (b == 0) {
    fprintf(stderr, "Zero Division Error");
    exit(EXIT_FAILURE);
  }
  return a / b;
}
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int mainMenu(void) {
  printf("Simple Calculator\n");
  printf("1 add\n");
  printf("2 subtract\n");
  printf("3 divide\n");
  printf("4 multiply\n");
  printf("5 exit\n");

  int choice = 0;
  do {
    printf(">: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
      ;
  } while (choice == 0 || choice < 1 || choice > 5);

  return choice;
}

static int numbersInput(int *a, int *b) {
  size_t size = 10;
  char *buff = NULL;
  int error = 1;

  while (error) {

    printf("enter the 2 operants (a b): ");
    if (getline(&buff, &size, stdin) != -1)
      error = !isCorrectFormated(buff);
  }

  sscanf(buff, "%d %d", a, b);

  if (buff != NULL) {
    free(buff);
  }

  return 0;
};

static int isCorrectFormated(char *restrict string) {
  int beforeSpace = 0;
  int space = false;
  int afterSpace = 0;
  for (; *string != '\n'; string++)

    if (isdigit(*string)) {
      if (space)
        afterSpace++;
      else
        beforeSpace++;

    } else if (*string == ' ') {
      if (beforeSpace > 0)
        space = true;

    } else {
      return false;
      break;
    }
  if (beforeSpace > 0 && afterSpace > 0) {
    return true;
  }
  return false;
}
