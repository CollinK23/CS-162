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

Board::Board() : v2(4, vector<int>(4, 0)){
    this->boardSize = 4;
    player.setLocX(0);
    player.setLocY(0);
}

Board::Board(int newBoardSize) : v2(newBoardSize, vector<int>(newBoardSize, 0)){
    this->boardSize = newBoardSize;
    player.setLocX(0);
    player.setLocY(0);
}

void Board::setRoomType(int xcord, int ycord, int i, int r){
    v2[ycord][xcord] = i;
    if (i == 1){
        player.setLocX(xcord);
        player.setLocY(ycord);
        start->setRoomLoc(xcord, ycord);
    }else if (i == 2){
        gold->setRoomLoc(xcord, ycord);
    }else if (i == 3){
        pit[r].setRoomLoc(xcord, ycord);
    }else if (i == 4){
        bat[r].setRoomLoc(xcord, ycord);
    }else if (i == 5){
        wumpus->setRoomLoc(xcord, ycord);
    }
}

void Board::setSpecRooms(bool newBoard){
    player.setBoardSize(this->boardSize);
    int xcord;
    int ycord;
    if (newBoard == true){
        srand(time(NULL));
    }
    int specialRooms[5] = {1, 1, 2, 2, 1};

    for (int i = 1; i < 6; i++){
        int roomsFilled = 0;
        while (roomsFilled < specialRooms[i - 1]){
            while (true){
                xcord = rand()%this->boardSize;
                ycord = rand()%this->boardSize;
                if (v2[xcord][ycord] == 0){break;}
            }

            setRoomType(xcord, ycord, i, roomsFilled);

            roomsFilled++;
        }
    }
}

void Board::printBoard(){
    cout << player.getLocX() + 1 << ", " << player.getLocY() + 1 << endl;
    for (int i = 0; i < this->boardSize; i++){
        for (int j = 0; j < this->boardSize; j++){
            cout << "-----------";
        }
        cout << endl;
        for (int z = 0; z < 5; z++){
            for (int k = 0; k < this->boardSize; k++){
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

void Board::printCheatBoard(){
    for (auto i : v2){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << player.getLocX() + 1 << ", " << player.getLocY() + 1 << endl;

    cout << endl << "Array Key: 1 = Starting Point, 2 = gold, 3 = pit, 4 = bats, 5 = wumpus" << endl;
}

bool Board::printEvents(){
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

    if (pit[0].checkHealth() != pit[1].checkHealth() != wumpus->checkHealth() != start->checkHealth()){
        return true;
    }else{
        return false;
    }

}

void Board::movePlayer(){
    while (printEvents() != true){
        printBoard();
        char c;
        cout << "Enter Move: " << endl;
        cin >> c;

        if (c == 'w' and player.getLocY() > 0){
            player.moveUp();
        }else if (c == 'a' and player.getLocX() > 0){
            player.moveLeft();
        }else if(c == 's' and player.getLocY() + 1 < this->boardSize){
            player.moveDown();
        }else if(c == 'd' and player.getLocX() + 1 < this->boardSize){
            player.moveRight();
        }
    }
    cout << "Game Over" << endl;
}