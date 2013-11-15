//
//  nonisotrees.h
//  alrashid
//
//  Created by Ivan Dmitrievsky on 12.11.13.
//  Copyright (c) 2013 Ivan Dmitrievsky. All rights reserved.
//

#ifndef __alrashid__nonisotrees__
#define __alrashid__nonisotrees__

class TreeForm
{
protected:
    unsigned *vertices;
    unsigned verticesNumber;
public:
    TreeForm(unsigned verticesCount);
    TreeForm(const TreeForm &form);
    ~TreeForm(void);
    
    unsigned & operator[](unsigned position);
    
    unsigned size(void) const;
    
    unsigned maximum(void);

    TreeForm & operator=(const TreeForm &form);
    
    bool hasSimpleStructure(void);
};

namespace TreeBuild
{
    TreeForm successor(TreeForm &form, unsigned position = 0);
    TreeForm buildForm(TreeForm &form);
}


#endif /* defined(__alrashid__nonisotrees__) */
