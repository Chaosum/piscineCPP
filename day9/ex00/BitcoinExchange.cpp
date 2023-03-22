/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:53:27 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/23 00:53:48 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */): _infile("data.csv")
{
	initMap();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){
	_btcValue = src._btcValue;
}


BitcoinExchange::~BitcoinExchange(){
}

void	BitcoinExchange::initMap(){
	
	std::string line;
	std::string date;
	std::pair<int, float> node;
	getline(_infile, line);
	line.clear();
	while (std::getline(_infile, line))
	{
		date = line.substr(0, line.find(','));
		while (date.find('-') < date.length()){
			date.erase(date.find('-'), 1);
		}
		node.first = std::stoi(date);
		node.second = std::stof(line.substr(line.find(',', line.length())));
		std::cout << node.first << " et " << node.second << std::endl;
		_btcValue.insert(node);
	}
}
std::map<int, float>::iterator BitcoinExchange::getElement(int date){
	std::map<int, float>::iterator it = _btcValue.begin();
	while (it != _btcValue.end() && it->first < date){
		if (it->first == date)
			return it;
		it++;
	}
	return (it != _btcValue.begin()? --it: it);
}
