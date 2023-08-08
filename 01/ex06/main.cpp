/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:18:58 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/08 11:18:59 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
		return (std::cerr << "Usage: ./harlFilter arg" << "\n", 1);
	harl.complain(av[1]);
	return (0);
}