#include "Sorting.hpp"

template <typename Container>
Sorting<Container>::Sorting(char **argv) {
    int i = 1;
    while (argv[i])
    {
        nums.push_back(std::atoi(argv[i]));
        i++;
    }
}

template <typename Container>
Sorting<Container>::~Sorting() {
}

template <typename Container>
Sorting<Container>::Sorting(const Sorting& other) {
    *this = other;
}

template <typename Container>
Sorting<Container>& Sorting<Container>::operator=(const Sorting& other) {
    if (this != &other) {
        this->nums = other.nums;
    }
    return *this;
}

template <typename Container>
Container Sorting<Container>::bubbel() {
    clock_t start_time = clock();
    Container tmp = this->nums;
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

template <typename Container>
Container Sorting<Container>::insertion() {
    clock_t start_time = clock();
    Container tmp = this->nums;
    typename Container::iterator i, j;
    for (i = tmp.begin() + 1; i != tmp.end(); ++i)
    {
        typename Container::value_type current = *i;
        j = i - 1;

        while (j >= tmp.begin() && *j > current)
        {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = current;
    }
    clock_t end_time = clock();
    this->time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
    return tmp;
}

template <typename Container>
void Sorting<Container>::merger(typename Container::iterator begin, typename Container::iterator mid, typename Container::iterator end) {
    Container left(begin, mid);
    Container right(mid, end);

    typename Container::iterator left_it = left.begin();
    typename Container::iterator right_it = right.begin();
    typename Container::iterator container_it = begin;

    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            *container_it = *left_it;
            ++left_it;
        } else {
            *container_it = *right_it;
            ++right_it;
        }
        ++container_it;
    }

    while (left_it != left.end()) {
        *container_it = *left_it;
        ++left_it;
        ++container_it;
    }

    while (right_it != right.end()) {
        *container_it = *right_it;
        ++right_it;
        ++container_it;
    }
}

template <typename Container>
void Sorting<Container>::mergeSort(Container& container, typename Container::iterator begin, typename Container::iterator end) {
    if (std::distance(begin, end) > 1) {
        typename Container::iterator mid = begin + (std::distance(begin, end) / 2);
        mergeSort(container, begin, mid);
        mergeSort(container, mid, end);
        merger(begin, mid, end);
    }
}

template <typename Container>
Container Sorting<Container>::merge() {
    clock_t start_time = clock();
    Container tmp = this->nums;
    mergeSort(tmp, tmp.begin(), tmp.end());
    clock_t end_time = clock();
    this->time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
    return tmp;
}

template <typename Container>
void    Sorting<Container>::print(Container nums) {
    for (typename Container::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        std::cout << *it << ((it != nums.end() - 1) ? " " : "\n");
    }
}

template <typename Container>
double  Sorting<Container>::getTime() {
    return this->time;
}

template <typename Container>
typename Container::iterator Sorting<Container>::binarySearch(Container& container, typename Container::value_type value) {
    typename Container::iterator begin = container.begin();
    typename Container::iterator end = container.end();

    while (begin != end) {
        typename Container::iterator mid = begin + (std::distance(begin, end) / 2);

        if (*mid == value) {
            return mid;
        } else if (*mid < value) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }

    return container.end();
}

