#include <iostream>
#include <string>
#include "event.h"

/*********************************************************************
** Function: Default event constructor
** Description: Default values for event class
** Parameters: None
** Pre-Conditions: Event onject is created
** Post-Conditions: object values are set
*********************************************************************/ 
Event::Event(){
    this->gameOver = false;
    this->wumpusDead = false;
    this->roomLocX = 0;
    this->roomLocY = 0;
}

/*********************************************************************
** Function: encounter
** Description: Virtual function that runs event when player is in the same room
** Parameters:  Reference to player, event pointer
** Pre-Conditions: Player is in same room as event
** Post-Conditions: Display function will run
*********************************************************************/ 
void Event::encounter(Player& player, Event* ptr){
    if (player.getLocX() == this->roomLocX and player.getLocY() == this->roomLocY){
        //conditional checks if the player is in the same room
        ptr->display(player);
    }
}

/*********************************************************************
** Function: Percept
** Description: Virtual function that output's a message when player is near the event room
** Parameters: Reference to player, event pointer
** Pre-Conditions: Player is next to the room with the event
** Post-Conditions: Display2 function will run
*********************************************************************/ 
void Event::percept(Player& player, Event* ptr){
    if (((player.getLocX() == ((this->roomLocX) + 1) or player.getLocX() == ((this->roomLocX) - 1)) and player.getLocY() == (this->roomLocY)) or
        (player.getLocX() == (this->roomLocX) and (player.getLocY() == ((this->roomLocY) + 1) or player.getLocY() == ((this->roomLocY) - 1)))){
            // Conditional checks if the player is next to the room
            ptr->display2(player);
    }
}

/*********************************************************************
** Function: setRoomLoc
** Description: Sets the location of the event room
** Parameters: newRoomLocX, newRoomLocY
** Pre-Conditions: event object exists
** Post-Conditions: event location will change
*********************************************************************/ 
void Event::setRoomLoc(int newRoomLocX, int newRoomLocY){
    this->roomLocX = newRoomLocX;
    this->roomLocY = newRoomLocY;
}

/*********************************************************************
** Function: getRoomLocX
** Description: Gets the x coordinate of the event room
** Parameters: none
** Pre-Conditions:event object exists
** Post-Conditions: x coordinate is returned
*********************************************************************/ 
int Event::getRoomLocX(){
    return this->roomLocX;
}

/*********************************************************************
** Function: getRoomLocY
** Description: Gets the y coordinate of the event room
** Parameters: None
** Pre-Conditions: Event object exists
** Post-Conditions: y  coordinate is returned
*********************************************************************/ 
int Event::getRoomLocY(){
    return this->roomLocY;
}

/*********************************************************************
** Function: checkHealth
** Description: Returns boolean whether game is over or not
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: returns true or false
*********************************************************************/ 
bool Event::checkHealth(){
    return this->gameOver;
}

/*********************************************************************
** Function: checkWumpus
** Description: Returns boolean whether wumpus is dead or not
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: returns true or false
*********************************************************************/ 
bool Event::checkWumpus(){
    return this->wumpusDead;
}