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

    /*
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
    */
    cerr << "rows: " << rows << endl;
    cerr << "cols: " << cols << endl;
    cerr << "goal length: " << lengthGoal(b.goals) << endl;
    cerr << "player length: " << lengthPlayer(b.players) << endl;
    cerr << "spawn length: " << lengthSpawn(b.spawns) << endl;
    cerr << "wall length: " << lengthWall(b.walls) << endl;

    // Loop forever until user enters 'q'
    char c;
    do { 
        usleep(150000);
        
        c = inputChar();
        if(c == 'y') break; // game exits with a 'y'
    } while (true);

    // Close ncurses
    endCurses();

    cout << "Player start: (" << b.players->row << "," << b.players->col << ")" << endl;
    cout << "Spawn spots:";
    printSpawnLocs(b.spawns);

    return 0;
}

