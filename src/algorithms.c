#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void swap(int* x, int* y) {
  int t=*y;
  *y=*x;
  *x=t;
}

void InsertionSort(int A[], int p, int r);
void SelectionSort(int A[], int p, int r);
void BubbleSort(int A[], int p, int r);
void MergeSort(int A[], int p, int r);
void Merge(int A[], int p, int q, int r);
void QuickSort(int A[], int p, int r);
int  Partition(int A[], int p, int r);

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

void MergeSort(int A[], int p, int r) {
  if (p<r) {
    int q=(r-p)/2+p;
    MergeSort(A,p,q);
    MergeSort(A,q,r);
    Merge(A,p,q,r);
  }
}

void Merge(int A[], int p, int q, int r) {
  int n1=q-p;
  int n2=r-q;

  int* L=(int*)malloc((n1+1)*sizeof(A[0]));
  int* R=(int*)malloc((n2+1)*sizeof(A[0]));

  for (int i=0;i<n1;i++) L[i]=A[p+i];
  for (int i=0;i<n2;i++) R[q+i]=A[q+i];
  L[n1]=INT_MAX;
  R[n2]=INT_MAX;

  for (int i=0;i<n1;i++)
    printf(" %d", L[i]);
  puts("");
  for (int i=0;i<n2;i++)
    printf(" %d", R[i]);
  puts("");

  for (int i=0,j=0,k=p;k<r;k++) {
    if (L[i]<=R[j]) A[k]=L[i++];
    else A[k]=R[j++];
  }
  free(L);
  free(R);
}

void QuickSort(int A[], int p, int r) {
  int q=0;
  if (p<r) {
    q = Partition(A, p, r);
    QuickSort(A, p, q-1);
    QuickSort(A, q+1, r);
  }
}

int Partition(int A[], int p, int r) {
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
  MergeSort(A,0,n);

  printf("%d\n", n);
  for (i=0;i<n;i++) printf(" %d", A[i]);
  printf("\n");
  
  return 0;
}
