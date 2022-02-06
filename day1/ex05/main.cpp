/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:37:53 by matthieu          #+#    #+#             */
/*   Updated: 2022/02/06 18:11:06 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void)
{
	Karen	karen;

	std::cout << "1 |\"WARNING\" : expected WARNING|" << std::endl << std::endl;
	karen.complain("WARNING");
	std::cout << "2 |\"WAR\" : expected ERROR|" << std::endl << std::endl;
	karen.complain("WAR");
	std::cout << "3 |\"INFO\" : expected INFO|" << std::endl << std::endl;
	karen.complain("INFO");
	std::cout << "4 |\"DEBUG\" : expected DEBUG|" << std::endl << std::endl;
	karen.complain("DEBUG");
	std::cout << "5 |\"jkrsedtbnkhgktnjhb\" : expected ERROR|" << std::endl << std::endl;
	karen.complain("jkrsedtbnkhgktnjhb");
	std::cout << "6 |\"\" : expected  ERROR|" << std::endl << std::endl;
	karen.complain("");
}