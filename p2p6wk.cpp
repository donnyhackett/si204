#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int floor = 1, people = 0;
  bool done = false;
  string cmd = "";
  while(done == false){
    cin >> cmd;
    if(cmd == "up")
      floor++;
    if(cmd == "down")
      floor--;
    if(cmd == "pin")
      people++;
    if(cmd == "pout"){
      if(people == 0){
        cout << "error!" << endl;
        return 1;
      }
      people--;
    }
    if(cmd == "done")
      done = true;
  }
  cout << "floor: " << floor << endl;
  cout << "people: " << people << endl;
  return 0;
}
