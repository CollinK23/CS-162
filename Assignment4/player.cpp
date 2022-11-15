#include <iostream>
#include <string>
#include "player.h"

using namespace std;

Player::Player(){
    this->arrows = 3;
    this->playerLocationX = 0;
    this->playerLocationY = 0;
    this->boardSize = 0;
    this->goldCollected = false;
}

void Player::setBoardSize(int newBoardSize){
    this->boardSize = newBoardSize;
}

void Player::setGoldColl(bool goldPickedUp){
    this->goldCollected = goldPickedUp;
}

int Player::getBoardSize(){
    return this->boardSize;
}

void Player::setLocX(int newX){
    this->playerLocationX = newX;
}

void Player::setLocY(int newY){
    this->playerLocationY = newY;
}

int Player::getLocX(){
    return this->playerLocationX;
}

int Player::getLocY(){
    return this->playerLocationY;
}

int Player::getArrows(){
    return this->arrows;
}

bool Player::getGoldColl(){
    return this->goldCollected;
}

void Player::useArrow(){
    this->arrows -= 1;
}




void Player::moveUp(){
    this->playerLocationY -= 1;
}

void Player::moveDown(){
    this->playerLocationY += 1;
}

void Player::moveLeft(){
    this->playerLocationX -= 1;
}

void Player::moveRight(){
    this->playerLocationX += 1;
}