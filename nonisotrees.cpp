//
//  nonisotrees.cpp
//  alrashid
//
//  Created by Ivan Dmitrievsky on 12.11.13.
//  Copyright (c) 2013 Ivan Dmitrievsky. All rights reserved.
//

#include "nonisotrees.h"

TreeForm::TreeForm(unsigned _verticesNumber):verticesNumber(_verticesNumber), vertices(0)
{
    unsigned i = 0;
    
    if (verticesNumber > 0)
    {
        vertices = new unsigned[verticesNumber]; //int?
        if (vertices == 0)
            return;
        
        for (i = 0; i <= verticesNumber / 2; i++)
            vertices[i] = i;
        
        for (i = verticesNumber / 2 + 1; i < verticesNumber; i++)
            vertices[i] = i - verticesNumber / 2;
    }
}

TreeForm::TreeForm(const TreeForm &form):verticesNumber(form.verticesNumber)
{
    unsigned i = 0;
    
    vertices = new unsigned[verticesNumber];
    if (vertices == 0)
        return;
    
    for (i = 0; i < verticesNumber; i++)
        vertices[i] = form.vertices[i];
}

TreeForm::~TreeForm(void)
{
    if (vertices)
        delete[] vertices;
    
    verticesNumber = 0;
}

unsigned & TreeForm::operator[](unsigned position)
{
    return vertices[position % verticesNumber];
}

unsigned TreeForm::size(void) const
{
    return verticesNumber;
}

unsigned TreeForm::maximum(void)
{
    unsigned maxVertice = 0, i = 0;
    
    if (verticesNumber > 1)
    {
        maxVertice = vertices[1];
        
        for (i = 2; i < verticesNumber; i++)
        {
            if (vertices[i] > maxVertice)
                maxVertice = vertices[i];
        }
        return maxVertice;
    }
    else
        return 1;
}

TreeForm & TreeForm::operator=(const TreeForm &form)
{
    unsigned i = 0;
    
    if (form.size() == verticesNumber)
        for (i = 0; i < verticesNumber; i++)
        {
            vertices[i] = form.vertices[i];
        }
    
    return *this;
}

bool TreeForm::hasSimpleStructure(void)
{
    unsigned i = 0;
    
    for (i = 1; i < verticesNumber; i++)
    {
        if (vertices[i] != 1)
            return false;
    }
    
    return true;
}

bool operator<=(TreeForm &form1, TreeForm &form2)
{
    unsigned i = 0;
    
    if (form1.size() > form2.size())
        return false;
    else if (form1.size() < form2.size())
        return true;
    else
        for (i = 0; i < form1.size(); i++)
        {
            if (form1[i] < form2[i])
                continue; // fixed
            else if (form1[i] > form2[i])
                return false;
        }
    
    return true;
}

bool operator!=(TreeForm &form1, TreeForm &form2)
{
    unsigned i = 0;
    
    if (form1.size() != form2.size())
        return true;
    else
        for (i = 2; i < form1.size(); i++)
        {
            if (form1[i] != form2[i])
                return true;
        }
    
    return false;
}

TreeForm TreeBuild::successor(TreeForm &form, unsigned position)
{
    unsigned q;
    TreeForm newForm(form);
    
    if (position == 0)
    {
        /* Search maximum index of label, which isn't equal with 1 */
        for (position = form.size() - 1; form[position] == 1; position--)
            ;
        if (position == 0)
            return newForm;
    }
    
    /* Search a parent of vertex with position-th label (search maximum index of label, which is equal with label[position] - 1 */
    for (q = position - 1; form[q] != form[position] - 1; q--)
        ;
    
    /* Copy a part of successor to the end of successor */
    for (unsigned i = position; i < form.size(); i++)
        newForm[i] = newForm[i - position + q];
    return newForm;
}

TreeForm TreeBuild::buildForm(TreeForm &form)
{
    TreeForm newForm(successor(form));
    unsigned m, i = 0;
    
    for (m = 2; m < newForm.size(); m++)
    {
        if (newForm[m] == 1)
            break;
    }
    if (m <= 1)
        return newForm;
    
    TreeForm l1(m - 1);
    TreeForm l2(newForm.size() - m + 1);
    
    for (i = 0; i < l1.size(); i++)
        l1[i] = newForm[i + 1] - 1;
        
        l2[0] = 0;
        for (i = 1; i < l2.size(); i++)
        {
            l2[i] = newForm[i + m - 1];
            
            if (m != newForm.size())
            {
                if (l2.maximum() > l1.maximum())
                    return newForm;
                else if (l2.maximum() == l1.maximum())
                {
                    if (l1 <= l2)
                        return newForm;
                }
            }
        }
    
    newForm = TreeBuild::successor(newForm, m - 1);
    
    if (l1[m - 2] > 1)
    {
        unsigned height = 0, max = newForm[1];
        for (i = 2; i < newForm.size(); i++)
        {
            if (newForm[i] <= max)
                break;
            else
            {
                max = newForm[i];
                height++;
            }
        }
        for (i = newForm.size() - 1; i >= newForm.size() - height - 1; i--)
        {
            newForm[i] = i - newForm.size() + 2 + height;
        }
    }
    
    return newForm;
}

