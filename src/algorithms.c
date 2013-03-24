#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y) {
  int t=*y;
  *y=*x;
  *x=t;
}

void quicksort(int A[], int p, int r);
int  partition(int A[], int p, int r);

void quicksort(int A[], int p, int r) {
  int q=0;
  if (p<r) {
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int partition(int A[], int p, int r) {
  int x = A[r];
  int i = p-1;
  int j = 0;
  for (j=p;j<r;j++) {
    if (A[j] <= x) {
      i++;
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[i+1], &A[r]);
  return i+1;
}

int main(int argc, char* argv[]) {
  int n = 0;
  int *A = NULL;
  int i = 0;
  int s = 0, t = 0;

  if (argc < 2) {
    exit(1);
  } else {
    sscanf(argv[1], "%d", &n);
    A = (int*)malloc(sizeof(int)*n);
    for (i=0;i<n;i++) sscanf(argv[i+2],"%d",&A[i]);
  }
  
  printf("%d\n", n);
  for (i=0;i<n;i++) printf("%d ", A[i]);
  printf("\n");

  while (scanf("%d %d", &s, &t) == 2 && !(s==0 && t==0)) {
    if (s>n||t>n) continue;
    if (s>t) swap(&s, &t);
    quicksort(A,s,t);
    for (i=0;i<n;i++) printf("%d ", A[i]);
    printf("\n");
  }
  return 0;
}
