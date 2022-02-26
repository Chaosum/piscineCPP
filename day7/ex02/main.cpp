/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:41:49 by mservage          #+#    #+#             */
/*   Updated: 2022/02/26 21:55:11 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

void emptyTest() {
	Array<int> array0;
	Array<std::string> array1;

	try
	{
		array0[0] = 5;
		std::cout << "Not good" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		array1[0] = "pouet";
		std::cout << "not good 2" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void basicArray() {
	Array<int> array(10);
	std::cout << "Basic array tests" << std::endl;
	std::cout << "Default initialized values" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)array.size(); ++i)
	{
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}
	std::cout << "Filling it with values" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)array.size(); ++i)
	{
		array[i] = i;
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}
	try
	{
		std::cout << "index too high ";
		array[456] = 69;
		std::cout << "not good3" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Negative index ";
		array[-1] = 420;
		std::cout << "not good4" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "- size() index";
		array[array.size()] = 666;
		std::cout << "not good5" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void copyTests() {
	std::cout << "Copy array tests" << std::endl;

	Array<std::string> array(5);
	array[0] = "Bojour";
	array[1] = "-Salut, comment ca va ?";
	array[2] = "Ca va et toi";
	array[3] = "-Ca va j'essaye de valider mon day 7";
	array[4] = "HA !";

	std::cout << "Original values" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)array.size(); ++i) {
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}

	Array<std::string> arrayCpy0(array);
	Array<std::string> arrayCpy1 = Array<std::string>(50);

	std::cout << "Constructor-copied values" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)arrayCpy0.size(); ++i) {
		std::cout << "[" << i << "]: " << arrayCpy0[i] << std::endl;
	}

	std::cout << "Operator-copied values" << std::endl;
	arrayCpy1 = arrayCpy0;
	for (unsigned int i = 0; i < (unsigned int)arrayCpy1.size(); ++i) {
		std::cout << "[" << i << "]: " << arrayCpy1[i] << std::endl;
	}

	std::cout << "Modifying a value of the operator-copied array" << std::endl;
	arrayCpy1[3] = "-pouet";

	std::cout << "Original array" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)array.size(); ++i) {
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}

	std::cout << "Constructor-copied array" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)arrayCpy0.size(); ++i) {
		std::cout << "[" << i << "]: " << arrayCpy0[i] << std::endl;
	}

	std::cout << "Operator-copied array" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)arrayCpy1.size(); ++i) {
		std::cout << "[" << i << "]: " << arrayCpy1[i] << std::endl;
	}

	try {
		arrayCpy1[48] = "WHAT?!";
		std::cout << "Did not throw an exception when it was supposed :(" << std::endl;
	} catch (std::exception &exception) {
		(void)exception;
		std::cout << "Noice :)" << std::endl;
	}
}

int main(void) {
	emptyTest();
	basicArray();
	copyTests();

	return 0;
}