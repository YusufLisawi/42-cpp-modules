/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:32:03 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/05 17:22:23 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->nbContacts = 0;
}

void PhoneBook::addContact(Contact contact)
{
    if (this->nbContacts < 8)
    {
        this->contacts[this->nbContacts] = contact;
        this->nbContacts++;
    }
    else
    {
        for (int i = 0; i < 7; i++)
            this->contacts[i] = this->contacts[i + 1];
        this->contacts[7] = contact;
    }
}

void PhoneBook::searchContact()
{
    if (this->nbContacts == 0)
    {
        std::cout << "No contacts" << std::endl;
        return;
    }

    std::cout << "-------------------------------------------\n";
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < this->nbContacts; i++)
    {
        std::string firstName = this->contacts[i].getFirstName().size() > 10 ? this->contacts[i].getFirstName().substr(0, 9) + "." : this->contacts[i].getFirstName();
        std::string lastName = this->contacts[i].getLastName().size() > 10 ? this->contacts[i].getLastName().substr(0, 9) + "." : this->contacts[i].getLastName();
        std::string nickname = this->contacts[i].getNickname().size() > 10 ? this->contacts[i].getNickname().substr(0, 9) + "." : this->contacts[i].getNickname();
        
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << std::right << firstName << "|";
        std::cout << std::setw(10) << std::right << lastName << "|";
        std::cout << std::setw(10) << std::right << nickname << std::endl;
        std::cout << "-------------------------------------------\n";
    }
    
    std::cout << "Enter an index: ";
    int index;
    std::cin >> index;

    if (index >= 0 && index < this->nbContacts)
        this->contacts[index].printContact();
    else
        std::cout << "Wrong index" << std::endl;
}

void PhoneBook::exit()
{
    std::cout << "Bye !" << std::endl;
    std::exit(0);
}