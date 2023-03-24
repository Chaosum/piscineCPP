/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:13:25 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/24 13:46:55 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stack>

class RPN
{
private:
	std::stack<float> numbers;
	std::stack<char> operands;
public:
	RPN();
	RPN(const RPN &src);
	~RPN();
	RPN	&operator=(const RPN &src);
	bool	verifyString(std::string line);
	bool	executeRPN(std::string line);
	float	calculate(float first, float second, char operand);
};