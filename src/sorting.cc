#include <iostream>
#include <vector>
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
  void swap(T&,T&);
  Sort(){}
  Sort(const Sort&){}
  Sort& operator=(Sort&){}
  const Sort& operator=(const Sort&){}
  ~Sort(){}
public:
  static void InsertionSort(T[],uint,uint,compare);
  static void SelectionSort(T[],uint,uint,compare);
  static void    BubbleSort(T[],uint,uint,compare);
  static void     MergeSort(T[],uint,uint,compare);
  static void     QuickSort(T[],uint,uint,compare);
  static void      HeapSort(T[],uint,uint,compare);
};

template<typename T> class SortSeq {
private:
  void swap(T&,T&);
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

template<typename T>
void SortSeq<T>::Permutation(void) {
  srand(time(NULL));
  uint r=rand();
}
