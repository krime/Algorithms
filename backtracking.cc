#include <iostream>
#include <cstring>

using namespace std;

#define MAXCANDIDATES 2
#define MAX 2

void backtrack(int[],int,int);
bool is_a_solution(int[],int,int);
void construct_candidates(int[],int,int,int[],int&);
void process_solution(int[],int);

bool finished=false;

bool is_a_solution(int a[],int k,int n) {
  return k==n;
}

void construct_candidates(int a[],int k,int n,int c[],int&ncandidates) {
  c[0]=true;
  c[1]=false;
  ncandidates=2;
}

void process_solution(int a[],int k) {
  cout<<'{';
  for (int i=0;i<=k;i++)
    if (a[i])
      cout<<' '<<i+1;
  cout<<" }"<<endl;
}

void backtrack(int a[],int k,int input) {
  int c[MAXCANDIDATES]; // candidates for next positions
  int ncandidates;      // next position candidates count
  k++;

  if (is_a_solution(a,k,input))
    process_solution(a,k);
  else {
    construct_candidates(a,k,input,c,ncandidates);
    for (int i=0;i<ncandidates;i++) {
      a[k]=c[i];
      backtrack(a,k,input);
      if (finished) return;
    }
  }
}

int main(void) {
  int a[MAX];
  memset(a,0,sizeof a);
  backtrack(a,-1,MAX);
  return 0;
}
