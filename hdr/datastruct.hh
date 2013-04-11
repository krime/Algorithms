#ifndef _DATASTRUCT_H
#define _DATASTRUCT_H

#include <iostream>
#include <vector>

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
    Node(T key):k(key) {}
    Node(const T&n):k(n.k),next(NULL) {}
    Node& operator=(Node&n) {k=n.k;next=NULL;return *this;}
    const Node& operator=(const Node&n) {k=n.k;next=NULL;return *this;}
    ~Node() {delete next;}
  };
  Node*head;
public:
  List():head(NULL) {}
  List(T e):head(new Node(e)) {head->next=NULL;}
  List(const List&l) {
    Node*t=l.head;
    Node*c=head;
    while (t->next!=NULL) {
      c->next=new Node(*t.next);
      t=t->next;
    }
  }
  List& operator=(List&l) {
    head->next=l.head->next;
    return *this;
  }
  const List& operator=(const List&l) {
    head->next=l.head->next;
    return *this;
  }
  ~List() {
    Node*t=head;
    while (t->next!=NULL) {
      head=t->next;
      delete t;
    }
  }
};
#endif//_DATASTRUCT_H
