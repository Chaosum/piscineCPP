/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:33:43 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/24 15:22:37 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>

class PmergeMe
{
private:
	std::vector<int> vect;
	std::list<int>	lst;
public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &src);
	void	initContainers(int ac, char **av);
	void	sortList(std::list<int> &s_list);
	void	smallSortList(std::list<int> &s_list);
	void	sortVector();
	std::list<int> &getList();
};
