#include<iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"

using namespace std;

void pressEnter(){
    string temp;
    cout << "Press Enter To Roll" << endl;
    getline(cin, temp);
}

int main(){
    Deck deck;
    deck.fillDeck();
    deck.shuffleDeck();
    Hand hand;

    hand.setCardsInHand(deck);

    while (deck.get_n_cards() > 0){
        hand.printCardsInHand();
        cout << "Remove a Card: " << endl << endl;
        pressEnter();
        cout << "Card Removed: ";
        deck.printCard();
        deck.removeCard();
    }

    /*Player p;

    Player p1(10);
    Player p2(5);

    p1=p2;

    Player p3=p1;
    
    hand.handSize(hand.getCardsInHand());
    hand.setCardsInHand(deck);
    hand.printCardsInHand();

    while (deck.get_n_cards() > 0){
        cout << "Add a Card to Hand: " << endl << endl;
        cout << "Card Removed: " << deck.getCardRank() << " of " << deck.getCardSuit() << endl << endl;
        pressEnter();
        hand.addCardInHand(deck);
        hand.printCardsInHand();

    }*/


    return 0;
}