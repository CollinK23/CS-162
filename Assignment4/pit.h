#include <iostream>
#include <string>
#include "event.h"

#ifndef PIT
#define PIT

using namespace std;

class Pit : public Event{
    public:
        Pit() : Event(){}

        void display(Player&);
        void display2(Player&);
        bool checkHealth();

};

#endif