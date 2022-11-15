#include <iostream>
#include <string>
#include "pit.h"

using namespace std;

void Pit::display2(Player& player){
    cout <<  "You feel a breeze." << endl;
}

void Pit::display(Player& player){
    cout << "You fell into a bottomless pit and died" << endl;
    this->gameOver = true;
}

bool Pit::checkHealth(){
    return this->gameOver;
}