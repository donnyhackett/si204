#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string file, out = "";
  int r, c, t = 0;
  cin >> file >> r >> c;
  ifstream fin(file);
  if(!fin){
    cout << "File '" << file << "' not found!" << endl;
    return 0;
  }
  t = ((r - 1) * 26) + c;
  for(int i = 0; i < t; i++){
    fin >> out;
  }
  cout << out << endl;
  return 0;
}
