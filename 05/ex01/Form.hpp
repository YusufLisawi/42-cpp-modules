/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:30:57 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 12:32:20 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
private:
    std::string const   name;
    int const           gradeToSign;
    int const           gradeToExecute;
    bool                isSigned;
public:
    AForm();
    ~AForm();
    AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    std::string getName() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;
    bool        getIsSigned() const;
    void        beSigned(Bureaucrat& bureaucrat);

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
std::ostream& operator<<(std::ostream& out, AForm& Form);

#endif
