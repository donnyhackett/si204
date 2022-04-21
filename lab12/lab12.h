#ifndef LAB12HEADER
#define LAB12HEADER
#include <iostream>
using namespace std;

struct word{
    string data;
    int value;
    word *next;
    word *before;
};


void addFront(string, int, word*&);
int length(word*);
string printList(word*);
void move(word*, char&);
string printBefore(word*);
string printData(word*);
int returnScore(word*);
void removeNode(word*&);

#endif