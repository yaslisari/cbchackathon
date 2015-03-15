#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "comment.h"
#include "libjson.h"
#include "_internal/Source/JSONDefs.h"
#include "csvReader.h"

using namespace std;

vector<double> createComments(vector<string> comments, vector<double> commentScores){
    for (int i = 0; i < comments.size(); i++) {
        Comment newComment(comments.at(i), "");
        commentScores.push_back(newComment.getCommentScore());
    }
    
    return commentScores;
}


int main(int argc, char *argv[])
{
    vector<double> commentScores;
   // Comment newComment("I wish the news was full of more stories like this, and the constant stream of doom & gloom that makes one not want to get out of bed in the morning. Nice to have a reminder now & then that there are decent people out there, doing good things for their fellow man.", "Don't Call Me Shirley");
 //   commentScores.push_back(newComment.getCommentScore());
    
    CSVReader reader("bill-c-51-day-of-action-protests-denounce-new-policing-powers.csv");
    vector<string> comments = reader.getCommentsVector();
    
    
   commentScores = createComments(comments, commentScores);

    
    ofstream myfile;
    myfile.open ("output.csv");

    myfile << "comment, score" << endl;
    
    for (int i =  0; i < commentScores.size(); i++) {
        //cout << "question " << questionScores.at(i).questionNo << " score is " << questionScores.at(i).score << endl;
        //myfile << questionsVector.at(questionScores.at(i).questionNo).phrase << endl;
        myfile << i << ", " <<commentScores.at(i) << endl;
    }
    myfile.close();

    return EXIT_SUCCESS;
}

