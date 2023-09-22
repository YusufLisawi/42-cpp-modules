/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 13:11:35 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
    // std::cout << "Constructor called for ShrubberyCreationForm"<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    // std::cout << "Constructor called for ShrubberyCreationForm"<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "Destructor called for ShrubberyCreationForm"<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    // std::cout << "Copy constructor called for ShrubberyCreationForm"<< std::endl;
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    // std::cout << "Assignment operator called for ShrubberyCreationForm" << std::endl;
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned())
    {
        if (executor.getGrade() > this->getGradeToExecute())
            throw AForm::GradeTooLowException();
        else
        {
            std::ofstream file;
            file.open(this->target + "_shrubbery", std::ios::out | std::ios::trunc);
            std::string asciiArt = 
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\\\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\";
    
            if (file.is_open())
                file << asciiArt << std::endl;
        }
    }
    else
        throw AForm::GradeTooLowException();
}