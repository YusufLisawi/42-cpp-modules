#pragma once

#include <iostream>

class MutantStack 
{
public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
};

