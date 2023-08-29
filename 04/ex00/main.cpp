/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:30:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 16:52:48 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();
    const Animal* animals[3] = {animal, cat, dog};
    std::cout << "===============" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << animals[i]->getType() << " : ";
        animals[i]->makeSound();
    }
    std::cout << "===============" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    const WrongAnimal* wrongDog = new WrongDog();

    const WrongAnimal* wrongAnimals[3] = {wrongAnimal, wrongCat, wrongDog};
    std::cout << "===============" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << wrongAnimals[i]->getType() << " : ";
        wrongAnimals[i]->makeSound();
    }
    std::cout << "===============" << std::endl;

    // Clean up memory
    delete animal;
    delete cat;
    delete dog;
    delete wrongAnimal;
    delete wrongCat;
    delete wrongDog;

    return 0;
}