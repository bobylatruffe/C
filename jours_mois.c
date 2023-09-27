#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
  if (ac < 2) {
    printf("Merci de fournit le mois (1=jan, 12=dec)\n");
    printf("Usage: mois 12\n");

    return -1;
  }

  int mois = atoi(av[1]);
  if (mois < 1 || mois > 12) {
    printf("Ce mois n'existe pas !\n");
    return 0;
  }

  switch (mois) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      printf("31 jours !\n");
      break;

    case 2:
      printf("De base 28 mais sa peut être 29\n");
      break;

    default:
      printf("30 jours !\n");
  }
}