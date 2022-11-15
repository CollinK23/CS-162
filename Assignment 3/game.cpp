#include <iostream>
#include "game.h"
#include "player.h"
#include "deck.h"
#include "card.h"
#include <string>

using namespace std;


/*********************************************************************
** Function: Default Game constructor
** Description: Creates and shuffles deck, sets the starting hand for both players
** Parameters: None
** Pre-Conditions: Game object is initiallized
** Post-Conditions: deck is shuffled and 7 cards are added to both players hands
*********************************************************************/
Game::Game(){
    //Fills deck object with cards
    d.fillDeck();
    //Shuffles cards in the deck object
    d.shuffleDeck();
    //Gives 7 cards to the user
    players[0].setPlayersHand(d);
    //Gives 7 cards to the computer
    players[1].setPlayersHand(d);
}

/*********************************************************************
** Function: rankConverter
** Description: Converts the string of the card to its corresponding integer rank
** Parameters: rank string
** Pre-Conditions: Player or computer asks for a card
** Post-Conditions: rank is converted into an integer
*********************************************************************/
int rankConverter(string rank){
    if (rank == "A"){
        return 0;
    }else if (rank == "K"){
        return 12;
    }else if (rank == "Q"){
        return 11;
    }else if (rank == "J"){
        return 10;
    }else{
        //Subtracts one because integer ranks start at 0
        return (stoi(rank) - 1);
    }
}

/*********************************************************************
** Function: validateCardSelection
** Description: Makes sure the card that the user is asking for exits in their hand
** Parameters: None
** Pre-Conditions: Game object is initiallized
** Post-Conditions: Returns the card that the user is asking for
*********************************************************************/
string Game::validateCardSelection(){
    //Only takes in input when the player still has cards remaining in hand
    while(players[0].cardsRemainingInHand() > 0){
        string askForCard;
        Card* playerCards = players[0].getCards();
        cout << "Choose Card To Ask For: ";
        cin >> askForCard;

        //Checks in the users hand for that card that they are asking for
        for (int i = 0; i < players[0].cardsRemainingInHand(); i++){
            if (playerCards[i].map_rank(playerCards[i].get_rank()) == askForCard){
                return askForCard;
            }
        }
        //Will output this message and continue to loop if the user enters a card that they don't have
        cout << "Card Is Not In Your Hand" << endl;
    }
    //Only returns when the game is finished
    return " ";
}

/*********************************************************************
** Function: playersTurn
** Description: Allows user to play their turn
** Parameters: None
** Pre-Conditions: It is currently the user's turn
** Post-Conditions: Returns true or false based on if the user gets another turn
** Over 15 lines: Additional lines were used to make the cout statements more legible
*********************************************************************/
bool Game::playersTurn(){
    //Potential suits of cards that can be added to the players hand
    int cardSuit[3] = {0, 0, 0};
    //Shows the user their total cards in hand
    players[0].printCardsInHand();
    cout << "Your ";
    //Prints all of the books that the user has
    players[0].printBooks();

    string askForCard = validateCardSelection();
    
    //Ends users turn if they have no cards remaining
    if(askForCard == " "){
        return false;
    }

    //Returns the number of cards in the computers hand that are the same rank as the one that user asks for
    int cardExists = players[1].removeCard(rankConverter(askForCard), cardSuit);
    //If No cards match in the computers hand, the player draws a card from the deck
    if (cardExists == 0){
        cout << endl << endl << "* * * * * GO FISH * * * * *" << endl << endl << endl;
        cout << "Card Added: ";
        //Prints the card that is being added to the users hand
        d.printCard();
        cout << endl << endl;
        //If the rank of the card that the user gets from the deck matches the one that they ask for, user gets another turn
        bool cont = players[0].goFish(d, rankConverter(askForCard));
        return cont;
    }else{
        //Runs if the user correctly guesses a card in the computers hand
        cout << "You Got: " << cardExists << " " << askForCard << "'s" << endl << endl;
        //Adds the cards from the opponents hand into the users hands
        for (int i = 0; i < cardExists; i++){
            players[0].addCardInHand(rankConverter(askForCard), cardSuit[i]);
        }
        //Player gets another turn
        return true;
    }

}

