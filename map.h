#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

struct Map{
    int tMap[36][28];

    /*
    * Description: Constructor, reads and assigns the
    *              values of "mapText.txt" to tMap
    * Return: none
    * Precondition: the file, "mapText.txt", exists
    * Postcondition: tMap holds the location of the map tiles
    */
    Map(){
        ifstream input;
        input.open("mapText.txt");

        for(int i = 0; i < 36; i++){
            for(int k = 0; k < 28; k++){
                input >> tMap[i][k];
                cout << tMap[i][k] << " ";
            }
            cout << endl;
        }
    }

};

#endif // MAP_H_INCLUDED
