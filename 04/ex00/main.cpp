/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:30:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 16:37:50 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    const Animal* animals[3] = {animal, cat, dog};
    for (int i = 0; i < 3; i++)
    {
        std::cout << animals[i]->getType() << " : ";
        animals[i]->makeSound();
    }
    // Clean up memory
    delete animal;
    delete cat;
    delete dog;

    return 0;
}