#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
  int an_integer = 0;
  float a_float = 0.0f;

  printf("Un entier : ");
  scanf("%d", &an_integer);
  printf("Vous avez fournit : %d\n", an_integer);

  printf("Un float : ");
  scanf("%f", &a_float);
  printf("Vous avez fournit : %f\n", a_float);
}