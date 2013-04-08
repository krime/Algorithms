#include <iostream>
#include <vector>

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "sorting.h"
#include "orderstat.h"

using namespace std;

int comp(void*a,void*b) {
  return *(int*)a-*(int*)b;
}

int main(void) {
  int num[16]={0};
  unsigned int n=sizeof(num)/sizeof(num[0]);
  for (unsigned int i=0;i<n;i++) num[i]=i;
  vector<int> v(num,num+n);
  stat::Shuffle(v);

  for (vector<int>::size_type i=0;i<v.size();i++)
    cout<<' '<<v[i];
  cout<<endl;

  vector<int> o(v);
  stat::size_type osr=stat::OrderStat(o,0,o.size(),comp);
  cout<<osr<<endl;
  vector<int> b(v);
  osr=stat::BruteForceStat(b,0,b.size(),comp);
  cout<<osr<<endl;
  vector<int> vec(v);
  sort::QuickSort(vec,0,vec.size(),comp);
  for (sort::size_type i=0;i<vec.size();i++)
    cout<<' '<<vec[i];
  cout<<endl;
  vector<int> s(v);
  for (sort::size_type i=0;i<s.size();i++)
    cout<<' '<<s[i];
  cout<<endl;
  int rs=stat::RandomSelect(v,0,v.size(),5,comp);
  cout<<rs<<endl;
  return 0;
}
