/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:33:47 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/24 15:25:20 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define EXIT_VALUE 8

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(int ac, char **av){
	initContainers(ac, av);
}


PmergeMe::PmergeMe(const PmergeMe &src){
	this->vect = src.vect;
	this->lst = src.lst;
}

PmergeMe::~PmergeMe(){
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src){
	this->vect = src.vect;
	this->lst = src.lst;
	return (*this);
}

void	PmergeMe::initContainers(int ac, char **av){
	int i = 1;
	while (i < ac){
		vect.push_back(atoi(av[i]));
		lst.push_back(atoi(av[i]));
		std::cout << av[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

void	PmergeMe::sortVector(){
	
}

void	PmergeMe::smallSortList(std::list<int> &s_list){
	s_list.sort();
}

void	PmergeMe::sortList(std::list<int> &s_list){
	if (s_list.size() <= EXIT_VALUE){
		smallSortList(s_list);
		return ;
	}
	else {
		std::pair<std::list<int>, std::list<int> > p_list;
		sortList(p_list.first);
		sortList(p_list.second);
		p_list.first.merge(p_list.second);
		s_list = p_list.first;
	}
}

std::list<int> &PmergeMe::getList(){
	return (this->lst);
}


