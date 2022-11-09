#include <iostream>
#include <string>
#include "player.h"
#include <vector>

#ifndef BOARD
#define BOARD

using namespace std;

class Board{
    private:
        int boardSize;
        Player player;
        vector<vector<int>> v2;
    public:
        Board();
        Board(int);
        void setSpecRooms();
        void printBoard();
        void printCheatBoard();
        void movePlayer();

};



#endif