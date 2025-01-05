#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MONTHS 12

int mainMenu(void);
double simpleInterestCalculator(double principal, double interestRate,
                                int months);
double comproundInterestCalculator(double principal, double interestRate,
                                   double months);
void userInput(double *principal, double *interestRate, double *months);
static void getInput(double *number, char *text, bool integral);

int main(void) {
  int choice = 0;
  while ((choice = mainMenu()) != 3) {
    double interest = 0.0;
    double principal = 0;
    double interestRate = 0;
    double months = 0;
    userInput(&principal, &interestRate, &months);
    switch (choice) {
    case 1:
      interest = simpleInterestCalculator(principal, interestRate, months);
      printf("\nFrom Principal: %.2lf Interest Rate: %.0lf and months: %.0lf\n",
             principal, interestRate, months);
      printf("The simple interest is: %.4lf\n\n", interest);
      break;
    case 2:
      interest = comproundInterestCalculator(principal, interestRate, months);

      printf("\nFrom Principal: %.2lf Interest Rate: %.0lf and months: %.0lf\n",
             principal, interestRate, months);
      printf("The comprount interest is: %.4lf\n\n", interest);
      break;
    }
    printf("Press Enter to continue .......");
    getchar();
    system("clear");
  }

  return 0;
}

void userInput(double *principal, double *interestRate, double *months) {

  getInput(principal, "Enter the Prinvipal: ", false);
  getInput(interestRate, "Enter the Interest Rate: ", true);
  getInput(months, "Enter the months: ", true);
}
static void getInput(double *number, char *text, bool integral) {
  int i = 0;

  do {
    printf("%s", text);
    i = scanf("%lf", number);
    while (getchar() != '\n')
      ;
  } while (!i);

  if (integral) {
    double integral = 0.0;
    modf(*number, &integral);
    *number = integral;
  }
}

double comproundInterestCalculator(double principal, double interestRate,
                                   double months) {

  double ammount = principal * pow((1 + (interestRate / (100 * MONTHS))),
                                   12 * (months / MONTHS));
  double comprountInterest = ammount - principal;
  return comprountInterest;
}

double simpleInterestCalculator(double principal, double interestRate,
                                int months) {
  double si = (principal * interestRate * months) / (100 * MONTHS);
  return si;
}

int mainMenu(void) {
  int choice = 0;
  puts("Interest Calculator");
  puts("1 Simple interest Calculator");
  puts("2 Compround interest Calculator");
  puts("3 exit");

  do {
    printf(">: ");
    scanf("%d", &choice);
    while (getchar() != '\n')
      ;

  } while (choice < 1 || choice > 3);

  return choice;
}
