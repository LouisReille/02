/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:10:04 by lreille           #+#    #+#             */
/*   Updated: 2023/04/20 18:16:05 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define 	FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &english_bob);
		Fixed&operator=(const Fixed&bob);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();

	private:
		int entier;
		static const int bit = 8;
};

#endif
