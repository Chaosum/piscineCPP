/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:33:50 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/28 01:27:26 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
#include <iostream>
#include <string>
#include <sys/time.h>

int main(int ac, char **av){
	struct timeval timer_start;
	struct timeval timer_end;
	unsigned long time_in_micros;

	if (ac <= 1){
		std::cout << "Error: Not enought arguments" << std::endl;
		return (1);
	}
	int inci = 1;
	int incj = 0;
	while ( inci < ac){
		while (av[inci][incj])
		{
			if (av[inci][incj] < '0' || av[inci][incj] > '9'){
				std::cout << "Error: Wrong arguments - Not a number \"" << av[inci] << "\"" << std::endl;
				return (1);
			}
			incj++;
		}
		if (incj >= 10 && atoll(av[inci]) > 2147483647){
			std::cout << "Error: number too large " << av[inci] << std::endl;
			return (1);
		}
		incj = 0;
		inci++;
	}
	
	PmergeMe	test(ac, av);

	gettimeofday(&timer_start, NULL);
	test.mergeInsertionSortList(test.getList());
	gettimeofday(&timer_end, NULL);

	std::list<int> mylist = test.getList();
	std::cout << "after : ";
	size_t i = 0;
	std::list<int>::iterator it = mylist.begin();
	std::list<int>::iterator itprev = it;
	while (i < mylist.size())
	{
		std::cout << *it << " ";
		i++;
		itprev = it;
		it++;
		if (i < mylist.size() && *itprev >= *it){
			std::cout << "error list not sorted" << std::endl;
			return 1;
		}
	}
	std::cout << std::endl;
	time_in_micros = ((1000000 * timer_end.tv_sec) + timer_end.tv_usec) - ((1000000 * timer_start.tv_sec) + timer_start.tv_usec);
	std::cout << "Time to process a range of " << mylist.size() << "elements whith std::list : " << time_in_micros << "ms" << std::endl;

	gettimeofday(&timer_start, NULL);
	test.mergeInsertionSort(test.getVector());
	gettimeofday(&timer_end, NULL);
	time_in_micros = ((1000000 * timer_end.tv_sec) + timer_end.tv_usec) - ((1000000 * timer_start.tv_sec) + timer_start.tv_usec);
	std::cout << "Time to process a range of " << mylist.size() << "elements whith std::vector : " << time_in_micros << "ms" << std::endl;
	// std::vector<int> myVector = test.getVector();
	// std::vector<int>::iterator itv = myVector.begin();
	// std::vector<int>::iterator itprevv = itv;
	// i = 0;
	// while (i < myVector.size())
	// {
	// 	std::cout << *itv << " ";
	// 	i++;
	// 	itprevv = itv;
	// 	itv++;
	// 	if (i < myVector.size() && *itprevv >= *itv){
	// 		std::cout << "error list not sorted" << std::endl;
	// 		return 1;
	// 	}
	// }
	return (0);
}