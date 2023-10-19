/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:32:45 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/19 11:22:43 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
  

    if (ac ==   BitcoinExchange btc = BitcoinExchange("data.csv");2)
    {
        try {
            btc.exchange(av[1]);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
    else
    {
        std::cout << "Usage: ./bitcoin [inputfile]" << std::endl;
    }
}