#include <iostream>

using namespace std;

template <typename T>
class Bintree {
protected:
  struct Node {
    Node*lt;
    Node*rt;
    T key;
    Node(T k):key(k){}
  };
private:
  Node*root;
public:
  Bintree():root(NULL){}
  Bintree(T e);
  Bintree(const Bintree&);
  Bintree& operator=(Bintree&);
  const Bintree& operator=(const Bintree&);
  ~Bintree();
};

