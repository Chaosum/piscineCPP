/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:45:21 by mservage          #+#    #+#             */
/*   Updated: 2022/02/09 00:04:40 by matthieu         ###   ########.fr       */
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
	Fixed	&operator=(Fixed const &rhs);

private:
	int					_value;
	static const int	_fractional;
	static const int	_bits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif