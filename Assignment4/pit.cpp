#include <iostream>
#include <string>
#include "pit.h"

using namespace std;


/*********************************************************************
** Function: display2
** Description: Shows precept message when player is near room
** Parameters: Reference to player
** Pre-Conditions: Player is next to the room
** Post-Conditions: message is output
*********************************************************************/ 
void Pit::display2(Player& player){
    cout <<  "You feel a breeze." << endl;
}

/*********************************************************************
** Function: display
** Description: Runs event when player is in the room
** Parameters:  reference to player
** Pre-Conditions: Player is in the same room as event
** Post-Conditions: Player dies
*********************************************************************/ 
void Pit::display(Player& player){
    cout << "You fell into a bottomless pit and died" << endl;
    //Ends the game
    this->gameOver = true;
}

/*********************************************************************
** Function: checkHealth
** Description: Checks if the player is still alive
** Parameters: none
** Pre-Conditions: 
** Post-Conditions: game ends or continues
*********************************************************************/ 
bool Pit::checkHealth(){
    return this->gameOver;
}