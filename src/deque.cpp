#include <iostream>
#include <vector>
#include <string>
#include "algos.h"
#include <ostream>

using namespace std;



template<typename T>
void FyShuffle(std::vector<T>& input){
    // Fisher-Yates shuffle algorithm implemented for a vector of any type
    for(int i = input.size()-1; i>1; i--){
        srand((unsigned int)time(NULL));
        int j = rand()%(i + 1);
        swap(input[i],input[j]);
    }
}


enum class Suit
{
    Clubs,
    Hearts,
    Spades,
    Diamonds,
};

string representRank(unsigned int input)
{
    string result;
    if (input < 11){
        result = to_string(input);
    }
    else
    {
        switch (input)
        {
        case 11:
            result = "J";
            break;
        case 12:
            result = "Q";
            break;
        case 13:
            result = "K";
            break;
        case 14:
            result = "A";
            break;
        default:
            throw std::runtime_error("Invalid rank");
        }
    }

    return result;
}

string representSuit(Suit input)
{
    string result;
    switch (input)
    {
    case Suit::Clubs:
        result = "C";
        break;
    case Suit::Hearts:
        result = "H";
        break;
    case Suit::Diamonds:
        result = "D";
        break;
    case Suit::Spades:
        result = "S";
        break;
    default:
        throw std::runtime_error("Invalid Su");
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

    string Represent()
    {
        return representRank(rank) + representSuit(suit);
    }

    // overload the << operator to print a Card object
    friend std::ostream &operator<<(std::ostream &os, const Card &obj)
    {
        os << representRank(obj.rank) << representSuit(obj.suit);
        return os;
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
            for (Suit c = Suit::Clubs; c <= Suit::Hearts; c = static_cast<Suit>(static_cast<int>(c) + 1))
            {
                {
                    cards.push_back(Card(i, c));
                }
            }
        }
    }
    void Print()
    {
        for (Card card : cards)
        {
            cout << card << ' ';
        }
    }
    void Shuffle()
    {
        FyShuffle(cards);
    }
    Deque Deal(int n)
    {
        vector<Card> dealt_hand;
        Deque return_hand = Deque();
        return_hand.cards.clear();
        for (int i = 0; i < n; i++)
        {
            return_hand.cards.push_back(cards[cards.size() - 1]);
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

    return 0;
}

