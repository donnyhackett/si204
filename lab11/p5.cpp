#include "easycurses.h"
#include <unistd.h>
#include <cstdlib>
#include <iostream>


using namespace std;

struct letter{
    int row = 0, col = 0;
    int xvel = 0, yvel = 0;
    char c = ' ';
};

letter* readIn(int);
letter* fillRand(int, int, int);
void drawAndRefresh(char, int, int);
void eraseAndRefresh(letter*, int);
void erase(letter*, int);
void moveChars(letter*, int);
void giveAllVelocity(letter*, int, int, int);
void giveVelocity(letter&, int, int);
void drawAll(letter*, int);
void drawAllAndRefresh(letter*, int);
void randDir(letter*, int);
int getYDir(string);
int getXDir(string);
string getDir(int, int);
void turnLeft(letter&);
void turnRight(letter&);
void turnBack(letter&);
bool atEdge(letter, int, int);
void edgeCheck(letter*, int, int, int);
int rand();
int ctime();
void getWindowDimensions(int& row, int& col);

int main() {
    //seed random
    srand(time(0));

    //read in letters
    int N;
    cin >> N;

    // Initialize ncurses
    startCurses();

    //get height and width
    int height, width;
    getWindowDimensions(height, width);

    letter* letters = fillRand(N, height, width);
    
    //give all velocity of 1 to the right
    giveAllVelocity(letters, N, 1, 0);

    // Loop forever until user enters 'q'
    char c;
    do { 
        refreshWindow(); // These two lines correspond to flipping to 
        usleep(80000);  // the next frame in the animation.
        c = inputChar();
        erase(letters, N);
        randDir(letters, N);
        if(c == 'a'){
            letters[0].xvel = -1;
            letters[0].yvel = 0;
        }
        if(c == 'w'){
            letters[0].xvel = 0;
            letters[0].yvel = -1;
        }
        if(c == 's'){
            letters[0].xvel = 0;
            letters[0].yvel = 1;
        }
        if(c == 'd'){
            letters[0].xvel = 1;
            letters[0].yvel = 0;
        }
        edgeCheck(letters, N, height, width);
        moveChars(letters, N);
        drawAll(letters, N);
        //cerr << "xvel: " << letters[0].xvel << "yvel: " << letters[0].yvel <<  endl;
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

void drawAll(letter* letters, int N){
    for(int i = 0; i < N; i++){
        drawChar(letters[i].c, letters[i].row, letters[i].col);
    }
}

void drawAllAndRefresh(letter* letters, int N){
    for(int i = 0; i < N; i++){
        drawChar(letters[i].c, letters[i].row, letters[i].col);
    }
    refreshWindow();
}

void erase(letter* letters, int N){
    char temp;
    for(int i = 0; i < N; i++){
        temp = letters[i].c;
        letters[i].c = ' ';
        drawChar(letters[i].c, letters[i].row, letters[i].col);
        letters[i].c = temp;
    }
}

void eraseAndRefresh(letter* letters, int N){
    char temp;
    for(int i = 0; i < N; i++){
        temp = letters[i].c;
        letters[i].c = ' ';
        drawChar(letters[i].c, letters[i].row, letters[i].col);
        letters[i].c = temp;
    }
    refreshWindow();
}

void moveChars(letter* letters, int N){
    for(int i = 0; i < N; i++){
        letters[i].row += letters[i].yvel;
        letters[i].col += letters[i].xvel;
    }
}

void giveVelocity(letter& let, int xvel, int yvel)
{
    let.xvel = xvel;
    let.yvel = yvel;
}

void giveAllVelocity(letter* letters, int N, int xvel, int yvel){
    for(int i = 0; i < N; i++){
        letters[i].xvel = xvel;
        letters[i].yvel = yvel;
    }
}

void randDir(letter* letters, int N){
    for(int i = 1; i < N; i++){
        if((rand() % 10) == 0){ // 1 in 10 of changing direction
            if((rand() % 2) == 0){// 1 in 2 of being left/right
                turnLeft(letters[i]);
            }
            else{
                turnRight(letters[i]);
            }
        }
        //cerr << "testroll: " << rand() % 10 << " dir: " << getDir(letters[i].xvel, letters[i].yvel) << endl;
    }
}

string getDir(int xvel, int yvel){
    if(xvel > 0)
        return "East";
    else if( xvel < 0)
        return "West";
    else if(yvel > 0)
        return "South";
    else
        return "North";
}

int getXDir(string dir){
    if(dir == "North" || dir == "South")
        return 0;
    else if(dir == "East")
        return 1;
    else
        return -1;
}

int getYDir(string dir){
    if(dir == "East" || dir == "West")
        return 0;
    else if(dir == "South")
        return 1;
    else
        return -1;
}

void turnLeft(letter& let){
    if(getDir(let.xvel, let.yvel) == "North"){
        let.yvel = 0;
        let.xvel = -1;
        //cerr << "Turned West" << endl;
    }
    else if(getDir(let.xvel, let.yvel) == "South"){
        let.yvel = 0;
        let.xvel = 1;
        //cerr << "Turned East" << endl;
    }
    else if(getDir(let.xvel, let.yvel) == "East"){
        let.yvel = -1;
        let.xvel = 0;
        //cerr << "Turned North" << endl;
    }
    else{
        let.yvel = 1;
        let.xvel = 0;
        //cerr << "Turned South" << endl;
    }
    //cerr << "Turned left" << endl;
}

void turnRight(letter& let){
    if(getDir(let.xvel, let.yvel) == "North"){
        let.yvel = 0;
        let.xvel = 1;
    }
    else if(getDir(let.xvel, let.yvel) == "South"){
        let.yvel = 0;
        let.xvel = -1;
    }
    else if(getDir(let.xvel, let.yvel) == "East"){
        let.yvel = 1;
        let.xvel = 0;
    }
    else{
        let.yvel = -1;
        let.xvel = 0;
    }
    //cerr << "Turned right" << endl;
}

void turnBack(letter& let){
    if(getDir(let.xvel, let.yvel) == "North"){
        let.yvel = 1;
        let.xvel = 0;
    }
    else if(getDir(let.xvel, let.yvel) == "South"){
        let.yvel = -1;
        let.xvel = 0;
    }
    else if(getDir(let.xvel, let.yvel) == "East"){
        let.yvel = 0;
        let.xvel = -1;
    }
    else{
        let.yvel = 0;
        let.xvel = 1;
    }
}

bool atEdge(letter let, int height, int width){
    if(((let.row + let.yvel) >= height) || ((let.col + let.xvel) >= width)){
        return true;
    }
    else if(((let.row + let.yvel) <= 0) || ((let.col + let.xvel) <= 0)){
        return true;
    }
    return false;
}

void edgeCheck(letter* letters, int N, int height, int width){
    for(int i = 1; i < N; i++){
        if(atEdge(letters[i], height, width)){
            turnBack(letters[i]);
        }
    }
}

letter* fillRand(int N, int height, int width){
    letter* letters = new letter[N];
    for(int i = 0; i < N; i++){
        letters[i].c = 'x';
        letters[i].col = (rand() % width);
        letters[i].row = (rand() & height);
    }
    return letters;
}
