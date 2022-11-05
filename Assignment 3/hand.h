#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#ifndef HANDS
#define HANDS

using namespace std;

class Hand{
    private:
        Card* cards; // An array of cards in hand
        int n_cards; // Number of cards in the hand
    public:
        Hand();
        Card* get_cards();
        void setCardsInHand(Deck&);
        void printCardsInHand();
        int getCardsInHand();
        void addCardInHand();
        void removeCardInHand();
        //~Hand(); //destructor 
        //Hand (const Hand &); //copy constructor
        //Hand& operator=(const Hand &); //assignment operator overload

};

#endif