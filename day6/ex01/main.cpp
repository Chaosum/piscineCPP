/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:00:29 by mservage          #+#    #+#             */
/*   Updated: 2022/02/24 20:48:05 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>
#include <string>

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main ()
{
	Data test(1337);
	std::cout << "value = " << test.getValue() << std::endl;
	std::cout << "origin adress " << &test << std::endl;
	std::cout << "result adress " << deserialize(serialize(&test)) << std::endl;
	std::cout << "la structure est toujours utilisable value = " << test.getValue() << std::endl;
	return (0);
}