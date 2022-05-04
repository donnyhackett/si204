#ifndef Proj3_h
#define Proj3_h
#include <iostream>
#include <fstream>
using namespace std;

struct wall{
  int row, col;
  char c;
  wall* next;
};

struct spawn{
  int row, col;
  char c;
  spawn* next;
};

struct goal{
  int row, col;
  char c;
  goal* next;
};

struct player{
  int startrow, startcol;
  int row, col;
  int prevrow, prevcol;
  char c;
  char dir;
  bool moving;
  player* next;
};

struct star{
  int startrow, startcol;
  int row, col;
  int prevrow, prevcol;
  char c;
  char dir;
  bool moving;
  star* next;
};

struct killer{
  int startrow, startcol;
  int row, col;
  int prevrow, prevcol;
  char c;
  char dir;
  bool moving;
  killer* next;
};

struct board{
  int numstar, numkiller, points;
  wall* walls;
  spawn* spawns;
  goal* goals;
  player* players;
  star* stars;
  killer* killers;
  board* next;
};

void readBoard(ifstream &, int &, int &, board*);
void printBoard(board*);
void addBackWall(wall* &, int, int, char);
void addBackSpawn(spawn* &, int, int, char);
void addBackGoal(goal* &, int, int, char);
void addBackPlayer(player* &, int, int, char);
void addBackStar(star* &, int, int, char);
void addBackKiller(killer* &, int, int, char);
int lengthWall(wall*);
int lengthSpawn(spawn*);
int lengthGoal(goal*);
int lengthPlayer(player*);
int lengthStar(star*);
void printWalls(wall*);
void printSpawns(spawn*);
void printGoals(goal*);
void printPlayers(player*);
void printSpawnLocs(spawn*);
void turnBackPlayer(player*, board*);
void turnBackStar(star*, board*);
void turnBackKiller(killer*, board*);
bool atEdge(wall*, int, int);
void edgeCheck(board*);
void moveChars(board*);
void movePlayer(player*);
void moveStars(star*);
void moveKillers(killer*);
int futureRowPlayer(player*);
int futureColPlayer(player*);
int futureRowStar(star*);
int futureColStar(star*);
int futureRowKiller(killer*);
int futureColKiller(killer*);
void playerCmd(player*, char);
void starCmd(star*);
void killerCmd(killer*, board*);
char getStarCmd(char);
char getKillerCmd(killer*, board*);
void drawAll(board*);
void drawPlayers(player*);
void drawStars(star*);
void drawKillers(killer*);
void eraseAll(board*);
void erasePlayers(player*);
void eraseStars(star*);
void eraseKillers(killer*);
bool checkEnd(board*, bool &);
void spawnStars(board*);
void spawnKillers(board*);
char turnLeft(char);
char turnRight(char);
char getRandDir();
void firstStarCmd(star*);
void firstKillerCmd(killer*);
bool playerCollide(board*);
bool tradedSpotsPlayerStar(player*, star*);
bool tradedSpotsPlayerKiller(player*, killer*);
void updateOldsPlayer(player*);
void updateOldsStar(star*);
void updateOldsKiller(killer*);
void resetAll(board*);

#endif
