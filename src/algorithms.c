#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int* x, int* y) {
  int t=*y;
  *y=*x;
  *x=t;
}

void quicksort(int A[], int p, int r);
void insertionsort(int A[], int p, int r);
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

void InsertionSort(int A[], int p, int r) {
  for (int i=p+1;i<r;i++) {
    int key=A[i];
    int j=i-1;
    for (;j>=p && A[j]<key;j--)
      A[j+1]=A[j];
    A[j+1]=key;
  }
}

void SelectionSort(int A[], int p, int r) {
  for (int i=p;i<r;i++) {
    int min=i;
    for (int j=i+1;j<r;j++)
      if (A[min]>A[j]) min=j;
    swap(&A[i],&A[min]);
  }
}

void BubbleSort(int A[], int p, int r) {
  for (int i=p;i<r-1;i++)
    for (int j=r-1;j>i;j--)
      if (A[j]<A[j-1])
        swap(&A[j],&A[j-1]);
}

int main(int argc, char* argv[]) {
  int n = 0;
  int *A = NULL;
  int i = 0;
  int s = 0, t = 0;

  char* pEnd;

  if (argc < 2) {
    exit(1);
  } else {
    //printf("%d\n", argc);
    //for (int i=0;i<argc; i++) puts(argv[i]);
    //puts("");
    //puts(argv[1]);
    n=strtol(argv[1], &pEnd, 10);
    A = (int*)malloc(sizeof(int)*n);
    for (i=0;i<n;i++) A[i]=strtol(argv[i+2],&pEnd,10);
  }
  
  printf("%d\n", n);
  for (i=0;i<n;i++) printf(" %d", A[i]);
  printf("\n");

  /*
  while (scanf("%d %d", &s, &t) == 2 && !(s==0 && t==0)) {
    if (s>n||t>n) continue;
    if (s>t) swap(&s, &t);
    quicksort(A,s,t);
    for (i=0;i<n;i++) printf("%d ", A[i]);
    printf("\n");
  }
  */
  BubbleSort(A,0,n);

  printf("%d\n", n);
  for (i=0;i<n;i++) printf(" %d", A[i]);
  printf("\n");
  
  return 0;
}
