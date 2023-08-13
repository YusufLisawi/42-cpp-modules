#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav1("Goku");
    ScavTrap scav2("Vegeta");
    ScavTrap scav3;

    scav3 = scav2;

    scav1.attack(scav3.getName());
    scav3.takeDamage(10);
    scav3.beRepaired(5);

    scav3.attack(scav1.getName());
    scav1.takeDamage(10);
    scav1.beRepaired(5);

    scav1.guardGate();
    scav2.guardGate();
    scav3.guardGate();

    return 0;
}