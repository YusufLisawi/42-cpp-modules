/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:00:13 by yelaissa          #+#    #+#             */
/*   Updated: 2023/08/09 13:03:35 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	bits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
