#include "easycurses.h"
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "proj3.h"
using namespace std;

int main(){
    string file;
    cout << "board file: ";
    cin >> file;
    ifstream fin(file);
    if(!(fin)){
        cout << "File '" << file << "' not found!" << endl;
        return 0;
    }
    char** board = readBoard(fin);


    // Initialize ncurses
    startCurses();

    // Draw 4 digit characters to the terminal screen.
    drawChar('A', 0, 0);
    refreshWindow();
    usleep(800000);

    drawChar('B', 20, 30);
    refreshWindow();
    usleep(800000);

    drawChar('C', 20, 31);
    refreshWindow();
    usleep(800000);

    drawChar('D', 15, 50);
    refreshWindow();

    // Loop forever until user enters 'q'
    char c;
    do { 
    c = inputChar();
    } while ( c!= 'q' );

    // Close ncurses
    endCurses();

    return 0;
}

