#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T> class SortSeq {
public:
  typedef typename vector<T>::size_type size_type;
  typedef typename vector<T>::iterator  iterator;
  typedef int (*compare)(void*,void*);

  SortSeq(void):v(NULL){}
  SortSeq(T arr[]):v(arr){}
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
    rp=r1+r2+r3;
    return rp;
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
  size_type n=v.size();
  for (size_type i=0;i<n;i++) {
    size_type r=::rand()%(n-i)+i;
    swap(&v[i],&v[r]);
  }
}

