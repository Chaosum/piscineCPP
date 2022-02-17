/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:33:56 by mservage          #+#    #+#             */
/*   Updated: 2022/02/17 17:36:58 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(Cure const &src);
	virtual ~Cure(void);

	std::string	&getType(void) const;
	Cure	&operator=(Cure const &rhs);
	virtual	AMateria *clone() const;
	virtual void use(ICharacter& target);
protected:
	std::string	_type;
};

#endif