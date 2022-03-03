/************************************************
 ** This program reads in two temperatures, both
 ** greater than 0C/32F and less than 360C/680F,
 ** and it outputs the change in energy (in
 ** kilo joules) of 1kg of water going from the
 ** initial temp to final.
 ** NOTE: this program needs the file enth.txt.
 ************************************************/
#include <iostream>
#include <fstream>
using namespace std;
void fish(int, string);
void fowl(int, string);
void fowl(char, string);
void fowl(char);
int main()
{
  fish(7,"fan");
  fish('$',"naf");
  fowl(dog);
  fowl(rat,"fun");
  fowl(dog,"nuf");
  fowl(pig,"huh");
  return 0;
}
void fish(int i, string s)
{
  cout << "fish" << s << ' ' << i << endl;
}

void fowl(int i, string s)
{
  cout << "chicken" << s << ' ' << i << endl;
}

void fowl(char c, string s)
{
  cout << "turkey" << s << c << endl;
}

void fowl(char c)
{
  fowl(c - 'a',"alpha");
}

int rat = 3;
char dog = 'd';
string pig = "tone";

