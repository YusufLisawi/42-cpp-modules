/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:30:10 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/06 14:37:55 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Default")
{
    std::cout << this->name << " is born" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << this->name << " is born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is dead" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void   Zombie::setName(std::string name)
{
    this->name = name;
}