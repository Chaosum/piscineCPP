/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:50:23 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 15:03:15 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#include <exception>

template <typename T>
typename T::iterator	easyfind(T &container, int find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), find);
	if (*it == find)
		return (it);
	throw std::exception();
}