#include "Sorting.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "Usage: ./sorting [numbers]" << std::endl;
        return 1;
    }

    Sorting<int> s(av);

    std::deque<int> nums = s.bubbel();
    s.print(nums);
    std::cout << "Execution time: " << s.getTime() << " us" << std::endl;
}