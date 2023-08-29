/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:16:08 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 19:55:36 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain* brain;
public:
    Dog();
    ~Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);

    void    makeSound() const;
};

#endif
