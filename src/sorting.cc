#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include "sorting.h"

template<typename T>
void Sort::InsertionSort(vector<T>&v,size_type p,size_type r,compare fc) {
  for (size_type i=p+1;i<r;i++) {
    T key=v[i];
    size_type j=i;
    while (j>p && fc((void*)&key,(void*)&v[j-1])<0) {
      v[j]=v[j-1];
      j--;
    }
    v[j]=key;
  }
}

template<typename T>
void Sort::SelectionSort(vector<T>&v,size_type p,size_type r,compare fc) {
  for (size_type i=p;i<r;i++) {
    size_type min=i;
    for (size_type j=i+1;j<r;j++)
      if (fc((void*)&v[j],(void*)&v[min])<0)
        min=j;
    swap(v[i],v[min]);
  }
}

template<typename T>
void Sort::BubbleSort(vector<T>&v,size_type p,size_type r,compare fc) {
  for (size_type i=p;i<r-1;i++)
    for (size_type j=r-1;j>i;j--)
      if (fc((void*)&v[j],(void*)&v[j-1])<0)
        swap(v[j],v[j-1]);
}

template<typename T>
void Sort::MergeSort(vector<T>&v,size_type p,size_type r,compare fc) {
  if (p<r-1) {
    size_type q=(r-p)/2+p;
    MergeSort(v,p,q,fc);
    MergeSort(v,q,r,fc);
    Merge(v,p,q,r,fc);
  }
}

template<typename T>
void Sort::Merge(vector<T>&v,size_type p,size_type q,size_type r,compare fc) {
  vector<T> L(v.begin()+p,v.begin()+q);
  vector<T> R(v.begin()+q,v.begin()+r);

  for (size_type i=0,j=0,k=p;k<r;) {
    if (fc((void*)&L[i],(void*)&R[j])<0) v[k++]=L[i++];
    else v[k++]=R[j++];
    if (i==q-p) {
      copy(R.begin()+j,R.end(),v.begin()+k);
      break;
    }
    if (j==r-q) {
      copy(L.begin()+i,L.end(),v.begin()+k);
      break;
    }
  }
}

template<typename T>
void Sort::QuickSort(vector<T>&v,size_type p,size_type r,compare fc) {
  if (p<r-1) {
    size_type q=Partition(v,p,r,fc);
    QuickSort<T>(v,p,q,fc);
    QuickSort<T>(v,q+1,r,fc);
  }
}

template<typename T>
typename Sort::size_type Sort::Partition(vector<T>&v,size_type p,size_type r,compare fc) {
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
void Sort::HeapSort(vector<T>&v,size_type p,size_type r,compare fc) {
  for (size_type i=(r+p)/2-1;i>=p&&i+1!=0;i--)
    Heapify(v,p,r,i,fc);
  for (size_type i=p;i<r;i++)
    cout<<v[i]<<' ';
  cout<<endl;
  for (size_type i=r-1;i>=p && i+1!=0;i--) {
    swap(v[p],v[i]);
    Heapify(v,p,r-1,p,fc);
  }
}

template<typename T>
void Sort::Heapify(vector<T>&v,size_type p,size_type r,size_type i,compare fc) {
  size_type ln=i*2-p+1;
  size_type rn=i*2-p+2;
  size_type s=i;

  cout<<v[i]<<' '<<v[ln]<<' '<<v[rn]<<endl;

  if (ln<r && fc((void*)&v[ln],(void*)&v[s])<0)
    s=ln;
  if (rn<r && fc((void*)&v[rn],(void*)&v[s])<0)
    s=rn;
  if (s!=i) {
    swap(v[i],v[s]);
    Heapify(v,p,r,s,fc);
  }
}

int comp(void*a,void*b) {
  return *(int*)a-*(int*)b;
}

int main(void) {
  int n[16]={0};
  for (unsigned int i=0;i<8;i++)
    n[i]=i;
  for (unsigned int i=8;i<16;i++)
    n[i]=23-i;
  
  vector<int> v(n,n+16);
  for (vector<int>::size_type i=0;i<v.size();i++)
   cout<<' '<<v[i];
  cout<<endl;
  Sort::HeapSort(v,0,v.size(),comp);
  for (vector<int>::size_type i=0;i<v.size();i++)
    cout<<' '<<v[i];
  cout<<endl;
  return 0;
}
