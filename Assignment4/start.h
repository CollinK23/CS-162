#include <iostream>
#include <string>
#include "event.h"


#ifndef START
#define START

using namespace std;

class Start : public Event{
    public:
        Start() : Event(){}

        void display(Player&);
        void display2(Player& player){}
        bool checkHealth();

};

#endif