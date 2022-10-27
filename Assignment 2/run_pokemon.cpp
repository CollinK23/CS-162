#include<iostream>
#include "pokemon.h"
#include<fstream>

using namespace std;

/*********************************************************************
** Function: main
** Description: Calls functions from pokemon.cpp and checks if the .txt file exists
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: File will either open and run functions from pokemon.cpp or a message will be output to the user
*********************************************************************/ 
int main(){

    string pokemonFile;
    //Creates ifstream object
    ifstream fin;

    cout << "Enter the name of the file that contains information about Pokemon: ";
    cin >> pokemonFile;

    //converts the file string into a c-string 
    fin.open(pokemonFile.c_str());

    if (fin.is_open()){

        int numOfPokemon;

        //Reads the number of pokemon from the .txt file and stores it as an integer

        fin >> numOfPokemon;

        //Creates the info struct
        Pokedex info;

        //Adds the number of pokemon into the info struct
        info.num_pokemon = numOfPokemon;

        populate_pokedex_data(info, fin);

        searchPrompt(numOfPokemon, info);

        fin.close();

        //Deletes the memory that was allocated to Pokemon and move arrays
        delete_info(info);

    }else{
        //If the file doesn't exist, this message will be output to the user
        cout << pokemonFile << " Does Not Exist" << endl;
    }

    return 0;
}