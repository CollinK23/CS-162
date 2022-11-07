/*********************************************************************
** Program Filename: run_gofish.cpp
** Author: Collin Kimball
** Date:11/6/2022
** Description: Gofish game vs Computer
** Input: User selects if they want to use cheat mode
** Output: User will be able to play go fish until they choose to quit program
*********************************************************************/
#include<iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"
#include<cstdlib>
#include<iomanip>
#include<ctime>

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

    //While loop that checks user input for correctiveness
    while (true){
        
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
}

/*********************************************************************
** Function: hardMode
** Description: User chooses if they want to play against the harder AI
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Computer can either see player cards or not
*********************************************************************/
bool hardMode(){
    string cont;

    //While loop that checks user input for correctiveness
    while (true){
        
        //While loop continues to run until the user enters a valid input
        while (cont != "y" or cont != "n"){
            cout << "Press y for hard game, n for regular game:";
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
}

/*********************************************************************
** Function: Main
** Description: Runs go fish program until user decides to quit
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/

int main(){
    srand(time(NULL));
    //Decides if user continues or not
    bool contGame = true;

    string cont;

    //While loop that checks user input for correctiveness
    while (contGame){
        //Initializes game object
        Game game;
        //Runs game
        game.startGame(cheatMode(), hardMode());
        game.gameOver();
        //While loop continues to run until the user enters a valid input
        while (cont != "y" or cont != "n"){
            cout << "Press y to continue, n to exit:";
            cin >> cont;
            
            if (cont == "y"){
                //Continues game
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