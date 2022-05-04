#include "proj3.h"
#include "easycurses.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

void readBoard(ifstream &fin, int &rows, int &cols, board* board){
    int spawns;
    char temp;
    fin >> rows >> temp >> cols >> spawns;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            char curr;
            curr = fin.get();
            if(curr == '\n'){
                if(fin){
                    curr = fin.get();
                } 
            }
            if(curr == '#'){
                addBackWall(board->walls, i, j, curr);
            }
            else if(curr == 'Z'){
                addBackSpawn(board->spawns, i, j, curr);
            }
            else if(curr == 'X'){
                addBackGoal(board->goals, i, j, curr);
            }
            else if(curr == 'Y'){
                addBackPlayer(board->players, i, j, curr);
            }
        }
    }
}

void printBoard(board* board){
    printWalls(board->walls);
    //printSpawns(board.spawns);
    printGoals(board->goals);
    //printPlayers(board.players);
    refreshWindow();
}

void printWalls(wall* node){
    if(node == NULL){
        return;
    }
    else{
        drawChar(node->c, node->row, node->col);
        printWalls(node->next);
    }
}

void printSpawns(spawn* node){
    if(node == NULL){
        return;
    }
    else{
        drawChar(node->c, node->row, node->col);
        printSpawns(node->next);
    }
}

void printGoals(goal* node){
    if(node == NULL){
        return;
    }
    else{
        drawChar(node->c, node->row, node->col);
        printGoals(node->next);
    }
}

void printPlayers(player* node){
    if(node == NULL){
        return;
    }
    else{
        drawChar(node->c, node->row, node->col);
        printPlayers(node->next);
    }
}

void addBackWall(wall* &walls, int row, int col, char c){
    if(walls == NULL){
        walls = new wall;
        walls->col = col;
        walls->row = row;
        walls->c = c;
        walls->next = NULL;
        return;
    }
    wall* save = walls;
    wall* temp = walls;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new wall;
    temp->next->row = row;
    temp->next->col = col;
    temp->next->c = c;
    temp->next->next = NULL;
    walls = save;
}

int lengthWall(wall* w){
    if(w == NULL){
        return 0;
    }
    else{
        return 1 + lengthWall(w->next);
    }
}

int lengthBoard(board* w){
    if(w == NULL){
        return 0;
    }
    else{
        return 1 + lengthBoard(w->next);
    }
}

void addBackSpawn(spawn* &walls, int row, int col, char c){
    if(walls == NULL){
        walls = new spawn;
        walls->col = col;
        walls->row = row;
        walls->c = c;
        walls->next = NULL;
        return;
    }
    spawn* save = walls;
    spawn* temp = walls;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new spawn;
    temp->next->row = row;
    temp->next->col = col;
    temp->next->c = c;
    temp->next->next = NULL;
    walls = save;
}

int lengthSpawn(spawn* w){
    if(w == NULL){
        return 0;
    }
    else{
        return 1 + lengthSpawn(w->next);
    }
}

void addBackGoal(goal* &walls, int row, int col, char c){
    if(walls == NULL){
        walls = new goal;
        walls->col = col;
        walls->row = row;
        walls->c = c;
        walls->next = NULL;
        return;
    }
    goal* save = walls;
    goal* temp = walls;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new goal;
    temp->next->row = row;
    temp->next->col = col;
    temp->next->c = c;
    temp->next->next = NULL;
    walls = save;
}

int lengthGoal(goal* w){
    if(w == NULL){
        return 0;
    }
    else{
        return 1 + lengthGoal(w->next);
    }
}

void addBackPlayer(player* &walls, int row, int col, char c){
    if(walls == NULL){
        walls = new player;
        walls->col = col;
        walls->row = row;
        walls->c = 'Y';
        walls->next = NULL;
        walls->startcol = col;
        walls->startrow = row;
        return;
    }
    player* save = walls;
    player* temp = walls;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new player;
    temp->next->row = row;
    temp->next->col = col;
    temp->next->c = 'Y';
    temp->next->next = NULL;
    temp->next->startcol = col;
    temp->next->startrow = row;
    walls = save;
}

void addBackStar(star* &walls, int row, int col, char c){
    if(walls == NULL){
        walls = new star;
        walls->col = col;
        walls->row = row;
        walls->c = c;
        walls->next = NULL;
        walls->startcol = col;
        walls->startrow = row;
        walls->moving = true;
        return;
    }
    star* save = walls;
    star* temp = walls;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new star;
    temp->next->row = row;
    temp->next->col = col;
    temp->next->c = c;
    temp->next->next = NULL;
    temp->next->startcol = col;
    temp->next->startrow = row;
    temp->next->moving = true;
    walls = save;
}

