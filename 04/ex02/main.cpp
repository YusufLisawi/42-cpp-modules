/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:30:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 20:01:47 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

AAnimal    **create_animals(int size)
{
    AAnimal **animals = new AAnimal*[size];

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    return (animals);
}

int main()
{
    const int size = 10;
    AAnimal **animals;

    animals = create_animals(size);
    for (int i = 0; i < size; i++)
        delete animals[i];
    delete[] animals;
}