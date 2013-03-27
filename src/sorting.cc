#include <iostream>
#include <vector>
#include <cctype>

#define uint unsigned int

using namespace std;
/*
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
  void swap(T,T);
public:
  static void InsertionSort(T[],uint,uint,compare);
  static void SelectionSort(T[],uint,uint,compare);
  static void    BubbleSort(T[],uint,uint,compare);
  static void     MergeSort(T[],uint,uint,compare);
  static void     QuickSort(T[],uint,uint,compare);
  static void      HeapSort(T[],uint,uint,compare);
};

template<typename T> class SortSeq {
public:
  SortSeq(vector<T> vec):v(vec){}
  SortSeq(const SortSeq& s):v(s.v){}
  SortSeq& operator=(SortSeq& s) {v=s.v;return *this;}
  const SortSeq& operator=(const SortSeq& s) {v=s.v;return *this;}
  ~SortSeq() {}

  // Order Statistic
  void OrderStat(uint&,uint&);
private:
  vector<T> v;
};
