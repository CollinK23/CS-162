#include <iostream>
#include <string>
#include "start.h"

using namespace std;

void Start::display(Player& player){
    if (player.getGoldColl() == true){
        cout << "You Left The Cave" << endl;
        this->gameOver = true;
    }
}

bool Start::checkHealth(){
    return this->gameOver;
}