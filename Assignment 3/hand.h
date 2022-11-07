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
        Hand(); //Default constructor
        Hand(int);
        ~Hand(); //destructor 
        Hand (const Hand &); //copy constructor
        Hand& operator=(const Hand &); //assignment operator overload

        Card* get_cards(); // Gets array of cards
        void setCardsInHand(Deck&); //Puts 7 cards in players hand
        void printCardsInHand(); //Prints all cards in hand
        int getCardsInHand();
        bool goFish(Deck&, Hand&, int); //Gets card from deck and adds to players hand
        void addCardInHand(Hand&, int, int);
        int removeCardInHand(int, Hand&, int*);
        int getRankOfCard(int); //Returns rank of card
        

};

#endif