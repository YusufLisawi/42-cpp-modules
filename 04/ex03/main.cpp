/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:01:29 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/30 20:56:21 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
    ICharacter *me = new Character("me");
    ICharacter *bob = new Character("bob");

    // Test 1: Create a new MateriaSource and learn a new Materia
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Test 2: Create a new Character and equip a Materia
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    // Test 3: Create a new Character and equip a Materia
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Test 4: Use a Materia on a Character
    me->use(0, *bob);

    // Test 5: Use a Materia on a Character
    me->use(1, *bob);

    // Test 6: Unequip a Materia from a Character
    me->unequip(0);

    // Test 7: Create a new Character and equip a Materia
    tmp = src->createMateria("ice");
    me->equip(tmp);

    // Test 8: Create a new Character and equip a Materia
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Test 9: Use a Materia on a Character
    me->use(0, *bob);

    // Test 10: Use a Materia on a Character
    me->use(1, *bob);

    // Test 11: Create a new Character and equip a Materia
    ICharacter *jim = new Character("jim");
    tmp = src->createMateria("ice");
    jim->equip(tmp);

    // Test 12: Create a new Character and equip a Materia
    tmp = src->createMateria("cure");
    jim->equip(tmp);

    // Test 13: Use a Materia on a Character
    jim->use(0, *bob);

    // Test 14: Use a Materia on a Character
    jim->use(1, *bob);

    // Test 15: Try to equip more than 4 materias
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

    // Test 16: Try to unequip more than 4 materias
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->unequip(4);

    // Test 17: Try to learn more than 4 materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());

    // Test 18: Delete all objects and check for memory leaks
    delete jim;
    delete bob;
    delete me;
    delete src;
    system("leaks materia -q");
    return 0;
}