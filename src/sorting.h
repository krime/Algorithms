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
#endif//_ALGOSORT_H
