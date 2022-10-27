#include <string>
#ifndef POKEMON
#define POKEMON

using namespace std;

struct Pokemon {
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};

struct Pokedex {
    string trainer;
    int num_pokemon;
    Pokemon* selectPokemon;
};

bool getUserFile();

int selectSearchMethod();

void searchPrompt(int, Pokedex&);

Pokemon* create_pokemons(int);

void populate_pokedex_data(Pokedex & , ifstream &);

string* create_moves(int);

void populate_pokemon(Pokemon&, ifstream &);

void delete_info(Pokedex&);

#endif
