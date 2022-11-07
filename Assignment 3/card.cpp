#include <iostream>
#include "card.h"
#include <string>


using namespace std;


//----------------------------------------------------------- CARD FUNCTIONS ----------------------------------------------------------


/*********************************************************************
** Function: default card constructor
** Description: Default class values for card object
** Parameters: None
** Pre-Conditions: card object is created
** Post-Conditions: The rank and suit are given placeholder values
*********************************************************************/
Card::Card(){
    this->rank = -1;        //Sets the objects rank
    this->suit = -1;        //Sets the objects suit
}

/*********************************************************************
** Function: card constructor
** Description: Creates rank and suit values for card object
** Parameters: new_suit, new_rank
** Pre-Conditions: Card object is given values for its rank and suit
** Post-Conditions: The rank and suit values are given to the card object
*********************************************************************/
Card::Card(int new_suit, int new_rank){
    this->rank = new_rank;      //Sets the objects rank
    this->suit = new_suit;      // Sets the objects suit
}

/*********************************************************************
** Function: set_rank
** Description: Sets the rank of the card object
** Parameters: new_rank
** Pre-Conditions: Card object is already created
** Post-Conditions: The rank of the object will be updated
*********************************************************************/
void Card::set_rank(int new_rank){
    this->rank = new_rank;        // Sets the objects rank
}

/*********************************************************************
** Function: set_suit
** Description: Sets the suit of the card object
** Parameters: new_suit
** Pre-Conditions: Card object is already created
** Post-Conditions: The suit of the object will be updated
*********************************************************************/
void Card::set_suit(int new_suit){
    this->suit = new_suit;        // Sets the objects suit
}

/*********************************************************************
** Function: get_suit
** Description: Gets the suit of the card object
** Parameters: None
** Pre-Conditions: Card object is already created
** Post-Conditions: The suit of the object will be returned as an integer
*********************************************************************/
int Card::get_suit(){
    return this->suit;          // Gets the objects suit
}

/*********************************************************************
** Function: get_rank
** Description: Gets the rank of the card object
** Parameters: None
** Pre-Conditions: Card object is already created
** Post-Conditions: The rank of the object will be returned as an integer
*********************************************************************/
int Card::get_rank(){
    return this->rank;          // Gets the objects rank
}

/*********************************************************************
** Function: map_rank
** Description: Turns the object's rank into its corresponding card value
** Parameters: rank
** Pre-Conditions: Rank of object is already set
** Post-Conditions: Rank of the object will be mapped to a card value
*********************************************************************/
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
        return to_string(rank + 1);     //Adds one to rank because rank starts at 0
    }
}

/*********************************************************************
** Function: map_suit
** Description: Turns the object's suit into its corresponding suit value
** Parameters: suit
** Pre-Conditions: Suit of the object is already set
** Post-Conditions: Suit of the object will be mapped to the object
*********************************************************************/
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

/*********************************************************************
** Function: print_card
** Description: Prints the objects rank and suit
** Parameters: None
** Pre-Conditions: Card object is created
** Post-Conditions: Card will be output
*********************************************************************/
void Card::print_card(){
    cout << " [" << map_rank(this->get_rank()) << " " << map_suit(this->get_suit()) << "] ";
}