void addBackKiller(killer* &walls, int row, int col, char c){
    if(walls == NULL){
        walls = new killer;
        walls->col = col;
        walls->row = row;
        walls->c = c;
        walls->next = NULL;
        walls->startcol = col;
        walls->startrow = row;
        walls->moving = true;
        return;
    }
    killer* save = walls;
    killer* temp = walls;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new killer;
    temp->next->row = row;
    temp->next->col = col;
    temp->next->c = c;
    temp->next->next = NULL;
    temp->next->startcol = col;
    temp->next->startrow = row;
    temp->next->moving = true;
    walls = save;
}

int lengthStar(star* w){
    if(w == NULL){
        return 0;
    }
    else{
        return 1 + lengthStar(w->next);
    }
}

int lengthPlayer(player* w){
    if(w == NULL){
        return 0;
    }
    else{
        return 1 + lengthPlayer(w->next);
    }
}

void printSpawnLocs(spawn* s){
    if(s == NULL){
        cout << endl;
    }
    else{
        cout << " (" << s->row << "," << s->col << ")";
        printSpawnLocs(s->next);
    }
}

void turnBackPlayer(player* p, board* b){
    if((p->dir) == 'N'){
        p->dir = 'S';
        if(atEdge(b->walls, futureRowPlayer(p), futureColPlayer(p))){
            p->dir = 'N';
            p->moving = false;
        }
    }
    else if((p->dir) == 'S'){
        p->dir = 'N';
        if(atEdge(b->walls, futureRowPlayer(p), futureColPlayer(p))){
            p->dir = 'S';
            p->moving = false;
        }
    }
    else if((p->dir) == 'E'){
        p->dir = 'W';
        if(atEdge(b->walls, futureRowPlayer(p), futureColPlayer(p))){
            p->dir = 'E';
            p->moving = false;
        }
    }
    else{
        p->dir = 'E';
        if(atEdge(b->walls, futureRowPlayer(p), futureColPlayer(p))){
            p->dir = 'W';
            p->moving = false;
        }
    }
}

void turnBackStar(star* p, board* b){
    if((p->dir) == 'N'){
        p->dir = 'S';
        if(atEdge(b->walls, futureRowStar(p), futureColStar(p))){
            p->dir = 'N';
            p->moving = false;
        }
    }
    else if((p->dir) == 'S'){
        p->dir = 'N';
        if(atEdge(b->walls, futureRowStar(p), futureColStar(p))){
            p->dir = 'S';
            p->moving = false;
        }
    }
    else if((p->dir) == 'E'){
        p->dir = 'W';
        if(atEdge(b->walls, futureRowStar(p), futureColStar(p))){
            p->dir = 'E';
            p->moving = false;
        }
    }
    else{
        p->dir = 'E';
        if(atEdge(b->walls, futureRowStar(p), futureColStar(p))){
            p->dir = 'W';
            p->moving = false;
        }
    }
}

void turnBackKiller(killer* p, board* b){
    if((p->dir) == 'N'){
        p->dir = 'S';
        if(atEdge(b->walls, futureRowKiller(p), futureColKiller(p))){
            p->dir = 'N';
            p->moving = false;
        }
    }
    else if((p->dir) == 'S'){
        p->dir = 'N';
        if(atEdge(b->walls, futureRowKiller(p), futureColKiller(p))){
            p->dir = 'S';
            p->moving = false;
        }
    }
    else if((p->dir) == 'E'){
        p->dir = 'W';
        if(atEdge(b->walls, futureRowKiller(p), futureColKiller(p))){
            p->dir = 'E';
            p->moving = false;
        }
    }
    else{
        p->dir = 'E';
        if(atEdge(b->walls, futureRowKiller(p), futureColKiller(p))){
            p->dir = 'W';
            p->moving = false;
        }
    }
}

bool atEdge(wall* walls, int row, int col){
    if(walls == NULL){
        return false;
    }
    else if(walls->row == row && walls->col == col){
        return true;
    }
    else{
        return atEdge(walls->next, row, col);
    }
}

