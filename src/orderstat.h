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

  template<typename T>
  size_type OrderStat(compare fc) {
    return OrderStat(0,v.size(),fc);
  }

  template<typedef T>
  size_type OrderStat(size_type p,size_type r,compare fc) {
    if (p<r-1&&r) {
      size_type q=(r-p)/2+p;
      size_type r1=OrderStat(p,q,fc);
      size_type r2=OrderStat(q,r,fc);
      size_type r3=MergeStat(p,q,r,fc);
      return r1+r2+r3;
    }
  }

  template<typename T>
  size_type MergeStat(size_type p,size_type q,size_type r,compare fc) {
    vector<T> L(v.begin()+p,v.begin()+q);
    vector<T> R(v.begin()+q,v.begin()+r);
    size_type rp=0;

    for (size_type i=0,j=0,k=p;k<r;) {
      if (fc((void*)&L[i],(void*)&R[j])<0) v[k++]=L[i++];
      else {
        v[k++]=R[j++];
        rp+=q-p-i;
      }
      if (i==q-p) {
        copy(R.begin()+j,R.end(),v.begin()+k);
        break;
      }
      if (j==r-q) {
        copy(L.begin()+i,L.end(),v.begin()+k);
        break;
      }
    }
    return rp;
  }

  template<typename T>
  size_type BruteForceStat(vector<T>&v,compare fc) {
    size_type r=0;
    for (size_type i=0;i<v.size();i++)
      for (size_type j=i+1;j<v.size();j++)
        if (fc((void*)&v[j],(void*)&v[i])<0)
          r++;
    return r;
  }

  template<typename T>
  void Shuffle(vector<T>&v) {
    ::srand(::time(NULL));
    size_type n=v.size();
    for (size_type i=0;i<n;i++) {
      size_type r=::rand()%(n-i)+i;
      swap(v[i],v[r]);
    }
  }
}
#endif//_ORDERSTAT_H
