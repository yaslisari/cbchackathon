//
//  csvReader.h
//  commentAnalyzer
//
//  Created by Nazli Bozoglu on 2015-03-15.
//  Copyright (c) 2015 Asli. All rights reserved.
//

#ifndef __commentAnalyzer__csvReader__
#define __commentAnalyzer__csvReader__

#include <string>
#include <vector>

class CSVReader{
private:
    std::vector<std::string> comments;
    
public:
    CSVReader(std::string filename);
    std::vector<std::string> getCommentsVector();
    
};

#endif /* defined(__commentAnalyzer__csvReader__) */
