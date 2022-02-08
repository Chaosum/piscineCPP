/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:51:35 by matthieu          #+#    #+#             */
/*   Updated: 2022/02/09 00:31:59 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;
const int	Fixed::_fractional = 8;

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(int const nbr)
{
	this->_value = (nbr << this->_fractional);
}

Fixed::Fixed(float const nbr)
{
	this->_value = (int)roundf(nbr * (1 << this->_fractional));
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt() const
{
	return (this->_value >> this->_bits);
}


float	Fixed::toFloat() const
{
	return (this->_value / (float)(1 << this->_fractional));
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}


Fixed	&Fixed::operator=(Fixed const &rhs)
{
	this->_value = rhs.getRawBits();
	return (*this);
}

int		Fixed::operator<(Fixed const &rhs) const
{
	return(this->getRawBits() < rhs.getRawBits());
}

int		Fixed::operator>(Fixed const &rhs) const
{
	return(this->getRawBits() > rhs.getRawBits());
}

int		Fixed::operator>=(Fixed const &rhs) const
{
	return(this->getRawBits() >= rhs.getRawBits());
}

int		Fixed::operator<=(Fixed const &rhs) const
{
	return(this->getRawBits() <= rhs.getRawBits());
}

int		Fixed::operator==(Fixed const &rhs) const
{
	return(this->getRawBits() == rhs.getRawBits());
}

int		Fixed::operator!=(Fixed const &rhs) const
{
	return(this->getRawBits() != rhs.getRawBits());
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	ret;
	ret.setRawBits(this->_value);
	this->_value++;
	return (ret);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	ret;
	ret.setRawBits(this->_value);
	this->_value--;
	return (ret);
}
	
Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (ret);
}	

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	ret;

	ret.setRawBits((this->getRawBits() * rhs.getRawBits()) >> Fixed::_fractional);
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	ret;

	ret.setRawBits(this->getRawBits() << Fixed::_fractional / rhs.getRawBits());
	return (ret);
}

std::ostream &	operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
