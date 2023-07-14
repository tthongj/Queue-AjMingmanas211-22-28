#ifndef node_h
#define node_h
#include <iostream>
using namespace std;

class Node {
private:
  int pricelist[3] = {100, 20, 50};
  char menu[3][30] = {"Ramen", "Somtum", "KFC"};
  int ord_number, qty;
  Node *nextPtr;

public:
  Node(int, int = 1);
  ~Node();
  int get_value();
  void set_next(Node *);
  Node *get_next();
  void print_menu();
};

typedef Node *NodePtr;

Node::Node(int o, int q) {
  ord_number = o;
  qty = q;
  nextPtr = NULL;
}

int Node::get_value() {
  int price = 0;

  if (ord_number >= 1 && ord_number <= 3) {
    price = pricelist[ord_number - 1] * qty;
    cout <<"Ordered "<<qty<<" "<< menu[ord_number - 1] << endl;
  } else {
    cout << "Wrong Order number." << endl;
  }

  return price;
}

Node *Node::get_next() {
  return nextPtr;
}

void Node::set_next(Node *t) {
  nextPtr = t;
}

Node::~Node() {
  // cout << "deleting " << ord_number << endl;
}

void Node::print_menu() {
  cout <<"Ordered "<<qty<<" "<< menu[ord_number - 1] << endl;
}

#endif