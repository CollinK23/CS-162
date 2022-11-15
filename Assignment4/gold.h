#include <iostream>
#include <string>
#include "event.h"

#ifndef GOLD
#define GOLD

using namespace std;

class Gold : public Event{
    public:
        Gold() : Event(){}

        void display(Player&);
        void display2(Player&);

};

#endif