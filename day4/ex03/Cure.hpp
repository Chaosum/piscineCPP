/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:33:56 by mservage          #+#    #+#             */
/*   Updated: 2022/02/18 00:53:38 by matthieu         ###   ########.fr       */
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
};

#endif