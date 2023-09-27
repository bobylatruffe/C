#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_validity_time(char *time, int *hour, int *minutes, int *seconds) {
  int h = 0;
  int m = 0;
  int s = 0;
  int nb_valide = 0;

  char *endptr = NULL;
  char *token = strtok(time, ":");

  for (int i = 0; i < 3 && token != NULL; i++) {
#ifdef DEBUG
    printf("%s\n", token);
#endif

    switch (i) {
      case 0:
        h = strtol(token, &endptr, 10);
        if (endptr == token) {
#ifdef DEBUG
          printf("Erreur hours\n");
#endif
          return -1;
        } else
          *hour = h;
        nb_valide++;
        break;

      case 1:
        m = strtol(token, &endptr, 10);
        if (endptr == token) {
#ifdef DEBUG
          printf("Erreur minutes\n");
#endif
          return -1;
        } else
          *minutes = m;
        nb_valide++;
        break;

      case 2:
        s = strtol(token, &endptr, 10);
        if (endptr == token) {
#ifdef DEBUG
          printf("Erreur secondes\n");
#endif
          return -1;
        } else
          *seconds = s;
        nb_valide++;
        break;
    }

    token = strtok(NULL, ":");
  }

  return nb_valide;
}

int main(int ac, char **av) {
  if (ac < 2) {
    printf("Merci de fournit les deux durées\n");
    printf("Usage: h2:m2:s2  h1:m1:s1\n");

    return -1;
  }

  int hour_1 = 0;
  int minutes_1 = 0;
  int seconds_1 = 0;

  int hour_2 = 0;
  int minutes_2 = 0;
  int seconds_2 = 0;

  if (check_validity_time(av[1], &hour_1, &minutes_1, &seconds_1) != 3) {
    printf("Error format time 1\n");
    return -1;
  }
  if (check_validity_time(av[2], &hour_2, &minutes_2, &seconds_2) != 3) {
    printf("Error format time 2\n");
    return -1;
  }

  int time_1_in_seconds = hour_1 * 3600 + minutes_1 * 60 + seconds_1;
  int time_2_in_seconds = hour_2 * 3600 + minutes_2 * 60 + seconds_2;

  int elapsed_same_day = time_1_in_seconds - time_2_in_seconds;
  if (elapsed_same_day >= 0) {
    printf("Nombre de secondes entres les deux temps : %d secondes\n",
           elapsed_same_day);
  } else
    printf("Les durée ne se succèdent pas!");

  int elapsed_not_same_day = time_1_in_seconds + 86400 - time_2_in_seconds;
  if (elapsed_not_same_day >= 0) {
    printf("Nombre de secondes entres les deux temps : %d secondes\n",
           elapsed_not_same_day);
  } else
    printf("Les durée ne se succèdent pas!");
}