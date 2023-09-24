/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:00:15 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/24 19:18:31 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat 
{
private:
    std::string const   name;
    int                 grade;
public:
    Bureaucrat();
    Bureaucrat(std::string const   name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    const std::string getName() const;
    int         getGrade() const;
    void        increment();
    void        decrement();
    void        signForm(AForm& form);
    void        executeForm(AForm const & form);

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
           const char* what() const throw(); 
    };
};
std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat);

#endif
