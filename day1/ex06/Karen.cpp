/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:41:40 by matthieu          #+#    #+#             */
/*   Updated: 2022/02/07 13:54:25 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
}

Karen::~Karen()
{
}

void Karen::complain(std::string level)
{
	int i = 0;

	void	(Karen::*exec)(void);
	std::string complain[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	while (i < 4)
	{
		if (level == complain[i])
			break ;
		i++;
	}
	void (Karen::*fnct_ptr[4])(void) = 
	{
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error,
	};
	switch (i)
	{
		case 0:
			exec = fnct_ptr[0];
			(this->*exec)();
		case 1:
			exec = fnct_ptr[1];
			(this->*exec)();
		case 2:
			exec = fnct_ptr[2];
			(this->*exec)();
		case 3:
			exec = fnct_ptr[3];
			(this->*exec)();
			break ;
		default :
			std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
	}
}

void	Karen::debug()
{
	std::cout << "[ DEBUG ]" << std::endl << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info()
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning()
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error()
{
	std::cout << "[ ERROR ]" << std::endl<< "This is unacceptable, I want to speak to the manager now." << std::endl;
}