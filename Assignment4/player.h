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
    public:
        Player();
        Player(int, int);

        void setLocX(int);
        void setLocY(int);

        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        int getLocX();
        int getLocY();
        int getArrows();

        void useArrow();
};

#endif