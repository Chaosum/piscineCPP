/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:40:51 by mservage          #+#    #+#             */
/*   Updated: 2022/02/24 23:35:29 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename T>
void	iter(T *tab, int size, void fnct(T &src))
{
	int i = 0;
	while (i < size)
	{
		fnct(tab[i]);
		i++;
	}
}

template< typename T >
void print(T &src)
{
	std::cout << src << std::endl;
}

int main()
{
	char tab_char[5] = {'a', 'b', 'c', 'd', 'e'};
	int tab_int[5] = {1, 2, 3, 4, 5};
	float tab_float[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string	str_tab[5] = {"oui", "non", "pouet", "lol", "nope"};
	
	iter<char>(tab_char, 5, print);
	iter<int>(tab_int, 5, print);
	iter<float>(tab_float, 5, print);
	iter<std::string>(str_tab, 5, print);
	return 0;
}
