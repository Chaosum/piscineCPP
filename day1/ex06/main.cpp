/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:37:53 by matthieu          #+#    #+#             */
/*   Updated: 2022/02/07 13:50:20 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int ac, char **av)
{
	Karen karen;
	std::string level;

	if (ac != 2)
	{
		std::cout << "Wrongs Args." << std::endl;
		return (1);
	}
	level = av[1];
	karen.complain(level);
	return (0);
}
