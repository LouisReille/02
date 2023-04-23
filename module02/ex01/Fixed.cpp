/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:09:42 by lreille           #+#    #+#             */
/*   Updated: 2023/04/20 18:54:39 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): entier(0)
{
	std::cout << "Default constructor call" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called " << std::endl;
	this->entier = copy.entier;
	return *this;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->entier = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->entier);
}

Fixed::Fixed(int num)
{
	std::cout << "Int constructor called" << std::endl;
	entier = num << bit;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	entier = roundf(num * (1 << Fixed::bit));
}

float Fixed::toFloat(void) const
{
	return ((float)(this->entier/ (float)(1 << bit)));
}

int Fixed::toInt(void) const
{
	return (this->entier >> bit);
}

std::ostream& operator<<(std::ostream &out, Fixed const &src)
{
	out<< src.toFloat();
	return (out);
}
