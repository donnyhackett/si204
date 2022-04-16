#include "easycurses.h"
#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;

struct letter{
    int row, col;
    char c;
};

letter* readIn(int);
void drawAndRefresh(char, int, int);
void eraseAndRefresh(letter*, int);

int main() {

    int N;
    cin >> N;
    letter* letters = readIn(N);

    // Initialize ncurses
    startCurses();

    // Draw 4 digit characters to the terminal screen.
    for(int i = 0; i < N; i++){
        drawAndRefresh(letters[i].c, letters[i].row, letters[i].col);
    }
   
    //Erase Screen
    eraseAndRefresh(letters, N);

    // Loop forever until user enters 'q'
    char c;
    do { 
    c = inputChar();
    } while ( c!= 'q' );

    // Close ncurses
    endCurses();

    return 0;
    
}

letter* readIn(int N){
    char temp;
    letter* letters = new letter[N];
    for(int i = 0; i < N; i++){
        cin >> letters[i].c >> temp >> letters[i].row >> temp >> letters[i].col >> temp;
    }
    return letters;
}

void drawAndRefresh(char c, int row, int col){
    drawChar(c, row, col);
    refreshWindow();
    usleep(800000);
}

void eraseAndRefresh(letter* letters, int N){
    for(int i = 0; i < N; i++){
        letters[i].c = ' ';
        drawChar(letters[i].c, letters[i].row, letters[i].col);
    }
    refreshWindow();
}