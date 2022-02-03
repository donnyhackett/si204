#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string file, outfile;
  cin >> file >> outfile;
  ifstream fin(file);
  if(!fin){
    cout << "Could not open file '" << file << "'" << endl; 
    return 1;
  }
  double avg, prev;
  double max = -99999999;
  double min = 99999999;
  int count;
  string temp, date, time, max_date, min_date;
  fin >> temp >> temp;

  while( fin >> date >> time >> prev){
    if(prev > max){
      max = prev;
      max_date = date;
    }
    if(prev < min){
      min = prev;
      min_date = date;
    }
    count ++;
    avg += prev;
  }
  double max_Far = ((9.0/5.0)*max)+32;
  double min_Far = ((9.0/5.0)*min)+32;
  double Cel = avg/count;
  double Far = ((9.0/5.0)*Cel)+32;
  cout << "file: " << file << "\n" << "ave: " << Far << endl;
  cout << "min: " << min_Far << " on " << min_date << endl;
  cout << "max: " << max_Far << " on " << max_date << endl;

  ofstream fout(outfile);
  ifstream fin2(file);
  fin2 >> temp >> temp;
  fout << "day" << "\t" << "hour" << "\t" << "temp" << "\n";
  int h;
  while(fin2 >> date >> h >> time >> prev){
    fout << date << "\t" << h+1 << "\t" << ((9.0/5.0)*prev)+32 << "\n";
  }
  cout << "output in: " << outfile << endl;
  return 0;
}
