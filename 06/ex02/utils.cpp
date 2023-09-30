/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:31:48 by yelaissa          #+#    #+#             */
/*   Updated: 2023/09/30 10:33:29 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

Base* generate() {
    srand(time(0));
    int choice = rand() % 3;
    switch (choice) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    } catch (std::exception &e) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)b;
        } catch (std::exception &e) {
            try {
                C& c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)c;
            } catch (std::exception &e) {
                std::cout << "Error" << std::endl;
            }
        }
    }
}