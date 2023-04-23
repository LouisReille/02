/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:10:04 by lreille           #+#    #+#             */
/*   Updated: 2023/04/20 18:52:00 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define 	FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &english_bob);
		Fixed&operator=(const Fixed&bob);
		Fixed(const float num);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();
		Fixed(int num);
		float toFloat(void) const;
		int toInt(void) const;
	private:
		int entier;
		static const int bit = 8;
};
std::ostream& operator<<(std::ostream &out, Fixed const &src);
#endif
