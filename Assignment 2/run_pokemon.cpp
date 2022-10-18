#include<iostream>
#include "pokemon.h"
#include<fstream>

using namespace std;

int main(){

    string pokemonFile;
    ifstream fin;
    ifstream forLoopCounter;
    string line_;

    cout << "Enter the name of the file that contains information about Pokemon: ";
    cin >> pokemonFile;

    fin.open(pokemonFile.c_str());

    if (fin.is_open()){

        int numOfPokemon;

        fin >> numOfPokemon;

        Pokedex info;

        populate_pokedex_data(info, fin);

        Pokemon* selectPokemon = create_pokemons(numOfPokemon);

        populate_pokemon(selectPokemon, fin, numOfPokemon);

        searchPrompt(numOfPokemon, selectPokemon);

        fin.close();

        delete_info(selectPokemon, numOfPokemon);

    }else{
        cout << pokemonFile << " Does Not Exist" << endl;
    }

    return 0;
}