#ifndef _ALGOSORT_H
#define _ALGOSORT_H

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
#endif//_ALGOSORT_H
