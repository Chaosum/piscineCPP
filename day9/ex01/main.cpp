/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:13:29 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/24 13:55:33 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "RPN.hpp"
#include <stack>

int main(int ac, char **av){
	if (ac != 2){
		std::cout << "Error: Wrongs args - ./RPN \"numbers=> 0123456789 | symbols => /*-+ \"" << std::endl;
		return (1);
	}
	RPN	myRPN;
	if (myRPN.verifyString(av[1])){
		return (1);
	}
	std::string line = av[1];
	if (myRPN.executeRPN(line))
		return (1);
	return (0);
}