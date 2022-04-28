#include "proj3.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

char** readBoard(ifstream& fin){
    int rows, cols, spawns;
    char temp;
    fin.get(rows);
    fin.get(temp);
    fin.get(cols);
    fin.get(spawns);
    char** board = new char*[rows];
    for(int i = 0; i < rows; i++){
        board[i] = new char[cols];
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            char curr;
            fin.get(curr);
            if(curr == '#' || curr == ' '){
                board[i][j] = curr;
            }
            else if(curr == 'Z'){
                
            }
        }
    }
}
