/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:13:27 by matthieu          #+#    #+#             */
/*   Updated: 2023/03/24 14:23:15 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
}

RPN::RPN(const RPN &src){
	this->numbers = src.numbers;
	this->operands = src.operands;
}

RPN::~RPN(){
}

RPN	&RPN::operator=(const RPN &src){
	this->numbers = src.numbers;
	this->operands = src.operands;
	return (*this);
}

bool	RPN::verifyString(std::string line) /*return true if invalid*/ {
	if (line.find_first_not_of("0123456789+-/* ") != line.npos){
		std::cout << "Error: wrongs char - ./RPN \"numbers=> 0123456789 | symbols => /*-+ \"" << std::endl;
		return (true);
	}
	int i = 0;
	int operands = 0;
	int numbers = 0;
	while (line[i]){
		if (line[i] == '/' || line[i] == '*' || line[i] == '+' || line[i] == '-')
			operands++;
		else if (line[i] >= '0' && line[i] <= '9')
			numbers++;
		i++;
	}
	if (operands > numbers - 1){
		std::cout << "Error: Too many operands compared to numbers" << std::endl;
		return (true);
	}
	else if (numbers - 1 > operands){
		std::cout << "Error: Too many numbers compared to operands" << std::endl;
		return (true);
	}
	return (false);
}

float	RPN::calculate(float first, float second, char operand){
	if (operand == '*'){
		return (first * second);
	}
	else if (operand == '/'){
		return (first / second);
	}
	else if (operand == '+'){
		return (first + second);
	}
	else if (operand == '-'){
		return (first - second);
	}
	return (0);
}


bool	RPN::executeRPN(std::string line)
{
	int i = 0;
	int count_operands = 0;
	int count_numbers = 0;
	float first = 0, second = 0, result = 0;
	while (line[i]){
		if (line[i] == '/' || line[i] == '*' || line[i] == '+' || line[i] == '-'){
			if (count_numbers < 2){
				std::cout << "Error: Not a valid RPN notation" << std::endl;
				return (true);
			}
			this->operands.push(line[i]);
			count_operands++;
			if (count_operands && count_numbers >= 2){
				first = this->numbers.top();
				this->numbers.pop();
				second = this->numbers.top();
				this->numbers.pop();
				if ( this->operands.top() == '/' && first == 0){
					std::cout << "Error: Division by 0" << std::endl;
					return (true);
				}
				result = calculate(second, first, this->operands.top());
				this->numbers.push(result);
				this->operands.pop();
				count_operands--;
				count_numbers--;
			}
		}
		else if (line[i] >= '0' && line[i] <= '9'){
			this->numbers.push(line[i] - '0');
			count_numbers++;
			if (count_operands && count_numbers >= 2){
				first = this->numbers.top();
				this->numbers.pop();
				second = this->numbers.top();
				this->numbers.pop();
				if ( this->operands.top() == '/' && first == 0){
					std::cout << "Error: Division by 0" << std::endl;
					return (true);
				}
				result = calculate(second, first, this->operands.top());
				this->numbers.push(result);
				this->operands.pop();
				count_operands--;
				count_numbers--;
			}
		}

		i++;
	}
	count_numbers? std::cout << this->numbers.top() << std::endl : std::cout << "0" << std::endl;
	return (false);
}

