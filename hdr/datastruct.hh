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
class Node {
public:
  T k;
  Node*next;
  Node*prev;
public:
  // Copy Constructors
  Node():next(NULL),prev(NULL) {}
  Node(const T key):k(key),next(NULL),prev(NULL) {}
  Node& operator=(Node&n) {k=n.k;next=NULL;prev=NULL;return *this;}
  const Node& operator=(const Node&n) {k=n.k;next=NULL;prev=NULL;return *this;}
  ~Node() {}

  T& operator*(void) {return k;}
  Node& operator++(void) {this=this->next;return *this;}
  Node& operator++(int) {Node*t=this;this=this->next;return *t;}
  Node& operator--(void) {this=this->prev;return *this;}
  Node& operator--(int) {Node*t=this;this=this->prev;return *t;}
};

template <typename T>
class List {
private:
  Node<T>*head;
public:
  List():head(NULL) {}
  List(T e):head(new Node<T>(e)) {head->next=NULL;head->prev=NULL;}
  List(const List&);
  List& operator=(List&);
  const List& operator=(const List&);
  ~List();

  Node<T>* Search(T);
  List& Insert(Node<T>*);
  List& Delete(Node<T>*);

  template<typename NT> friend
  ostream& operator<<(ostream&,const List<NT>&);
};

template<typename T>
List<T>::List(const List&l) {
  Node<T>*t=l.head;
  Node<T>*c=head;
  while (t->next!=NULL) {
    c->next=new Node<T>(*t.next);
    c->next->prev=&c;
    t=t->next;
  }
}

template<typename T>
List<T>& List<T>::operator=(List&l) {
  head->next=l.head->next;
  l.head->prev=head;
  return *this;
}

template<typename T>
const List<T>& List<T>::operator=(const List&l) {
  head->next=l.head->next;
  l.head->prev=head;
  return *this;
}

template<typename T>
List<T>::~List() {
  while (head!=NULL) {
    Node<T>*t=head;
    head=head->next;
    delete t;
  }
}

template<typename T>
Node<T>* List<T>::Search(T k) {
  Node<T>*t=head;
  while (t!=NULL) {
    if (t->k==k)
      break;
    t=t->next;
  }
  return t;
}

template<typename T>
List<T>& List<T>::Insert(Node<T>*x) {
  if (head!=NULL) {
    x->next=head;
    head->prev=x;
  }
  head=x;
  return *this;
}

template<typename T>
List<T>& List<T>::Delete(Node<T>*x) {
  if (x==head) {
    head=x->next;
    head->prev=NULL;
    delete x;
  } else if (x->next==NULL) {
    x->prev->next=NULL;
    delete x;
  } else {
    x->prev->next=x->next;
    x->next->prev=x->prev;
    delete x;
  }

  return *this;
}

template<typename T>
ostream& operator<<(ostream&sout,const List<T>&l)  {
  Node<T>*t=l.head;
  while (t!=NULL) {
    sout<<t->k<<' ';
    t=t->next;
  }
  return sout;
}

int main(void) {
  List<int> l;
  for (int i=0;i<100;i++) {
    l.Insert(new Node<int>(i));
  }
  l.Delete(l.Search(15));
  cout<<l<<endl;
  return 0;
}
#endif//_DATASTRUCT_H
