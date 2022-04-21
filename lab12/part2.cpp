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
    string word;
    int value;
    while(fin >> left >> word >> value >> right){
        addFront(word, value, w);
    }

    //Print length
    int len = length(w);
    cout << "count is " << len << endl;

    //Print file
    cout << printList(w);

    return 0;
}
