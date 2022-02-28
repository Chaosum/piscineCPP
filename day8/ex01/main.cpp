/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:09:08 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 15:13:47 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <exception>
#include <vector>

void emptyTest()
{
	Span a;
	try
	{
		a.addNumber(15);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test1()
{
	std::cout << "TEST1" << std::endl;
	Span a(10);
	std::vector<int> vec;

	vec.push_back(INT_MAX);
	vec.push_back(INT_MIN);
	a.addMultiple<std::vector<int> >(vec.begin(), vec.end());
	std::cout << a.longestSpan() << std::endl;
	std::cout << a.shortestSpan() << std::endl;
}

void test2()
{
	std::cout << "TEST2" << std::endl;
	Span a(10);
	std::vector<int> vec;
	int i = 0;
	vec.push_back(i++);
	vec.push_back(i++);
	vec.push_back(i++);
	vec.push_back(i++);
	vec.push_back(i++);
	vec.push_back(i++);
	vec.push_back(i++);
	vec.push_back(i++);
	vec.push_back(i++);
	vec.push_back(i++);
	a.addMultiple<std::vector<int> >(vec.begin(), vec.end());
	try
	{
		a.addNumber(i++);
		std::cout << "Pas bon!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a.longestSpan() << std::endl;
	std::cout << a.shortestSpan() << std::endl;
}

int main()
{
	emptyTest();
	test1();
	test2();
}