#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

/**
 * @file   permutation.c
 * @author Krime <krime@gmail.com>
 */

/**
 * 
 * @fn     swap(int*a,int*b)
 * @author Krime <krime@gmail.com>
 *
 * @param  a
 *         swap number unit
 * @param  b
 *         swap number unit
 */
void swap(int *a, int *b){int t=0;t=*a;*a=*b;*b=t;}

/**
 * @date   Mon Jan  9 03:48:26 2012
 * @note
 *
 * @brief  
 * @param argc The number of arguments
 * @param argv Argument list for the following descriptions:
 * - n The number range, default value: 16;
 * - r The randomize number from system;
 * - d The dividor, default value: 16;
 * - l The chargement for result, default value: 4;
 * - t The increment for srand(), default value: 0;
 * 
 * @return The permutation from 1 to n
 */
int main(int argc, char* argv[]) {
  int r=0,i=0,n=0,d=0,l=0,t=0;
  int a[N]={0};
  
  switch (argc) {
  case 1:n=16;case 2:d=16;case 3:l=4;case 4:t=0;case 5:break;
  default:printf("permutation [n [d [l [t]]]]\n");exit(1);
  }

  switch (6-argc) {
  case 1:sscanf(argv[4], "%d", &t);case 2:sscanf(argv[3], "%d", &l);
  case 3:sscanf(argv[2], "%d", &d);case 4:sscanf(argv[1], "%d", &n);
  }

  for (i=0;i<n;i++) a[i]=i;
  srand(time(NULL)+t);
  for (i=0;i<n;i++) {r=rand()%(n-i)+i;swap(&a[i],&a[r]);}
  for (i=0;i<n;i++) printf("%d ", a[i]);printf("\n");

  return 0;
}