void edgeCheck(board* b){
    player* temp = b->players;
    while(temp != NULL){
        if(atEdge(b->walls, futureRowPlayer(temp), futureColPlayer(temp)) == true){
            if(temp->moving == true){
                turnBackPlayer(temp, b);
            }  
        }
        temp = temp->next;
    }
    star* s = b->stars;
    while(s != NULL){
        if(atEdge(b->walls, futureRowStar(s), futureColStar(s)) == true){
            if(s->moving == true){
                turnBackStar(s, b);
            }  
        }
        s = s->next;
    }
    killer* k = b->killers;
    while(k != NULL){
        if(atEdge(b->walls, futureRowKiller(k), futureColKiller(k)) == true){
            if(k->moving == true){
                turnBackKiller(k, b);
            }  
        }
        k = k->next;
    }
}

void moveChars(board* b){
    updateOldsPlayer(b->players);
    updateOldsStar(b->stars);
    updateOldsKiller(b->killers);
    movePlayer(b->players);
    moveStars(b->stars);
    moveKillers(b->killers);
}

void movePlayer(player* p){
    if(p == NULL){
        return;
    }
    if(p->moving){
        if(p->dir == 'N'){
            p->row = p->row - 1;
        }
        else if(p->dir == 'S'){
            p->row = p->row + 1;
        }
        else if(p->dir == 'E'){
            p->col = p->col + 1;
        }
        else if(p->dir == 'W'){
            p->col = p->col - 1;
        }
    }
    movePlayer(p->next);
}

void moveStars(star* p){
    if(p == NULL){
        return;
    }
    if(p->moving){
        if(p->dir == 'N'){
            p->row = p->row - 1;
        }
        else if(p->dir == 'S'){
            p->row = p->row + 1;
        }
        else if(p->dir == 'E'){
            p->col = p->col + 1;
        }
        else if(p->dir == 'W'){
            p->col = p->col - 1;
        }
    }
    moveStars(p->next);
}

void moveKillers(killer* p){
    if(p == NULL){
        return;
    }
    if(p->moving){
        if(p->dir == 'N'){
            p->row = p->row - 1;
        }
        else if(p->dir == 'S'){
            p->row = p->row + 1;
        }
        else if(p->dir == 'E'){
            p->col = p->col + 1;
        }
        else if(p->dir == 'W'){
            p->col = p->col - 1;
        }
    }
    moveKillers(p->next);
}

int futureRowPlayer(player* p){
    if(p->dir == 'N'){
            return p->row - 1;
    }
    else if(p->dir == 'S'){
        return p->row + 1;
    }
    else if(p->dir == 'E'){
        return p->row;
    }
    else{
        return p->row;
    }
}

int futureColPlayer(player* p){
    if(p->dir == 'N'){
        return p->col;
    }
    else if(p->dir == 'S'){
        return p->col;
    }
    else if(p->dir == 'E'){
        return p->col + 1;
    }
    else{
        return p->col - 1;
    }
}

int futureRowStar(star* p){
    if(p->dir == 'N'){
            return p->row - 1;
    }
    else if(p->dir == 'S'){
        return p->row + 1;
    }
    else if(p->dir == 'E'){
        return p->row;
    }
    else{
        return p->row;
    }
}

int futureColStar(star* p){
    if(p->dir == 'N'){
        return p->col;
    }
    else if(p->dir == 'S'){
        return p->col;
    }
    else if(p->dir == 'E'){
        return p->col + 1;
    }
    else{
        return p->col - 1;
    }
}

int futureRowKiller(killer* p){
    if(p->dir == 'N'){
            return p->row - 1;
    }
    else if(p->dir == 'S'){
        return p->row + 1;
    }
    else if(p->dir == 'E'){
        return p->row;
    }
    else{
        return p->row;
    }
}

int futureColKiller(killer* p){
    if(p->dir == 'N'){
        return p->col;
    }
    else if(p->dir == 'S'){
        return p->col;
    }
    else if(p->dir == 'E'){
        return p->col + 1;
    }
    else{
        return p->col - 1;
    }
}

void playerCmd(player* p, char cmd){
    if(cmd == 'r'){
        p->moving = false;
    }
    else if(cmd == 'a'){
        p->dir = 'W';
        p->moving = true;
    }
    else if(cmd == 's'){
        p->dir = 'S';
        p->moving = true;
    }
    else if(cmd == 'd'){
        p->dir = 'E';
        p->moving = true;
    }
    else if(cmd == 'w'){
        p->dir = 'N';
        p->moving = true;
    }
}

