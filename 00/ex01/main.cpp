/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:12:07 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/05 17:30:23 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to your phonebook !"<< std::endl;
    while (1)
    {
        std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
        std::cin >> command;

        if (command == "ADD")
        {
            Contact contact;
            contact.addContact();
            phoneBook.addContact(contact);
        }
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            phoneBook.exit();
        else
            std::cout << "Wrong command" << std::endl;
        }
}