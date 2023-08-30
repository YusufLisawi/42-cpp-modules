/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:16:55 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/30 16:22:07 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource 
{
public:
    virtual ~IMateriaSource() {} 
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
