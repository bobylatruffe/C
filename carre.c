#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void calc_infos_carre(float cote) {
  printf("Le périmètre du carré vaut %f\n", 4 * cote);
  printf("La surface du carré vaut %f\n", cote * cote);

  float d_2 = cote * sqrtf(2);
  printf("La diagonale de ce carré est %f\n", d_2);
}

int main(int ac, char **av) {
  if (ac < 2) {
    printf("Merci de fournit la valeur du côté du carré\n");
    printf("Usage: carre 10\n");

    return -1;
  }

  calc_infos_carre(atoi(av[1]));
}