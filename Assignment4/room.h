#include <iostream>
#include <string>

#include "player.h"
#include "event.h"
#include "bats.h"
#include "pit.h"
#include "wumpus.h"
#include "gold.h"
#include "start.h"

#include <vector>

#ifndef ROOM
#define ROOM

using namespace std;

class Room{
    private:
        int boardSize;
        Event *wumpus = new Wumpus;
        Event *gold = new Gold;
        Event *start = new Start;
        Event *bat = new Bats[2];
        Event *pit = new Pit[2];
        Player player;
        vector<vector<int>> v2;
    public:
        Room();
        Room(int);
        ~Room();

        vector<vector<int>> setSpecRooms();
        vector<vector<int>> setSpecRooms2(vector<vector<int>>);
        void setRoomType(int, int, int, int);
        void printBoard();
        bool printEvents();
        void printCheatBoard();
        void movePlayer(bool);
        void moveWumpus();

};



#endif