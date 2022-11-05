#include <iostream>
#include <string>
#include "hand.h"
#ifndef PLAYERS
#define PLAYERS

using namespace std;

class Player{
    private:
        Hand hand;
        int* books; // Array with ranks for which the player has books.
        int n_books;
    public:
        Player(); //Default Constructor
        Player(int);
        int getNumOfBooks();
        void setNumOfBooks();
        void createBook();
        ~Player(); //destructor 
        Player (const Player &); //copy constructor
        Player& operator=(const Player &); //assignment operator overload

};

#endif