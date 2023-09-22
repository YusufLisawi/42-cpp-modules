/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:38 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 12:31:39 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default"), gradeToSign(150), gradeToExecute(150), isSigned(false) {
    // std::cout << "Constructor called for AForm"<< std::endl;
}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false) {
    // std::cout << "Constructor called for AForm"<< std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::~AForm() {
    // std::cout << "Destructor called for AForm"<< std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
    // std::cout << "Copy constructor called for AForm"<< std::endl;
    *this = other;
}

AForm& AForm::operator=(const AForm& other) {
    // std::cout << "Assignment operator called for AForm" << std::endl;
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

std::string AForm::getName() const {
    return this->name;
}

int AForm::getGradeToSign() const {
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

bool AForm::getIsSigned() const {
    return this->isSigned;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, AForm& AForm) {
    out << AForm.getName() << ", AForm grade to sign " << AForm.getGradeToSign() << ", AForm grade to execute " << AForm.getGradeToExecute() << ", AForm is signed " << AForm.getIsSigned() << std::endl;
    return out;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

