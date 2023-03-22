/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:53:29 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/22 23:56:31 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>

int main(int ac, char **av){
	

	if ( ac != 2){
		std::cout << "Wrong args: ./btc [file]" << std::endl;
		return (1);
	}

	return (0);
}