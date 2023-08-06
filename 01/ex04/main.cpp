/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:58:40 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/06 19:59:46 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Usage: " << argv[0] << " filename old new" << std::endl;
		return (1);
	}

	FileReplacer replacer(argv[1], argv[2], argv[3]);
	replacer.replace();

	return (0);
}


