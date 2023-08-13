/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:15:22 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/13 23:23:17 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    
    DiamondTrap yusuf("Yusuf");
    DiamondTrap isawi("Isawi");
    
    yusuf.attack(isawi.getName());
    isawi.takeDamage(50);
    isawi.beRepaired(22);
    isawi.attack(yusuf.getName());
    yusuf.takeDamage(69);
    yusuf.highFivesGuys();
    isawi.guardGate();
    yusuf.whoAmI();

    return (0);
}