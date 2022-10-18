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
    Pokemon* dex;
};

bool getUserFile();

int selectSearchMethod();

void searchPrompt(int, Pokemon* selectPokemon);

Pokemon* create_pokemons(int);

void populate_pokedex_data(Pokedex & , ifstream &);

string* create_moves(int);

void populate_pokemon(Pokemon* selectPokemon, ifstream &, int);

void delete_info(Pokemon* selectPokemon, int);

#endif
