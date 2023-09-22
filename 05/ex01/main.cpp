/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:25 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/22 12:31:26 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    // Create a bureaucrat with a grade of 1 (highest possible grade)
    Bureaucrat bureaucrat("Yusuf", 1);

    // Create a form that requires a grade of 2 to sign and execute
    AForm form("Form 1", 1, 1);

    // Test that the bureaucrat cannot sign the form again
    try
    {
        bureaucrat.signForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test that a form with a grade requirement higher than the bureaucrat's grade cannot be signed
    Bureaucrat bureaucrat2("Youssef", 3);
    AForm form2("Form 2", 2, 2);
    try
    {
        bureaucrat2.signForm(form2);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}