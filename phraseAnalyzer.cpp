//
//  phraseAnalyzer.cpp
//  commentAnalyzer
//
//  Created by Asli Sari on 2015-03-14.
//  Copyright (c) 2015 Asli. All rights reserved.
//

#include "phraseAnalyzer.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct words{
    int count;
    string word;
    int locationInWordsVector;
    words() : count(0) {} //instead of int count = 0
};

void printVector(vector<string> v){
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
}


vector<string> loadWordVectors(string fileLocation){
    vector<string> wordsVector;
    ifstream wordsFile;
    wordsFile.open(fileLocation);
    
    int lineCount = 0;
    if (wordsFile.is_open()) {
      //  while (!wordsFile.eof()) {
        //    string line;
        string word;
         //   getline(wordsFile,line); // Saves the line in STRING.
        while (wordsFile >> word) {
            try {
                 wordsVector.push_back(word);
            } catch(exception& e){
                cout << "Vector dimensions exceeded" << endl;
            }
            // std::cout<<STRING << endl; // Prints our STRING.
            lineCount++;
            
        }
    }
    wordsFile.close();
    
    return wordsVector;
    
}

PhraseAnalyzer::PhraseAnalyzer(string phrase){
    
    //load stop words
    ifstream stopWordsFile;
    vector<string> stopWordsVector = loadWordVectors("english.stop.txt");
    
    //load positive list of words
    ifstream positiveWordsFile;
    vector<string> positiveWordsVector = loadWordVectors("positive-words.txt");

    //load positive list of words
    ifstream negativeWordsFile;
    vector<string> negativeWordsVector = loadWordVectors("negative-words.txt");
}