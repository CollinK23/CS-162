#include <iostream>
#include "deck.h"
#include <string>
#include<cstdlib>
#include<iomanip>
#include<ctime>

using namespace std;

//---------------------------------------------------------------- DECK FUNCTIONS -----------------------------------------------------------------

Deck::Deck(){
    this->n_cards = 51;
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
        cards[k] = temp_card;
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
    return this->n_cards + 1;
}

int Deck::getCardRank(){
    return cards[this->n_cards].get_rank();
}

int Deck::getCardSuit(){
    return cards[this->n_cards].get_suit();
}

void Deck::printCard(){
    cout << cards[this->n_cards].map_rank(cards[this->n_cards].get_rank()) << " of " << cards[this->n_cards].map_suit(cards[this->n_cards].get_suit()) << endl << endl;
}
