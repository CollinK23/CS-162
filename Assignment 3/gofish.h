#include <iostream>
#include <string>
#ifndef GOFISH
#define GOFISH

using namespace std;


// Header file
class Card {
    int rank;
    int suit;
    public:
        Card(); //Card constructor
        Card(int, int);

        //~Card(); //Card destructor

        void set_rank(int);
        int get_rank();
        void set_suit(int);
        int get_suit();
        string map_suit(int); //convert the int suit to corresponding string
        string map_rank(int); //convert the int rank to corresponding string
        void print_card(); //print the card out
    private:
};


class Deck{
    private:
        Card cards[52]; //A full deck of cards
        int n_cards; //number of cards remaining in the deck
    public:
        Deck(); //Deck Constructor
        Deck(int);

        //~Deck();

        void set_n_cards(int);
        int get_n_cards();
        void fillDeck();
        void shuffleDeck();
        void removeCard();
    
};

class Hand{
    private:
        Card* cards; // An array of cards in hand
        int n_cards; // Number of cards in the hand
    public:
};

class Player{
    private:
        Hand hand;
        int* books; // Array with ranks for which the player has books.
        int n_books;
    public:
};

class Game {
    private:
        Deck d;
        Player players[2];
    public:
};

#endif