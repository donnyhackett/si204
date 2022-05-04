#include "easycurses.h"
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "proj3.h"
using namespace std;

int main(){
    //seed random
    srand(time(0));

    string file;
    cout << "board file: ";
    cin >> file;
    ifstream fin(file);
    if(!(fin)){
        cout << "File '" << file << "' not found!" << endl;
        return 0;
    }

    int rows, cols;
    board b;
    b.goals = NULL;
    b.players = NULL;
    b.spawns = NULL;
    b.walls = NULL;
    readBoard(fin, rows, cols, b);

    // Initialize ncurses
    startCurses();

    printBoard(b);

    // Loop forever until user enters 'q'
    char c;
    int steps = 0;
    spawnStars(b);
    spawnKillers(b);
    do { 
        refreshWindow();
        c = inputChar();
        usleep(150000);
        eraseAll(b);
        playerCmd(b.players, c);
        if(steps == 0){
            firstStarCmd(b.stars);
            firstKillerCmd(b.killers);
        }
        else{
            starCmd(b.stars);
            killerCmd(b.killers, b);
        }
        edgeCheck(b);
        moveChars(b);
        drawAll(b);
        if(checkEnd(b)){ 
            break; 
        }
        steps++;
        if(c == 'y') break; // game exits with a 'y'
    } while (true);

    // Close ncurses
    endCurses();

    cout << "Player start: (" << b.players->startrow << "," << b.players->startcol << ")" << endl;
    cout << "Spawn spots:";
    printSpawnLocs(b.spawns);
    cout << "Player score: " << 500 - steps << endl;

    return 0;
}

