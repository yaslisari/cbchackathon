//
//  csvReader.cpp
//  commentAnalyzer
//
//  Created by Nazli Bozoglu on 2015-03-15.
//  Copyright (c) 2015 Asli. All rights reserved.
//

#include "csvReader.h"
#include <fstream>
#include <iostream>


using namespace std;

vector<string> CSVReader::getCommentsVector(){
    return comments;
}

CSVReader::CSVReader(string filename){
    
    ifstream stopWordsFile;
    ifstream myReadFile;
    myReadFile.open(filename);
    string STRING;

    int lineCount = 0;
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            getline(myReadFile,STRING); // Saves the line in STRING.
            try {
                comments.push_back(STRING);
            } catch(exception& e){
                cout << "Vector dimensions exceeded" << endl;
            }
             //std::cout<<STRING << endl; // Prints our STRING.
            lineCount++;
            
        }
    }
    myReadFile.close();
}