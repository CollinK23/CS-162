#include <iostream>
#include "deck.h"
#include <string>
#include<cstdlib>
#include<iomanip>
#include<ctime>

using namespace std;

//---------------------------------------------------------------- DECK FUNCTIONS -----------------------------------------------------------------

/*********************************************************************
** Function: Default deck constructor
** Description: Sets the size of the deck to 51
** Parameters: none
** Pre-Conditions: A deck object is created
** Post-Conditions: The size of the deck object is set to 51
*********************************************************************/
Deck::Deck(){
    this->n_cards = 51;
}

/*********************************************************************
** Function:  Deck Constructor
** Description: Sets the size of the deck
** Parameters:  totalCards
** Pre-Conditions: A deck object is created with a given deck size
** Post-Conditions: 
*********************************************************************/
Deck::Deck(int totalCards){
    this->n_cards = totalCards;
}

/*********************************************************************
** Function: fill_deck
** Description: Creates a deck with 52 cards
** Parameters: None
** Pre-Conditions: Deck object is initialized with 51 total cards
** Post-Conditions: All cards in the deck object are unique
*********************************************************************/
void Deck::fillDeck(){
    //Used to track the index of the card that's values are being created
    int k = 0;
    //For loop iterates 4 times for the 4 different suits
    for (int i = 0; i < 4; i++){
        //For loop iterates 13 times for the 13 different ranks
        for (int j = 0; j < 13; j++){
            cards[k].set_suit(i);
            cards[k].set_rank(j);
            k++;
        }
    } 
} 

/*********************************************************************
** Function: shuffle_deck
** Description: Shuffles the cards in the deck
** Parameters: None
** Pre-Conditions: The deck is already filled with cards
** Post-Conditions: The order of the cards is randomized
*********************************************************************/
void Deck::shuffleDeck(){
    srand(time(NULL));
    //Sets random values for j and k, which are the indices thare being swapped
    int j, k;

    //For loop that shuffles two cards a random number of times
    for (int i = 0; i < 100 + rand()%52; i++){
        j = rand()%52;
        k = rand()%52;

        //Swaps the values of two card objects
        Card temp_card = cards[j];
        cards[j] = cards[k];
        cards[k] = temp_card;
    }
}

/*********************************************************************
** Function: removeCard
** Description: Removes the top card from the deck
** Parameters: None
** Pre-Conditions: Deck object is created
** Post-Conditions: Removes one card
*********************************************************************/
void Deck::removeCard(){
    this->n_cards = n_cards - 1;

}

/*********************************************************************
** Function: get_n_cards
** Description: Returns the number of cards remaining in the deck
** Parameters: None
** Pre-Conditions: Deck object is created
** Post-Conditions: Returns number of card remaining in the deck
*********************************************************************/
int Deck::get_n_cards(){
    //Add one to total cards because index starts at 0
    return this->n_cards + 1;
}

/*********************************************************************
** Function: getCardRank
** Description: Gets the rank of the first card in the deck
** Parameters: None
** Pre-Conditions: Deck object is created
** Post-Conditions: Returns the rank of the first card
*********************************************************************/
int Deck::getCardRank(){
    //n_cards is the first card in the deck
    return cards[this->n_cards].get_rank();
}

/*********************************************************************
** Function: getCardSuit
** Description: Gets the suit of the first card in the deck
** Parameters: None
** Pre-Conditions: Deck object is created
** Post-Conditions: Returns the suit of the first card
*********************************************************************/
int Deck::getCardSuit(){
    return cards[this->n_cards].get_suit();
}

/*********************************************************************
** Function: printCard
** Description: Prints the first card in the deck
** Parameters: None
** Pre-Conditions: Deck object is created
** Post-Conditions: 
*********************************************************************/
void Deck::printCard(){
    cards[this->n_cards].print_card();
}
