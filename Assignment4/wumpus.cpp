#include <iostream>
#include <string>
#include "wumpus.h"

using namespace std;

void Wumpus::display2(Player& player){
    cout <<  "You Smell a Terrible Stench." << endl;
}

void Wumpus::display(Player& player){
    cout << "You Were Eaten by the Wumpus" << endl;
    this->gameOver = true;
}

bool Wumpus::checkHealth(){
    return this->gameOver;
}