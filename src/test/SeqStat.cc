#include <iostream>
#include <vector>

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

template<typename T> class SortSeq {
public:
  typedef typename vector<T>::size_type size_type;
  typedef typename vector<T>::iterator  iterator;
  typedef int (*compare)(void*,void*);

  SortSeq(void):v(NULL){}
  SortSeq(T arr[],size_type n):v(arr,arr+n){}
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
  // Display
  void Display(void) {for (size_type i=0;i<v.size();i++)cout<<' '<<v[i];cout<<endl;}
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
  vector<T> L(v.begin()+p,v.begin()+q);
  vector<T> R(v.begin()+q,v.begin()+r);
  size_type rp=0;

  for (size_type i=0,j=0,k=p;k<r;k++) {
    if (fc((void*)&L[i],(void*)&R[j])<0) v[k]=L[i++];
    else {
      v[k]=R[j++];
      rp+=q-p-i;
    }
    if (i==q-p) {
      copy(L.begin()+j,v.begin()+j,v.begin()+q);
      break;
    }
    if (j==r-q) {
      copy(L.begin()+i,v.begin()+k,v.begin()+r);
      rp+=(r-q)*(q-i);
      break;
    }
  }
  return rp;
}

template<typename T> void SortSeq<T>::Shuffle(void) {
  ::srand(::time(NULL));
  size_type n=v.size();
  for (size_type i=0;i<n;i++) {
    size_type r=::rand()%(n-i)+i;
    swap(v[i],v[r]);
  }
}

int main(void) {
  unsigned int num[128]={0};
  for (unsigned int i=0;i<128;i++) num[i]=i;
  SortSeq<unsigned int> seq(num,128);
  seq.Display();
  seq.Shuffle();
  seq.Display();
}
