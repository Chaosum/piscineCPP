/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:45:21 by mservage          #+#    #+#             */
/*   Updated: 2022/02/08 23:46:50 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed
{
public:
	Fixed(void);
	Fixed(int const nbr);
	Fixed(float const nbr);
	Fixed(Fixed const &src);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static const Fixed	&min(Fixed const &a, Fixed const &b);
	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&max(Fixed const &a, Fixed const &b);
	static Fixed	&max(Fixed &a, Fixed &b);

	int		operator<(Fixed const &rhs) const;
	int		operator>(Fixed const &rhs) const;
	int		operator>=(Fixed const &rhs) const;
	int		operator<=(Fixed const &rhs) const;
	int		operator==(Fixed const &rhs) const;
	int		operator!=(Fixed const &rhs) const;

	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);
	
	
	
	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;
	
	Fixed	&operator=(Fixed const &rhs);

private:
	int					_value;
	static const int	_fractional;
	static const int	_bits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif