/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:36:54 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/06 14:41:15 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie;
	int		i;

	i = 0;
	zombie = new Zombie[N];
	while (i < N)
	{
		zombie[i].setName(name);
		i++;
	}
	return (zombie);
}