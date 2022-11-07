#include <iostream>
#include "deck.h"
#include "player.h"
#ifndef GAME
#define GAME

using namespace std;

class Game {
    private:
        Deck d; //deck object
        Player players[2]; //two player objects are created
    public:
    Game(); // Default game constructor
    void startGame(bool, bool); //runs both players turns
    void gameOver(); // Tells user which player is the winner
    string validateCardSelection(); //Tells user if the card they ask for is valid or not
    bool playersTurn();
    bool computersTurn(bool);
    string generateCardSelection(bool);
};

int rankConverter(string);

#endif