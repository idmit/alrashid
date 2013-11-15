//
//  main.cpp
//  alrashid
//
//  Created by Ivan Dmitrievsky on 12.11.13.
//  Copyright (c) 2013 Ivan Dmitrievsky. All rights reserved.
//

#include <iostream>
#include "nonisotrees.h"

int main(int argc, const char * argv[])
{
    unsigned verticesNumber = 3;
    TreeForm form(verticesNumber);
    
    while (!form.hasSimpleStructure())
    {
        // print
        form = TreeBuild::buildForm(form);
    }
    // print out
    
    return 0;
}

