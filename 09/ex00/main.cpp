/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:32:45 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/12 16:37:25 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btc = BitcoinExchange("data.csv");

    if (ac == 2)
    {
        btc.exchange(av[1]);
    }
    else
    {
        std::cout << "Usage: ./bitcoin [inputfile]" << std::endl;
    }
}