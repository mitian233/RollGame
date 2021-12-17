#include <iostream>
#include <fstream>
int writeToFile(int score) {
    ofstream myfile;
    myfile.open("data.txt");
    myfile << score;
    myfile.close();
    return 0;
}

int readFromFile() {
    ofstream myfile;
    myfile.open("data.txt");
    if (!myfile) {
        cout << "Error opening file or file does not exist. " << endl;
        return 0;
        writeToFile(0);
    }
    else {
        cout << "Game data successfully opened. " << endl;
        int score;
        myfile.write >> score;
        return score;
    }
}