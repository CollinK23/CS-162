#include <iostream>
#include "pokemon.h"
#include <fstream>

using namespace std;

bool getUserFile(){
    string pokemonFile;
    ifstream fin;
    string line_;
    bool contDex = true;

    cout << "Enter the name of the file that contains information about Pokemon: ";
    cin >> pokemonFile;

    fin.open(pokemonFile.c_str());

    if (fin.is_open()){

        fin.close();

    }else{
        cout << pokemonFile << " Does Not Exist" << endl;
        contDex = false;
    }

    return contDex;

}

int selectSearchMethod(){
    int searchMethod;
    cout << "Choose a Way to Display the Pokedex Information"<< endl
    << "1. Search By Dex Number" << endl << "2. Search By Name" << endl
    << "3. Search By Type" << endl << "4. Add New Pokemon" << endl;

    cin >> searchMethod;

    return searchMethod;
}

void searchPrompt(){
    int searchMethod = selectSearchMethod();

    if (searchMethod == 1){
        int dexNum;
        cout << "Enter the Dex Number of the Pokemon: " << endl;
        cin >> dexNum;
        cout << "Function 1 Goes Here " << dexNum << endl;
        
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
        searchPrompt();
    }
}

Pokemon* create_pokemons(int){

}

void populate_pokedex_data(Pokedex & , ifstream &){

}

string* create_moves(int){

}

void populate_pokemon(Pokemon &, ifstream &){

}

void delete_info(Pokemon &){

}