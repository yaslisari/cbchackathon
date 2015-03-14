#ifndef COMMENT_H
#define COMMENT_H

#include <string>
  
class Comment
{
private:
    int commentScore;
 
    Comment() { } // private default constructor
 
public:
    Comment(std::string commentText, std::string commenterName);
 
    int getCommentScore(){ return commentScore; };
 
};
 
#endif
