#include<iostream>
#include <string>
#include "gofish.h"

using namespace std;

void pressEnter(){
    string temp;
    cout << "Press Enter To Roll" << endl;
    getline(cin, temp);
}

int main(){
    Deck deck(52);
    deck.fillDeck();
    deck.shuffleDeck();
    int i = 52;
    while (deck.get_n_cards() > 0){
        cout << "Cards Left: " << i << endl;
        pressEnter();
        deck.removeCard();
        i--;
    }

    return 0;
}