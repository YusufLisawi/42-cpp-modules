/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:32:45 by yelaissa          #+#    #+#             */
/*   Updated: 2023/10/12 15:09:43 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
    try {
        BitcoinExchange btc = BitcoinExchange("data.csv", "input.txt");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;   
    }
}