void starCmd(star* s){
    star* p = s;
    while(p != NULL){
        char cmd = getStarCmd(p->dir);
        if(cmd == 'r'){
            p->moving = false;
        }
        else if(cmd == 'W'){
            p->dir = 'W';
            p->moving = true;
        }
        else if(cmd == 'S'){
            p->dir = 'S';
            p->moving = true;
        }
        else if(cmd == 'E'){
            p->dir = 'E';
            p->moving = true;
        }
        else if(cmd == 'N'){
            p->dir = 'N';
            p->moving = true;
        }
        p = p->next;
    }  
}

void killerCmd(killer* k, board* b){
    killer* curr = k;
    while(curr != NULL){
        char cmd = getKillerCmd(curr, b);
        if(cmd == 'r'){
            curr->moving = false;
        }
        else if(cmd == 'W'){
            curr->dir = 'W';
            curr->moving = true;
        }
        else if(cmd == 'S'){
            curr->dir = 'S';
            curr->moving = true;
        }
        else if(cmd == 'E'){
            curr->dir = 'E';
            curr->moving = true;
        }
        else if(cmd == 'N'){
            curr->dir = 'N';
            curr->moving = true;
        }
        curr = curr->next;
    }
}

char getStarCmd(char dir){
    if((rand() % 10) == 0){ // 1 in 10 of changing direction
        if((rand() % 2) == 0){// 1 in 2 of being left/right
            return turnLeft(dir);
        }
        else{
            return turnRight(dir);
        }
    }
    return dir;
}

char getKillerCmd(killer* curr, board* b){
    char origdir;
    if((rand() % 10) == 0){ // 1 in 10 of changing direction
        if((rand() % 2) == 0){// 1 in 2 of being left/right
            origdir = turnLeft(curr->dir);
        }
        else{
            origdir = turnRight(curr->dir);
        }
    }
    if((rand() % 2) == 0){ // 1 in 2 of reassessing direciton
        int dc = b->players->col - curr->col;
        int dr = b->players->row - curr->row;
        char cdir, rdir;
        if(dc < 0){
            cdir = 'N';
        }
        else{
            cdir = 'S';
        }
        if(dr < 0){
            rdir = 'W';
        }
        else{
            rdir = 'E';
        }
        if((rand() % 2) == 0){ // 1 in 2 of choosing c adjust or r adjust
            return cdir;
        }
        else{
            return rdir;
        }
    }
    else{
        return origdir;
    }
}

void firstStarCmd(star* s){
    star* p = s;
    while(p != NULL){
        char cmd = getRandDir();
        if(cmd == 'r'){             //this cmd should never happen
            p->moving = false;
        }
        else if(cmd == 'W'){
            p->dir = 'W';
            p->moving = true;
        }
        else if(cmd == 'S'){
            p->dir = 'S';
            p->moving = true;
        }
        else if(cmd == 'E'){
            p->dir = 'E';
            p->moving = true;
        }
        else if(cmd == 'N'){
            p->dir = 'N';
            p->moving = true;
        }
        p = p->next;
    }  
}

void firstKillerCmd(killer* s){
    killer* p = s;
    while(p != NULL){
        char cmd = getRandDir();
        if(cmd == 'r'){             //this cmd should never happen
            p->moving = false;
        }
        else if(cmd == 'W'){
            p->dir = 'W';
            p->moving = true;
        }
        else if(cmd == 'S'){
            p->dir = 'S';
            p->moving = true;
        }
        else if(cmd == 'E'){
            p->dir = 'E';
            p->moving = true;
        }
        else if(cmd == 'N'){
            p->dir = 'N';
            p->moving = true;
        }
        p = p->next;
    }  
}

char getRandDir(){
    int r = rand() % 4;
    char dir;
    if(r == 0){ 
        dir = 'N';
    }
    else if(r == 1){ 
        dir = 'S';
    }
    else if(r == 2){ 
        dir = 'E';
    }
    else{
        dir = 'W';
    }
    return dir;
}

char turnLeft(char dir){
    if(dir == 'N'){
        return 'W';
    }
    else if(dir == 'S'){
        return 'E';
    }
    else if(dir == 'E'){
        return 'N';
    }
    else{
        return 'S';
    }
}

char turnRight(char dir){
    if(dir == 'N'){
        return 'E';
    }
    else if(dir == 'S'){
        return 'W';
    }
    else if(dir == 'E'){
        return 'S';
    }
    else{
        return 'N';
    }
}

