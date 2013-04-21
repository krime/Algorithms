#ifndef _DATASTRUCT_H
#define _DATASTRUCT_H

#include <iostream>
#include <vector>

using namespace std;

/**
   @brief This class implements the containing unit that <b>Double Linked List</b> use
 
   @details This class implements the containing unit that <b>Double Linked List</b> use
   @author Krime Lam <krimelam@gmail.com>
   @version 1.0
   @date Mon Apr 15 03:43:09 UTC 2013
   @class Node datastruct.hh "datastruct.hh"
 */
/*
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

  Node& operator*(void) {return *this;}
  Node& operator++(void) {this=this->next;return *this;}
  Node& operator++(int) {Node*t=this;this=this->next;return *t;}
  Node& operator--(void) {this=this->prev;return *this;}
  Node& operator--(int) {Node*t=this;this=this->prev;return *t;}

  Node* ptr_next(void) {return next;}
  Node* ptr_prev(void) {return prev;}
};
*/
/**
 * @brief This class implements the <b>Double Linked List</b>
 * @details This class implements the <b>Double Linked List</b> with the following operations (Comman Operations on Dynamic Sets):
 *
 * - Search(S,k)
 * - Insert(S,x)
 * - Delete(S,x)
 * - Minimum(S)
 * - Maximum(S)
 * - Successor(S,x)
 * - Predecessor(S,x)
 *
 * @author Krime Lam <krimelam@gmail.com>
 * @version 1.0
 * @date Mon Apr 15 03:43:09 UTC 2013
 * 
 */

template <typename T>
class List {
protected:
  struct Node {
    T key;
    Node* next;
    Node(T k):key(k) {}
  };
private:
  Node *head;
  Node *tail;
public:
  List():head(NULL),tail(NULL) {}
  List(T e);
  List(const List&);
  List& operator=(List&);
  const List& operator=(const List&);
  ~List();

  Node<T>* Search(T);
  List& Insert(Node<T>*);
  List& Delete(Node<T>*);

  template<typename NT>
  friend ostream& operator<<(ostream&,const List<NT>&);
};

/**
 * @class List datastruct.hh "hdr/datastruct.hh"
 */
template<typename T>
List<T>::List(T e):head(new Node(e)),tail(new Node(e)) {
  head->next=
    tail->prev=
    head->prev=
    tail->next=NULL;
}

// clone
template<typename T>
List<T>::List(const List&l):head(l.head),tail(l.tail) {
  /*
    if (l.head==NULL) return;
  else head=tail=new Node<T>(*l.head);
  
  Node<T>*c=head;
  for (Node<T>*t=l.head->next;t!=NULL;t=t->next) {
    c->next=new Node<T>(*t);
    c->next->prev=c;
    c=c->next;
  }
  */
}

// concat
template<typename T>
List<T>& List<T>::operator=(List&l) {
  while (head!=NULL) {
    Node*t=head;
    head=head->next;
    delete[] t;
  }
  head=l.head;
  tail=l.tail;
  return *this;
}

template<typename T>
const List<T>& List<T>::operator=(const List&l) {
  while (head!=NULL) {
    Node*t=head;
    head=head->next;
    delete[] t;
  }
  head=l.head;
  tail=l.tail;
  return *this;
}

template<typename T>
List<T>::~List() {
  while (head!=NULL) {
    Node*t=head;
    head=head->next;
    delete[] t;
  }
}

template<typename T>
Node<T>* List<T>::Search(T k) {
  Node*t=head;
  while (t!=NULL) {
    if (t->k==k)
      break;
    t=t->next;
  }
  return t;
}

template<typename T>
List<T>& List<T>::Insert(T e) {
  Node*x=new Node(e);
  if (head!=NULL) {
    x->next=head;
    head->prev=x;
  }
  head=x;
  return *this;
}

template<typename T>
List<T>& List<T>::Delete(T e) {
  Node*x=new Node(e);
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
  Node*t=l.head;
  while (t!=NULL) {
    sout<<t->k<<' ';
    t=t->next;
  }
  return sout;
}

int main(void) {
  List<int> l;
  for (int i=0;i<100;i++)
    l.Insert(new Node<int>(i));
  l.Delete(l.Search(15));
  cout<<l<<endl;
  List<int> m(l);
  cout<<m<<endl;
  return 0;
}
#endif//_DATASTRUCT_H
