/*
  This is a complete program except that a definition
  for the function

  void read(istream& in, DivBox &DB);

  is missing.  Your job is to define that function so
  that this program successfully reads and processes
  inputs (two example input files are given).  A line
  of input that's supposed to become a single DivBox 
  looks like this:
  
  new (80,160) 100x50 50,50,255 filled

  or like this:

  new (40,240) 100x200 70,70,70 hollow
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//-- DEFININING POINT ---//
struct Point
{
  double x, y;
};

//-- DEFININING RECTANGLE ---//
struct Rectangle
{
  Point lowerLeft;
  double width, height;
};

//-- DEFININING COLOR ---//
struct Color
{
  int r, g, b;
};

//-- DEFININING DIVBOX ---//
struct DivBox
{
  Rectangle R;
  Color C;
  bool filled;
};
void read(istream& in, DivBox &DB);
void write(ostream &out, DivBox A);

//---------- MAIN -----------//
int main()
{
  cout << "Input filename: ";
  string fn;
  cin >> fn;
  ifstream fin(fn.c_str());
  if (!fin)
  {
    cout << "File '" << fn << "' not found!" << endl;
    exit(1);
  }

  ofstream fout("tst.html");
  fout << "<html><head></head><body>" << endl;
  string comm;
  while(fin >> comm && comm != "quit")
  {
    DivBox A;
    read(fin,A);
    write(fout,A);
  }
  fout << "</body></html>" << endl;  
  cout << "Output in file tst.html" << endl;
  return 0;
}

//---------- FUNCTION DEFINITIONS -----------//

void read(istream& in, DivBox &DB)
{
  //!!!!!!!!!! YOUR WORK GOES HERE !!!!!!!!!!
  char temp;
  string garb;
  in >> temp >> DB.R.lowerLeft.x >> temp >> DB.R.lowerLeft.y >> temp >> DB.R.width >> temp >> DB.R.height >> DB.C.r >> temp >> DB.C.g >> temp >> DB.C.b >> garb; 
  if(garb == "filled")
    DB.filled = true;
  else
    DB.filled = false;
  //cout << DB.R.lowerLeft.x << " " << DB.R.lowerLeft.y << " " << DB.R.width << " " << DB.R.height << " " << DB.C.r << " " << DB.C.g << " " << DB.C.b << " " << garb;
}








// PLEASE DON'T LOOK AT THIS!  USE YOUR OWN UNDERSTANDING TO FIGURE OUT YOUR PART
void write(ostream &out, DivBox A)
{
out << "<div style=\"position: fixed; border-style: solid; border-width: 2pt;"; out << "left: " << A.R.lowerLeft.x << "pt; ";out << "top: " << A.R.lowerLeft.y - A.R.height << "pt; ";out << "height: " << A.R.height << "pt; ";out << "width: " << A.R.width << "pt; ";out << "color: rgb(" << A.C.r << "," << A.C.g << "," << A.C.b << "); "; if (A.filled) out << "background-color: rgb(" << A.C.r << "," << A.C.g << "," << A.C.b << "); ";out << "\"></div>" << endl;
}
