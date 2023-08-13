/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:44:21 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/13 22:58:32 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default__clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = ScavTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "__clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap constructor called with name " << name << std::endl;
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = ScavTrap::attackDamage;
}

DiamondTrap::~DiamondTrap() 
{
	std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other.name + "__clap_name") 
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy assignement operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void	DiamondTrap::attack(std::string const &target) 
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "DiamondTrap " << this->name << " attack " << target << ", causing (" << this->attackDamage << ") points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "DiamondTrap " << this->name << " cannot attack " << target << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << this->name << ", ClapTrap name is " << ClapTrap::name << std::endl;
}