/******************************************************
** Program: bowling.cpp
** Author: Collin Kimball
** Date: 10/09/2022
** Description: Bowling program that uses the random function to generate scores
** Input: Name
** Output: 2D scoreboard array
******************************************************/

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>

using namespace std;

/*********************************************************************
** Function: pressEnter
** Description: Pauses the game until the user presses enter
** Parameters: none
** Pre-Conditions:
** Post-Conditions:The roll functions will run
*********************************************************************/
void pressEnter(){
    string temp;
    cout << "Press Enter To Roll" << endl;
    getline(cin, temp);
}


/*********************************************************************
** Function: introduction
** Description: Gets input from user to greet them
** Parameters: none
** Pre-Conditions: 
** Post-Conditions: User will be greeted
*********************************************************************/
void introduction(){
    string name;
    cout << "Welcome To Bowling!" << endl;
    cout << "What's Your Name?";
    cin >> name;
    cout << endl << "Hello " << name << "!"<< endl << endl;
    getline(cin, name);
}


/*********************************************************************
** Function: specialChar1
** Description: Catches special characters for the first and third roll
** Parameters: first roll value
** Pre-Conditions: first roll must be complete
** Post-Conditions: scoreboard will return the score for that roll
*********************************************************************/ 
//Catches special characters for the first roll
string specialChar1(int value){
    if (value == 10){
        return "X";
    }else if (value == 0){
        return "-";
    }
    return to_string(value);
}


/*********************************************************************
** Function: specialChar2
** Description: Catches special characters for the second roll
** Parameters:  first roll value, second roll value and the current frame
** Pre-Conditions: first and second rolls must be completed
** Post-Conditions: scoreboard will return the score for that roll
*********************************************************************/ 
string specialChar2(int value1, int value2, int i){
    // returns a strike for multiple strikes in the 10th frmae
    if (value1 == 10 and value2 == 10){
        return "X";
    }else if (value1 + value2 == 10 and value2 != 0){
        return "/";
    }else if (value1 == 10 and i != 9){
        return " ";
    }else if (value2 == 0){
        return "-";
    }
    return to_string(value2);
}


/*********************************************************************
** Function: output
** Description: Outpus the scoreboard after each roll
** Parameters: Current frame, score array, roll number
** Pre-Conditions: atleast one roll is completed
** Post-Conditions: scoreboard will be printed out
** Over 15 line justification: The output can't be done in less lines because of the two for loops
*********************************************************************/ 
void output(int f, int fr[10][4], int roll){
    cout << "Name    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10  |Total" <<endl;
    cout << "-----------------------------------------------------------------------------" <<endl;
    cout << "Player1 |";
    for (int i = 0; i < 10; i++){
        if ((i < f and roll == 1) or (i <= f and roll == 2) or (i < 9 and roll == 3)){
            // prints out each roll for all frames that have been completed
            cout << setw(2)<< specialChar1(fr[i][0])
            << setw(3)<< specialChar2(fr[i][0], fr[i][1], i)<< "|";

        }else if (i == f and roll == 1){
            //prints out the first roll in the first frame
            cout << setw(2)<< specialChar1(fr[i][0])<< setw(4)<< "|";

        }else if(i == 9 and roll == 3){
            //prints out the last frame if there are 3 rolls
            cout << setw(1) << specialChar1(fr[i][0]) 
            << setw(2)<< specialChar2(fr[i][0], fr[i][1], i) 
            << " " << specialChar1(fr[i][2]) << "|";

        }else{
            cout << setw(6)<<"|";
        }
    }
    // prints out a 0 for the first roll's total score
    if (f == 0 and roll == 1){
        cout << "0" << endl;
    } //prints out total score after first roll is completed
    else if (roll == 1){
        cout << fr[f - 1][3] << endl;
    } //prints out total score after second roll is completed
    else{
        cout << fr[f][3] << endl;
    }
    cout << "        |";
    for (int i = 0; i < 10; i++){
        //prints out total score for frames that have been completed
        if ((i < f and (roll == 1 or roll == 3)) or (i <= f and roll == 2)){
            cout << setw(5) << fr[i][3]<< "|";
        }//prints out the final score
        else if(i == 9 and roll == 3){
            cout << setw(5) << fr[i][3]<< "|";
        }else{
            cout << setw(6)<<"|";
        }
    }
    cout << endl << "-----------------------------------------------------------------------------\n\n\n";
}


