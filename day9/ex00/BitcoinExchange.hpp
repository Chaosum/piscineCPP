/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:53:25 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/23 00:45:58 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
private:
	std::map<int, float> _btcValue;
	std::ifstream _infile;
	void	initMap();
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &src);
	std::map<int, float>::iterator getElement(int date);
};