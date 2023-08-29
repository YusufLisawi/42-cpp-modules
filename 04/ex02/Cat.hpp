/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:17:00 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 19:55:52 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain* brain;
public:
    Cat();
    ~Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    void    makeSound() const;
};

#endif
