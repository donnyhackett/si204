#include <iostream>
#include "hw.h"
using namespace std;

void add2front(int val, Node* &LIST)
{
  Node *temp = new Node;
  temp->data = val;
  temp->next = LIST;
  LIST = temp;
}