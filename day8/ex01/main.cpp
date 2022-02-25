/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:09:08 by mservage          #+#    #+#             */
/*   Updated: 2022/02/25 18:50:51 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <exception>
#include <vector>

int main()
{
	Span a(10);
	std::vector<int> vec;

	vec.push_back(INT_MAX);
	vec.push_back(INT_MIN);
	a.addMultiple<std::vector<int> >(vec.begin(), vec.end());
	std::cout << a.longestSpan() << std::endl;
	std::cout << a.shortestSpan() << std::endl;
}