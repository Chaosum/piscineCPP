/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 05:44:16 by matthieu          #+#    #+#             */
/*   Updated: 2021/11/02 13:53:50 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

int	main(int ac, char **av)
{
	int i;
	int j;
	char c;

	i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			c = av[i][j];
			c = std::toupper(c);
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
}