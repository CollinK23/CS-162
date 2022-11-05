#include <iostream>
#include "hand.h"
#include "card.h"
#include <string>

using namespace std;

Hand::Hand(){
    this->n_cards = 7;
    this->cards = new Card[7];
}

Card* Hand::get_cards(){
    return this->cards;
}

int Hand::getCardsInHand(){
    return this-> n_cards;
}

void Hand::addCardInHand(){
    this->n_cards = n_cards + 1;
    //handSize(this->n_cards);
    //cards[this->n_cards - 1].set_rank(deck.getCardRank());
    //cards[this->n_cards - 1].set_suit(deck.getCardSuit());
    //deck.removeCard();
}

void Hand::removeCardInHand(){
    this->n_cards = n_cards - 1;
}

void Hand::setCardsInHand(Deck &deck){
    for (int i = 0; i < 7; i++){
        cards[i].set_rank(deck.getCardRank());
        cards[i].set_suit(deck.getCardSuit());
        deck.removeCard();
    }
}

void Hand::printCardsInHand(){
    cout << "Cards in Hand: " << endl;
    for (int i = 0; i < this->n_cards; i++){
        cards[i].print_card();
    }
    cout << endl << endl;
}

//Destructor
/*Hand::~Hand(){

    if (this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }
}

//Assignment Operator Overload
Hand& Hand::operator=(const Hand &h){
    
    this->n_cards = h.n_cards;

    if (this->cards != NULL){
        delete [] this->cards;
    }

    this->cards = new Card[this->n_cards];
    for (int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }

    return *this;
}


//Copy Constructor
Hand::Hand (const Hand &h){
    cout << "inside our CC..." << endl;
    this->n_cards = h.n_cards;

    this->cards = new Card[this->n_cards];
    for (int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }
}*/

/*void Hand::setCardsInHand(){
    this->n_cards = 7;
}*/