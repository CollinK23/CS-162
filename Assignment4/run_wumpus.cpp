/*********************************************************************
** Program Filename: run_wumpus.cpp
** Author: Collin Kimball
** Date: 11/20/22
** Description: Hunt the Wumpus Game
** Input:
** Output:
*********************************************************************/

#include <iostream>
#include <vector>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include "room.h"

using namespace std;

/*********************************************************************
** Function: cheatMode
** Description: User chooses if they want to enter debug mode
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: User will either see computers cards or not
*********************************************************************/
bool cheatMode(){
    string cont;

        
    //While loop continues to run until the user enters a valid input
    while (cont != "y" or cont != "n"){
        cout << "Press y to use cheats, n for regular game:";
        cin >> cont;
        
        if (cont == "y"){
            //User selects cheat mode
            return true;
        }else if (cont == "n"){
            //User doesn't use cheats
            return false;
        }else{
            cout << "Invalid Input. ";
        }
    }
}

/*********************************************************************
** Function: dimensions
** Description: User selects the size of the board
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Board size is an integer greater than 3
*********************************************************************/ 
int dimensions(){
    int size;

    //While loop continues to run until the user enters a valid input
    while (true){
        cout << "Choose Width and Length of The Board:";
        cin >> size;
        
        if (size > 3){
            //User selects size
            return size;
        }else{
            cout << "Invalid Input. ";
        }
    }
}

/*********************************************************************
** Function: runGame
** Description: Runs the entire game
** Parameters: randomize boolean, boardSize boolean, 2D Vector
** Pre-Conditions: board size is selected
** Post-Conditions: Returns vector copy of the board
*********************************************************************/ 
vector<vector<int>> runGame(bool randomize, int boardSize, vector<vector<int>> v2Copy){
    Room board(boardSize);

    //User wants to play with new rooms
    if (randomize == true){
        v2Copy = board.setSpecRooms();  
    }else{
        //User wants to play with the same rooms
        v2Copy = board.setSpecRooms2(v2Copy);
    }

    board.movePlayer(cheatMode());

    return v2Copy;
}


/*********************************************************************
** Function: newBoard
** Description: User selects whether they want to play the game on the same board or not
** Parameters: none
** Pre-Conditions: User selects to play the game again
** Post-Conditions: True or false depending on if they want the same board
*********************************************************************/ 
bool newBoard(){
    string cont;

    //While loop continues to run until the user enters a valid input
    while (cont != "y" or cont != "n"){
        cout << "Press y to randomize board, n for same board:";
        cin >> cont;
        
        if (cont == "y"){
            //User selects hard mode
            return true;
        }else if (cont == "n"){
            //User selects regular mode
            return false;
        }else{
            cout << "Invalid Input. ";
        }
    }
}

/*********************************************************************
** Function: main
** Description: Replays the program until user quits
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
int main(){
    int boardSize = dimensions();
    bool randomize = true;
    bool contGame = true;
    string cont;
    vector<vector<int>> v2Copy;

    //While loop that checks user input for correctiveness
    while (contGame){

        //Runs game
        v2Copy = runGame(randomize, boardSize, v2Copy);
        //While loop continues to run until the user enters a valid input
        while (cont != "y" or cont != "n"){
            cout << "Press y to continue, n to exit:";
            cin >> cont;
            
            if (cont == "y"){
                //Continues game
                randomize = newBoard();
                if (randomize){
                    boardSize = dimensions();
                }
                break;
            }else if (cont == "n"){
                //Quits Game
                contGame = false;
                break;
            }else{
                cout << "Invalid Input. ";
            }
        }
    }

    return 0;
}