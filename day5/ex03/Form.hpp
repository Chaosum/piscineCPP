/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:32:37 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 20:02:11 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(std::string const &name, int exec, int sign);
	Form(Form const &src);
	virtual ~Form();
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too High");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too Low");
		}
	};
	class FormNotSigned : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Form Not signed, can't execute");
		}
	};
	Form	&operator=(Form &rhs);

	std::string const	&getName() const;
	bool	const &getSigned() const;
	int const	&getGradeExec() const;
	int const	&getGradeSign() const;
	void	beSigned(Bureaucrat const &src);
	virtual void	execute(Bureaucrat const & executor) const = 0;
private:
	std::string const	_name;
	bool				_signed;
	int const			_gradeExec;
	int const			_gradeSign;
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);
