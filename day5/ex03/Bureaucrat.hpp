/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:34:10 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 21:07:20 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdexcept>
# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	Bureaucrat	&operator=(Bureaucrat &rhs);
	int	getGrade(void) const;
	std::string	const &getName(void) const;
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw ()
		{
			return ("Grade Too Hight");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw ()
		{
			return ("Grade Too Low");
		}
	};
	class NegativeIncrement : public std::exception
	{
	public:
		virtual const char *what() const throw ()
		{
			return ("Negative increment");
		}
	};
	class ExecuteError : public std::exception
	{
	public:
		virtual const char *what() const throw ()
		{
			return ("Can't execute the form");
		}
	};
	void	gradeDown(int incr);
	void	gradeUp(int incr);
	void	signForm(Form &src);
	void	executeForm(Form const &Form);
private:
	std::string	_name;
	int			grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);