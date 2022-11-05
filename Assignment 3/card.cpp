#include <iostream>
#include "card.h"
#include <string>


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
    this->suit = new_suit;
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
        return " ♥";
    }else if (suit == 1){
        return " ♠";
    }else if (suit == 2){
        return " ☘";
    }else if (suit == 3){
        return " ◆";
    }
}

void Card::print_card(){
    cout << " | " << map_rank(this->get_rank()) << " of " << map_suit(this->get_suit()) << " | ";
}