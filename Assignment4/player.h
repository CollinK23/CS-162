#include <iostream>
#include <string>

#ifndef PLAYER
#define PLAYER

using namespace std;

class Player{
    private:
        int playerLocationX;
        int playerLocationY;
        int arrows;
        int boardSize;
        bool goldCollected;
        bool killedWump;
    public:
        Player();

        void setLocX(int);
        void setLocY(int);
        void setGoldColl(bool);
        void setBoardSize(int);
        void killWumpus();

        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        int getLocX();
        int getLocY();
        int getArrows();
        void removeArrow();
        int getBoardSize();
        bool getGoldColl();
        bool getWumpus();
};

#endif