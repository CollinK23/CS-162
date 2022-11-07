#include <iostream>
#include <string>
#include "hand.h"
#include "deck.h"
#ifndef PLAYERS
#define PLAYERS

using namespace std;

class Player{
    private:
        Hand hand;
        int* books; // Array with ranks for which the player has books.
        int n_books;
        int cardCounter[13];
    public:
        Player(); //Default Constructor
        Player(int);
        ~Player(); //destructor 
        Player (const Player &); //copy constructor
        Player& operator=(const Player &); //assignment operator overload

        Card* getCards();
        int getNumOfBooks();
        void setNumOfBooks(Player&);
        void createBook();
        int cardsRemainingInHand();
        void setPlayersHand(Deck&);
        bool goFish(Deck&, int);
        int removeCard(int, int*);
        string rankConverter(int);
        void printCardsInHand();
        void printBooks();
        void addCardInHand(int, int);

};

#endif