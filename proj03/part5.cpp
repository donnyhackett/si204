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

    int deaths = 0;
    int scoretot = 0;

    string file, temp;
    int numstar, numkiller, points;
    board* b = new board;
    b->goals = NULL;
    b->players = NULL;
    b->spawns = NULL;
    b->walls = NULL;
    b->next = NULL;
    ifstream finstart("gameScript.txt");
    while(finstart >> file >> numstar >> numkiller >> temp >> temp >> points){
        ifstream fin(file);
        if(!(fin)){
            cout << "File '" << file << "' not found!" << endl;
            return 0;
        }
        int rows, cols;
        cerr << "ran" << endl;
        if(b->next-> == NULL){
            cerr << "first time" << endl;
            readBoard(fin, rows, cols, b);
            continue;
        }
        board* temp = b;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new board;
        temp->next->goals = NULL;
        temp->next->players = NULL;
        temp->next->spawns = NULL;
        temp->next->walls = NULL;
        temp->next->next = NULL;
        readBoard(fin, rows, cols, temp->next);
    }

    cerr << "num boards: " << lengthBoard(b) << endl;
    return 0;
    board* currentboard = b;
    // Initialize ncurses
    startCurses();
    bool passed = true;
    while(deaths < 3)
    {
        if(currentboard != NULL){    
            printBoard(currentboard);
            // Loop forever until user enters 'q'
            char c;
            int steps = 0;
            if(passed){        //creates linked lists
                spawnStars(currentboard);
                spawnKillers(currentboard);
            }
            do { 
                refreshWindow();
                c = inputChar();
                usleep(150000);
                eraseAll(currentboard);
                playerCmd(currentboard->players, c);
                if(steps == 0){
                    resetAll(currentboard);
                    firstStarCmd(currentboard->stars);
                    firstKillerCmd(currentboard->killers);
                }
                else{
                    starCmd(currentboard->stars);
                    killerCmd(currentboard->killers, currentboard);
                }
                edgeCheck(currentboard);
                moveChars(currentboard);
                drawAll(currentboard);
                if(checkEnd(currentboard, passed)){ 
                    break; 
                }
                steps++;
                if(c == 'y'){
                    deaths = 3; 
                    break;          // game exits with a 'y'
                } 
            } while (true);
            if(passed){
                scoretot += currentboard->points;
                currentboard = currentboard->next;
            }
            else{
                deaths++;
            }
            scoretot += 500 - steps;
        }
        else{
            deaths = 3;
            cout << "You Won!" << endl;
        }
        
    }
    // Close ncurses
    endCurses();

    cout << "Total score: " << scoretot << endl;

    return 0;
}

