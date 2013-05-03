#include <iostream>

using namespace std;

class Bintree {
    private:
        class Node {
            Node*lt;
            Node*rt;
        };
    public:
        Node*root;
};

