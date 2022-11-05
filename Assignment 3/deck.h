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
        Deck(); //Deck Constructor
        Deck(int);

        //~Deck();

        void set_n_cards(int);
        int get_n_cards();
        void fillDeck();
        void shuffleDeck();
        int getCardRank();
        int getCardSuit();
        void printCard();
        void removeCard(); //Cards are drawn from the first index card, need to change index of where card is drawn from.
    
};

#endif