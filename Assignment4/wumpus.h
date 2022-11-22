#include <iostream>
#include <string>
#include "event.h"

#ifndef WUMPUS
#define WUMPUS

using namespace std;

class Wumpus : public Event{
    public:
        Wumpus() : Event(){}

        void display(Player&);
        void display2(Player&);
        bool checkHealth();
        void killWumpus();

        void shootLeft(Player&);
        void shootRight(Player&);
        void shootUp(Player&);
        void shootDown(Player&);

        bool useArrow(Player&);

};

#endif