//
//  nonisotreesgen.h
//  alrashid
//
//  Created by Ivan Dmitrievsky on 01.12.13.
//  Copyright (c) 2013 Ivan Dmitrievsky. All rights reserved.
//

#ifndef __alrashid__nonisotreesgen__
#define __alrashid__nonisotreesgen__

#include "table.h"

class Layout
{
    /* private: */
    unsigned *sequence;
    unsigned leftmostHeight(void) const;
    unsigned _pprint(Table &t, unsigned int index, int &x, int y );
public:
    unsigned n;
    Layout (unsigned n);
    ~Layout ();
    
    Layout &operator =(const Layout &right);
    unsigned &operator[](unsigned i) const;
    
    Layout *succ(void);
    void print(void);
    void pprint(void);
};

class Generator
{
    Layout lastGiven;
    unsigned n;
    bool notFirst;
    
    bool gaveAll(void);
public:
    Generator(unsigned n);
    Layout *giveNext(void);
    
    unsigned lastGenerationStrength;
};

#endif /* defined(__alrashid__nonisotreesgen__) */
