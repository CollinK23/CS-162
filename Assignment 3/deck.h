#include <iostream>
#include <string>
#include "card.h"
#ifndef DECKS
#define DECKS

using namespace std;

class Deck{
    private:
        Card cards[52]; //A full deck of cards
        int n_cards; //number of cards remaining in the deck
    public:
        Deck(); //Default Deck Constructor
        Deck(int); //Deck constructor

        void set_n_cards(int);
        int get_n_cards();
        void fillDeck();
        void shuffleDeck();
        int getCardRank();
        int getCardSuit();
        void printCard();
        void removeCard();
    
};

#endif