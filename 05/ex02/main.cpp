/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:49 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 13:11:52 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
    ShrubberyCreationForm *form = new ShrubberyCreationForm("Home");
    
    try
    {
        bureaucrat->signForm(*form);
        bureaucrat->executeForm(*form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}