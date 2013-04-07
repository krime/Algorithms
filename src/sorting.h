#ifndef _ALGOSORT_H
#define _ALGOSORT_H

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

class Sort {
public:
  typedef unsigned long size_type;
  typedef int (*compare)(void*,void*);

  template<typename T>
  static void InsertionSort(vector<T>&,size_type,size_type,compare);
  template<typename T>
  static void SelectionSort(vector<T>&,size_type,size_type,compare);
  template<typename T>
  static void    BubbleSort(vector<T>&,size_type,size_type,compare);
  template<typename T>
  static void     MergeSort(vector<T>&,size_type,size_type,compare);
  template<typename T>
  static void     QuickSort(vector<T>&,size_type,size_type,compare);
  template<typename T>
  static void      HeapSort(vector<T>&,size_type,size_type,compare);

  template<typename T>
  static void InsertionSort(vector<T>&v,compare fc) {InsertionSort(v,0,v.size(),fc);}
  template<typename T>
  static void SelectionSort(vector<T>&v,compare fc) {SelectionSort(v,0,v.size(),fc);}
  template<typename T>
  static void    BubbleSort(vector<T>&v,compare fc) {   BubbleSort(v,0,v.size(),fc);}
  template<typename T>
  static void     MergeSort(vector<T>&v,compare fc) {    MergeSort(v,0,v.size(),fc);}
  template<typename T>
  static void     QuickSort(vector<T>&v,compare fc) {    QuickSort(v,0,v.size(),fc);}
  template<typename T>
  static void      HeapSort(vector<T>&v,compare fc) {     HeapSort(v,0,v.size(),fc);}

  template<typename T>
  static void Merge(vector<T>&,size_type,size_type,size_type,compare);
  template<typename T>
  static size_type Partition(vector<T>&,size_type,size_type,compare);
  template<typename T>
  static void Heapify(vector<T>&,size_type,size_type,size_type,compare);

private:
  Sort(){}
  Sort(const Sort&){}
  Sort& operator=(Sort&){}
  const Sort& operator=(const Sort&){}
  ~Sort(){}

  template<typename T>
  static void swap(T&r,T&s) {T t=r;r=s;s=t;}
  // Number of Reversed Pairs
  size_type rp;
};
#endif//_ALGOSORT_H
