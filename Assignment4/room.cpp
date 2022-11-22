#include <iostream>
#include <string>

#include "room.h"
#include "player.h"
#include "event.h"

#include <vector>
#include<cstdlib>
#include<iomanip>
#include<ctime>

using namespace std;

/*********************************************************************
** Function: Default room constructor
** Description: Default values for room object, creates vector dimensions
** Parameters: None
** Pre-Conditions: Room object is created
** Post-Conditions: vector values are set, object values are set
*********************************************************************/ 
Room::Room() : v2(4, vector<int>(4, 0)){
    this->boardSize = 4;
    player.setLocX(0);
    player.setLocY(0);
}

/*********************************************************************
** Function: Room constructor
** Description: values for room object, creates vector dimensions
** Parameters: board size
** Pre-Conditions: Player chooses size of the board
** Post-Conditions: vector values are set, object values are set
*********************************************************************/ 
Room::Room(int newBoardSize) : v2(newBoardSize, vector<int>(newBoardSize, 0)){
    this->boardSize = newBoardSize;
    player.setLocX(0);
    player.setLocY(0);
}

/*********************************************************************
** Function: room deconstructor
** Description: clears memory that was allocated to event objects
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: memory is freed
*********************************************************************/ 
Room::~Room(){
    delete wumpus;
    delete gold;
    delete start;
    delete [] bat;
    delete [] pit;
}

/*********************************************************************
** Function: setRoomType
** Description: Sets the coordinates of the event rooms
** Parameters: xcord, ycord, for loop iteration, room number
** Pre-Conditions:
** Post-Conditions: coordinates of the event rooms are set
*********************************************************************/ 
void Room::setRoomType(int xcord, int ycord, int i, int r){
    v2[ycord][xcord] = i;
    if (i == 1){
        //sets location the player will start at
        player.setLocX(xcord);
        player.setLocY(ycord);
        //Sets location where player can leave
        start->setRoomLoc(xcord, ycord);
    }else if (i == 2){
        //Sets location of the gold
        gold->setRoomLoc(xcord, ycord);
    }else if (i == 3){
        //Sets location of the pit
        pit[r].setRoomLoc(xcord, ycord);
    }else if (i == 4){
        //sets location of the super bats
        bat[r].setRoomLoc(xcord, ycord);
    }else if (i == 5){
        //sets locatin of the wumpus
        wumpus->setRoomLoc(xcord, ycord);
    }
}

/*********************************************************************
** Function: setSpecRooms
** Description: selects random locations for the event rooms
** Parameters: none
** Pre-Conditions:
** Post-Conditions: Returns the vector of the board
*********************************************************************/ 
vector<vector<int>> Room::setSpecRooms(){
    srand(time(NULL));
    player.setBoardSize(this->boardSize);
    int xcord;
    int ycord;
    //Number of rooms of each event type
    int specialRooms[5] = {1, 1, 2, 2, 1};

    for (int i = 1; i < 6; i++){
        int roomsFilled = 0;
        //While loop fills rooms of each event type
        while (roomsFilled < specialRooms[i - 1]){
            while (true){
                //sets random coordinates for each event room
                xcord = rand()%this->boardSize;
                ycord = rand()%this->boardSize;
                //Only breaks when an empty room is selected to have an event
                if (v2[ycord][xcord] == 0){break;}
            }

            setRoomType(xcord, ycord, i, roomsFilled);

            roomsFilled++;
        }
    }

    return v2;
}

/*********************************************************************
** Function: setSpecRooms2
** Description: Copies board from the previous game
** Parameters: v2copy vector
** Pre-Conditions: Game was previously played
** Post-Conditions: Event rooms will be set to the same locations as previous game
*********************************************************************/ 
vector<vector<int>> Room::setSpecRooms2(vector<vector<int>> v2Copy){
    player.setBoardSize(this->boardSize);
    int specialRooms[5] = {1, 1, 2, 2, 1};

    //Places event objects in the same rooms as last game
    for (int k = 1; k < 6; k++){
        int roomsFilled = 0;
        while (roomsFilled < specialRooms[k - 1]){
            //Double for loops checks for event location in the vector
            for (int i = 0; i < this->boardSize; i++){
                for (int j = 0; j < this->boardSize; j++){
                    if (v2Copy[j][i] == k){
                        setRoomType(i, j, k, roomsFilled);
                    }
                }
            }
            roomsFilled++;
        }
    }

    return v2;
}

