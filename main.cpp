//
//  main.cpp
//  alrashid
//
//  Created by Ivan Dmitrievsky on 12.11.13.
//  Copyright (c) 2013 Ivan Dmitrievsky. All rights reserved.
//

#include <iostream>
#include "nonisotreesgen.h"

int main(int argc, const char * argv[])
{
    unsigned verticesNumber = 4;
    Generator gen(verticesNumber);
    Layout *lay = 0;
    
    while ((lay = gen.giveNext()))
    {
        lay->pprint();
        std::cout << '\n';
        delete lay;
    }
    
    std::cout << "\nOverall generated: " << gen.lastGenerationStrength << "\n\n";
    
    return 0;
}

