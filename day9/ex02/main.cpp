/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:33:50 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/24 15:33:55 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
#include <iostream>
#include <string>

int main(int ac, char **av){
	
	PmergeMe	test(ac, av);
	test.sortList(test.getList());
	std::list<int> mylist = test.getList();

	return (0);
}