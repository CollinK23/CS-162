#include <iostream>
#include <string>
#include "event.h"

#ifndef BAT
#define BAT

using namespace std;

class Bats : public Event{
    public:
        Bats() : Event(){}

        void display(Player&);
        void display2(Player&);

};

#endif