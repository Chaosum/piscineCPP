/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:54:54 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 15:08:43 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Span
{
public:
	Span(void);
	Span(unsigned int n);
	Span(Span &src);
	~Span(void);
	Span	&operator=(Span const &src);
	void	addNumber(int nbr)
	{
		if (tab.size() == max_nbr)
			throw TooManyNumber();
		nb_stocked++;
		tab.push_back(nbr);
	}
	unsigned int	shortestSpan()
	{
		std::vector<int>::iterator it;
		std::vector<int>::iterator test_val = tab.begin();
		unsigned int dest = 4294967295;

		while (test_val != tab.end())
		{
			it = tab.begin();
			while(it != tab.end())
			{
				if (it == test_val)
					it++;
				else if ((unsigned int)(*it >= *test_val? *it - *test_val: *test_val - *it) <= dest)
				{
					dest = (unsigned int)(*it >= *test_val? *it - *test_val: *test_val - *it);
					it++;
				}
				else
					it++;
			}
			test_val++;
		}
		return static_cast<int>(dest);
	}
	long int	longestSpan()
	{
		long int min;
		long int max;

		min = *(std::min_element(tab.begin(), tab.end()));
		max = *(std::max_element(tab.begin(), tab.end()));
		return (max - min);
	}
	template <typename T>
	void	addMultiple(typename T::iterator begin, typename T::iterator end)
	{
		for (typename T::iterator it = begin; it != end; it++)
		{
			addNumber(*it);
		}
	}
	class TooManyNumber : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Too many number is tab");
		}
	};
private:
	int					nb_stocked;
	unsigned int		max_nbr;
	std::vector<int>	tab;
};