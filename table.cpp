//
//  table.cpp
//  alrashid
//
//  Created by Ivan Dmitrievsky on 01.12.13.
//  Copyright (c) 2013 Ivan Dmitrievsky. All rights reserved.
//

#include "table.h"
#include <iostream>

unsigned globalShift = 0;

Table::Table(unsigned n):n(n)
{
    unsigned i = 0, j = 0;
    
    _ = new unsigned*[n];
    
    for (i = 0; i < n; i++)
    {
        _[i] = new unsigned[n];
        for (j = 0; j < n; j++)
        {
            _[i][j] = -1;
        }
    }
}

void Table::print(void)
{
    unsigned i = 0, j = 0;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (_[i][j] != -1)
            {
                std::cout << _[i][j];
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}


Table::~Table(void)
{
    unsigned i = 0;
    
    for (i = 0; i < n; i++)
    {
        delete[] _[i];
    }
    
    delete[] _;
}