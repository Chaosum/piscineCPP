/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:05:43 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 12:05:56 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	swap(T &a, T &b)
{
	T	temp(b);

	b = a;
	a = temp;
}

template <typename T>
T	min(T const a, T const b)
{
	return (b <= a ? b : a);
}

template <typename T>
T	max(T const a, T const b)
{
	return (b >= a ? b : a);
}