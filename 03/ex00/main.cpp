#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clapTrap1;
    ClapTrap clapTrap2("Yusuf");

    // std::cout << clapTrap1 << std::endl;
    // std::cout << clapTrap2 << std::endl;

    clapTrap1.setAttackDamage(5);
    clapTrap1.attack(clapTrap2.getName());
    clapTrap2.takeDamage(5);

    clapTrap2.setAttackDamage(10);
    clapTrap2.attack(clapTrap1.getName());
    clapTrap1.takeDamage(10);

    clapTrap1.beRepaired(5);
    clapTrap2.beRepaired(10);

    return 0;
}