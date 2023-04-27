/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:33:43 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/28 00:31:28 by matthieu         ###   ########.fr       */
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
	std::list<int> lst;

public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &src);
	void	initContainers(int ac, char **av);
	void	mergeVector(std::vector<int>& nums, int left, int mid, int right);
	void 	insertionSort(std::vector<int>& nums, int left, int right);
	void 	mergeInsertionSort(std::vector<int>& nums, int left, int right);
	void 	mergeInsertionSort(std::vector<int>& nums);
	void	mergeList(std::list<int>& nums, std::list<int>& left, std::list<int>& right);
	void	insertionSortList(std::list<int>& nums);
	void	mergeInsertionSortList(std::list<int>& nums);



	std::list<int> &getList();
	std::vector<int> &getVector();
};
