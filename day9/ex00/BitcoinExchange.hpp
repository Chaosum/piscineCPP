/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:53:25 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/28 02:09:30 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

class BitcoinExchange
{
private:
	std::map<int, float> _btcValue;
	std::ifstream _infile;
	void	initMap();
	bool	checkDateFormat(std::string &date) const;
	bool	checkAmontFormat(std::string &amount) const;
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &src);
	std::map<int, float>::iterator getElement(int date);
	bool	is_invalid_string(const std::string &line) const;
	std::string	convertDateFormat(int date);
	std::map<int, float> &get_btcValue();

};