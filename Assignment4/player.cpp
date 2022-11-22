#include <iostream>
#include <string>
#include "player.h"

using namespace std;

/*********************************************************************
** Function: Default player constructor
** Description: Default values for new player object
** Parameters: None
** Pre-Conditions: Player object is created
** Post-Conditions: Object values are set
*********************************************************************/ 
Player::Player(){
    this->arrows = 3;
    this->playerLocationX = 0;
    this->playerLocationY = 0;
    this->boardSize = 0;
    this->goldCollected = false;
    this->killedWump = false;
}

/*********************************************************************
** Function: setBoardSize
** Description: Sets the board size in the player class
** Parameters: newBoardSize
** Pre-Conditions:
** Post-Conditions: object boardSize is updated
*********************************************************************/ 
void Player::setBoardSize(int newBoardSize){
    this->boardSize = newBoardSize;
}

/*********************************************************************
** Function: setGoldColl
** Description: Sets whether player has gold or not
** Parameters: goldPickedUp
** Pre-Conditions: 
** Post-Conditions: 
*********************************************************************/ 
void Player::setGoldColl(bool goldPickedUp){
    this->goldCollected = goldPickedUp;
}

/*********************************************************************
** Function: getBoardSize
** Description: Returns the size of the board
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the size of the board
*********************************************************************/ 
int Player::getBoardSize(){
    return this->boardSize;
}

/*********************************************************************
** Function: setLocX
** Description: Sets the x coordinate of the player
** Parameters: newX
** Pre-Conditions: None
** Post-Conditions: Player location is updated
*********************************************************************/ 
void Player::setLocX(int newX){
    this->playerLocationX = newX;
}

/*********************************************************************
** Function: setLocY
** Description: Sets the y coordinate of the player
** Parameters: newY
** Pre-Conditions: None
** Post-Conditions: Player location is updated
*********************************************************************/ 
void Player::setLocY(int newY){
    this->playerLocationY = newY;
}

/*********************************************************************
** Function: removeArrow
** Description: Removes an arrow when player uses one
** Parameters: none
** Pre-Conditions: Player decides to shoot an arrow
** Post-Conditions: Player has one less arrow
*********************************************************************/ 
void Player::removeArrow(){
    this->arrows -= 1;
}

/*********************************************************************
** Function: getLocX
** Description: gets the x coordinate of the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the x coordinate of the player
*********************************************************************/ 
int Player::getLocX(){
    return this->playerLocationX;
}

/*********************************************************************
** Function:  getLocY
** Description: Gets the y coordinate of the player
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Returns the y coordinate of the player
*********************************************************************/ 
int Player::getLocY(){
    return this->playerLocationY;
}

/*********************************************************************
** Function: getArrows
** Description: Gets the total number of arrows the player has remaining
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns number of arrows
*********************************************************************/ 
int Player::getArrows(){
    return this->arrows;
}

/*********************************************************************
** Function: getGoldColl
** Description: Returns true or false whether player has the gold or not
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Returns true or false
*********************************************************************/ 
bool Player::getGoldColl(){
    return this->goldCollected;
}

/*********************************************************************
** Function: moveUp
** Description: Moves the player up
** Parameters: none
** Pre-Conditions: player chooses to move up
** Post-Conditions:
*********************************************************************/ 
void Player::moveUp(){
    this->playerLocationY -= 1;
}

/*********************************************************************
** Function: moveDown
** Description: moves the player down
** Parameters: none
** Pre-Conditions: Player chooses to move down
** Post-Conditions:
*********************************************************************/ 
void Player::moveDown(){
    this->playerLocationY += 1;
}

/*********************************************************************
** Function: moveLeft
** Description: moves the player left
** Parameters: none
** Pre-Conditions: Player chooses to move left
** Post-Conditions:
*********************************************************************/ 
void Player::moveLeft(){
    this->playerLocationX -= 1;
}

/*********************************************************************
** Function: moveRight
** Description:Moves the player right
** Parameters: none
** Pre-Conditions: Player chooses to move right
** Post-Conditions:
*********************************************************************/ 
void Player::moveRight(){
    this->playerLocationX += 1;
}

/*********************************************************************
** Function: killWumpus
** Description: kills the wumpus
** Parameters: none
** Pre-Conditions: player hits wumpus with arrow
** Post-Conditions: wumpus is dead
*********************************************************************/ 
void Player::killWumpus(){
    this->killedWump = true;
}

/*********************************************************************
** Function: getWumpus
** Description: Returns true or false whether wumpus is dead or not
** Parameters: none
** Pre-Conditions:none
** Post-Conditions: returns true or false
*********************************************************************/ 
bool Player::getWumpus(){
    return this->killedWump;
}