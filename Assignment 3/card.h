#include <iostream>
#include <string>
#ifndef CARDS
#define CARDS

using namespace std;


// Header file
class Card {
    int rank;
    int suit;
    public:
        Card(); //Card constructor
        Card(int, int);

        void set_rank(int);
        int get_rank();
        void set_suit(int);
        int get_suit();
        string map_suit(int); //convert the int suit to corresponding string
        string map_rank(int); //convert the int rank to corresponding string
        void print_card(); //print the card out
    private:
};

#endif