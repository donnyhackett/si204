#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string file;
  cin >> file;
  ifstream fin(file);
  if(!fin){
    cout << "Could not open file '" << file << "'" << endl; 
    return 1;
  }
  double avg;
  double prev;
  int count;
  string temp;
  string date;
  string time;
  fin >> temp >> temp;
  while( fin >> date >> time >> prev){
    count ++;
    avg += prev;
  }
  double Cel = avg/count;
  double Far = ((9.0/5.0)*Cel)+32;
  cout << "file: " << file << "\n" << "ave: " << Far << endl;

  return 0;
}
