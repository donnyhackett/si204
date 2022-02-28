/*******************************************
 ** This program reads an integer from the
 ** user and prints out its factorization
 ** into irreducibles.  Unfortunately, I've
 ** been unable to figure out how to implement
 ** the function firstfactor, which takes an
 ** integer n, where n > 1, and returns the
 ** smallest factor of n, i.e. the smallest
 ** integer greater than 1 that divides n
 ** evenly.  You need to add the definition
 ** of firstfactor.
 *******************************************/
#include <iostream>
using namespace std;

/*******************************************
 ** PROTOTYPE
 *******************************************/
int firstfactor(int);

/*******************************************
 ** MAIN FUNCTION
 *******************************************/
int main()
{
  // Get integer n, n > 1, from user
  int n;
  cout << "Enter an integer larger than 1: ";
  cin >> n;

  // Print out factorization
  cout << "The factorization of " << n << " is ";
  while(n > 1)
  {
    // get & print next irreducible factor
    int f = firstfactor(n);
    cout << '(' << f << ')';
    n = n / f;
  }
  cout << endl;

  return 0;
}

/*******************************************
 ** FUNCTION DEFINITION
 *******************************************/
int firstfactor(int i){
    for(int j = 2; j <= i; j++){
        if((i % j) == 0){
            return j;
        }
    }
    return 2;
}