#include "comment.h"
#include "phraseAnalyzer.h"

using namespace std;

Comment::Comment(string commentText, string commenterName){
    PhraseAnalyzer analyzer(commentText);
}
