#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>

using namespace std;

void introduction(){
    string name;
    cout << "Welcome To Bowling!" << endl;
    cout << "What's Your Name?";
    cin >> name;
    cout << "Hello " << name << "!"<< endl;
}

string spec1(int value){
    if (value == 10){
        return "X";
    }else if (value == 0){
        return "-";
    }else{
        return to_string(value);
    }
}

string spec2(int value1, int value2, int rollNumber){
    if (value1 == 10 and value2 == 10){
        return "X";
    }else if (value1 + value2 == 10 and value2 != 0){
        return "/";
    }else if (value1 == 10 and rollNumber != 3){
        return " ";
    }else if (value2 == 0){
        return "-";
    }else{
        return to_string(value2);
    }
}


void output(int f, int (&totalScore), int fr[10][4], int rollNumber){
    cout << "Name    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10  |Total" <<endl;
    cout << "-----------------------------------------------------------------------------" <<endl;
    cout << "Player1 |";
    for (int i = 0; i < 10; i++){
        if ((i<f and rollNumber == 1) or (i<=f and rollNumber == 2) or (i<9 and rollNumber == 3)){
            cout << setw(2)<< spec1(fr[i][0])<< setw(3)<< spec2(fr[i][0], fr[i][1], rollNumber)<< "|";
        }else if (i==f and rollNumber == 1){
            cout << setw(2)<< spec1(fr[i][0])<< setw(4)<< "|";
        }else if(i == 9 and rollNumber == 3){
            cout << setw(1) << spec1(fr[i][0]) << setw(3)<< spec2(fr[i][0], fr[i][1], rollNumber)<< spec1(fr[i][2]) << "|";
        }
        else{
            cout << setw(6)<<"|";
        }
    }
    cout << totalScore << endl;
    cout << "        |";
    for (int i = 0; i < 10; i++){
        if ((i<f and (rollNumber == 1 or rollNumber == 3)) or (i<=f and rollNumber == 2)){
            cout << setw(5) << fr[i][3]<< "|";
        }else if(i == 9 and rollNumber == 3){
            cout << setw(5) << totalScore<< "|";
        }
        else{
            cout << setw(6)<<"|";
        }
    }
    cout << endl;
}

int rollOne(int &totalScore, int f, int fr[10][4]){
    int firstRoll = rand()%11;
    int rollNumber = 1;
    cout << "You Knocked Down " << firstRoll << " pins" << endl;
    fr[f][0] = firstRoll;

    if(fr[f - 1][0] == 10 and fr[f - 2][0] == 10 and firstRoll < 10){
        fr[f - 2][3] += firstRoll;
        fr[f - 1][3] += (2 * firstRoll);
        totalScore += (2 * firstRoll);
    }

    if (firstRoll == 10){
        if(fr[f - 1][0] == 10 and fr[f - 2][0] == 10){
            fr[f - 2][3] += 10;
            fr[f - 1][3] += 20;
            totalScore += 20;
        }else if((fr[f - 1][0] == 10) or (fr[f - 1][0] + fr[f - 1][1] == 10)){
            fr[f - 1][3] += 10;
            totalScore = fr[f - 1][3];
        }
        totalScore += 10;
        fr[f][3] = totalScore;
    }
    output(f, totalScore, fr, rollNumber);
    return firstRoll;
}

int rollTwo(int (&totalScore), int pinsLeft, int firstRoll, int f, int fr[10][4]){
    int secondRoll;
    int rollNumber = 2;
    if (firstRoll == 10 and f == 9){
        pinsLeft = 10;
        secondRoll = rand()%11;
    }else{
    secondRoll = rand()%(pinsLeft + 1);
    }
    pinsLeft -= secondRoll;
    cout << "You Knocked Down " << secondRoll << " pins" << endl;
    fr[f][1] = secondRoll;
    totalScore += (firstRoll + secondRoll);
    fr[f][3] = totalScore;

    if(fr[f - 1][0] == 10 and fr[9][0] != 10){
        fr[f - 1][3] += (firstRoll + secondRoll);
        totalScore += (firstRoll + secondRoll);
        fr[f][3] = totalScore;
    }else if (fr[f-1][0] + fr[f-1][1] == 10 and fr[9][0] != 10){
        fr[f - 1][3] += firstRoll;
        totalScore += firstRoll;
        fr[f][3] = totalScore;
    }

    output(f, totalScore, fr, rollNumber);
    return secondRoll;
}

void rollThree(int f, int fr[10][4], int (&totalScore)){
    int rollNumber = 3;
    int thirdRoll;
    if (fr[f][1] == 10 or fr[f][0] == 10 or fr[f][1] + fr[f][0] == 10){
        thirdRoll = rand()%11;
    }else{
        thirdRoll = rand()%(11 - fr[f][1]);
    }
    fr[f][2] = thirdRoll;
    totalScore += thirdRoll;

    output(f, totalScore, fr, rollNumber);
}

void frame(){
    int totalScore = 0;
    srand(time(NULL));
    int fr[10][4] = {0};
    int pinsLeft = 10;
    int firstRoll;
    int secondRoll;

    for (int i = 0; i < 10; i++){
        pinsLeft = 10;
        cout << "Frame " << i + 1 << endl;
        cout << "Press Enter To Roll" << endl;
        cin.get();

        firstRoll = rollOne(totalScore, i, fr);
        pinsLeft -= firstRoll;

        if (pinsLeft > 0 or fr[9][0] == 10){
            cout << "Press Enter To Roll" << endl;
            cin.get();
            secondRoll = rollTwo(totalScore, pinsLeft, firstRoll, i, fr);
            pinsLeft -= secondRoll;
            cout << "\n\n";
        }     
        if ((firstRoll == 10 or secondRoll == 10 or firstRoll + secondRoll == 10) and i == 9){
            cout << "Press Enter To Roll" << endl;
            cin.get();
            rollThree(i, fr, totalScore);
            cout << "\n\n";
        }
    }
}

int main() {
    bool contGame = true;
    string cont;

    introduction();

    while (contGame){
        frame();
        while (cont != "y" or cont != "n"){
            cont = "";
            cout << "Press y to continue, n to exit:" << cont;
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