/*********************************************************************
** Function: rollOne
** Description: Completes the scoring for roll one
** Parameters: Current Frame, scoreboard array
** Pre-Conditions: User presses enter
** Post-Conditions: A value will be assigned to the first roll of a frame
** Over 15 line justification: Needed extra lines to adjust the scoreboard for strikes and spares
*********************************************************************/ 
void rollOne(int f, int fr[10][4]){
    if (f > 0){
        // sets the current frames total score equal to the previous frames total score
        fr[f][3] = fr[f - 1][3];
    }
    fr[f][0] = rand()%11;
    cout << "You Knocked Down " << fr[f][0] << " pins" << endl;

    //Calculates the score if the previous 2 frames were strikes, and the current is not
    if(fr[f - 1][0] == 10 and fr[f - 2][0] == 10 and fr[f][0] < 10){
        fr[f - 2][3] += fr[f][0];
        if (f < 9){
            fr[f - 1][3] += 2 * fr[f][0];
        }else{
            fr[f - 1][3] += fr[f][0];
        }
        fr[f][3] += 2 * fr[f][0];
    }
    //Calculates the scores for strikes
    if (fr[f][0] == 10){
        //Calculates the score for 3 strikes in a row
        if(fr[f - 1][0] == 10 and fr[f - 2][0] == 10){
            fr[f - 2][3] += 10;
            fr[f - 1][3] += 20;
            fr[f][3] += 20;
        } //Calculates the score if the previous frame was a strike or spare
        else if((fr[f - 1][0] == 10) or (fr[f - 1][0] + fr[f - 1][1] == 10)){
            fr[f - 1][3] += 10;
            fr[f][3] = fr[f - 1][3];
        } //Adds 10 to the total score if it isn't the last frame
        if(f < 9){
           fr[f][3] += 10; 
        }
    }
    output(f, fr, 1);
}


/*********************************************************************
** Function: rollTwo
** Description: Completes the scoring for roll two
** Parameters: current frame, scoreboard array
** Pre-Conditions: User presses enter
** Post-Conditions: A value will be assigned to the second roll of a frame
** Over 15 line justification: Needed extra lines to adjust the scoreboard for strikes and spares
*********************************************************************/ 
void rollTwo(int f, int fr[10][4]){
    // Resets the pins knocked down to 0 if the the player gets a strike in the last frame
    if (fr[f][0] == 10 and f == 9){
        fr[f][1] = rand()%11;
    }else{
        fr[f][1] = rand()%(11 - fr[f][0]);
    }

    cout << "You Knocked Down " << fr[f][1] << " pins" << endl;
    int frameTotal = fr[f][0] + fr[f][1];
    fr[f][3] += frameTotal;

    //Calculates special cases in the last frame
    if(fr[f - 1][0] == 10 and fr[9][0] == 10){
        if (fr[f][0] == 10){
            fr[f - 1][3] += fr[f][1];
            fr[f][3] += fr[f][1];
        }else{
            fr[f - 1][3] += fr[f][1];
            fr[f][3] += frameTotal;
        }

    }else if(fr[f - 1][0] == 10 and fr[9][0] != 10){
        fr[f - 1][3] += fr[f][1];
        fr[f][3] += fr[f][1]; 
         
    }else if (fr[f-1][0] + fr[f-1][1] == 10 and fr[9][0] != 10){
        fr[f - 1][3] += fr[f][0];
        fr[f][3] += fr[f][0];
    }

    output(f, fr, 2);
}


/*********************************************************************
** Function: rollThree
** Description: Completes the scoring for roll three
** Parameters: current frame, scoreboard array
** Pre-Conditions: User presses enter
** Post-Conditions: A value will be assigned to the third roll of a frame
*********************************************************************/ 
//Completes the scoring for roll three
void rollThree(int f, int fr[10][4]){
    //Resets the total pins knocked down if the second roll was a strike or spare
    if (fr[f][1] == 10 or fr[f][1] + fr[f][0] == 10){
        fr[f][2] = rand()%11;
    }else{
        fr[f][2] = rand()%(11 - fr[f][1]);
    }

    fr[f][3] += fr[f][2];

    output(f, fr, 3);
}


/*********************************************************************
** Function: frame
** Description: Iterates over each frame and runs the roll functions
** Parameters: none
** Pre-Conditions: The contGame variable must be equal to true
** Post-Conditions:
*********************************************************************/ 
void frame(){
    srand(time(NULL));
    //Initializes a 2d array to store 1st roll, 2nd roll, 3rd roll, and total score for each frame
    
    int fr[10][4] = {0};

    //Iterates over each frame in the scoreboard
    for (int i = 0; i < 10; i++){
        cout << "Frame " << i + 1 << "..." << endl;
        pressEnter();
        rollOne(i, fr);

        if (fr[i][0] < 10 or fr[9][0] == 10){
            pressEnter();
            rollTwo(i, fr);
        }     

        if ((fr[i][0] == 10 or fr[i][1] == 10 or fr[i][0] + fr[i][1] == 10) and i == 9){
            pressEnter();
            rollThree(i, fr);
        }
    }
}


/*********************************************************************
** Function: main
** Description: Runs the program until the user wants to quit
** Parameters:  none
** Pre-Conditions: none
** Post-Conditions: The program will either repeat or stop
*********************************************************************/ 
int main() {
    //boolean that keeps the game running
    bool contGame = true;

    string cont;

    //While loop that checks user input for correctiveness
    while (contGame){
        introduction();
        frame();
        //While loop continues to run until the user enters a valid input
        while (cont != "y" or cont != "n"){
            cout << "Press y to continue, n to exit:";
            cin >> cont;
            
            if (cont == "y"){
                break;
            }else if (cont == "n"){
                contGame = false;
                break;
            }else{
                cout << "Invalid Input. ";
            }
        }
    }
    return 0;
}