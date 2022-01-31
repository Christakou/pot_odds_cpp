#include <iostream>
#include <vector>
#include <string>
#include "utils.h"

using namespace std;


enum Suit
{
    Clubs,
    Hearts,
    Spades,
    Diamonds,
};

Suit AllSuits[4] = {Clubs, Hearts, Spades, Diamonds};

string representRank(int input)
{
    string result;
    if (input < 11)
    {
        result = to_string(input);
    }
    else
    {
        switch (input)
        {
        case 11:
            result = "J";
        case 12:
            result = "Q";
        case 13:
            result = "K";
        case 14:
            result = "A";
        default:
            break;
        }
    }

    return result;
}


template<typename T>
void FyShuffle(vector<T>& input){
    for(int i = input.size()-1; i>1; i--){
        srand((unsigned int)time(NULL));
        int j = rand()%(i + 1);
        swap(input[i],input[j]);
    }
}


string representSuit(Suit input)
{
    string result;
    switch (input)
    {
    case 0:
        result = "C";
        break;
    case Hearts:
        result = "H";
        break;
    case Diamonds:
        result = "D";
        break;
    case Spades:
        result = "S";
        break;
    }
    return result;
}



class Card
{
public:
    int rank;
    Suit suit;

    Card(int _rank, Suit _suit)
    {
        rank = _rank;
        suit = _suit;
    }


    string Represent(){
        return representRank(rank)+representSuit(suit);
    }

    void Print()
    {
        cout << Represent();
    }

};


class Deque
{
public:
   vector<Card> cards;

    Deque()
    {
        for (int i = 1; i < 15; i++)
        {
            for (Suit suit : AllSuits)
            {
                cards.push_back(Card(i, suit));
            }
        }
    }
    void Print()
    {
        for (Card card : cards)
        {
           cout << ' ';
            card.Print();
        }
    }
    void Shuffle(){
        FyShuffle(cards);
    }
    Deque Deal(int n){
        vector<Card> dealt_hand;
        Deque return_hand = Deque();
        return_hand.cards.clear();
        for(int i=0; i < n; i++){
            return_hand.cards.push_back(cards[cards.size()-1]);
            cards.pop_back();
        }
        return return_hand;
    }
};



void Log(const char *message)
{
   cout << message << '\n';
}

int main()
{
    Deque a = Deque();

    a.Print();
    a.Shuffle();
    cout << '\n';
    cout << '\n';
    a.Print();
    cout << '\n';
    Deque hand = a.Deal(10);
    cout << '\n';
    cout << '\n';
    hand.Print();
    cout << '\n';

    foo();
    return 0;
}
