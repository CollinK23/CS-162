#include <iostream>
#include <string>
#include "event.h"

Event::Event() : roomName("Empty Room"){
    this->playerVisited = false;
    this->gameOver = false;
    this->roomType = 0;
}

Event::Event(string newName, int roomType) : roomName(newName){
    this->playerVisited = false;
    this->gameOver = false;
    this->roomType = roomType;
}

void Event::encounter(){
    cout << "The room is Empty" << endl;
}


void Event::percept(){

}