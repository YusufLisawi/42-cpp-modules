/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:06:50 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/24 18:49:41 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

int main() {
    Intern intern;

    AForm* form1 = intern.makeForm("robotomy request", "Bender");
    AForm* form2 = intern.makeForm("presidential pardon", "Fry");
    AForm* form3 = intern.makeForm("asd", "Leela");

    if (form1 != nullptr) {
        delete form1;
    }

    if (form2 != nullptr) {
        delete form2;
    }

    if (form3 != nullptr) {
        delete form3;
    }
    return 0;
}