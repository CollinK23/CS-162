#include <iostream>
#include "hand.h"
#include "card.h"
#include <string>

using namespace std;

/*********************************************************************
** Function: Default hand constructor
** Description: Creates the default hand for a player
** Parameters: None
** Pre-Conditions: Hand object is created
** Post-Conditions: dynamic array is created for the hand object
*********************************************************************/
Hand::Hand(){
    this->n_cards = 7;
    this->cards = new Card[7];
}

/*********************************************************************
** Function: Hand constructor
** Description: Creates the hand for a player
** Parameters: Number of starting cards in hand
** Pre-Conditions: Hand object is created
** Post-Conditions: dynamic array is created for the hand object
*********************************************************************/
Hand::Hand(int newNumCards){
    this->n_cards = newNumCards;
    this->cards = new Card[newNumCards];
}

//Destructor
/*********************************************************************
** Function: Hand destructor
** Description: Frees memory when object goes out of scope
** Parameters: None
** Pre-Conditions: Hand object is created
** Post-Conditions: Memory is freed
*********************************************************************/
Hand::~Hand(){

    if (this->cards != NULL){
        //Deletes cards in hand
        delete [] this->cards;
        this->cards = NULL;
    }
}

//Assignment Operator Overload
/*********************************************************************
** Function: Assignment Operator Overload
** Description: Copies one objects values to another
** Parameters: Hand object
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
Hand& Hand::operator=(const Hand &h){
    this->n_cards = h.n_cards;

    //Free Memory
    if (this->cards != NULL){
        delete [] this->cards;
    }

    //Deep copy
    this->cards = new Card[this->n_cards];
    for (int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }

    return *this;
}


//Copy Constructor
/*********************************************************************
** Function: Copy constructor
** Description: Copies values of hand object into a new hand object
** Parameters: new hand object
** Pre-Conditions: Hand object is already created
** Post-Conditions: Deep copy is created
*********************************************************************/
Hand::Hand (const Hand &h){
    this->n_cards = h.n_cards;

    //Deep copy
    this->cards = new Card[this->n_cards];
    for (int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }
}

/*********************************************************************
** Function: get_cards
** Description: Returns the array of cards in hand
** Parameters: None
** Pre-Conditions: Cards have been given to hand
** Post-Conditions:
*********************************************************************/
Card* Hand::get_cards(){
    return this->cards;
}

/*********************************************************************
** Function: getCardsInHand
** Description: Returns the total number of cards in hand
** Parameters: None
** Pre-Conditions: Hand object is created
** Post-Conditions:
*********************************************************************/
int Hand::getCardsInHand(){
    return this-> n_cards;
}

/*********************************************************************
** Function: goFish
** Description: Player draws a card from the deck
** Parameters: reference to deck, reference to hand, rank of card
** Pre-Conditions: Deck and hand objects are created, card is asked for
** Post-Conditions: Returns true or false if the rank that they ask for matches the one on the card that they drew
*********************************************************************/
bool Hand::goFish(Deck & deck, Hand& hand, int rank){
    bool cont = false;
    //Increases size of hand array
    this->n_cards = n_cards + 1;
    //Creates new hand object 
    Hand tempHand(n_cards);
    //Uses copy constructor to copy values to new object
    tempHand = hand;
    //Uses copy constructor to set hand equal to the new object
    hand = tempHand;

    //Sets rank and suit for the new card in hand
    cards[this->n_cards - 1].set_rank(deck.getCardRank());
    cards[this->n_cards - 1].set_suit(deck.getCardSuit());

    //Rank of card that was drawn, matches the card that was asked for
    if (deck.getCardRank() == rank){
        //Player gets another turn
        cont = true;
    }
    //Removes card from the deck
    deck.removeCard();
    return cont;
}

/*********************************************************************
** Function: addCardInHand
** Description:adds a card into the players hand
** Parameters: reference to hand, rank, suit
** Pre-Conditions: A card has been selected to add to the players hand
** Post-Conditions: Card will be added to players hand array
*********************************************************************/
void Hand::addCardInHand(Hand& hand, int rank, int suit){
    //Increases size of array by one
    this->n_cards = n_cards + 1;
    //Creates temporary hand object
    Hand tempHand2(n_cards);
    tempHand2 = hand;
    //Increases size of hand by one
    hand = tempHand2;

    //Sets the rank and suit of the new card in the hand
    cards[this->n_cards - 1].set_rank(rank);
    cards[this->n_cards - 1].set_suit(suit);

}


/*********************************************************************
** Function: removeCardInHand
** Description: Removes a card from the hand
** Parameters: rank that is being removed from hand. reference to hand, cardSuit array
** Pre-Conditions: The rank of the card that is being removed must be selected
** Post-Conditions: the cards with the same rank will be removed from the hand array
*********************************************************************/ 
int Hand::removeCardInHand(int rankRemoved, Hand& hand, int cardSuit[]){
    int count = 0;
    //Number of cards with the same rank in the players hand
    int numOfDupes = 0;
    int j = 0;
    //Creates a temporary hand that sorts the hand array based on rank
    Hand tempHand(this->n_cards);
    for (int i = 0; i < this->n_cards; i++){
        //Cards that aren't selected are moved to front of the temporary hand
        if (cards[i].get_rank() != rankRemoved){
            tempHand.cards[count] = cards[i];
            count++;
        }
    }
    for (int i = 0; i < this->n_cards; i++){
        //Cards that are selected are moved to the back of the temporary hand
        if (cards[i].get_rank() == rankRemoved){
            tempHand.cards[count] = cards[i];
            cardSuit[j] = cards[i].get_suit();
            j++;
            numOfDupes++;
        }
    }
    //Changes the length of the tempHand array to remove selected cards at the back
    tempHand.n_cards = tempHand.n_cards - numOfDupes;
    //hand array is updated to remove the selected card
    hand = tempHand;

    return numOfDupes;


}

/*********************************************************************
** Function: setCardsInHand
** Description: Gives each player 7 cards to start the game
** Parameters: reference to the deck object
** Pre-Conditions: number of cards in hand constructor is equal to 7
** Post-Conditions: Player will have 7 cards in hand, deck will have 7 less cards
*********************************************************************/ 
void Hand::setCardsInHand(Deck &deck){
    for (int i = 0; i < 7; i++){
        //Sets the values for each card
        cards[i].set_rank(deck.getCardRank());
        cards[i].set_suit(deck.getCardSuit());
        //Removes seven cards from the deck
        deck.removeCard();
    }
}

/*********************************************************************
** Function: printCardsInHand
** Description: Shows the user what cards they have in their hand
** Parameters: none
** Pre-Conditions: Player has cards in their hand
** Post-Conditions:
*********************************************************************/ 
void Hand::printCardsInHand(){
    cout << "Cards in Hand: " << endl;
    //Iterates over each card in the players hand
    for (int i = 0; i < this->n_cards; i++){
        //prints the info for a card
        cards[i].print_card();
    }
    cout << endl << endl;
}

/*********************************************************************
** Function: getRankOfCard
** Description: Gets the rank of the card in hand at the specified index
** Parameters: index i
** Pre-Conditions: Called inside for loop
** Post-Conditions:returns the cards rank
*********************************************************************/ 
int Hand::getRankOfCard(int i){
    return cards[i].get_rank();
}