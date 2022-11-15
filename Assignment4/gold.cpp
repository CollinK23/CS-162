#include <iostream>
#include <string>
#include "gold.h"

using namespace std;


void Gold::display2(Player& player){
    cout << "You see a glimmer nearby." << endl;
}

void Gold::display(Player& player){
    cout << "You Picked up the Gold" << endl;
    player.setGoldColl(true);
}