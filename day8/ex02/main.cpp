/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:04:24 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 14:58:34 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutanStack.hpp"
#include <string>
#include <iostream>
#include <stack>
#include <deque>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	const MutantStack<int> &cstack = mstack;
	MutantStack<int>::const_iterator cit;
	MutantStack<int>::const_iterator cite;
	cit = cstack.begin();
	cite = cstack.end();
	++ite;
	--ite;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	MutantStack<int>::const_reverse_iterator rcit;
	MutantStack<int>::const_reverse_iterator rcite;
	rcit = cstack.rbegin();
	rcite = cstack.rend();
	while (rcit != rcite)
	{
		std::cout << *rcit << std::endl;
		++rcit;
	}
	return (0);
}