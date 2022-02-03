#include <iostream>
using namespace std;

int main()
{
  double in_1_x;
  double in_1_y;
  double in_2_x;
  double in_2_y;
  double in_3_x;
  double in_3_y;
  char temp;
  cin >> temp >> in_1_x >> temp >> in_1_y >> temp >> temp >> in_2_x >> temp >> in_2_y >> temp >> temp >> in_3_x >> temp >> in_3_y >> temp;
  
  //checks lowest x-value
  double most_left;
  if (in_1_x < in_2_x)
  {
    if(in_1_x < in_3_x)
      most_left = in_1_x;
    else
      most_left = in_3_x;
  }
  else if (in_2_x < in_3_x)
    most_left = in_2_x;
  else
    most_left = in_3_x;

  double most_right;
  //checks highest x-value
  if (in_1_x > in_2_x)
  {
    if(in_1_x > in_3_x)
      most_right = in_1_x;
    else
      most_right = in_3_x;
  }
  else if (in_2_x > in_3_x)
    most_right = in_2_x;
  else
    most_right = in_3_x;

  double most_up;
  //checks highest y-vlaue
  if (in_1_y > in_2_y)
  {
    if(in_1_y > in_3_y)
      most_up = in_1_y;
    else
      most_up = in_3_y;
  }
  else if (in_2_y > in_3_y)
    most_up = in_2_y;
  else
    most_up = in_3_y;

  double most_down;
  //checks lowest y-value
  if (in_1_y < in_2_y)
  {
    if(in_1_y < in_3_y)
      most_down = in_1_y;
    else
      most_down = in_3_y;
  }
  else if (in_2_y < in_3_y)
    most_down = in_2_y;
  else
    most_down = in_3_y;
  
  

  cout << most_left << " " << most_down << endl;
  cout << most_left << " " << most_up << endl;
  cout << most_right << " " << most_up << endl;
  cout << most_right << " " << most_down << endl;
  cout << most_left << " " << most_down << endl;
  cout << "\n";
  cout << in_1_x << " " << in_1_y << endl;
  cout << in_2_x << " " << in_2_y << endl;
  cout << in_3_x << " " << in_3_y << endl;
  cout << in_1_x << " " << in_1_y << endl;

  return 0;
}

