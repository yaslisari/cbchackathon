#ifndef COMMENT_H
#define COMMENT_H

#include <string>
  
class Comment
{
private:
    double commentScore;
 
    Comment() { } // private default constructor
 
public:
    Comment(std::string commentText, std::string commenterName);
 
    double getCommentScore(){ return commentScore; };
 
};
 
#endif
