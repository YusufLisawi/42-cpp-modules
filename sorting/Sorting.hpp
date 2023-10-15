#pragma once

#include <iostream>
#include <deque>
#include <ctime>

template <class Container>
class Sorting
{
private:
    Container   nums;
    double      time;
public:
    Sorting<Container>(char **argv);
    ~Sorting<Container>();
    Sorting<Container>(const Sorting& other);
    Sorting<Container>& operator=(const Sorting& other);

    Container bubbel();
    Container insertion();
    Container merge();

    typename Container::iterator binarySearch(Container& container, typename Container::value_type value);

    void merger(typename Container::iterator begin, typename Container::iterator mid, typename Container::iterator end);
    void mergeSort(Container& container, typename Container::iterator begin, typename Container::iterator end);

    void    print(Container nums);
    double  getTime();
};

#include "Sorting.tpp"