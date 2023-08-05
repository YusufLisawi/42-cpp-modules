/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:23:14 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/05 17:33:53 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Getters

std::string Contact::getFirstName()
{
    return (this->firstName);
}

std::string Contact::getLastName()
{
    return (this->lastName);
}

std::string Contact::getNickname()
{
    return (this->nickname);
}

std::string Contact::getPhoneNumber()
{
    return (this->phoneNumber);
}

std::string Contact::getDarkestSecret()
{
    return (this->darkestSecret);
}

void Contact::printContact()
{
    std::cout << "-------------------------------------------\n";
    std::cout << "First Name : " << this->getFirstName() << std::endl;
    std::cout << "Last Name : " << this->getLastName() << std::endl;
    std::cout << "Nickname : " << this->getNickname() << std::endl;
    std::cout << "Phone Number : " << this->getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << this->getDarkestSecret() << std::endl;
    std::cout << "-------------------------------------------\n";
}


bool Contact::isValidPhone(std::string phoneNumber)
{
    if (phoneNumber.size() != 10)
        return (false);
    for (int i = 0; i < 10; i++)
        if (!std::isdigit(phoneNumber[i]))
            return (false);
    return (true);
}

void Contact::addContact()
{
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter nickname: ";
    std::cin >> nickname;
    do {
        std::cout << "Enter phone number: ";
        std::cin >> phoneNumber;
        if (!isValidPhone(phoneNumber))
            std::cout << "Invalid phone number, try again!" << std::endl;
    } while (!isValidPhone(phoneNumber));
    std::cout << "Enter darkest secret: ";
    std::cin >> darkestSecret;
}
