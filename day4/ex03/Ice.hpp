/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:30:27 by mservage          #+#    #+#             */
/*   Updated: 2022/02/17 17:37:23 by mservage         ###   ########.fr       */
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
	
protected:
	std::string	_type;
};

#endif