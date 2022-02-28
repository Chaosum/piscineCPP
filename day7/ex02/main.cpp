/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:41:49 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 11:09:44 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

void emptyTest() {
	Array<int> testInt;
	Array<std::string> testString;

	try
	{
		testInt[0] = 5;
		std::cout << "Not good" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		testString[0] = "pouet";
		std::cout << "not good 2" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void basicTest() {
	Array<int> testInt(10);
	std::cout << "Basic tests" << std::endl;
	std::cout << "Default value init" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)testInt.size(); ++i)
	{
		std::cout << "[" << i << "]: " << testInt[i] << std::endl;
	}
	std::cout << "add value" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)testInt.size(); ++i)
	{
		testInt[i] = i;
		std::cout << "[" << i << "]: " << testInt[i] << std::endl;
	}
	try
	{
		std::cout << "index too high ";
		testInt[456] = 69;
		std::cout << "not good3" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Negative index";
		testInt[-1] = 420;
		std::cout << "not good4" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "size() index";
		testInt[testInt.size()] = 666;
		std::cout << "not good5" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void copyTests() {
	std::cout << "Copy tests" << std::endl;

	Array<std::string> array(5);
	array[0] = "Bojour";
	array[1] = "-Salut, comment ca va ?";
	array[2] = "Ca va et toi";
	array[3] = "-Ca va, j'essaye de valider mon day 7";
	array[4] = "HA !";

	std::cout << "Original values" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)array.size(); ++i)
	{
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}

	Array<std::string> arrayCpy0(array);
	Array<std::string> arrayCpy1 = Array<std::string>(50);

	std::cout << "Constructor-copied values" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)arrayCpy0.size(); ++i)
	{
		std::cout << "[" << i << "]: " << arrayCpy0[i] << std::endl;
	}

	std::cout << "Operator-copied values" << std::endl;
	arrayCpy1 = arrayCpy0;
	for (unsigned int i = 0; i < (unsigned int)arrayCpy1.size(); ++i)
	{
		std::cout << "[" << i << "]: " << arrayCpy1[i] << std::endl;
	}

	std::cout << "Modifying a value of the operator-copied array" << std::endl;
	arrayCpy1[3] = "-stp valide mon day7 :'(";

	std::cout << "Original array" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)array.size(); ++i)
	{
		std::cout << "[" << i << "]: " << array[i] << std::endl;
	}
	std::cout << "Constructor-copied array" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)arrayCpy0.size(); ++i)
	{
		std::cout << "[" << i << "]: " << arrayCpy0[i] << std::endl;
	}
	std::cout << "Operator-copied array" << std::endl;
	for (unsigned int i = 0; i < (unsigned int)arrayCpy1.size(); ++i)
	{
		std::cout << "[" << i << "]: " << arrayCpy1[i] << std::endl;
	}
	try
	{
		arrayCpy1[48] = "POUAITE";
		std::cout << "Did not throw an exception when it was supposed" << std::endl;
	} catch (std::exception &exception) {
		(void)exception;
		std::cout << "OK" << std::endl;
	}
}

int main(void) {
	emptyTest();
	basicTest();
	copyTests();
	return 0;
}