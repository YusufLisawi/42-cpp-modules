/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:42 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 13:04:16 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
    // std::cout << "Constructor called for Bureaucrat"<< std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name) {
    // std::cout << "Constructor called for Bureaucrat"<< std::endl;
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {
    // std::cout << "Destructor called for Bureaucrat"<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) {
    // std::cout << "Copy constructor called for Bureaucrat"<< std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    // std::cout << "Assignment operator called for Bureaucrat" << std::endl;
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

const std::string Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}

void Bureaucrat::increment() {
    if (this->grade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrement() {
    if (this->grade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}