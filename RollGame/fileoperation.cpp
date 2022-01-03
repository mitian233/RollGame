#include <iostream>
#include <fstream>
using namespace std;

int writeToFile(int score) {
    ofstream myfile;
    myfile.open("data.txt");
    myfile << score;
    myfile.close();
    return 0;
}

int readFromFile(int score) {
    ofstream myfile;
    myfile.open("data.txt");
    if (!myfile) {
        cout << "Error opening file or file does not exist. " << endl;
        return 0;
        writeToFile(0);
    }
    else {
        new char 
        const char* cs;
        cs[] = score;
        cout << "Game data successfully opened. " << endl;
        int score1 = 0;
        myfile.write(cs,9);
        return score1;
    }
}