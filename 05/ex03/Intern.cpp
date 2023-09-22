/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:35:49 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 21:09:00 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    // std::cout << "Constructor called for Intern"<< std::endl;
}

Intern::~Intern() {
    // std::cout << "Destructor called for Intern"<< std::endl;
}

Intern::Intern(const Intern& other) {
    // std::cout << "Copy constructor called for Intern"<< std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    // std::cout << "Assignment operator called for Intern" << std::endl;
    if (this != &other) {
        // Copy data here
    }
    return *this;
}


struct FormCreator {
    std::string formType;
    AForm *(*create)(std::string);
};

AForm *createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

FormCreator formCreators[] = {
    {"robotomy request", createRobotomyRequestForm},
    {"presidential pardon", createPresidentialPardonForm},
    {"shrubbery creation", createShrubberyCreationForm}
};

AForm *Intern::makeForm(std::string formType, std::string target) {
    for (unsigned long i = 0; i < sizeof(formCreators) / sizeof(FormCreator); i++) {
        if (formCreators[i].formType == formType) {
            std::cout << "Intern creates " + formType + " form" << std::endl;
            return formCreators[i].create(target);
        }
    }
    std::cout << "Form not found" << std::endl;
    return NULL;
}