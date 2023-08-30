/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:24:25 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/30 18:18:11 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria 
{
protected:
    std::string type;
public:
    AMateria();
    AMateria(std::string const &type);
    virtual ~AMateria();
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);

    std::string const &getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
