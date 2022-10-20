#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

enum { JAN=1, FEB=2, MAR=3, APR=4, MAI=5, JUN=6, JUL=7, AUG=8, SEP=9, OKT=10, NOV=11, DEZ=12 };

int daysInLeap[] = {  31,  29,  31,  30,  31,  30,  31,  31, 30,  31,  30,  31 };
int daysInNormal[] = {  31,  28,  31,  30,  31,  30,  31,  31, 30,  31,  30,  31 };


int main() {
  int year = 0;
  int month = 0;

  printf("Jahr: ");
  scanf("%d", &year);

  printf("Monat: ");
  scanf("%d", &month);

  bool isLeap = year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0);

  isLeap ? printf("%d", daysInLeap[month-1]) : printf("%d", daysInNormal[month-1]);

  return 0;
}