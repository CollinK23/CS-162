#include <iostream>
#include <string>
#include "event.h"

Event::Event(){
    this->gameOver = false;
    this->roomLocX = 0;
    this->roomLocY = 0;
}

void Event::encounter(Player& player, Event* ptr){
    if (player.getLocX() == this->roomLocX and player.getLocY() == this->roomLocY){
        ptr->display(player);
    }
}


void Event::percept(Player& player, Event* ptr){
    if (((player.getLocX() == ((this->roomLocX) + 1) or player.getLocX() == ((this->roomLocX) - 1)) and player.getLocY() == (this->roomLocY)) or
        (player.getLocX() == (this->roomLocX) and (player.getLocY() == ((this->roomLocY) + 1) or player.getLocY() == ((this->roomLocY) - 1)))){
            ptr->display2(player);
    }
}

void Event::setRoomLoc(int newRoomLocX, int newRoomLocY){
    this->roomLocX = newRoomLocX;
    this->roomLocY = newRoomLocY;
}

int Event::getRoomLocX(){
    return this->roomLocX;
}

int Event::getRoomLocY(){
    return this->roomLocY;
}

bool Event::checkHealth(){
    return this->gameOver;
}