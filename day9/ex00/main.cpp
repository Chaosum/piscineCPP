/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:53:29 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/28 02:13:18 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include "BitcoinExchange.hpp"
#include <cstdlib>

int main(int ac, char **av){
	

	if ( ac != 2){
		std::cout << "Wrong args: ./btc [file]" << std::endl;
		return (1);
	}
	std::string line, date, sep, amount;
	std::pair<int, float> input_data;
	std::ifstream input(av[1]);
	BitcoinExchange csv_data;

	while (std::getline(input, line))
	{
		if (!csv_data.is_invalid_string(line))
		{
			std::istringstream ss(line);
			ss >> date >> sep >> amount;
			while (date.find('-') < date.length()){
				date.erase(date.find('-'), 1);
			}
			input_data.first = atoi(date.c_str());
			input_data.second = atof(amount.c_str());
			std::map<int, float>::iterator it = csv_data.getElement(input_data.first);
			if (it == csv_data.get_btcValue().end()){
				std::cout << "Error: date too old. => " << line << std::endl;
			}
			else
				std::cout << csv_data.convertDateFormat(it->first) << " => " << input_data.second << " = " << it->second * input_data.second << std::endl;
		}
		line.clear();
	}
	return (0);
}