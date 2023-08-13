#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() 
	: name("Default"), hitPoints(10), 
	energyPoints(10), attackDamage(0) 
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: name(name), hitPoints(10), 
	energyPoints(10), attackDamage(0) 
{
	std::cout << "ClapTrap constructor called with name " << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignement operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

std::string	ClapTrap::getName()
{
	return this->name;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	this->attackDamage = amount;
}

std::ostream &operator<<(std::ostream &out, ClapTrap &other)
{
	out << "ClapTrap " << other.getName();
	return out;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << *this << " attack " << target << ", causing (" << this->attackDamage << ") points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << *this << " cannot attack " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << *this << " have taken a damage of (" << amount << ") points!" << std::endl;
	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
		std::cout << *this << " have been destroyed!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << *this << "'s hit points got repaired, +" << amount << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << *this << "'s hit points cannot get repaired" << std::endl;	
}