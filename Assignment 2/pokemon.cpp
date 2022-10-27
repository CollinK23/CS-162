/******************************************************
** Program: pokemon.cpp
** Author: Collin Kimball
** Date: 10/22/2022
** Description: User selects a .txt file they want to read information from, and chooses a search method they want
                to use to find a Pokemon.
** Input: .txt file
** Output: Pokemon Information, .txt file
******************************************************/
#include <iostream>
#include "pokemon.h"
#include <fstream>
#include <string>
#include <limits>

using namespace std;

/*********************************************************************
** Function: Pokemon* create_pokemons
** Description: Dynamically allocate an array of Pokemon
** Parameters: number of pokemon
** Pre-Conditions: ifstream needs to read the number of Pokemon from the .txt file
** Post-Conditions: memory will be allocated for an array of Pokemon
*********************************************************************/
Pokemon* create_pokemons(int numOfPokemon){
    //Creates an array of Pokemon with a dynamic length
    Pokemon* dex = new Pokemon[numOfPokemon];
    return dex;

}

/*********************************************************************
** Function: string* create_moves
** Description: Dynamically allocates on array of Moves
** Parameters: Number of moves that the Pokemon has
** Pre-Conditions: ifstream needs to read the number of moves the Pokemon has
** Post-Conditions: Memory will be allocated for an array of moves
*********************************************************************/ 
string* create_moves(int numOfMoves){
    //Creates an array of Moves with a dynamic length
    string* moves = new string [numOfMoves];
    return moves;
}

/*********************************************************************
** Function: populate_pokemon
** Description: Reads information about a Pokemon from the .txt file
** Parameters: Reference to selectPokemon struct and fin
** Pre-Conditions: The .txt file that the user enters exists
** Post-Conditions: Information for a specific Pokemon will be stored in a struct
*********************************************************************/ 
void populate_pokemon(Pokemon& selectPokemon, ifstream &fin){
    //Reads the Pokemon data fro mthe .txt file and stores it inside the Pokemon struct
    fin >> selectPokemon.dex_num;
    fin >> selectPokemon.name;
    fin >> selectPokemon.type;
    fin >> selectPokemon.num_moves;

    string* moves = create_moves(selectPokemon.num_moves);

    //Runs a dynamic Number of times based on how many total moves the Pokemon has
    for (int j = 0; j < selectPokemon.num_moves; j++){
        selectPokemon.moves = moves;
        fin >> selectPokemon.moves[j];
    }
}

/*********************************************************************
** Function: populate_pokedex_data
** Description: Stores the array of Pokemon into a Pokemon Struct and iterates through
                the entie .txt file
** Parameters: Reference to info struct and fin
** Pre-Conditions: the .txt file that the user enters exists
** Post-Conditions: The enitre .txt file will be read and each Pokemon will be stored in seperate structs
*********************************************************************/ 
void populate_pokedex_data(Pokedex &info , ifstream &fin){

    info.selectPokemon = create_pokemons(info.num_pokemon);

    //Iterates through the populate_pokemon function for each Pokemon in the .txt file
    for (int i = 0; i < info.num_pokemon; i++){
        populate_pokemon(info.selectPokemon[i], fin);
    }

}

/*********************************************************************
** Function: delete_info
** Description: deletes memory allocation from the heap
** Parameters:  Reference to the info struct
** Pre-Conditions: Memory is being allocated to the heap
** Post-Conditions: All Memory will be freed
*********************************************************************/ 
void delete_info(Pokedex& info){
    //Deletes the memory allocated to the moves array
    for (int i = 0; i < info.num_pokemon; i++){
        delete []info.selectPokemon[i].moves;
    }

    //Deletes the memory allocated to the Pokemon array
    delete []info.selectPokemon;
    info.selectPokemon = NULL;
}


//------------------------------------------------ OUTPUT FUNCTIONS ----------------------------------------------------------------------------

