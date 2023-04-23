/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreille <lreille@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:09:42 by lreille           #+#    #+#             */
/*   Updated: 2023/04/23 16:23:33 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): entier(0)
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed& copy)
{
	this->entier = copy.entier;
	return *this;
}

Fixed::Fixed(const Fixed &copy)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

void	Fixed::setRawBits(int const raw)
{
	this->entier = raw;
}

int	Fixed::getRawBits(void) const
{
	return (this->entier);
}

Fixed::Fixed(int num)
{
//	std::cout << "Int constructor called" << std::endl;
	entier = num << bit;
}

Fixed::Fixed(const float num)
{
//	std::cout << "Float constructor called" << std::endl;
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
/////////

bool Fixed::operator==(const Fixed &n) const {

	return(this->getRawBits() == n.getRawBits());
}

bool Fixed::operator<(const Fixed &n) const {
	return(this->getRawBits() < n.getRawBits());
}
bool Fixed::operator<=(const Fixed &n) const {
	return(this->getRawBits() <= n.getRawBits());
}

bool Fixed::operator>(const Fixed &n) const {
	return(this->getRawBits() > n.getRawBits());
}

bool Fixed::operator>=(const Fixed &n) const {
	return(this->getRawBits() >= n.getRawBits());
}

bool Fixed::operator!=(const Fixed &n) const {
	return(this->getRawBits() != n.getRawBits());
}

//////////////////////

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++_entier;
	return(tmp);
}

Fixed Fixed::operator++(void)
{
	_entier++;
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed tmp(*this);
	--_entier;
	return(tmp);
}

Fixed Fixed::operator--(void)
{
	_entier--;
	return (*this);
}

//////////////////////////


Fixed&	Fixed::operator*=(const Fixed &n)
{
	long tmp1, tmp2;

	tmp1 = 	((long)this->getRawBits());
	tmp2 = 	((long)n.getRawBits());
	this->setRawBits((tmp1 * tmp2) / (1 << _bits));
	return (*this);
}

Fixed& Fixed::operator+=(const Fixed &n)
{
	this->setRawBits(this->getRawBits() + n.getRawBits());
	return (*this);
}

Fixed& Fixed::operator-=(const Fixed &n){
	this->setRawBits(this->getRawBits() - n.getRawBits());
	return(*this);
}

Fixed& Fixed::operator/=(const Fixed &n){
	long tmp1, tmp2;

	tmp1 = 	((long)this->getRawBits());
	tmp2 = 	((long)n.getRawBits());
	this->setRawBits((tmp1 * (1 << _bits)) / tmp2);
	return (*this);;
}
///////////////////

Fixed	Fixed::operator*(const Fixed &n)
{
	Fixed _entier(*this);
	long tmp1, tmp2;

	tmp1 = 	((long)this->getRawBits());
	tmp2 = 	((long)n.getRawBits());
	_entier.setRawBits((tmp1 * tmp2) / (1 << _bits));
	return (_entier);
}

Fixed Fixed::operator+(const Fixed &n)
{
	Fixed _entier(*this);
	_entier.setRawBits(this->getRawBits() + n.getRawBits());
	return (_entier);
}

Fixed Fixed::operator-(const Fixed &n){
	Fixed _entier(*this);
	_entier.setRawBits(this->getRawBits() - n.getRawBits());
	return(_entier);
}

Fixed Fixed::operator/(const Fixed &n){
	Fixed _entier(*this);
	long tmp1, tmp2;

	tmp1 = 	((long)this->getRawBits());
	tmp2 = 	((long)n.getRawBits());
	_entier.setRawBits((tmp1 * (1 << _bits)) / tmp2);
	return (_entier);;
}


///////////////

Fixed& Fixed::min(Fixed &a, Fixed &b){
	if(a > b)
		return(b);
	return(a);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b){
	if(a > b)
		return(b);
	return(a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b){
	if(a > b)
		return(a);
	return(b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
	if(a > b)
		return(a);
	return(b);
}
