#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int height, width, offset;
  cout << "Enter height (greater than 2): ";
  cin >> height;
  cout << "Enter width  (greater than 2): ";
  cin >> width;
  cout << "Enter offset: ";
  cin >> offset;
  cout << "\n";
  for(int i = 0; i < height; i++){
	  for(int j = 0; j < width + offset; j++){
		  if((i == 0) || (i == height - 1)){
			  if(j >= offset)
				  cout << "*";
			  else
				  cout << " ";
		  }
		  else if((j == offset) || (j == (width + offset) - 1))
			  cout << "*";
		  else
			  cout << " ";
	  }
	  cout << endl;
  }

		
  return 0;
}
