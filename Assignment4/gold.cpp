#include <iostream>
#include <string>
#include "gold.h"

using namespace std;

/*********************************************************************
** Function: display2
** Description: Shows precept message when player is near room
** Parameters: Reference to player
** Pre-Conditions: Player is next to the room
** Post-Conditions: message is output
*********************************************************************/  
void Gold::display2(Player& player){
    cout << "You see a glimmer nearby." << endl;
}

/*********************************************************************
** Function: display
** Description: Runs event when player is in the room
** Parameters:  reference to player
** Pre-Conditions: Player is in the same room as event
** Post-Conditions: Player picks up the gold
*********************************************************************/ 
void Gold::display(Player& player){
    cout << "You Picked up the Gold" << endl;
    //Player object gets gold
    player.setGoldColl(true);
}