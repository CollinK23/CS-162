#include <iostream>
#include <string>
#include "bats.h"

#include<cstdlib>
#include<iomanip>
#include<ctime>

using namespace std;

void Bats::display2(Player& player){
    cout <<  "You hear wings flapping." << endl;
}

void Bats::display(Player& player){
    cout << "A Bat Has Taken You To A New Room" << endl;
    player.setLocX(rand()%player.getBoardSize());
    player.setLocY(rand()%player.getBoardSize());
}