/*********************************************************************
** Function: printBoard
** Description: outputs the cave and player lcoation to the user
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void Room::printBoard(){
    for (int i = 0; i < this->boardSize; i++){
        for (int j = 0; j < this->boardSize; j++){
            cout << "-----------";
        }
        cout << endl;
        for (int z = 0; z < 5; z++){
            for (int k = 0; k < this->boardSize; k++){
                //Indicates location of the player
                if ((i) == (player.getLocY()) and (k) == (player.getLocX()) and z == 2){
                    cout << "|    *    |";
                }else{
                    cout << "|         |";
                }
            }
            cout << endl;
        }
    }
    for (int j = 0; j < this->boardSize; j++){
            cout << "-----------";
    }
    cout << endl << endl;
}

/*********************************************************************
** Function: printCheatBoard
** Description: shows the user all rooms inside of the cave
** Parameters: none
** Pre-Conditions: User chooses to play in cheat mode
** Post-Conditions: all locations are output
*********************************************************************/ 
void Room::printCheatBoard(){
    //Prints values inside of the vector
    for (auto i : v2){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl << "Key: 1 = Starting Point, 2 = gold, 3 = pit, 4 = bats, 5 = wumpus" << endl;
}

/*********************************************************************
** Function: printEvents
** Description: runs all of the encounters and percept functions
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Percept message is output or event runs depending on location, game continues or ends
*********************************************************************/ 
bool Room::printEvents(){
    //Checks percepts and encounters of each event
    for (int i = 0; i < 2; i++){
        bat[i].percept(player, bat);
        bat[i].encounter(player, bat);
        pit[i].percept(player, pit);
        pit[i].encounter(player, pit);
    }

    wumpus->percept(player, wumpus);
    wumpus->encounter(player, wumpus);
    gold->percept(player, gold);
    gold->encounter(player, gold);
    start->encounter(player, start);

    //If one is true, the game will end
    if (pit[0].checkHealth() != pit[1].checkHealth() != wumpus->checkHealth() != start->checkHealth()){
        return true;
    }else{
        return false;
    }

}

/*********************************************************************
** Function: moveWumpus
** Description: Moves wumpus if player misses an arrow
** Parameters: none
** Pre-Conditions: Player misses an arrow
** Post-Conditions: Wumpus location changes
*********************************************************************/ 
void Room::moveWumpus(){
    int move = rand()%4;
    int x = wumpus->getRoomLocX();
    int y = wumpus->getRoomLocY();

    //75% chance of wumpus moving
    while (move <= 3){
        //moves wumpus right
        if (move == 0 and (x + 1 < this->boardSize) and (v2[y][x + 1] == 0)){
            swap(v2[y][x], v2[y][x + 1]);
            wumpus->setRoomLoc(x + 1, y);
            break;
        //moves wumpus left
        }else if (move == 1 and x > 0 and (v2[y][x - 1] == 0)){
            swap(v2[y][x], v2[y][x - 1]);
            wumpus->setRoomLoc(x - 1, y);
            break;
        //moves wumpus down
        }else if (move == 2 and (y + 1 < this->boardSize) and (v2[y + 1][x] == 0)){
            swap(v2[y][x], v2[y + 1][x]);
            wumpus->setRoomLoc(x, y + 1);
            break;
        //moves wumpus up
        }else if (move == 3 and y > 0 and (v2[y - 1][x] == 0)){
            swap(v2[y][x], v2[y - 1][x]);
            wumpus->setRoomLoc(x, y - 1);
            break;
        }
        move ++;
    }
}

/*********************************************************************
** Function: movePlayer
** Description: Player selects which direction to move in or shoot an arrow
** Parameters: cheats
** Pre-Conditions: 
** Post-Conditions: Player will either move or shoot an arrow
*********************************************************************/ 
void Room::movePlayer(bool cheats){
    //While loop runs until game ends
    while (printEvents() != true){
        //Outputs the board to the user
        printBoard();
        //Outputs the cheat board if user is playing in debug mode
        if (cheats){printCheatBoard();}
        char c;
        cout << "Enter WASD To Move, Q To Use Arrow: " << endl;
        cin >> c;

        if (c == 'w' and player.getLocY() > 0){
            //moves player up
            player.moveUp();
        }else if (c == 'a' and player.getLocX() > 0){
            //moves player left
            player.moveLeft();
        }else if(c == 's' and player.getLocY() + 1 < this->boardSize){
            //moves player down
            player.moveDown();
        }else if(c == 'd' and player.getLocX() + 1 < this->boardSize){
            //moves player right
            player.moveRight();
        }else if(c == 'q'){
            //shoots arrow
            bool move = wumpus->useArrow(player);
            //moves wumpus
            if (not move){moveWumpus();}
        }
    }
    cout << "Game Over" << endl;
}