/*********************************************************************
** Function: txtOutput
** Description: Outputs the Pokemon Information to a .txt file
** Parameters: for loop index number, reference to info struct, number of total Pokemon
** Pre-Conditions: User must select the option to output to a .txt file
** Post-Conditions:
*********************************************************************/ 
void txtOutput(int j, Pokedex& info, int numOfPokemon){
    //Creates an ofstram object
    ofstream fout;
    string fileName;
    
    //User selects the File they want to use
    cout << "Select The File You Want To Output To: " << endl;
    cin >> fileName;

    //Opens the file that the information will be written on
    fout.open(fileName.c_str(), ios::app);

    //Writes the information to the open file
    fout << "Dex Number: " << info.selectPokemon[j].dex_num << endl;
    fout << "Name: " << info.selectPokemon[j].name << endl;
    fout << "Type: " << info.selectPokemon[j].type << endl;
    fout << "Number of Moves: " << info.selectPokemon[j].num_moves << endl;
    
    //Outputs each Move that the Pokemon Has
    for (int i = 0; i < info.selectPokemon[j].num_moves; i++){
        fout << "Move" << i + 1 << ": " << info.selectPokemon[j].moves[i] << endl;
    }

    fout << endl << endl;
    //Closes the .txt file
    fout.close();
}

/*********************************************************************
** Function: terminalOutput
** Description: Outputs the Pokemon information into the terminal
** Parameters: For loop index number, reference to info struct, number of Pokemon
** Pre-Conditions: User must select the option to print the data in the terminal
** Post-Conditions:
*********************************************************************/ 
void terminalOutput(int j, Pokedex& info, int numOfPokemon){
    //Outputs Pokemon Data in the Terminal
    cout << "Dex Number: " << info.selectPokemon[j].dex_num << endl;
    cout << "Name: " << info.selectPokemon[j].name << endl;
    cout << "Type: " << info.selectPokemon[j].type << endl;
    cout << "Number of Moves: " << info.selectPokemon[j].num_moves << endl;
    
    for (int i = 0; i < info.selectPokemon[j].num_moves; i++){
        cout << "Move" << i + 1 << ": " << info.selectPokemon[j].moves[i] << endl;
    }

    cout << endl << endl;
}

//----------------------------------------------- SEARCH METHODS --------------------------------------------

