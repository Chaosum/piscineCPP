/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:36:57 by mservage          #+#    #+#             */
/*   Updated: 2022/02/25 00:33:01 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
public:
	Array<T>(void)
	{
		array = new T[0];
		this->n = 0;
	}
	Array<T>(unsigned int n)
	{
		this->n = n;
		array = new T[n]();
	}
	Array<T>(Array const &src)
	{
		int i = 0;
		n = src.size();
		array = new T[n];
		while (i < n)
		{
			array[i] = src.array[i];
			i++;
		}
	}
	~Array<T>(void)
	{
		delete [] this->array;
	}

	Array<T>	&operator=(Array const &src)
	{
		delete [] array;
		int i = 0;
		this->n = src.size();
		array = new T[this->n];
		while (i < this->n)
		{
			array[i] = src.array[i];
			i++;
		}
	}
	T			&operator[](const int idx)
	{
		if (idx < 0 || idx > this->n)
			throw WrongIndex();
		return this->array[idx];
	}
	int			size(void) const { return (this->n); }
	
	class WrongIndex : public std::exception
	{
	public:
		virtual const char *what() const throw ()
		{
			return ("Wrong index");
		}
	};
private:
	int	n;
	T	*array;
};
