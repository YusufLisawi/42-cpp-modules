/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:16:17 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/29 20:02:28 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal 
{
    protected:
        std::string type; 
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif
