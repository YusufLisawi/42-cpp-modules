/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:31:25 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/24 18:12:18 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    AForm form("Form 1", 1, 1);
    Bureaucrat bureaucrat("Yusuf", 1);
    AForm form2("Form 2", 2, 2);
    Bureaucrat bureaucrat2("Isawi", 3);

    std::cout << form;
    std::cout << form2;
    std::cout << bureaucrat;
    std::cout << bureaucrat2;

    bureaucrat.signForm(form);
    bureaucrat2.signForm(form2);

    std::cout << form;
    std::cout << form2;
    return 0;
}