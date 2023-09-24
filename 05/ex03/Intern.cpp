/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:35:49 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/24 18:48:19 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    // std::cout << "Constructor called for Intern"<< std::endl;
}

Intern::~Intern()
{
    // std::cout << "Destructor called for Intern"<< std::endl;
}

Intern::Intern(const Intern &other)
{
    // std::cout << "Copy constructor called for Intern"<< std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    // std::cout << "Assignment operator called for Intern" << std::endl;
    if (this != &other)
    {
        // Copy data here
    }
    return *this;
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formType, std::string target)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    AForm *(Intern::*FormFunc[3])(std::string) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};

    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == formType)
        {
            std::cout << "Intern creates " << formType << std::endl;
            return (this->*FormFunc[i])(target);
        }
    }
    std::cout << "Intern can't create " << formType << " because it's not a valid form type" << std::endl;
    return NULL;
}