#include<iostream>
#include "pokemon.h"
#include<fstream>

using namespace std;

int main(){

    bool contDex = getUserFile();

    if (contDex == true){
        searchPrompt();


        //Need to move dynamic functions into main function
        delete_info(character);
    }

    return 0;
}