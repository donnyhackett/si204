#include <iostream>
#include <fstream>
#include "lab12.h"
using namespace std;

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
    char left, right;
    string words;
    int value;
    while(fin >> left >> words >> value >> right){
        addFront(words, value, w);
    }

    char input;
    word *temp = w;
    while(length(temp) != 0){
        move(temp, input);
        temp = temp->next;
    }
    
    cout << endl;
    cout << "List is: " << printData(w);
    cout << "Score is: " << returnScore(w) << endl;
    return 0;
}
