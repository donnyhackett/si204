#include <iostream>
#include <cstdlib>
using namespace std;

int cardValue(int, int);
void shuffle(int**);
void print(int**);
int** makeDeck();

int rand();
int ctime();

//1 = ♣, 2 = ♦, 3 = ♥, 4 = ♠

int main()
{
    cout << "Shuffle: [n | s | u <seed>]: ";

    //Seed function
    char in;
    cin >> in;
    if(in == 'n')
    {
        int** deck = makeDeck();
        print(deck);
    }
    else if(in == 's')
    {
        srand(time(0));
        int** deck = makeDeck();
        shuffle(deck);
        print(deck);
    }
    else if(in == 'u')
    {
        int seed;
        cin >> seed;
        srand(seed);
        int** deck = makeDeck();
        shuffle(deck);
        print(deck);
    }



    return 0;
}

int cardValue(int suit, int face)
{
    return (100 * suit) + face;
}

void shuffle(int** deck)
{
    for(int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        int temp1 = deck[i][0];
        int temp2 = deck[i][1];
        deck[i][0] = deck[j][0];
        deck[i][1] = deck[j][1];
        deck[j][0] = temp1;
        deck[j][1] = temp2;
    }
}

void print(int** deck)
{
    for(int i = 0; i < 52; i++)
    {
        cout << (cardValue(deck[i][0], deck[i][1])) << endl;
    }
}

int** makeDeck()
{
    int** deck = new int*[52];
    for(int i = 0; i < 52; i++)
        deck[i] = new int[2];
    for(int i = 0; i < 52; i++)
    {
        if(i < 13)
            deck[i][0] = 1;
        else if(i < 26)
            deck[i][0] = 2;
        else if(i < 39)
            deck[i][0] = 3;
        else
            deck[i][0] = 4;
        deck[i][1] = (i % 13) + 2;
    }
    return deck;
}

