#include "Sorting.hpp"

template <typename T>
Sorting<T>::Sorting(char **argv) {
    int i = 1;
    while (argv[i])
    {
        nums.push_back(std::atoi(argv[i]));
        i++;
    }
}

template <typename T>
Sorting<T>::~Sorting() {
}

template <typename T>
Sorting<T>::Sorting(const Sorting& other) {
    *this = other;
}

template <typename T>
Sorting<T>& Sorting<T>::operator=(const Sorting& other) {
    if (this != &other) {
        this->nums = other.nums;
    }
    return *this;
}

template <typename T>
std::deque<T> Sorting<T>::bubbel() {
    clock_t start_time = clock();
    std::deque<T> tmp = this->nums;
    size_t i = -1;
    while (++i < tmp.size())
    {
        size_t j = -1;
        while (++j < tmp.size() - 1)
        {
            if (tmp[j] > tmp[j + 1])
                std::swap(tmp[j], tmp[j + 1]);
        }
    }
    clock_t end_time = clock();
    this->time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
    return tmp;
}

template <typename T>
void    Sorting<T>::print(std::deque<T> nums) {
    for (typename std::deque<T>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout << *it << ((it != nums.end() - 1) ? " " : "\n");
    }
}

template <typename T>
double  Sorting<T>::getTime() {
    return this->time;
}