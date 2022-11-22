#include <iostream>
#include "player.h"

#ifndef EVENT
#define EVENT

using namespace std;

class Event{
    protected:
        bool gameOver;
        bool wumpusDead;
        int roomLocX;
        int roomLocY;
    public:
        Event();

        void setRoomLoc(int, int);
        int getRoomLocX();
        int getRoomLocY();

        virtual void display(Player&) = 0;
        virtual void display2(Player&) = 0;
        virtual void encounter(Player&, Event*);
        virtual void percept(Player&, Event*);
        virtual bool useArrow(Player&){}
        virtual bool checkHealth();
        virtual bool checkWumpus();
};

#endif