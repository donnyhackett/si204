#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int* A, int&card, int&j);
int* deck(int card);
void shuffle(int* A);
void print(int* A);

int rand();
int ctime();

int main() {
  //give shuffle message, receive input
  char shuf;
  int seed;
  cout << "Shuffle: [n | s | u <seed>]: ";
  cin >> shuf;
  int card = 52, j;
  if (shuf == 'n'){
    int* A = deck(card);
    print(A);
  }
  else if (shuf == 's') {
    srand(time(0));
    int* A = deck(card);
    shuffle(A);
    print(A);
  }
  //shuffle wit+h given seed
  else if (shuf == 'u') {
    int* A = deck(card);
    cin >> seed;
    srand(seed);
    shuffle(A);
    print(A);
  }

}

void swap(int* A, int&card, int&j){
  int temp = A[card];
  A[card] = A[j];
  A[j] = temp;
}
int* deck(int card) {
    int* A = new int[card];
    int cnt = 0;
    for (int j = 100; j <= 400; j += 100)
    {
      for (int i = 2; i <= 14; i++){
        A[cnt] = j + i;
        cnt++;
      }    
    }
    return A;

}

void shuffle(int* A){
    for (int i = 0; i < 52; i++){
       int j = (rand() % 52);
       swap(A, i, j);
    }
}

void print(int* A)
{
  for(int i = 0; i < 52; i++)
  {
    cout << A[i] << endl;
  }
}

