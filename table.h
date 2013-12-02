//
//  table.h
//  alrashid
//
//  Created by Ivan Dmitrievsky on 01.12.13.
//  Copyright (c) 2013 Ivan Dmitrievsky. All rights reserved.
//

#ifndef __alrashid__table__
#define __alrashid__table__

class Table
{
    unsigned n;
    
public:
    unsigned **_;
    Table(unsigned n);
    ~Table(void);
    void print(void);
};

#endif /* defined(__alrashid__table__) */
