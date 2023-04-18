/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:53:27 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/28 02:09:47 by matthieu         ###   ########.fr       */
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

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	_btcValue = src._btcValue;
	return (*this);
}


void	BitcoinExchange::initMap(){
	std::string line;
	std::string date;
	std::pair<int, float> node;
	getline(_infile, line);
	line.clear();
	while (std::getline(_infile, line))
	{
		line[line.find(',')] = ' ';
		std::stringstream ss(line);
		ss >> date >> node.second;
		while (date.find('-') < date.length()){
			date.erase(date.find('-'), 1);
		}
		node.first = atoi(date.c_str());
		_btcValue.insert(node);
	}
}
std::map<int, float>::iterator BitcoinExchange::getElement(int date){
	std::map<int, float>::iterator it = _btcValue.begin();
	while (it != _btcValue.end() && it->first <= date){
		if (it->first == date)
			return it;
		it++;
	}
	return (it != _btcValue.begin()? --it: _btcValue.end());
}

bool	BitcoinExchange::checkDateFormat(std::string &date) const{
	std::istringstream streamdate(date);
	std::string year, day, month;
	getline(streamdate, year, '-');
	getline(streamdate, month, '-');
	getline(streamdate, day);
	if (year.empty() || month.empty() || day.empty()
		|| year.find_first_not_of("0123456789") != std::string::npos
		|| day.find_first_not_of("0123456789") != std::string::npos
		|| month.find_first_not_of("0123456789") != std::string::npos
		|| year.size() > 4 || month.size() > 2 || day.size() > 2
		|| atoi(month.c_str()) > 13 || atoi(month.c_str()) < 1 
		|| atoi(day.c_str()) > 31 || atoi(day.c_str()) < 1 ){
		std::cout << "Error: bad date => " << date << std::endl;
		return (true);
	}
	return (false);
}

bool	BitcoinExchange::checkAmontFormat(std::string &amount) const {
	if (amount.empty() || amount.find_first_not_of("0123456789.") != std::string::npos){
		std::cout << "Error: bad imput => " << amount << std::endl;
		return (true);
	}
	else if (atof(amount.c_str()) > 1000){
		std::cout << "Error: value too big => " << amount << std::endl;
		return (true);

	}
	else if (atof(amount.c_str()) < 0){
		std::cout << "Error: negative value => " << amount << std::endl;
		return (true);

	}
	return (false);
}

bool	BitcoinExchange::is_invalid_string(const std::string &line) const{
	std::stringstream ss(line);
	std::string date, amount, sep;
	ss >> date >> sep >> amount;

	if (ss.fail() || !ss.eof()){
		std::cout << "Error: Wrong format." << std::endl;
		return (true);
	}
	else if (checkDateFormat(date)){
		return (true);
	}
	else if (sep != "|"){
		std::cout << "Error: bad imput '|' => " << line << std::endl;
		return (true);
	}
	else if (checkAmontFormat(amount)){
		return (true);
	}
	return (false);
}

std::string	BitcoinExchange::convertDateFormat(int date){
	char	tmp[20];
	std::string	dest;
	sprintf(tmp, "%d", date);
	dest = tmp;
	dest.insert(6,"-");
	dest.insert(4,"-");
	return (dest);
}

std::map<int, float> &BitcoinExchange::get_btcValue(){
	return (_btcValue);
}