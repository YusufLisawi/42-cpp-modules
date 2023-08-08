/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:29:22 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/06 16:33:31 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    std::cout << "Weapon created - Type : " << this->type << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destroyed - Type : " << this->type << std::endl;
}

std::string const	&Weapon::getType(void)
{
    return (this->type);
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}
