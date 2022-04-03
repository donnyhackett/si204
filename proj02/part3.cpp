#include <iostream>
#include <cstdlib>
using namespace std;

int cardValue(int, int);
void shuffle(int**);
void print(int**);
int** makeDeck();
string stringValue(int, int);
int dealCard(int**, int&);
void printDeck(int*, int*, int);

int rand();
int ctime();

//1 = ♣, 2 = ♦, 3 = ♥, 4 = ♠

int main()
{
    cout << "Shuffle: [n | s | u <seed>]: ";

    //Seed function
    char in;
    cin >> in;
    int** deck = makeDeck();
    if(in == 'n')
    {
    }
    else if(in == 's')
    {
        srand(time(0));
        shuffle(deck);
    }
    else if(in == 'u')
    {
        int seed;
        cin >> seed;
        srand(seed);
        shuffle(deck);
    }

    int index = 0;
    int* playerHand = new int[11];
    int* dealerHand = new int[11];
    for(int i = 0; i < 2; i++)
    {
        playerHand[i] = dealCard(deck, index);
        dealerHand[i] = dealCard(deck, index);
    }
    printDeck(playerHand, dealerHand, index);
    for(int i = 2; i < 5; i++)
    {
        playerHand[i] = dealCard(deck, index);
        dealerHand[i] = dealCard(deck, index);
        printDeck(playerHand, dealerHand, index);
    }


    return 0;
}

int cardValue(int suit, int face)
{
    return (100 * suit) + face;
}

int valueToSuit(int val)
{
    return val / 100;
}

int valueToFace(int val)
{
    return val % 100;
}

string stringValue(int suit, int face)
{
    string suitchar;
    if(suit == 1)
        suitchar = "\u2663";
    else if(suit == 2)
        suitchar = "\u2666";
    else if(suit == 3)
        suitchar = "\u2665";
    else
        suitchar = "\u2660";
    if(face == 11)
        return " J" + suitchar;
    else if(face == 12)
        return " Q" + suitchar;
    else if(face == 13)
        return " K" + suitchar;
    else if(face == 14)
        return " A" + suitchar;
    else if(face < 10)
        return " " + to_string(face) + suitchar;
    else
        return to_string(face) + suitchar;
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
        cout << (stringValue(deck[i][0], deck[i][1])) << endl;
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

int dealCard(int** deck, int& index)
{
    index++;
    return cardValue(deck[index - 1][0], deck[index - 1][1]);
    
}

void printDeck(int* playerHand, int* dealerHand, int index)
{
    cout << endl;
    cout << " Player Dealer" << endl;
    for(int i = 0; i < (index / 2); i++)
    {
        cout << "| ";
        cout << stringValue(valueToSuit(playerHand[i]), valueToFace(playerHand[i]));
        cout << "  | ";
        cout << stringValue(valueToSuit(dealerHand[i]), valueToFace(dealerHand[i]));
        cout << "  |" << endl;
    }
}

