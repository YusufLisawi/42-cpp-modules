/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 20:18:47 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default")
{
    // std::cout << "Constructor called for PresidentialPardonForm"<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    // std::cout << "Constructor called for PresidentialPardonForm"<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    // std::cout << "Destructor called for PresidentialPardonForm"<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
    // std::cout << "Copy constructor called for PresidentialPardonForm"<< std::endl;
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    // std::cout << "Assignment operator called for PresidentialPardonForm" << std::endl;
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned())
    {
        if (executor.getGrade() > this->getGradeToExecute())
            throw AForm::GradeTooLowException();
        else
        {
            std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;; 
        }
    }
    else
        throw AForm::GradeTooLowException();
}