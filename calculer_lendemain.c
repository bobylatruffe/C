#include <stdio.h>

typedef struct {
  int day;
  int month;
  int year;
} Date;

int isLeapYear(int year) {
  if (year % 400 == 0) return 1;
  if (year % 100 == 0) return 0;
  if (year % 4 == 0) return 1;
  return 0;
}

Date nextDay(Date d, int isBissectile) {
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (isBissectile && (d.year)) {
    daysInMonth[2] = 29;
  }

  d.day++;

  if (d.day > daysInMonth[d.month]) {
    d.day = 1;
    d.month++;
    if (d.month > 12) {
      d.month = 1;
      d.year++;
    }
  }

  return d;
}

int main() {
  Date today = {28, 2, 2023};
  Date tomorrow_no_bissectile = nextDay(today, 0);
  printf("Tomorrow's date (no bissextile): %02d/%02d/%04d\n",
         tomorrow_no_bissectile.day, tomorrow_no_bissectile.month,
         tomorrow_no_bissectile.year);

  Date tomorrow = nextDay(today, 1);
  printf("Tomorrow's date (no bissextile): %02d/%02d/%04d\n", tomorrow.day,
         tomorrow.month, tomorrow.year);
  return 0;
}
