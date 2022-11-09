#include <iostream>
#include <vector>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include "board.h"

using namespace std;

int main(){
    int boardSize = 0;

    cout << "Enter a Width And Height For The Cave: ";
    cin >> boardSize;

    Board board(boardSize);

    board.setSpecRooms();
    board.printBoard();
    board.printCheatBoard();
    board.movePlayer();
    /*srand(time(NULL));
    int xcord;
    int ycord;
    int boardSize = 0;
    int specialRooms[5] = {1, 1, 2, 2, 1};
    int playerLocation[2] = {0, 0};
    cout << "Enter a Width And Height For The Cave: ";
    cin >> boardSize;


    vector<vector<int>> v2(boardSize, vector<int>(boardSize, 0));

    for (int i = 0; i < 5; i++){
        int roomsFilled = 0;
        while (roomsFilled < specialRooms[i]){
            xcord = rand()%boardSize;
            ycord = rand()%boardSize;

            if (i == 0){
                playerLocation[0] = xcord;
                playerLocation[1] = ycord;
            }

            v2[xcord][ycord] = i + 1;
            roomsFilled++;
        }
    }

    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j <boardSize; j++){
            cout << "-----------";
        }
        cout << endl;
        for (int z = 0; z < 5; z++){
            for (int k = 0; k < boardSize; k++){
                if ((i + 1) == playerLocation[1] and (k + 1) == playerLocation[0] and z == 2){
                    cout << "|    *    |";
                }else{
                    cout << "|         |";
                }
            }
            cout << endl;
        }
    }
    for (int j = 0; j <boardSize; j++){
            cout << "-----------";
    }
    cout << endl << endl;

    /*for (auto i : v2){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl << "Array Key: 1 = Starting Point, 2 = gold, 3 = pit, 4 = bats, 5 = wumpus" << endl;*/

    return 0;
}