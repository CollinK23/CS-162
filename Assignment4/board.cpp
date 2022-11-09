#include <iostream>
#include <string>

#include "board.h"
#include "player.h"

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

void Board::setSpecRooms(){
    int xcord;
    int ycord;
    srand(time(NULL));
    int specialRooms[5] = {1, 1, 2, 2, 1};

    for (int i = 0; i < 5; i++){
        int roomsFilled = 0;
        while (roomsFilled < specialRooms[i]){
            xcord = rand()%this->boardSize;
            ycord = rand()%this->boardSize;

            if (i == 0){
                player.setLocX(xcord);
                player.setLocY(ycord);
            }

            v2[xcord][ycord] = i + 1;
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

void Board::movePlayer(){
    int x =0;
    while (true){
        char c;
        cout << "Enter Move: " << endl;
        cin >> c;
        
        if (c == 'w'){
            player.moveUp();
            printBoard();
        }else if (c == 'a'){
            player.moveLeft();
            printBoard();
        }else if(c == 's'){
            player.moveDown();
            printBoard();
        }else if(c == 'd'){
            player.moveRight();
            printBoard();
        }
        x++;
    }
}