/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:40 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 20:28:21 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

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
    virtual ~AForm();
    AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    std::string getName() const;
    int         getGradeToSign() const;
    int         getGradeToExecute() const;
    bool        getIsSigned() const;
    void        beSigned(Bureaucrat& bureaucrat);
    
    virtual void execute(Bureaucrat const & executor) const = 0;

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
