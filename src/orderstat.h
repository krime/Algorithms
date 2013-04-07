#ifndef _ORDERSTAT_H
#define _ORDERSTAT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace stat {
  typedef unsigned long size_type;
  typedef long (*compare)(void*,void*);
  
  template<typename T>
  void swap(T&r,T&s) {T t=r;r=s;s=t;}
  
  template<typename T>
  size_type RandomSelect(vector<T>&v,size_type p,size_type r,size_type k,compare fc) {
    if (p==r)
      return v[p];
    size_type q=RandomPartition(v,p,r,fc);
    size_type i=q-p;
    if (k==i)
      return v[q];
    else if (k<i)
      return RandomSelect(v,p,q,k);
    else
      return RandomSelect(v,q+1,r,k-i);
  }

  template<typename T>
  size_type RandomPartition(vector<T>&v,size_type p,size_type r,compare fc) {
    ::srand(::time(NULL));
    size_type n=::rand()%(r-p)+p;
    swap(v[n],v[r-1]);
    size_type i=p-1;
    T pivot=v[r-1];
    for (size_type j=p;j<r-1;j++)
      if (fc((void*)&v[j],(void*)&pivot)<0)
        if (++i!=j)
          swap(v[i],v[j]);
    swap(v[i+1],v[r-1]);
    return i+1;
  }
}
#endif//_ORDERSTAT_H
