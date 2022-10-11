#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>

using namespace std;

void pressEnter(){
    string temp;
    cout << "Press Enter To Roll" << endl;
    getline(cin, temp);
}

void introduction(){
    string name;
    cout << "Welcome To Bowling!" << endl;
    cout << "What's Your Name?";
    cin >> name;
    cout << endl << "Hello " << name << "!"<< endl << endl;
    getline(cin, name);
}

string specialChar1(int value){
    if (value == 10){
        return "X";
    }else if (value == 0){
        return "-";
    }
    return to_string(value);
}

string specialChar2(int value1, int value2, int i){
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

void output(int f, int fr[10][4], int roll){
    cout << "Name    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10  |Total" <<endl;
    cout << "-----------------------------------------------------------------------------" <<endl;
    cout << "Player1 |";
    for (int i = 0; i < 10; i++){
        if ((i < f and roll == 1) or (i <= f and roll == 2) or (i < 9 and roll == 3)){
            cout << setw(2)<< specialChar1(fr[i][0])
            << setw(3)<< specialChar2(fr[i][0], fr[i][1], i)<< "|";

        }else if (i == f and roll == 1){
            cout << setw(2)<< specialChar1(fr[i][0])<< setw(4)<< "|";

        }else if(i == 9 and roll == 3){
            cout << setw(1) << specialChar1(fr[i][0]) 
            << setw(2)<< specialChar2(fr[i][0], fr[i][1], i) 
            << " " << specialChar1(fr[i][2]) << "|";

        }else{
            cout << setw(6)<<"|";
        }
    }
    if (f == 0 and roll == 1){
        cout << "0" << endl;
    }else if (roll == 1){
        cout << fr[f - 1][3] << endl;
    }else{
        cout << fr[f][3] << endl;
    }
    cout << "        |";
    for (int i = 0; i < 10; i++){
        if ((i < f and (roll == 1 or roll == 3)) or (i <= f and roll == 2)){
            cout << setw(5) << fr[i][3]<< "|";
        }else if(i == 9 and roll == 3){
            cout << setw(5) << fr[i][3]<< "|";
        }else{
            cout << setw(6)<<"|";
        }
    }
    cout << endl << "-----------------------------------------------------------------------------\n\n\n";
}

void rollOne(int f, int fr[10][4]){
    if (f > 0){
        fr[f][3] = fr[f - 1][3];
    }
    fr[f][0] = rand()%11;
    cout << "You Knocked Down " << fr[f][0] << " pins" << endl;

    if(fr[f - 1][0] == 10 and fr[f - 2][0] == 10 and fr[f][0] < 10){
        fr[f - 2][3] += fr[f][0];
        if (f < 9){
            fr[f - 1][3] += 2 * fr[f][0];
        }else{
            fr[f - 1][3] += fr[f][0];
        }
        fr[f][3] += 2 * fr[f][0];
    }
    if (fr[f][0] == 10){
        if(fr[f - 1][0] == 10 and fr[f - 2][0] == 10){
            fr[f - 2][3] += 10;
            fr[f - 1][3] += 20;
            fr[f][3] += 20;
        }else if((fr[f - 1][0] == 10) or (fr[f - 1][0] + fr[f - 1][1] == 10)){
            fr[f - 1][3] += 10;
            fr[f][3] = fr[f - 1][3];
        }
        if(f < 9){
           fr[f][3] += 10; 
        }
    }
    output(f, fr, 1);
}

void rollTwo(int f, int fr[10][4]){
    if (fr[f][0] == 10 and f == 9){
        fr[f][1] = rand()%11;
    }else{
        fr[f][1] = rand()%(11 - fr[f][0]);
    }

    cout << "You Knocked Down " << fr[f][1] << " pins" << endl;
    int frameTotal = fr[f][0] + fr[f][1];
    fr[f][3] += frameTotal;

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

void rollThree(int f, int fr[10][4]){
    if (fr[f][1] == 10 or fr[f][1] + fr[f][0] == 10){
        fr[f][2] = rand()%11;
    }else{
        fr[f][2] = rand()%(11 - fr[f][1]);
    }

    fr[f][3] += fr[f][2];

    output(f, fr, 3);
}

void frame(){
    srand(time(NULL));
    int fr[10][4] = {0};
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

int main() {
    bool contGame = true;
    string cont;

    while (contGame){
        introduction();
        frame();
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