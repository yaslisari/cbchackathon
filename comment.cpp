#include "comment.h"
#include "phraseAnalyzer.h"
#include <iostream>

using namespace std;

Comment::Comment(string commentText, string commenterName){
    PhraseAnalyzer analyzer(commentText);
    int score = analyzer.scorePhrase();
    cout << "score of this comment is: " << score << endl;
}
