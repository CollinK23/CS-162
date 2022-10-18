#include <iostream>
#include "pokemon.h"
#include <fstream>
#include <limits>

using namespace std;

Pokemon* create_pokemons(int numOfPokemon){
    Pokemon* dex = new Pokemon[numOfPokemon];
    return dex;

}

string* create_moves(int numOfMoves){
    string* moves = new string [numOfMoves];
    return moves;
}

void populate_pokemon(Pokemon* selectPokemon, ifstream &fin, int numOfPokemon){
    for (int i = 0; i < numOfPokemon; i++){
        fin >> selectPokemon[i].dex_num;
        fin >> selectPokemon[i].name;
        fin >> selectPokemon[i].type;
        fin >> selectPokemon[i].num_moves;

        string* moves = create_moves(selectPokemon[i].num_moves);

        for (int j = 0; j < selectPokemon[i].num_moves; j++){
            selectPokemon[i].moves = moves;
            fin >> selectPokemon[i].moves[j];
        }
    }
}

void populate_pokedex_data(Pokedex &info , ifstream &fin){

    int numOfPokemon;
    info.trainer = "Collin";

}

void delete_info(Pokemon* selectPokemon, int numOfPokemon){
    for (int i = 0; i < numOfPokemon; i++){
        delete []selectPokemon[i].moves;
    }

    delete []selectPokemon;
    selectPokemon = NULL;
}




//------------------------------------------------ OUTPUT FUNCTIONS ----------------------------------------------------------------------------


void txtOutput(int j, Pokemon* selectPokemon, int numOfPokemon){
    ofstream fout;
    string fileName;
    
    cout << "Select The File You Want To Output To: " << endl;
    cin >> fileName;

    fout.open(fileName.c_str());


    fout << "Dex Number: " << selectPokemon[j].dex_num << endl;
    fout << "Name: " << selectPokemon[j].name << endl;
    fout << "Type: " << selectPokemon[j].type << endl;
    fout << "Number of Moves: " << selectPokemon[j].num_moves << endl;
    
    for (int i = 0; i < selectPokemon[j].num_moves; i++){
        fout << "Move" << i + 1 << ": " << selectPokemon[j].moves[i] << endl;
    }
}

void terminalOutput(int j, Pokemon* selectPokemon, int numOfPokemon){
    cout << "Dex Number: " << selectPokemon[j].dex_num << endl;
    cout << "Name: " << selectPokemon[j].name << endl;
    cout << "Type: " << selectPokemon[j].type << endl;
    cout << "Number of Moves: " << selectPokemon[j].num_moves << endl;
    
    for (int i = 0; i < selectPokemon[j].num_moves; i++){
        cout << "Move" << i + 1 << ": " << selectPokemon[j].moves[i] << endl;
    }
}

int searchByDex(Pokemon* selectPokemon, int dexNum, int numOfPokemon){
    int selectOutput;
    for (int j = 0; j < numOfPokemon; j++){
        if (selectPokemon[j].dex_num == dexNum){
            while (true){
                cout << "(1.) Output to .txt File" << endl;
                cout << "(2.) Output to Terminal" << endl;
                cin >> selectOutput;

                if (selectOutput == 1){
                    txtOutput(j, selectPokemon, numOfPokemon);
                    return 0;
                }else if (selectOutput == 2){
                    terminalOutput(j, selectPokemon, numOfPokemon);
                    return 0;
                }else if (selectOutput != 1 or selectOutput != 2){
                    searchPrompt(numOfPokemon, selectPokemon);
                    return 0;
                }
            }
        }
    }
    cout << "Pokemon Does Not Exist In the Dex" << endl;
    searchPrompt(numOfPokemon, selectPokemon);
}

int selectSearchMethod(){
    int searchMethod;

    cout << "Choose a Way to Display the Pokedex Information"<< endl;
    cout << "1. Search By Dex Number" << endl << "2. Search By Name" << endl;
    cout << "3. Search By Type" << endl << "4. Add New Pokemon" << endl;

    cin >> searchMethod;

    return searchMethod;
}

void searchPrompt(int numOfPokemon, Pokemon* selectPokemon){
    int searchMethod = selectSearchMethod();

    cout << "Enter the Dex Number of the Pokemon: " << endl;
    if (searchMethod == 1){
        int dexNum;
        while (true){
            cin >> dexNum;

            if (!cin){
                cout << "Invalid Dex Number. Enter again: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                continue;
            }
            else break;
        }
        searchByDex(selectPokemon, dexNum, numOfPokemon);
        
    }else if (searchMethod == 2){
        string pokeName;
        cout << "Enter the Name of the Pokemon: " << endl;
        cin >> pokeName;
        cout << "Function 2 Goes Here " << pokeName << endl;

    }else if (searchMethod == 3){
        string pokeType;
        cout << "Enter the Type of the Pokemon: " <<endl;
        cin >> pokeType;
        cout << "Function 3 Goes Here " << pokeType << endl;

    }else if (searchMethod == 4){
        cout << "Function 4 Goes Here" << endl;

    }else{
        searchPrompt(numOfPokemon, selectPokemon);
    }
}