/*********************************************************************
** Function: generateCardSelection
** Description: Computer selects a card from user's deck
** Parameters: None
** Pre-Conditions: Users turn is over
** Post-Conditions: Returns card that the computer is asking for
*********************************************************************/
string Game::generateCardSelection(bool hardMode){
    while (players[1].cardsRemainingInHand() > 0){
        Card* playerCards = players[0].getCards();
        Card* comCards = players[1].getCards();
        //Looks through players hand to see if they have any matching ranks
        if (hardMode == true){
            for (int i = 0; i < players[1].cardsRemainingInHand(); i++){
                for (int j = 0; j < players[0].cardsRemainingInHand();j++){
                    //Double for loop compares every value in both hands for any matches
                    if (comCards[i].get_rank() == playerCards[j].get_rank()){
                        cout << "The Computer Asked For: " << players[1].rankConverter(comCards[i].get_rank()) << "'s" << endl;
                        //Returns card that computer asks for
                        return players[1].rankConverter(comCards[i].get_rank());
                    }else{continue;}
                }
            }
        }

        //Will ask for random card if there are no matching ranks in the players hand
        //Creates random index of a card that computer is asking for
        int randIndex = rand()%(players[1].cardsRemainingInHand());
        cout << "The Computer Asked For: ";
        cout << comCards[randIndex].map_rank(comCards[randIndex].get_rank());
        cout << "'s" << endl << endl << endl;
        // Returns the rank of the card that the computer is asking for
        return comCards[randIndex].map_rank(comCards[randIndex].get_rank());
    }
    // Returns this if game is over
    return " ";
}

/*********************************************************************
** Function: computersTurn
** Description: Allows the user to use their turn
** Parameters:  None
** Pre-Conditions: Users turn is over, user still has cards in their hand
** Post-Conditions: Computer can go again based on return value
** Over 15 lines: extra lines used to make cout statements more legible
*********************************************************************/
bool Game::computersTurn(bool hardMode){
    //Potential suits of cards that can be added to the user's hand
    int cardSuit[3] = {0, 0, 0};
    //Sets number of books for the computer
    players[1].setNumOfBooks(players[1]);
    cout << "Computer's ";
    //Prints the books that the computer as
    players[1].printBooks();

    string askForCard = generateCardSelection(hardMode);

    // Only returns when game is over
    if(askForCard == " "){
        return false;
    }

    int cardExists = players[0].removeCard(rankConverter(askForCard), cardSuit);
    //If no matching cards exist in the user's hand, the computer gets a card from the deck
    if (cardExists == 0){
        cout << "* * * * * GO FISH * * * * *" << endl << endl << endl;
        bool cont = players[1].goFish(d, rankConverter(askForCard));
        return cont;
    }else{
        //If a matching card exists, all cards with matching values will be given to computer
        cout << "Computer Took: " << cardExists << " " << askForCard << "'s" << endl << endl;
        for (int i = 0; i < cardExists; i++){
            players[1].addCardInHand(rankConverter(askForCard), cardSuit[i]);
        }
        return true;
    }
}

/*********************************************************************
** Function: startGame
** Description: Runs both players turns
** Parameters: cheating, hard mode
** Pre-Conditions: Game object is created
** Post-Conditions: Game will end
*********************************************************************/
void Game::startGame(bool cheating, bool hardMode){
    while (d.get_n_cards() > 0 and players[0].cardsRemainingInHand() > 0 and players[1].cardsRemainingInHand() > 0){
    //Runs until no card remaining in either players hand or deck
        while (players[1].cardsRemainingInHand() > 0){
            cout << "* * * * * YOUR TURN * * * * *" << endl << endl << endl;
            //Lets you view computers cards
            if (cheating == true){
                cout << "Computer's ";
                players[1].printCardsInHand();
            }
            players[0].setNumOfBooks(players[0]);
            bool cont = playersTurn();
            //Breaks to end players turn
            if (cont == false){break;}
        }
        while (players[0].cardsRemainingInHand() > 0){
            cout << "* * * * * COMPUTER'S TURN * * * * *" << endl << endl << endl;
            players[1].setNumOfBooks(players[1]);
            bool cont2 = computersTurn(hardMode);
            if (cont2 == false){break;}
        }
    }
}

/*********************************************************************
** Function: Game over
** Description: Tells the user which player has won the game
** Parameters: None
** Pre-Conditions: Game is over
** Post-Conditions: Winner is output
*********************************************************************/
void Game::gameOver(){
    cout << endl << "GAME OVER" << endl << endl;

    cout << "Computer's Books: ";
    players[1].printBooks();
    cout << endl << endl;

    cout << "Your Books: ";
    players[0].printBooks();
    cout << endl << endl;

    if (players[0].getNumOfBooks() > players[1].getNumOfBooks()){
        cout << "You Win!" << endl << endl;
    }else if (players[0].getNumOfBooks() < players[1].getNumOfBooks()){
        cout << "You Lose, Computer Wins" << endl << endl;
    }else{
        cout << "You Tied" << endl << endl;
    }
}