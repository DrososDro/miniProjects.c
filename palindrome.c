#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *string);

int main(void) {
  size_t size = 120;
  char *string = NULL;
  string = malloc(size * sizeof(char));
  int active = 1;

  while (active) {

    do {

      printf("Enter # to exit\n");
      printf("Enter a string: ");
      scanf("%s", string);
      while (getchar() != '\n')
        ;
    } while (strlen(string) < 2 && string[0] != '#');

    if (string[0] == '#')
      active = 0;
    else if (isPalindrome(string))
      printf("\n%s is Palindrome!\n\n", string);
    else
      printf("\n%s is not palindrome!\n\n", string);

    if (active) {
      printf("Press enter to continue ......");
      getchar();
      system("clear");
    }
  }
  if (string != NULL) {
    free(string);
  }

  return 0;
}
int isPalindrome(char *string) {
  char *finish = string + strlen(string);

  char *end = string + strlen(string) - 1;

  while (finish > string) {
    if (tolower(*end) != tolower(*string))
      return false;
    end--, string++;
  }
  return true;
}
