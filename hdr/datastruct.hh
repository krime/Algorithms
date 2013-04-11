#ifndef _DATASTRUCT_H
#define _DATASTRUCT_H

#include <iostream>
#include <vector>

using namespace std;
/*
  Comman Operations on Dynamic Sets
  Search(S,k)
  Insert(S,x)
  Delete(S,x)
  Minimum(S)
  Maximum(S)
  Successor(S,x)
  Predecessor(S,x)
 */

template <typename T>
class List {
private:
  struct Node {
    T k;
    Node*next;

    Node():next(NULL) {}
    Node(T key):k(key),next(NULL) {}
    //Node(const T&n):k(n.k),next(NULL) {}
    Node& operator=(Node&n) {k=n.k;next=NULL;return *this;}
    const Node& operator=(const Node&n) {k=n.k;next=NULL;return *this;}
    //~Node() {delete next;}
  };
  Node*head;
public:
  List():head(NULL) {}
  List(T e):head(new Node(e)) {head->next=NULL;}
  List(const List&l);
  List& operator=(List&l);
  const List& operator=(const List&l);
  ~List();

  List& Insert(T x);

  template<typename NT> friend
  ostream& operator<<(ostream&sout,const List<NT>&l) {
    Node*t=l.head;
    while (t!=NULL) {
      sout<<t->k<<' ';
      t=t->next;
    }
    return sout;
  }
};

template<typename T>
List<T>::List(const List&l) {
  Node*t=l.head;
  Node*c=head;
  while (t->next!=NULL) {
    c->next=new Node(*t.next);
    t=t->next;
  }
}

template<typename T>
List<T>& List<T>::operator=(List&l) {
  head->next=l.head->next;
  return *this;
}

template<typename T>
const List<T>& List<T>::operator=(const List&l) {
  head->next=l.head->next;
  return *this;
}

template<typename T>
List<T>::~List() {
  while (head!=NULL) {
    Node*t=head;
    head=head->next;
    delete t;
  }
}

template<typename T>
List<T>& List<T>::Insert(T x) {
  Node*t=new Node(x);
  if (head!=NULL) t->next=head;
  head=t;
  return *this;
}

int main(void) {
  List<int> l;
  for (int i=0;i<100;i++) l.Insert(i);
  cout<<l<<endl;
  return 0;
}
#endif//_DATASTRUCT_H