/*********************************************************************
** Function: outputSelector
** Description: The user chooses which method they want to use to ouptut the Pokemon data
** Parameters: None
** Pre-Conditions: Pokemon must exist in the .txt file
** Post-Conditions: The output method is based on which option the user selects
*********************************************************************/ 
int outputSelector(){
    int selectOutput;
    //While loop that only breaks if user enters 1 or 2
    while (true){
        cout << "(1.) Output to .txt File" << endl;
        cout << "(2.) Output to Terminal" << endl;
        cin >> selectOutput;
        if (selectOutput == 1 or selectOutput == 2){
            break;
        }else {
            cout << "Invalid Output Format" << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
    }
    return selectOutput;
}

/*********************************************************************
** Function: searchByDex
** Description:Will search for the pokemon with the same dex number as the one that the user enters
** Parameters: Reference to info struct, dex number that user enters, total number of pokemon
** Pre-Conditions: User enters a dex number they want to search for
** Post-Conditions: Data will be output to terminal or .txt file
*********************************************************************/ 
void searchByDex(Pokedex& info, int dexNum, int numOfPokemon){
    //Intializing boolean expression to check whether a Pokemon has been found
    bool found = false;
    //Iterates through each Pokemon struct to check if a dex number matches the one that the user inputs
    for (int j = 0; j < numOfPokemon; j++){
        if (info.selectPokemon[j].dex_num == dexNum){
            found = true;
            int selectOutput = outputSelector();
            //Pokemon Info will be output on .txt file if the user selects 1 in the outputSelector() function
            if (selectOutput == 1){
                txtOutput(j, info, numOfPokemon);
            }
            //Pokemon Info will be output to terminal if the user selects 2 in the outputSelector() function
            else if (selectOutput == 2){
                terminalOutput(j, info, numOfPokemon);
            }
        }
    }
    //If Pokemon is not found, output a message
    if (!found){
        cout << "Pokemon Does Not Exist In the Dex" << endl;
    }
}

/*********************************************************************
** Function: searchByName
** Description: Will search for the pokemon with the same name as the one that the user enters
** Parameters: Reference to info struct, name that user enters, total number of pokemon
** Pre-Conditions: User enters a name they want to search for
** Post-Conditions: Data will be output to terminal or .txt file
*********************************************************************/ 
void searchByName(Pokedex& info, string pokeName, int numOfPokemon){
    bool found = false;
    //Iterates through each Pokemon struct to check if a Pokemon name matches the one that the user inputs
    for (int j = 0; j < numOfPokemon; j++){
        if (info.selectPokemon[j].name == pokeName){
            found = true;
            int selectOutput = outputSelector();
            //Pokemon Info will be output on .txt file if the user selects 1 in the outputSelector() function
            if (selectOutput == 1){
                txtOutput(j, info, numOfPokemon);
            }
            //Pokemon Info will be output to terminal if the user selects 2 in the outputSelector() function
            else if (selectOutput == 2){
                terminalOutput(j, info, numOfPokemon);
            }
        }
    }
    //If Pokemon is not found, output a message
    if (!found){
        cout << "Pokemon Does Not Exist In the Dex" << endl;
    }
}

/*********************************************************************
** Function: searchByType
** Description: Will search for Pokemon with the same type as the one that the user enters
** Parameters: Reference to info struct, type that the user enters, number of pokemon
** Pre-Conditions: User enters a type of Pokemon they want to search for
** Post-Conditions: Data will be output to terminal or .txt file
** Over 15 lines: fout statements did not work when put in other functions
*********************************************************************/ 
void searchByType(Pokedex& info, string pokeType, int numOfPokemon){
        int selectOutput = outputSelector();
        //Creates ofstream object
        ofstream fout;
        string fileName;
        bool exists = false;

        if (selectOutput == 1){
            cout << "Select The File You Want To Output To: " << endl;
            cin >> fileName;

            fout.open(fileName.c_str(), ios::app);
        }

        //Iterates through each Pokemon to check if they have the same type as the one that the user entered
        for (int j = 0; j < numOfPokemon; j++){
            if (info.selectPokemon[j].type == pokeType){
                exists = true;
                //If the user selected one, the data will be written to the file that they entered
                if (selectOutput == 1){
                    fout << "Dex Number: " << info.selectPokemon[j].dex_num << endl;
                    fout << "Name: " << info.selectPokemon[j].name << endl;
                    fout << "Type: " << info.selectPokemon[j].type << endl;
                    fout << "Number of Moves: " << info.selectPokemon[j].num_moves << endl;
                    
                    for (int i = 0; i < info.selectPokemon[j].num_moves; i++){
                        fout << "Move" << i + 1 << ": " << info.selectPokemon[j].moves[i] << endl;
                    }

                    fout << endl << endl;
                //if the user selected two the data will be output in the terminal
                }else if (selectOutput == 2){
                    terminalOutput(j, info, numOfPokemon);
                }
            }
       }fout.close();
    //if the type doesnt exist in the .txt file, a message will be output to the user
    if (!exists){
        cout << pokeType<< " Type Pokemon Do Not Exist In This Dex"<< endl;
    }
}


/*********************************************************************
** Function: selectSearchMethod
** Description: User is prompted with ways to search for a Pokemon
** Parameters: none
** Pre-Conditions: .txt file must exist
** Post-Conditions: 
*********************************************************************/ 
int selectSearchMethod(){
    int searchMethod;
    searchMethod = 4;

    cout << "Choose a Way to Display the Pokedex Information"<< endl;
    cout << "1. Search By Dex Number" << endl;
    cout << "2. Search By Name" << endl;
    cout << "3. Search By Type" << endl;
    cout << "4. Exit Program" << endl << endl;
    //The option the user selects will be stores an integer
    cin >> searchMethod;

    return searchMethod;
}


/*********************************************************************
** Function: searchPrompt
** Description: Runs other function based on which search method the user selected
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/ 
void searchPrompt(int numOfPokemon, Pokedex& info){
    int searchMethod;
    
    //Will continue running until the user presses 4 to quit the program
    while (searchMethod != 4){

        searchMethod = selectSearchMethod();

        //If the user entered one, the function will run a function that searches for Pokemon by dex number
        if (searchMethod == 1){
            int dexNum;
            cout << "Enter the Dex Number of the Pokemon: " << endl;
            cin >> dexNum;
            searchByDex(info, dexNum, numOfPokemon);
            
        }
        //If the user entered two, the function will run a function that searches for Pokemon by name
        else if (searchMethod == 2){
            string pokeName;
            cout << "Enter the Name of the Pokemon" << endl;
            cin >> pokeName;
            searchByName(info, pokeName, numOfPokemon);

        }
        //If the user entered three, the function will run a function that searches for Pokemon by type
        else if (searchMethod == 3){
            string pokeType;
            cout << "Enter the Type of the Pokemon" << endl;
            cin >> pokeType;
            searchByType(info, pokeType, numOfPokemon);

        }
    }
}