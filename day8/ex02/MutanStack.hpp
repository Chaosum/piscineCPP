/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:21:17 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 13:18:08 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template< typename T, typename _Container = std::deque<T> >
struct MutantStack: std::stack<T, _Container>
{
public:
	typedef typename _Container::iterator				iterator;
	typedef typename _Container::const_iterator			const_iterator;
	typedef typename _Container::reverse_iterator		reverse_iterator;
	typedef typename _Container::const_reverse_iterator	const_reverse_iterator;

	explicit MutantStack(const _Container& cont = _Container()) : std::stack<T, _Container>(cont) {}
	MutantStack(const MutantStack &cpy): std::stack<T, _Container>(cpy) {}
	~MutantStack() {}

	MutantStack &operator=(const MutantStack &rhs) {
		std::stack<T, _Container>::operator=(rhs);
	}
	iterator begin()
	{
		return MutantStack::c.begin();
	}
	iterator end()
	{
		return MutantStack::c.end();
	}
	const_iterator begin() const
	{
		return MutantStack::c.begin();
	}
	const_iterator end() const
	{
		return MutantStack::c.end();
	}
	reverse_iterator rbegin()
	{
		return MutantStack::c.rbegin();
	}
	reverse_iterator rend()
	{
		return MutantStack::c.rend();
	}
	const_reverse_iterator rbegin() const
	{
		return MutantStack::c.rbegin();
	}
	const_reverse_iterator rend() const
	{
		return MutantStack::c.rend();
	}
};