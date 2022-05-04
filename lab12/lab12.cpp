#include <iostream>
#include "lab12.h"
using namespace std;

void addFront(string in, int value, word* &curr){
    word *temp = new word;
    if(curr != NULL){
        curr->before = temp;
    }
    temp->data = in;
    temp->value = value;
    temp->next = curr;
    curr = temp;
    curr->before = NULL;
}

void removeNode(word* &w){
    word* temp = w->;
    w-> = temp;
}

int length(word *w){
    if(w == NULL){
        return 0;
    }
    else{
        return 1 + length(w->next);
    }
}

string printList(word *w){
    if(w == NULL){
        return "\n";
    }
    else{
        return "(" + w->data + " " + to_string(w->value) + ")" + " " + printList(w->next);
    }
}

void move(word* w, char &input){
    cout << endl;
    if(w->before != NULL){
        cout << "Before is: " << printBefore(w->before) << endl;
    }
    else{
        cout << "Before is: " << endl;
    }
    cout << "Current is: " << "(" << w->data << " " << to_string(w->value) << ")" << endl;
    cout << "Number after is: " << to_string(length(w->next)) << endl;;
    cout << "[a]ccept or [r]eject: ";
    cin >> input;
}

string printBefore(word* w){
    if(w == NULL){
        return "";
    }
    return printBefore(w->before) + " " + w->data;
}

string printData(word *w){
    if(w == NULL){
        return "\n";
    }
    else{
        return w->data + " " + printData(w->next);
    }
}

int returnScore(word *w){
    if(w == NULL){
        return 0;
    }
    else{
        return w->value + returnScore(w->next);
    }
}