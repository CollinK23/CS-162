#include <iostream>
#include <string>
#include "bats.h"

#include<cstdlib>
#include<iomanip>
#include<ctime>

using namespace std;


/*********************************************************************
** Function: display2
** Description: Shows precept message when player is near room
** Parameters: Reference to player
** Pre-Conditions: Player is next to the room
** Post-Conditions: message is output
*********************************************************************/ 
void Bats::display2(Player& player){
    cout <<  "You hear wings flapping." << endl;
}


/*********************************************************************
** Function: display
** Description: Runs event when player is in the room
** Parameters:  reference to player
** Pre-Conditions: Player is in the same room as event
** Post-Conditions: Player is taken to new room
*********************************************************************/ 
void Bats::display(Player& player){
    cout << "A Bat Has Taken You To A New Room" << endl;
    //Sets player location to a random room
    player.setLocX(rand()%player.getBoardSize());
    player.setLocY(rand()%player.getBoardSize());
}