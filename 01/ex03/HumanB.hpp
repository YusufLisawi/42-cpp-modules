/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:02:31 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/06 17:13:53 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string	name;
        Weapon		*weapon;

    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon &weapon);
        ~HumanB();
        void	attack(void);
        void    setWeapon(Weapon &weapon);
};

#endif