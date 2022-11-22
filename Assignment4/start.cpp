#include <iostream>
#include <string>
#include "start.h"

using namespace std;

/*********************************************************************
** Function: display
** Description: Runs event when player is in the room
** Parameters:  reference to player
** Pre-Conditions: Player is in the same room as event
** Post-Conditions: Player leaves or nothing happens
*********************************************************************/ 
void Start::display(Player& player){
    //only runs if player killed wumpus and picked up gold
    if (player.getWumpus() == true and player.getGoldColl() == true){
        cout << "You Left The Cave With The Gold" << endl;
        this->gameOver = true;
    }
}

/*********************************************************************
** Function: checkHealth
** Description: Checks if the player is still alive
** Parameters: none
** Pre-Conditions: 
** Post-Conditions: game ends or continues
*********************************************************************/ 
bool Start::checkHealth(){
    return this->gameOver;
}