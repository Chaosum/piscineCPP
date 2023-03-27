/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:33:47 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/28 01:25:07 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
	std::cout << "before : ";
	while (i < ac){
		vect.push_back(atoi(av[i]));
		lst.push_back(atoi(av[i]));
		std::cout << av[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

void	PmergeMe::mergeVector(std::vector<int> &first,std::vector<int> &second){
	std::vector<int> dest;
	std::vector<int>::iterator itf = first.begin();
	std::vector<int>::iterator its = second.begin();
	while(itf != first.end() || its != second.end()){
		if (itf != first.end() && *itf <= *its)
		{
			dest.push_back(*itf);
			itf++;
		}
		else if (its != second.end() && *its <= *itf)
		{
			dest.push_back(*its);
			its++;
		}
		else if (itf == first.end()){
			dest.push_back(*its);
			its++;
		}
		else if (its == second.end()){
			dest.push_back(*itf);
			itf++;
		}
	}
	first = dest;
	return ;
}

void	PmergeMe::sortVector(std::vector<int> &s_vect){
	if (s_vect.size() <= 2 && s_vect.size() != 0){
		if (s_vect.size() == 1)
			return ;
		else {
			if (s_vect[0] > s_vect[1]){
				int tmp = s_vect[0];
				s_vect[0] = s_vect[1];
				s_vect[1] = tmp;
			}
		}
		return ;
	}
	else {
		std::pair<std::vector<int>, std::vector<int> > p_vect;
		std::vector<int>::iterator it = s_vect.begin();
		size_t i = 0;
		while (i < s_vect.size())
		{
			if (i < s_vect.size() / 2){
				p_vect.first.push_back(*it);
			}
			else
				p_vect.second.push_back(*it);
			i++;
			it++;
		}
		if (!p_vect.first.empty())
			sortVector(p_vect.first);
		if (!p_vect.second.empty())
			sortVector(p_vect.second);
		mergeVector(p_vect.first, p_vect.second);
		s_vect = p_vect.first;
	}
}

void	PmergeMe::sortList(std::list<int> &s_list){
	if (s_list.size() <= 2 && s_list.size() > 0){
		s_list.sort();
		return ;
	}
	else {
		std::pair<std::list<int>, std::list<int> > p_list;
		std::list<int>::iterator it = s_list.begin();
		size_t i = 0;
		while (i < s_list.size())
		{
			if (i < s_list.size() / 2)
				p_list.first.push_back(*it);
			else
				p_list.second.push_back(*it);
			i++;
			it++;
		}
		if (p_list.first.empty())
			sortList(p_list.first);
		if (p_list.second.empty())
			sortList(p_list.second);
		p_list.first.merge(p_list.second);
		s_list = p_list.first;
		s_list.sort();
	}
}

std::list<int> &PmergeMe::getList(){
	return (this->lst);
}
std::vector<int> &PmergeMe::getVector(){
	return (this->vect);
}


