#include <iostream>
#include <cstring>

using namespace std;

#define MAXCANDIDATES 3
#define MAX 3

void backtrack(int[],int,int);
bool is_a_solution(int[],int,int);
void construct_candidates(int[],int,int,int[],int&);
void process_solution(int[],int);

bool finished=false;

// TODO: check whether the k-th trial satisfies the solution
bool is_a_solution(int a[],int k,int n) {
  return k==n-1;
}

// TODO: construct the probable solutions
void construct_candidates(int a[],int k,int n,int c[],int&ncandidates) {
  c[0]=true;
  c[1]=false;
  ncandidates=2;
}

void process_solution(int a[],int k) {
  cout<<'{';
  for (int i=0;i<k;i++)
    if (a[i])
      cout<<' '<<i;
  cout<<" }"<<endl;
}

// TODO: do the k-th backtrack
void backtrack(int a[],int k,int input) {
  int c[MAXCANDIDATES]; // candidates for next positions
  int ncandidates;      // next position candidates count

  // TODO: check the former solution vector a[0..k-1]
  if (is_a_solution(a,k-1,input))
    process_solution(a,k);
  else {
    construct_candidates(a,k,input,c,ncandidates);
    for (int i=0;i<ncandidates;i++) {
      a[k]=c[i];
      // TODO: the next trial
      backtrack(a,k+1,input);
      // TODO: for finding only 1 solution
      if (finished) return;
    }
  }
}

int main(void) {
  int a[MAX];
  memset(a,0,sizeof a);
  // TODO: start the first trial
  backtrack(a,0,MAX);
  return 0;
}
