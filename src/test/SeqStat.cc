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
  typedef typename vector<T>::const_iterator const_iterator;
  typedef int (*compare)(void*,void*);

  SortSeq(void):v(NULL){}
  SortSeq(T arr[],size_type n):v(arr,arr+n){}
  SortSeq(vector<T> vec):v(vec){}
  SortSeq(const SortSeq& s):v(s.v){}
  SortSeq& operator=(SortSeq& s) {v=s.v;return *this;}
  const SortSeq& operator=(const SortSeq& s) {v=s.v;return *this;}
  ~SortSeq() {}

  // Order Statistic
  size_type OrderStat(compare);
  size_type OrderStat(size_type,size_type,compare);
  size_type MergeStat(size_type,size_type,size_type,compare);
  size_type ForceStat(compare);
  // Permutation
  void Shuffle(void);
  // Display
  template<typename Tt>
  friend ostream& operator<<(ostream&, const SortSeq<Tt>&);
private:
  void swap(T&r,T&s) {T t=r;r=s;s=t;}

  vector<T> v;
  // Number of Reversed Pairs
  size_type rp;
};

template<typename T>
typename SortSeq<T>::size_type SortSeq<T>::OrderStat(compare fc) {
  return OrderStat(0,v.size(),fc);
}

template<typename T>
typename SortSeq<T>::size_type SortSeq<T>::OrderStat(size_type p,size_type r,compare fc) {
  if (p<r-1) {
    size_type q=(r-p)/2+p;
    size_type r1=OrderStat(p,q,fc);
    size_type r2=OrderStat(q,r,fc);
    size_type r3=MergeStat(p,q,r,fc);
    rp=r1+r2+r3;
    return rp;
  }
  else return 0;
}

template<typename T>
typename SortSeq<T>::size_type SortSeq<T>::MergeStat(size_type p,size_type q,size_type r,compare fc) {
  vector<T> L(v.begin()+p,v.begin()+q);
  vector<T> R(v.begin()+q,v.begin()+r);
  size_type rp=0;

  for (size_type i=0,j=0,k=p;k<r;) {
    if (fc((void*)&L[i],(void*)&R[j])<0) v[k++]=L[i++];
    else {
      v[k++]=R[j++];
      rp+=q-p-i;
    }
    if (i==q-p) {
      copy(R.begin()+j,R.end(),v.begin()+k);
      break;
    }
    if (j==r-q) {
      copy(L.begin()+i,L.end(),v.begin()+k);
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

template<typename T> ostream& operator<<(ostream& sout, const SortSeq<T>& s) {
  for (typename SortSeq<T>::const_iterator it=s.v.begin();it<s.v.end();it++)
    sout<<' '<<*it;
  return sout;
}

template<typename T> typename SortSeq<T>::size_type SortSeq<T>::ForceStat(compare fc) {
  size_type r=0;
  for (size_type i=0;i<v.size();i++)
    for (size_type j=i+1;j<v.size();j++)
      if (fc((void*)&v[j],(void*)&v[i])<0)
        r++;
  return r;
}

int comp(void*a,void*b) {
  return *(int*)a-*(int*)b;
}

int main(void) {
  unsigned int num[128]={0};
  unsigned int n=sizeof(num)/sizeof(num[0]);
  for (unsigned int i=0;i<n;i++) num[i]=i;
  SortSeq<unsigned int> seq(num,n);
  seq.Shuffle();
  //cout<<seq<<endl;
  //SortSeq<unsigned int>::size_type r=seq.ForceStat(comp);
  SortSeq<unsigned int>::size_type r=seq.OrderStat(comp);
  cout<<r<<endl;
  cout<<128*127/2<<endl;
}
