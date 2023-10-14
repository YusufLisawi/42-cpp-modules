#pragma once

#include <iostream>
#include <deque>
#include <ctime>

template <class T>
class Sorting
{
private:
    std::deque<T>   nums;
    double          time;
public:
    Sorting<T>(char **argv);
    ~Sorting<T>();
    Sorting<T>(const Sorting& other);
    Sorting<T>& operator=(const Sorting& other);

    std::deque<T> bubbel();
    std::deque<T> insertion();
    std::deque<T> merge();

    void    print(std::deque<T> nums);
    double  getTime();
};

#include "Sorting.tpp"