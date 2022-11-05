#include <iostream>
#include "hand.h"
#include "player.h"
#include <string>

using namespace std;

int Player::getNumOfBooks(){
    return this->n_books;
}

Player::Player(){
    this->n_books = 0;
    this->books = 0;
}

Player::Player (int size) {
    this->n_books = size;
    this->books = new int [size];
}

//Destructor
Player::~Player(){
    cout << "destructr is called " << endl;
    if (this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }
}

//Assignment Operator Overload
Player& Player::operator=(const Player &p){
    cout << "inside our AOO..." << endl;
    this->n_books = p.n_books;

    if (this->books != NULL){
        delete [] this->books;
    }

    this->books = new int[this->n_books];
    for (int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }

    return *this;
}


//Copy Constructor
Player::Player (const Player &p){
    cout << "inside our CC..." << endl;
    this->n_books = p.n_books;

    this->books = new int[this->n_books];
    for (int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }
}

