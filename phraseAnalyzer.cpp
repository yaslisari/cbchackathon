//
//  phraseAnalyzer.cpp
//  commentAnalyzer
//
//  Created by Asli Sari on 2015-03-14.
//  Copyright (c) 2015 Asli. All rights reserved.
//

#include "phraseAnalyzer.h"
#include <vector>
#include <string>
#include <cstring>


using namespace std;

struct words{
    int count;
    string word;
    int locationInWordsVector;
    words() : count(0) {} //instead of int count = 0
};