#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <ctime>

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
private:
  typedef int (*compare)(T,T);
  void swap(T&r,T&s) {T t=r;r=s;s=t;}
  Sort(){}
  Sort(const Sort&){}
  Sort& operator=(Sort&){}
  const Sort& operator=(const Sort&){}
  ~Sort(){}
public:
  typedef vector<T>::size_type counter;
  static void InsertionSort(vector<T>,counter,counter,compare);
  static void SelectionSort(vector<T>,counter,counter,compare);
  static void    BubbleSort(vector<T>,counter,counter,compare);
  static void     MergeSort(vector<T>,counter,counter,compare);
  static void     QuickSort(vector<T>,counter,counter,compare);
  static void      HeapSort(vector<T>,counter,counter,compare);
};

template<typename T> void Sort<T>::InsertionSort(vector<T> v,counter p,counter r,compare fc) {
  for (counter i=p;i<r;i++) {
    T key(v[i]);
    counter j=i-1;
    while (j>=p && v[j]<key) A[j+1]=A[j--];
    A[j]=key;
  }
}

template<typename T> class SortSeq {
private:
  void swap(T&r,T&s) {T t=r;r=s;s=t;}
  vector<T> v;
public:
  SortSeq(vector<T> vec):v(vec){}
  SortSeq(const SortSeq& s):v(s.v){}
  SortSeq& operator=(SortSeq& s) {v=s.v;return *this;}
  const SortSeq& operator=(const SortSeq& s) {v=s.v;return *this;}
  ~SortSeq() {}

  // Order Statistic
  void OrderStat(uint&,uint&);
  // Permutation
  void Permutation(void);
};

template<typename T> void OrderStat(uint& reverse, uint& ordered) {
  
}

template<typename T> void SortSeq<T>::Permutation(void) {
  ::srand(::time(NULL));
  uint n=v.size();
  for (uint i=0;i<n;i++) {
    uint r=::rand()%(n-i)+i;
    swap(&v[i],&v[r]);
  }
}
