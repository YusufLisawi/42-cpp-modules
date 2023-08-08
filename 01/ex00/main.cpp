/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:33:14 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/06 13:44:01 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

int main(void)
{
    Zombie  *zombie;

    zombie = newZombie("Zombie");
    zombie->announce();
    randomChump("Random");
    delete zombie;
    return (0);
}