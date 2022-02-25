/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 01:09:45 by mservage          #+#    #+#             */
/*   Updated: 2022/02/25 11:39:42 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include <array>
#include "easyfind.hpp"

int main()
{
	std::array<int, 10> A = {0, 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
	std::array<int, 10>::iterator it;

	try
	{
		it = easyfind< std::array<int, 10> >(A, 5);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		it = easyfind< std::array<int, 10> >(A, 10);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}