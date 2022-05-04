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
    board* curr = b;
    ifstream finstart("gameScript.txt");
    while(finstart >> file >> numstar >> numkiller >> temp >> temp >> points){
        ifstream fin(file);
        if(!(fin)){
            cout << "File '" << file << "' not found!" << endl;
            return 0;
        }
        board* temp = new board;
        int rows, cols;
        temp->goals = NULL;
        temp->players = NULL;
        temp->spawns = NULL;
        temp->walls = NULL;
        temp->next = NULL;
        temp->numstar = numstar;
        temp->numkiller = numkiller;
        temp->points = points;
        readBoard(fin, rows, cols, temp);
        curr->next = temp;
        curr = curr->next;
    }
    
    board* currentboard = curr;
    // Initialize ncurses
    startCurses();
    while(deaths < 3)
    {
        if(currentboard != NULL){    
            printBoard(currentboard);
            bool passed = false;
            // Loop forever until user enters 'q'
            char c;
            int steps = 0;
            if(!passed){        //creates linked lists
                spawnStars(currentboard);
                spawnKillers(currentboard);
            }
            cerr << endl;
            cerr << "after inside loop: " << endl;
            cerr << "goals: " << lengthGoal(currentboard->goals) << endl;
            cerr << "players: " << lengthPlayer(currentboard->players) << endl;
            cerr << "stars: " << lengthStar(currentboard->stars) << endl;
            cerr << "walls: " << lengthWall(currentboard->walls) << endl;
            cerr << endl;
            do { 
                refreshWindow();
                c = inputChar();
                usleep(150000);
                resetAll(currentboard);
                eraseAll(currentboard);
                playerCmd(currentboard->players, c);
                if(steps == 0){
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
                cerr << "got here" << endl;
                if(checkEnd(currentboard, passed)){ 
                    break; 
                }
                steps++;
                if(c == 'y'){
                    deaths = 4; 
                    break;          // game exits with a 'y'
                } 
                cerr << "got after check end" << endl;
            } while (true);
            if(passed){
                scoretot += currentboard->points;
                currentboard = currentboard->next;
            }
            scoretot += 500 - steps;
        }
        else{
            deaths = 4;
            cout << "You Won!" << endl;
        }
        
    }
    // Close ncurses
    endCurses();

    cout << "Total score: " << scoretot << endl;

    return 0;
}

