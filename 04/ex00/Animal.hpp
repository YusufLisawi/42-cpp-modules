/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:16:17 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/30 19:59:43 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// a virtual function is a member function which is declared within a base class and is re-defined(Overriden) by a derived class.
// it is a way to give related classes a way to implement the same behaviour in different ways
class Animal 
{
    protected:
        std::string type; 
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);

        virtual void makeSound() const;
        std::string getType() const;
};

#endif
