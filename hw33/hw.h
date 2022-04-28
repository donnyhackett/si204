#ifndef h
#define h
#include <iostream>
using namespace std;

/*****************************************
 ** Class def's and function prototypes
 *****************************************/
// Defines the nodes in our linked list
struct Node
{
  int data;
  Node* next;
};

void add2front(int val, Node* &LIST);

void add2front(int val, Node* &LIST)
{
  Node *temp = new Node;
  temp->data = val;
  temp->next = LIST;
  LIST = temp;
}
#endif