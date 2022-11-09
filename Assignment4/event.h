#include <iostream>

#ifndef EVENT
#define EVENT

using namespace std;

class Event{
    protected:
        const string roomName;
        int roomType;  // 0 - empty , 1 - starting room, 2 - gold, 3 - bottomless pit, 4 - super bats, 5 - wumpus
        bool playerVisited;
        bool gameOver;
    public:
        Event();
        Event(string, int);

        virtual void encounter();
        virtual void percept();
};

#endif