#include <iostream>
#include "gofish.h"
#include <string>
#include<cstdlib>
#include<iomanip>
#include<ctime>

using namespace std;


//----------------------------------------------------------- CARD FUNCTIONS ----------------------------------------------------------


Card::Card(){
    this->rank = -1;
    this->suit = -1;
}
Card::Card(int new_suit, int new_rank){
    this->rank = new_rank;
    this->suit = new_suit;
}

int Card::get_suit(){
    return this->suit;
}

int Card::get_rank(){
    return this->rank;
}

void Card::set_rank(int new_rank){
    this->rank = new_rank;
}

void Card::set_suit(int new_suit){
    this ->suit = new_suit;
}

string Card::map_rank(int rank){
    if (rank == 0){
        return "A";
    }else if (rank == 12){
        return "K";
    }else if (rank == 11){
        return "Q";
    }else if (rank == 10){
        return "J";
    }else{
        return to_string(rank + 1);
    }
}

string Card::map_suit(int suit){
    if (suit == 0){
        return " Hearts";
    }else if (suit == 1){
        return " Spades";
    }else if (suit == 2){
        return " Clovers";
    }else if (suit == 3){
        return " Diamonds";
    }
}

void Card::print_card(){

}


//---------------------------------------------------------------- DECK FUNCTIONS -----------------------------------------------------------------

Deck::Deck(){
    this->n_cards = 52;
}

Deck::Deck(int totalCards){
    this->n_cards = totalCards;
}

void Deck::fillDeck(){
    int k = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 13; j++){
            cards[k].set_suit(i);
            cards[k].set_rank(j);
            k++;
        }
    } 
} 

void Deck::shuffleDeck(){
    srand(time(NULL));
    int j, k;

    for (int i = 0; i < 100 + rand()%52; i++){
        j = rand()%52;
        k = rand()%52;
        Card temp_card = cards[j];
        cards[j] = cards[k];
        cards[k] = cards[j];
    }

    int l = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 13; j++){
            cout << cards[l].map_rank(cards[l].get_rank()) << " of " << cards[l].map_suit(cards[l].get_suit()) << endl << endl;
            l++;
        }
    } 
}

void Deck::removeCard(){
    this->n_cards = n_cards - 1;
}

int Deck::get_n_cards(){
    return this->n_cards;
}

