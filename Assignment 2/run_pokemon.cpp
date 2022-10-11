#include<iostream>
#include "pokemon.h"
#include<fstream>

using namespace std;

int main(){

    bool contDex = getUserFile();

    if (contDex == true){
        searchPrompt();
    }

    return 0;
}