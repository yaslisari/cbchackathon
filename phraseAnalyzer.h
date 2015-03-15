//
//  phraseAnalyzer.h
//  commentAnalyzer
//
//  Created by Asli Sari on 2015-03-14.
//  Copyright (c) 2015 Asli. All rights reserved.
//

#ifndef __commentAnalyzer__phraseAnalyzer__
#define __commentAnalyzer__phraseAnalyzer__

#include <string>
#include <vector>

class PhraseAnalyzer{
private:
    std::vector<std::string> stopWordsVector;
    std::vector<std::string> positiveWordsVector;
    std::vector<std::string> negativeWordsVector;
    std::vector<std::string> phraseVector;
    
public:
    PhraseAnalyzer(std::string phrase);
    int scorePhrase();
};

#endif /* defined(__commentAnalyzer__phraseAnalyzer__) */
