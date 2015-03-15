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
#include <algorithm>

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

//std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
//    std::stringstream ss(s);
//    std::string item;
//    while (std::getline(ss, item, delim)) {
//        elems.push_back(item);
//    }
//    return elems;
//}


vector<string> stringToVector(string st){
    vector<string> stVector;
    
    char * writable = new char[st.size() + 1];
    std::copy(st.begin(), st.end(), writable);
    writable[st.size()] = '\0'; // don't forget the terminating 0

    
    char *p = strtok(writable, " ,.?!;");
    while (p) {
        string word = p;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        stVector.push_back(word);
        //string a = questionsVector.at(i).wordsInQuestion.at(0).word;
        //cout << "first word is: " << a << endl;
        
        p = strtok(NULL, " ,.?!;");
    }
    
    delete [] writable;
    
    return stVector;
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
                 transform(word.begin(), word.end(), word.begin(), ::tolower);
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

int PhraseAnalyzer::scorePhrase(){
    int score = 0;
    
    for (int i = 0; i < phraseVector.size(); i++) {
        string currentWord = phraseVector.at(i);
        
        std::vector<std::string>::const_iterator it = std::find(stopWordsVector.begin(), stopWordsVector.end(), currentWord);
        
        if (it != stopWordsVector.end()) //this is a stopword, so dont test if it's pos or negative
        {
          //  std::cout << "Found '" << *it << "' in the vector." << std::endl;
            continue;
        }
        
        it = std::find(positiveWordsVector.begin(), positiveWordsVector.end(), currentWord);
        
        if (it != positiveWordsVector.end()) { //this is a positive word
            std::cout << "Found '" << *it << "' in pos vector." << std::endl;
            score++;
            continue;
        }
        
        it = std::find(negativeWordsVector.begin(), negativeWordsVector.end(), currentWord);
        
        if (it != negativeWordsVector.end()) { //this is a negative word
            std::cout << "Found '" << *it << "' in neg vector." << std::endl;

            score--;
        }
        
    }
    
    return score;
}


PhraseAnalyzer::PhraseAnalyzer(string phrase){
    
    //load stop words
    stopWordsVector = loadWordVectors("english.stop.txt");
    
    //load positive list of words
    positiveWordsVector = loadWordVectors("positive-words.txt");

    //load positive list of words
    negativeWordsVector = loadWordVectors("negative-words.txt");
    
    phraseVector = stringToVector(phrase);
    
    
}