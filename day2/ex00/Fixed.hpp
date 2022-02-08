/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:45:21 by mservage          #+#    #+#             */
/*   Updated: 2022/02/08 01:21:03 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(int	nbr);
	Fixed(Fixed const &src);
	~Fixed(void);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	Fixed	&operator=(Fixed const &rhs);

private:
	int	_value;
	static const int	_bits;
};

#endif