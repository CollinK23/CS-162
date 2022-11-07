#include <iostream>
#include "hand.h"
#include "player.h"
#include "deck.h"
#include <string>

using namespace std;

/*********************************************************************
** Function: Default player constructor
** Description: Initialization values for new player object
** Parameters: none
** Pre-Conditions: Player object is created
** Post-Conditions: Object values are set
*********************************************************************/ 
Player::Player(){
    this->n_books = 0;
    this->books = new int[1];
}

/*********************************************************************
** Function: Player constructor
** Description: Initialization values for new player object
** Parameters: number of books
** Pre-Conditions: player object is created
** Post-Conditions: Memory allocated to dynamic array
*********************************************************************/ 
Player::Player (int size) {
    this->n_books = size;
    this->books = new int [size];
}

//Destructor
/*********************************************************************
** Function: Player destructor
** Description: Frees memory when object goes out of scope
** Parameters: None
** Pre-Conditions: Player object is created
** Post-Conditions: Memory is freed
*********************************************************************/
Player::~Player(){
    if (this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }
}

//Assignment Operator Overload
/*********************************************************************
** Function: Assignment Operator Overload
** Description: Copies one objects values to another
** Parameters: Player object
** Pre-Conditions: Two player objects have been created
** Post-Conditions: Deep copy is created
*********************************************************************/
Player& Player::operator=(const Player &p){
    this->n_books = p.n_books;

    //Free Memory
    if (this->books != NULL){
        delete [] this->books;
    }

    //Deep copy
    this->books = new int[this->n_books];
    for (int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }

    return *this;
}


//Copy Constructor
/*********************************************************************
** Function: Copy constructor
** Description: Copies values of Player object into a new player object
** Parameters: new player object
** Pre-Conditions: Player object is already created
** Post-Conditions: Deep copy is created
*********************************************************************/
Player::Player (const Player &p){
    this->n_books = p.n_books;

    //Deep copy
    this->books = new int[this->n_books];
    for (int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }
}

/*********************************************************************
** Function: getNumOfBooks
** Description: Returns the number of books the player has
** Parameters:  None
** Pre-Conditions: Player object is created
** Post-Conditions: Number of books is returned
*********************************************************************/ 
int Player::getNumOfBooks(){
    return this->n_books;
}

/*********************************************************************
** Function: getCards
** Description: returns the hand array
** Parameters: None
** Pre-Conditions: hand array has been initialized
** Post-Conditions: Hand array is returned
*********************************************************************/ 
Card* Player::getCards(){
    return hand.get_cards();
}

/*********************************************************************
** Function: setPlayersHand
** Description: Sets the cards in the players hands at beginning of game
** Parameters: reference to deck object
** Pre-Conditions: Deck object has been initialized
** Post-Conditions: Player will have 7 cards, deck will have 7 less cards
*********************************************************************/ 
void Player::setPlayersHand(Deck&deck){
    hand.setCardsInHand(deck);
}

/*********************************************************************
** Function: goFish
** Description: Player draws a card from the deck
** Parameters: reference to deck, rank of card
** Pre-Conditions: Deck and hand objects are created, card is asked for
** Post-Conditions: Returns true or false if the rank that they ask for matches the one on the card that they drew
*********************************************************************/
bool Player::goFish(Deck& deck, int rank){
    return hand.goFish(deck, hand, rank);
}

/*********************************************************************
** Function: addCardInHand
** Description:adds a card into the players hand
** Parameters:  rank, suit
** Pre-Conditions: A card has been selected to add to the players hand
** Post-Conditions: Card will be added to players hand array
*********************************************************************/
void Player::addCardInHand(int rank, int suit){
    hand.addCardInHand(hand, rank, suit);
}

/*********************************************************************
** Function: removeCard
** Description: Removes a card from the hand
** Parameters: rank that is being removed from hand, cardSuit array
** Pre-Conditions: The rank of the card that is being removed must be selected
** Post-Conditions: the cards with the same rank will be removed from the hand array
*********************************************************************/ 
int Player::removeCard(int rankRemoved, int cardSuit[]){
    return hand.removeCardInHand(rankRemoved, hand, cardSuit);
}

/*********************************************************************
** Function: printCardsInHand
** Description: Shows the user what cards they have in their hand
** Parameters: none
** Pre-Conditions: Player has cards in their hand
** Post-Conditions:
*********************************************************************/ 
void Player::printCardsInHand(){
    hand.printCardsInHand();
}

/*********************************************************************
** Function: cardsRemainingInHand
** Description: Returns the total number of cards in hand
** Parameters: None
** Pre-Conditions: Hand object is created
** Post-Conditions: Returns cards remaining in hand
*********************************************************************/
int Player::cardsRemainingInHand(){
    return hand.getCardsInHand();
}

/*********************************************************************
** Function: rankConverter
** Description: Converts the rank integer to its corresponding string
** Parameters: rank integer
** Pre-Conditions: Player enters the rank they are asking for
** Post-Conditions: Retturns corresponding rank string
*********************************************************************/ 
string Player::rankConverter(int rank){
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

/*********************************************************************
** Function: setNumOfBooks
** Description: Finds any books the player has in their hand
** Parameters: reference to player object
** Pre-Conditions: Player has cards in hand
** Post-Conditions: Player will be told if they have any books
*********************************************************************/ 
void Player::setNumOfBooks(Player& player){
    //Creates array that shows the number of each rank the player has
    for (int j = 0; j < 13; j++){
        cardCounter[j] = 0;
        //Adds 1 to cardCounter[j] if a card in their hand matches the rank
        for (int i = 0; i < hand.getCardsInHand(); i++){
            if (hand.getRankOfCard(i) == j){
                cardCounter[j] = cardCounter[j] + 1;
            }
        }
    }
    //Increases the number of books that the player has
    for (int i = 0; i < 13; i++){
        if (cardCounter[i] == 4){
            this->n_books += 1;
            Player tempPlayer(n_books);
            tempPlayer = player;
            player = tempPlayer;
            books[n_books - 1] = i;

            //Removes the cards from hand that were added to the book
            cout << "Created Book of: " << rankConverter(i) << "'s" << endl;
            hand.removeCardInHand(i, hand, cardCounter);
        }
    }
}

/*********************************************************************
** Function: printBooks
** Description: Prints all the books that the player has
** Parameters: None
** Pre-Conditions: Player has books
** Post-Conditions: 
*********************************************************************/ 
void Player::printBooks(){
    cout << "Books: ";
    for (int i = 0; i < this->n_books; i++){
        cout << rankConverter(books[i]) << "'s" << "  ";
    }
    cout << endl;
}