// midn long wong m247080
// 

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int* cardDeck();
void shuffler(int*);
void printer(int*);
void swap(int*, int, int);

int rand();
int ctime();

int main()
{
    string shuffle; 

    int cards, suite; 
    cout << "Shuffle: [n | s | u <seed>]: ";
    cin >> shuffle;

    if (shuffle == "n")

    {
       int* deck = cardDeck();
       printer(deck);
    }

    else if (shuffle == "s")
    {
        srand(time(0));
        int* deck = cardDeck();
        shuffler(deck);
        printer(deck);
    }
    else if(shuffle == "u")
    {
        int seed;
        cin >> seed;
        srand(seed);
        int* deck = cardDeck();
        shuffler(deck);
        printer(deck);

    }
    return 0;
}

// srand(time(0));

int* cardDeck()
{
    int* deck = new int[52];
    int cnt = 0;
    for(int suite = 100; suite <= 400; suite += 100)
    {
        for(int i = 2; i <= 14; i++)
        {
            deck[cnt] = suite + i;
            cnt++;
        }
    }
    return deck;
    
}

void printer(int* cardDeck)
{
    for(int i = 0; i < 52; i++)
        cout << cardDeck[i] << endl;
}

void shuffler(int* cardDeck)
{
    for(int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        swap(cardDeck, i , j);
    }

}

void swap(int* A, int i, int j)
{
    int newcard = A[i];
    A[i] = A[j];
    A[j] = newcard;
    
}