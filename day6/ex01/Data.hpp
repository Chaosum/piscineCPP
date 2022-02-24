/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:03:05 by mservage          #+#    #+#             */
/*   Updated: 2022/02/24 20:46:40 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Data
{
public:
	Data(void);
	Data(uintptr_t nbr);
	Data(Data const &src);
	~Data(void);

	uintptr_t	getValue() const;
	Data	&operator=(Data &src);
private:
	uintptr_t	data;
};