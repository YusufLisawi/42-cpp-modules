#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl    harl;

    if (ac != 2)
        return (1);
    harl.complain(av[1]);
    return (0);
}