void drawAll(board* b){
    drawPlayers(b->players);
    drawStars(b->stars);
    drawKillers(b->killers);
    drawGoals(b->goals);
}

void drawPlayers(player* p){
    if(p == NULL){
        return;
    }
    drawChar(p->c, p->row, p->col);
    drawPlayers(p->next);
}

void drawStars(star* s){
    if(s == NULL){
        return;
    }
    drawChar(s->c, s->row, s->col);
    drawStars(s->next);
}

void drawKillers(killer* s){
    if(s == NULL){
        return;
    }
    drawChar(s->c, s->row, s->col);
    drawKillers(s->next);
}

void drawGoals(goal* s){
    if(s == NULL){
        return;
    }
    drawChar(s->c, s->row, s->col);
    drawGoals(s->next);
}

void eraseAll(board* b){
    erasePlayers(b->players);
    eraseStars(b->stars);
    eraseKillers(b->killers);
}

void erasePlayers(player* p){
    if(p == NULL){
        return;
    }
    drawChar(' ', p->row, p->col);
    erasePlayers(p->next);
}

void eraseStars(star* s){
    if(s == NULL){
        return;
    }
    drawChar(' ', s->row, s->col);
    eraseStars(s->next);
}

void eraseKillers(killer* s){
    if(s == NULL){
        return;
    }
    drawChar(' ', s->row, s->col);
    eraseKillers(s->next);
}

bool checkEnd(board* b, bool &passed){
    if(playerCollide(b)){
        passed = false;
        return true;
    }
    if((abs(b->goals->col - b->players->col) <= 1) && (abs(b->goals->row - b->players->row) <= 1)){
        passed = true;
        return true;
    }
    return false;
}

void spawnStars(board* b){
    spawn* s = b->spawns;
    while(s != NULL){
        cerr << "numstar = " << b->numstar << endl;
        for(int i = 0; i < b->numstar; i++){
            addBackStar(b->stars, s->row, s->col, '*');
        }
        s = s->next;
    }
}

void spawnKillers(board* b){
    spawn* s = b->spawns;
    while(s != NULL){
        cerr << "numkiller = " << b->numkiller << endl;
        for(int i = 0; i < b->numkiller; i++){
            addBackKiller(b->killers, s->row, s->col, 'K');
        }
        s = s->next;
    }
}

bool playerCollide(board* b){
    star* s = b->stars;
    player* p = b->players;
    killer* k = b->killers;
    while(p != NULL){
        while(s != NULL){
            if(p->col == s->col && p->row == s->row){
                return true;
            }
            else if(tradedSpotsPlayerStar(p, s))
            {
                return true;
            }
            s = s->next;
        }
        while(k != NULL){
            if(p->col == k->col && p->row == k->row){
                return true;
            }
            else if(tradedSpotsPlayerKiller(p, k))
            {
                return true;
            }
            k = k->next;
        }
        p = p->next;
    }
    return false;
}

bool tradedSpotsPlayerStar(player* p, star* s){
    if(p->row == s->prevrow && p->col == s->prevcol){
        if(s->row == p->prevrow && s->col == p->prevcol){
            return true;
        }
    }
    return false;
}

bool tradedSpotsPlayerKiller(player* p, killer* s){
    if(p->row == s->prevrow && p->col == s->prevcol){
        if(s->row == p->prevrow && s->col == p->prevcol){
            return true;
        }
    }
    return false;
}

void updateOldsPlayer(player* p){
    while(p != NULL){
        p->prevcol = p->col;
        p->prevrow = p->row;
        p = p->next;
    }
}

void updateOldsStar(star* p){
    while(p != NULL){
        p->prevcol = p->col;
        p->prevrow = p->row;
        p = p->next;
    }
}

void updateOldsKiller(killer* p){
    while(p != NULL){
        p->prevcol = p->col;
        p->prevrow = p->row;
        p = p->next;
    }
}

void resetAll(board* b){
    star* s = b->stars;
    player* p = b->players;
    killer* k = b->killers;
    while(s != NULL){
        s->row = s->startrow;
        s->col = s->startcol;
        s = s->next;
    }
    while(p != NULL){
        p->row = p->startrow;
        p->col = p->startcol;
        p = p->next;
    }
    while(k != NULL){
        k->row = k->startrow;
        k->col = k->startcol;
        k = k->next;
    }
}