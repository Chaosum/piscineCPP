/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:19:40 by mservage          #+#    #+#             */
/*   Updated: 2022/02/17 14:48:22 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain
{
public:
	Brain(void);
	Brain(Brain const &src);
	virtual ~Brain(void);

	Brain	&operator=(Brain const &rhs);
protected:
	std::string	_ideas[100];
};