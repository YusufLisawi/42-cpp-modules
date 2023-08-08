/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:01:32 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/06 17:15:22 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "HumanB created - Name : " << this->name << std::endl;
}

HumanB::HumanB(std::string name, Weapon &weapon) : name(name), weapon(&weapon)
{
	std::cout << "HumanB created - Name : " << this->name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destroyed - Name : " << this->name << std::endl;
}

void    HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
