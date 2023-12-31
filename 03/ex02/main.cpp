/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:11:58 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/13 23:11:59 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("Goku");
    FragTrap frag2("Vegeta");


    frag1.attack(frag2.getName());
    frag2.takeDamage(30);
    frag2.beRepaired(5);

    frag2.attack(frag1.getName());
    frag1.takeDamage(30);
    frag1.beRepaired(15);

    frag1.highFivesGuys();
    frag2.highFivesGuys();

    return 0;
}