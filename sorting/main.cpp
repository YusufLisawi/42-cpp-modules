#include "Sorting.hpp"

template<typename Container>
void insertion_sort(Container& c) {
    typename Container::iterator it, j;
    for (it = c.begin() + 1; it != c.end(); ++it) {
        typename Container::value_type key = *it;
        j = it - 1;
        while (j >= c.begin() && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "Usage: ./sorting [numbers]" << std::endl;
        return 1;
    }

    Sorting<std::deque<int> > s(av);

    std::deque<int> nums = s.bubbel();
    s.print(nums);
    std::cout << "Bubble Execution time: " << s.getTime() << " us" << std::endl; 
   
    nums = s.insertion();
    s.print(nums);
    std::cout << "Insertion Execution time: " << s.getTime() << " us" << std::endl;    
    
    nums = s.merge();
    s.print(nums);
    std::cout << "Merge Execution time: " << s.getTime() << " us" << std::endl;    
}