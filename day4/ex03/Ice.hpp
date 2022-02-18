/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:30:27 by mservage          #+#    #+#             */
/*   Updated: 2022/02/18 00:51:31 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const &src);
	virtual ~Ice(void);

	std::string	&getType(void) const;
	Ice	&operator=(Ice const &rhs);
	virtual	AMateria *clone() const;
	virtual void use(ICharacter& target);
};

#endif