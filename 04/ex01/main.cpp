/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:30:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 18:46:06 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

Animal    **create_animals(int size)
{
    Animal **animals = new Animal*[size];

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
    Animal **animals;

    animals = create_animals(size);
    for (int i = 0; i < size; i++)
        delete animals[i];
    delete[] animals;
    system("leaks animal -q");
}