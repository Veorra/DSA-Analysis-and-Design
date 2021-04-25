#include <iostream>
#include<string>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{

    ifstream myFile;
    myFile.open("Project 2 - Sheet1.csv");

    while (myFile.good()){
        string line;
        getline(myFile, line, ',');
        cout << line << endl;

    }
    myFile.close();
}