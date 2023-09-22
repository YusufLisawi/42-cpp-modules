/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 20:21:33 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    // std::cout << "Constructor called for RobotomyRequestForm"<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    // std::cout << "Constructor called for RobotomyRequestForm"<< std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout << "Destructor called for RobotomyRequestForm"<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
    // std::cout << "Copy constructor called for RobotomyRequestForm"<< std::endl;
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    // std::cout << "Assignment operator called for RobotomyRequestForm" << std::endl;
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsSigned())
    {
        if (executor.getGrade() > this->getGradeToExecute())
            throw AForm::GradeTooLowException();
        else
        {
            srand(time(NULL));
            int number = rand();
			std::cout << "Making some drilling noises" << std::endl;
			if(number % 2 == 0)
				std::cout << target + " has been robotomized successfull\n";
			else
				std::cout << "robotomy failed for " + target << std::endl;
        }
    }
    else
        throw AForm::GradeTooLowException();
}