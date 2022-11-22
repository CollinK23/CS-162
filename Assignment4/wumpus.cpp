#include <iostream>
#include <string>

#include "wumpus.h"

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
void Wumpus::display2(Player& player){
    cout <<  "You Smell a Terrible Stench." << endl;
}

/*********************************************************************
** Function: display
** Description: Runs event when player is in the room
** Parameters:  reference to player
** Pre-Conditions: Player is in the same room as event
** Post-Conditions: Player dies
*********************************************************************/ 
void Wumpus::display(Player& player){
    //Runs if the player enters the room without killing the wumpus
    if (not this->wumpusDead){
        cout << "You Were Eaten by the Wumpus" << endl;
        this->gameOver = true;
    }
}

/*********************************************************************
** Function: display2
** Description: Shows precept message when player is near room
** Parameters: Reference to player
** Pre-Conditions: Player is next to the room
** Post-Conditions: message is output
*********************************************************************/ 
bool Wumpus::checkHealth(){
    return this->gameOver;
}

/*********************************************************************
** Function: killWumpus
** Description: kills the wumpus
** Parameters: none
** Pre-Conditions: Player hits the wumpus with an arrow
** Post-Conditions: Wumpus is dead
*********************************************************************/ 
void Wumpus::killWumpus(){
    this->wumpusDead = true;
}

/*********************************************************************
** Function: shootleft
** Description: Shoots an arrow to the left
** Parameters: reference to player
** Pre-Conditions: Player decides to shoot an arrow
** Post-Conditions: wumpus moves or dies
*********************************************************************/ 
void Wumpus::shootLeft(Player& player){
    //arrow only travels three rooms to the left
    if ((this->roomLocY == player.getLocY()) and ((player.getLocX() - 3) <= this->roomLocX < player.getLocX())){
        if(this->wumpusDead){
            cout << "You Already Killed The Wumpus" << endl;
        }else{
            cout << "You Killed The Wumpus" << endl;
            //sets wumpus to dead in each class
            killWumpus();
            player.killWumpus();
        }
    }else{
        cout << "You Missed" << endl;
    }
}

/*********************************************************************
** Function: shootRight
** Description: Shoots an arrow to the right
** Parameters: reference to player
** Pre-Conditions: Player decides to shoot an arrow
** Post-Conditions: wumpus moves or dies
*********************************************************************/ 
void Wumpus::shootRight(Player& player){
    //arrow only travels three rooms to the right
    if ((this->roomLocY == player.getLocY()) and ((player.getLocX() + 4) > (this->roomLocX) > player.getLocX())){
        if(this->wumpusDead){
            cout << "You Already Killed The Wumpus" << endl;
        }else{
            cout << "You Killed The Wumpus" << endl;
            //sets wumpus to dead in each class
            killWumpus();
            player.killWumpus();
        }
    }else{
        cout << "You Missed" << endl;
    }
}

/*********************************************************************
** Function: shootUp
** Description: Shoots an arrow upwards
** Parameters: reference to player
** Pre-Conditions: Player decides to shoot an arrow
** Post-Conditions: wumpus moves or dies
*********************************************************************/ 
void Wumpus::shootUp(Player& player){
    //arrow only travels three rooms up
    if (((player.getLocY() - 3) <= this->roomLocY < player.getLocY()) and (this->roomLocX == player.getLocX())){
        if(this->wumpusDead){
            cout << "You Already Killed The Wumpus" << endl;
        }else{
            cout << "You Killed The Wumpus" << endl;
            //sets wumpus to dead in each class
            killWumpus();
            player.killWumpus();
        }
    }else{
        cout << "You Missed" << endl;
    }
}

/*********************************************************************
** Function: shootDown
** Description: Shoots an arrow downwards
** Parameters: reference to player
** Pre-Conditions: Player decides to shoot an arrow
** Post-Conditions: wumpus moves or dies
*********************************************************************/ 
void Wumpus::shootDown(Player& player){
    //arrow only travels three rooms down
    if (this->roomLocX == player.getLocX() and (player.getLocY() < (this->roomLocY) < (player.getLocY() + 4))){
        if(this->wumpusDead){
            cout << "You Already Killed The Wumpus" << endl;
        }else{
            cout << "You Killed The Wumpus" << endl;
            //sets wumpus to dead in each class
            killWumpus();
            player.killWumpus();
        }
    }else{
        cout << "You Missed" << endl;
    }
}

/*********************************************************************
** Function: useArrow
** Description: Player chooses the direction they want to shoot the arrow
** Parameters: reference to player
** Pre-Conditions: Player selected to shoot an arrow
** Post-Conditions: returns whether wumpus is dead or not
*********************************************************************/ 
bool Wumpus::useArrow(Player& player){
    //Player gets told a message if they have no arrows remaining
    if (player.getArrows() == 0){
        cout << "You Have No More Arrows" << endl;
        return true;
    }else{
        char c;

        //removes an arrow from player class
        player.removeArrow();
        cout << "Choose Direction To Shoot Arrow: " << endl;
        cin >> c;

        if (c == 'w'){
            shootUp(player);
        }else if (c == 'a'){
            shootLeft(player);
        }else if(c == 's'){
            shootDown(player);
        }else if(c == 'd'){
            shootRight(player);
        }
        //tells user the number of arrows they have left
        cout << "Arrows Remaining: " << player.getArrows() << endl;
    }

    return this->wumpusDead;
}