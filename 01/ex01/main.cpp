/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:33:14 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/06 14:41:59 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name);

int main(void)
{
    Zombie  *zombies;

    zombies = zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}