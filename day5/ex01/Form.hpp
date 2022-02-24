/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:32:37 by mservage          #+#    #+#             */
/*   Updated: 2022/02/24 16:46:09 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(std::string const &name, int exec, int sign);
	Form(Form const &src);
	~Form();
	class GradeTooHighException : std::exception
	{
		const char *what() const throw()
		{
			return ("Grade too High");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Grade too Low");
		}
	};
	Form	&operator=(Form &rhs);
	std::string const	&getName() const;
	bool	const &getSigned() const;
	int const	&getGradeExec() const;
	int const	&getGradeSign() const;
	void	beSigned(Bureaucrat const &src);
private:
	std::string const	_name;
	bool				_signed;
	int const			_gradeExec;
	int const			_gradeSign;
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);
