//
//  nonisotreesgen.cpp
//  alrashid
//
//  Created by Ivan Dmitrievsky on 01.12.13.
//  Copyright (c) 2013 Ivan Dmitrievsky. All rights reserved.
//

#include <iostream>
#include <vector>
#include "nonisotreesgen.h"

/* Layout */

Layout::Layout(unsigned n):n(n)
{
    sequence = new unsigned[n];
}

Layout::~Layout()
{
    if (!n)
    {
        return;
    }
    
    delete[] sequence;
    n = 0;
}

void Layout::print(void)
{
    unsigned i = 0;
    
    for (i = 0; i < n; i++)
    {
        std::cout << sequence[i] << ' ';
    }
    
    std::cout << std::endl;
}

unsigned Layout::leftmostHeight(void) const
{
    unsigned height = 0;
    
    for (unsigned int i = 2; i < n && sequence[i] <= sequence[i - 1]; i++)
    {
        height++;
    }
    return height;
}

unsigned Layout::_pprint(Table &t, unsigned int index, int &x, int y)
{
    unsigned i = index + 1;
    
    if (index < n)
    {
        if (sequence[index + 1] - 1 == sequence[index])
            i = _pprint(t, index + 1, x, y + 1);
        
        t._[y][x] = index;
        x++;
        while (sequence[index] + 1 == sequence[i])
            i = _pprint(t, i, x, y + 1);
    }
    return i;
}

void Layout::pprint(void)
{
    int x = 0;
    
    Table t(n);
    
    _pprint(t, 0, x, 0);
    
    t.print();
}

Layout *Layout::succ(void)
{
    unsigned i = 0,
	p = 0,
	q = 0;
    Layout *s = 0;
    
    s = new Layout(n);
    
    for (i = 0; i < n; i++)
    {
        if (sequence[i] != 1)
        {
            p = i;
        }
    }
    for (i = 0; i < p; i++)
    {
        if (sequence[i] == sequence[p] - 1)
        {
            q = i;
        }
    }
    for (i = 0; i < n; i++)
    {
        s->sequence[i] = (i < p) ? sequence[i] : s->sequence[i - (p - q)];
    }
    
    return s;
}

Layout & Layout::operator =(const Layout &right)
{
    unsigned i = 0;
    
    if (&right != this)
    {
        if (right.n >= n)
        {
            for (i = 0; i < n; i++)
            {
                sequence[i] = right[i];
            }
        }
    }
    return *this;
}

unsigned &Layout::operator[](unsigned i) const
{
    return sequence[i];
}

/* Generator */

Generator::Generator(unsigned n):n(n), notFirst(0), lastGiven(n)
{
    unsigned i = 0;
    
    for (i = 0; i < n; i++)
    {
        lastGiven[i] = i;
    }

}

Layout *Generator::giveNext(void)
{
    unsigned i = 0;
    Layout *next = 0;
    
    if (gaveAll())
    {
        return 0;
    }
    lastGenerationStrength += 1;
    
    if (notFirst)
    {
        next = lastGiven.succ();
    }
    else
    {
        next = new Layout(n);
        for (i = 0; i < n; i++)
        {
            (*next)[i] = i;
        }
        notFirst = 1;
    }

    lastGiven = *next;
    
    return next;
}

bool Generator::gaveAll(void)
{
    unsigned i = 0;
    
    if (lastGiven[0])
    {
        return false;
    }
    
    for (i = 1; i < lastGiven.n; i++)
        if (lastGiven[i] != 1)
            return false;
    
    return true;
}