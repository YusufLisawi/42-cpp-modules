/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:28 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 12:31:29 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // Create a bureaucrat with grade 1
    Bureaucrat bureaucrat("John", 1);

    // Test getName and getGrade methods
    std::cout << "Bureaucrat name: " << bureaucrat.getName() << std::endl;
    std::cout << "Bureaucrat grade: " << bureaucrat.getGrade() << std::endl;

    // Test increment method
    try
    {
        bureaucrat.increment();
        std::cout << "Bureaucrat grade after increment: " << bureaucrat.getGrade() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test decrement method
    try
    {
        bureaucrat.decrement();
        std::cout << "Bureaucrat grade after decrement: " << bureaucrat.getGrade() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test GradeTooHighException
    try
    {
        Bureaucrat bureaucrat2("Jane", 0);
        std::cout << "Bureaucrat2 grade: " << bureaucrat2.getGrade() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test GradeTooLowException
    try
    {
        Bureaucrat bureaucrat3("Bob", 151);
        std::cout << "Bureaucrat3 grade: " << bureaucrat3.getGrade() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}