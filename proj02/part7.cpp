#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int cardValue(int, int);
void shuffle(int**);
void print(int**);
int** makeDeck();
string stringValue(int, int);
int dealCard(int**, int&);
void printDeck(int*, int*, int);
void printDeckFinal(int*, int*, int);
int returnScore(int*);
bool gameOver(int*, int*, bool, bool);
void clearHands(int*, int*);
void clearHands(int**);

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

    int index = 0, pstays = 0, dstays = 0;
    int* playerHand = new int[11];
    int* dealerHand = new int[11];
    for(int i = 0; i < 2; i++)
    {
        playerHand[i] = dealCard(deck, index);
        dealerHand[i] = dealCard(deck, index);
    }
    
    
    int round = 1;
    char hit;
    bool playerstayed = false, dealerstayed = false, notDone = true;
    int i = 2;
    while(gameOver(playerHand, dealerHand, playerstayed, dealerstayed) && notDone)
    {
        system("clear");
        printDeck(playerHand, dealerHand, (index + pstays + dstays));
        cout << "Round " << round << " Player's turn" << endl;
        cout << "hit or stand? [h/s] ";
        cin >> hit;
        if(hit == 'h')
        {
            playerHand[i-pstays] = dealCard(deck, index);
            playerstayed = false;
        }
        else
        {
            playerstayed = true;
            playerHand[i] = 0;
            pstays++;
        }

        if(!gameOver(playerHand, dealerHand, playerstayed, dealerstayed))
        {
            if(returnScore(playerHand) > 21)
            {
                notDone = false;
            }
            else if(returnScore(dealerHand) > 21)
            {
                notDone = false;
            }
            else if(returnScore(playerHand) > returnScore(dealerHand))
            {
                notDone = false;
            }
            else if(returnScore(playerHand) < returnScore(dealerHand))
            {
                notDone = false;
            }
            else if(returnScore(playerHand) == returnScore(dealerHand))
            {
                system("clear");
                printDeckFinal(playerHand, dealerHand, index + 1 + pstays + dstays);
                notDone = true;
                clearHands(playerHand, dealerHand);
                clearHands(deck);
                deck = makeDeck();
                shuffle(deck);
                round = 1;
                pstays = 1;
                index = 0;
                playerstayed = dealerstayed = false;
                for(i = 0; i < 2; i++)
                {
                    playerHand[i] = dealCard(deck, index);
                    dealerHand[i] = dealCard(deck, index);
                }
                continue;
            }
            if(notDone == false)
                break;
        }
        system("clear");
        printDeck(playerHand, dealerHand, (index + 1 + pstays + dstays));

        cout << "Round " << round << " Dealer's turn" << endl;
        cout << "hit or stand? [h/s] ";
        if(returnScore(dealerHand) < 17)
        {
            hit = 'h';
            cout << "h" << endl;
        }
        else
        {
            hit = 's';
            cout << "s" << endl;
        }
        sleep(2);
        if(hit == 'h')
        {
            dealerHand[i-dstays] = dealCard(deck, index);
            dealerstayed = false;
        }
        else
        {
            dealerstayed = true;
            dealerHand[i] = 0;
            dstays++;
        }
        if(!gameOver(playerHand, dealerHand, playerstayed, dealerstayed))
        {
            if(returnScore(playerHand) > 21)
            {
                notDone = false;
            }
            else if(returnScore(dealerHand) > 21)
            {
                notDone = false;
            }
            else if(returnScore(playerHand) > returnScore(dealerHand))
            {
                notDone = false;
            }
            else if(returnScore(playerHand) < returnScore(dealerHand))
            {
                notDone = false;
            }
            else if(returnScore(playerHand) == returnScore(dealerHand))
            {
                system("clear");
                printDeckFinal(playerHand, dealerHand, index + 1 + pstays + dstays);
                notDone = true;
                playerstayed = dealerstayed = false;
                clearHands(playerHand, dealerHand);
                clearHands(deck);
                deck = makeDeck();
                shuffle(deck);
                round = 0;
                index = 0;
                pstays = 1;
                for(i = 0; i < 2; i++)
                {
                    playerHand[i] = dealCard(deck, index);
                    dealerHand[i] = dealCard(deck, index);
                }
            }
        }

        
        round++;
        i++;
    }
    system("clear");
    printDeckFinal(playerHand, dealerHand, (index + 1 + pstays + dstays));
    if(returnScore(playerHand) > 21)
    {
        cout << "Player busts, dealer wins" << endl;
    }
    else if(returnScore(dealerHand) > 21)
    {
        cout << "Dealer busts, player wins" << endl;
    }
    else if(returnScore(playerHand) > returnScore(dealerHand))
    {
        cout << "Player wins" << endl;
    }
    else if(returnScore(playerHand) < returnScore(dealerHand))
    {
        cout << "Dealer wins" << endl;
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
    else if(suit == 4)
        suitchar = "\u2660";
    else
        suitchar = "";
    if(face == 0)
        return "";
    else if(face == 11)
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
    cout << " Player Dealer" << endl;
    for(int i = 0; i < (index / 2); i++)
    {
        if(playerHand[i] == 0 && dealerHand[i] == 0)
            return;
        cout << "| ";
        if(playerHand[i] == 0)
            cout << "   ";
        else
            cout << stringValue(valueToSuit(playerHand[i]), valueToFace(playerHand[i]));
        cout << "  | ";
        if(i == 0)
            cout << " **";
        else if(dealerHand[i] == 0)
            cout << "   ";
        else
            cout << stringValue(valueToSuit(dealerHand[i]), valueToFace(dealerHand[i]));
        cout << "  |" << endl;
    }
}

void printDeckFinal(int* playerHand, int* dealerHand, int index)
{
    cout << " Player Dealer" << endl;
    for(int i = 0; i < (index / 2); i++)
    {
        if(playerHand[i] == 0 && dealerHand[i] == 0)
            return;
        cout << "| ";
        if(playerHand[i] == 0)
            cout << "   ";
        else
            cout << stringValue(valueToSuit(playerHand[i]), valueToFace(playerHand[i]));
        cout << "  | ";
        if(dealerHand[i] == 0)
            cout << "   ";
        else
            cout << stringValue(valueToSuit(dealerHand[i]), valueToFace(dealerHand[i]));
        cout << "  |" << endl;
    }
}

int returnScore(int* A)
{
    int total = 0;
    bool ace = false;
    for(int i = 0; i < 11; i++)
    {
        int card = valueToFace(A[i]);
        if(card == 14)
        {
            ace = true;
            if(total > 10)
            {
                ace = false;
                total += 1;
            }
            else
            {
                total += 11;
            }
        }
        else if(card > 10)
        {
            total += 10;
        }
        else
        {
            total += card;  
        }
    }
    if(ace)
    {
        if(total > 21)
        {
            total -= 10;
        }
    }
    
    return total;
}

bool gameOver(int* playerHand, int* dealerHand, bool playerstayed, bool dealerstayed)
{
    if(returnScore(playerHand) > 21 || returnScore(dealerHand) > 21)
        return false;
    if((playerstayed && dealerstayed))
        return false;
    if((returnScore(playerHand) == 21) && (returnScore(dealerHand) == 21))
        return false;
    return true;
}

void clearHands(int* playerHand, int* dealerHand)
{
    for(int i = 0; i < 11; i++)
    {
        playerHand[i] = 0;
        dealerHand[i] = 0;
    }
}

void clearHands(int** deck)
{
    for(int i = 0; i < 52; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            deck[i][j] = 0;
        }
    }
}