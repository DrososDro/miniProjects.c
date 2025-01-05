#include <stdio.h>
#include <stdlib.h>

int mainMenu(void);
void tempInput(float *userTemp);
float FtoC(float *userTemp);
float CtoF(float *userTemp);

int main(void) {
  int choice = 0;

  //
  while ((choice = mainMenu()) != 3) {
    float temp = 0;

    tempInput(&temp);
    switch (choice) {
    case 1:
      printf("\n%.2f Fahrenheit is %.2f Celsius\n\n", temp, FtoC(&temp));
      break;
    case 2:
      printf("\n%.2f Celsius is %.2f Fahrenheit\n\n", temp, CtoF(&temp));
      break;
    }
    printf("Hit Enter To Continue ......");
    getchar();
    system("clear");
  }

  return 0;
}

void tempInput(float *userTemp) {
  int i;

  do {
    printf("enter temprature: ");
    i = scanf("%f", userTemp);
    while (getchar() != '\n')
      ;

  } while (!i);
}

float FtoC(float *userTemp) {
  float fahr = (*userTemp - 32) * 5 / 9;
  return fahr;
}

float CtoF(float *userTemp) {
  float far = *userTemp * 9 / 5 + 32;
  return far;
}

int mainMenu(void) {
  int choice = 0;
  puts("Temprature Converter");
  puts("1 [F]ahrenheit to [C]elcius");
  puts("2 [C]elcius to [F]ahrenheit");
  puts("3 exit");

  do {

    printf(">: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
      ;
  } while (choice < 1 || choice > 3);

  return choice;
}
