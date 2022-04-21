#include <iostream>
#include <fstream>
using namespace std;


struct word{
    string data;
    word *next;
};

void addFront(string, word*&);
int length(word*);
string printList(word*);

int main(){
    //get input file name
    cout << "Input file is: ";
    string file;
    cin >> file;

    //build ifstream
    ifstream fin(file);
    if(!fin){
        cout << "Error! File '" << file << "' not found!" << endl;
        return 0;
    }

    //Create list
    word *w = NULL;
    while(fin >> file){
        addFront(file, w);
    }

    //Print length
    int len = length(w);
    cout << "Count is " << len << endl;

    //Print file
    cout << printList(w);

    return 0;
}

void addFront(string in, word* &curr){
    word *temp = new word;
    temp->data = in;
    temp->next = curr;
    curr = temp;
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
        return w->data + " " + printList(w->next);
    }
}