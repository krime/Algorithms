#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <ctime>

/**
 * @file   sorting.cc
 * @author Krime <krimelam@gmail.com>
 * @date   Sun Mar 31 01:31:17 UTC 2013
 * @note
 * 
 * @brief
 */

#define uint unsigned int

using namespace std;
/**
   InsertionSort
   SelectionSort
   BubbleSort
   MergeSort
   QuickSort
   HeapSort
 */

template<typename T> class Sort {
public:
  typedef typename vector<T>::size_type size_type;
  typedef typename vector<T>::iterator  iterator;
  typedef int (*compare)(void*,void*);

  static void InsertionSort(vector<T>,size_type,size_type,compare);
  static void SelectionSort(vector<T>,size_type,size_type,compare);
  static void    BubbleSort(vector<T>,size_type,size_type,compare);
  static void     MergeSort(vector<T>,size_type,size_type,compare);
  static void     QuickSort(vector<T>,size_type,size_type,compare);
  static void      HeapSort(vector<T>,size_type,size_type,compare);

  void Merge(vector<T>,size_type,size_type,size_type,compare);
  size_type Partition(vector<T>,size_type,size_type,compare);
  void Heapify(vector<T>,size_type,size_type,compare);

private:
  Sort(){}
  Sort(const Sort&){}
  Sort& operator=(Sort&){}
  const Sort& operator=(const Sort&){}
  ~Sort(){}

  void swap(T&r,T&s) {T t=r;r=s;s=t;}
  // Number of Reversed Pairs
  size_type rp;
};

template<typename T>
void Sort<T>::InsertionSort(vector<T> v,size_type p,size_type r,compare fc) {
  for (size_type i=p+1;i<r;i++) {
    T key(v[i]);
    size_type j=i-1;
    while (j>=p && fc((void*)&v[j],(void*)&key)) v[j+1]=v[j--];
    v[j]=key;
  }
}

template<typename T>
void Sort<T>::SelectionSort(vector<T> v,size_type p,size_type r,compare fc) {
  for (size_type i=p;i<r;i++) {
    size_type min=i;
    for (size_type j=i+1;j<r;j++)
      if (fc((void*)&v[min],(void*)&v[j]))
        min=j;
    swap(&v[i],&v[min]);
  }
}

template<typename T>
void Sort<T>::BubbleSort(vector<T> v,size_type p,size_type r,compare fc) {
  for (size_type i=p;i<r-1;i++)
    for (size_type j=r-1;j>i;j--)
      if (fc((void*)&v[j],(void*)&v[j-1]))
        swap(&v[j],&v[j-1]);
}

template<typename T>
void Sort<T>::MergeSort(vector<T> v,size_type p,size_type r,compare fc) {
  if (p<r-1) {
    size_type q=(r-p)/2+p;
    MergeSort(v,p,q,fc);
    MergeSort(v,q,r,fc);
    Merge(v,p,q,r,fc);
  }
}

template<typename T>
void Sort<T>::Merge(vector<T> v,size_type p,size_type q,size_type r,compare fc) {
  iterator i1=v.begin();
  iterator i2=v.begin()+(q-p);

  vector<T> L(i1,i2);
  vector<T> R(i2,v.end());

  for (iterator i=L.begin(),j=R.begin(),k=v.begin();k!=v.end();k++) {
    if (fc((void*)i,(void*)j)) *k=*i;
    else *k=*j;
    if (i==L.end()) {copy(j,k,v.end());break;}
    if (j==R.end()) {copy(i,k,v.end());break;}
  }
}

template<typename T>
void Sort<T>::QuickSort(vector<T> v,size_type p,size_type r,compare fc) {
  if (p<r-1) {
    size_type q=Partition(v,p,r,fc);
    QuickSort(v,p,q,fc);
    QuickSort(v,q+1,r,fc);
  }
}

template<typename T>
typename Sort<T>::size_type Sort<T>::Partition(vector<T> v,size_type p,size_type r,compare fc) {
  size_type i=p-1, j=p;
  T pivot=v[r-1];
  while (j<r-1)
    if (fc((void*)&v[j],(void*)&pivot))
      if (++i!=j)
        swap(&v[i],&v[j]);
  swap(&v[i+1],&v[r-1]);
  return i+1;
}

template<typename T> class SortSeq {
public:
  typedef typename vector<T>::size_type size_type;
  typedef typename vector<T>::iterator  iterator;
  typedef int (*compare)(void*,void*);

  SortSeq(vector<T> vec):v(vec){}
  SortSeq(const SortSeq& s):v(s.v){}
  SortSeq& operator=(SortSeq& s) {v=s.v;return *this;}
  const SortSeq& operator=(const SortSeq& s) {v=s.v;return *this;}
  ~SortSeq() {}

  // Order Statistic
  size_type OrderStat(vector<T>,size_type,size_type,compare);
  size_type MergeStat(vector<T>,size_type,size_type,size_type,compare);
  // Permutation
  void Shuffle(void);
private:
  void swap(T&r,T&s) {T t=r;r=s;s=t;}
  vector<T> v;
  // Number of Reversed Pairs
  size_type rp;
};

template<typename T>
typename SortSeq<T>::size_type SortSeq<T>::OrderStat(vector<T> v,size_type p,size_type r,compare fc) {
  if (p<r-1) {
    size_type q=(r-p)/2+p;
    size_type r1=OrderStat(v,p,q,fc);
    size_type r2=OrderStat(v,q,r,fc);
    size_type r3=MergeStat(v,p,q,r,fc);
    return r1+r2+r3;
  }
}

template<typename T>
typename SortSeq<T>::size_type SortSeq<T>::MergeStat(vector<T> v,size_type p,size_type q,size_type r,compare fc) {
  iterator i1=v.begin();
  iterator i2=v.begin()+(q-p);
  size_type rp=0,ri=0;

  vector<T> L(i1,i2);
  vector<T> R(i2,v.end());

  for (iterator i=L.begin(),j=R.begin(),k=v.begin();k!=v.end();k++) {
    if (fc((void*)i,(void*)j)) {*k=*i;ri++;}
    else {*k=*j;rp+=q-p-ri;}
    if (i==L.end()) {copy(j,k,v.end());break;}
    if (j==R.end()) {copy(i,k,v.end());rp+=q-p-ri;break;}
  }
  return rp;
}

template<typename T> void SortSeq<T>::Shuffle(void) {
  ::srand(::time(NULL));
  uint n=v.size();
  for (uint i=0;i<n;i++) {
    uint r=::rand()%(n-i)+i;
    swap(&v[i],&v[r]);
  }
}

