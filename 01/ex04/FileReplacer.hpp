/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:59:17 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/06 19:59:27 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

class FileReplacer {
private:
	std::string filename;
	std::string s1;
	std::string s2;
public:
	FileReplacer(std::string filename, std::string s1, std::string s2);
	~FileReplacer();
	bool replace();
};
