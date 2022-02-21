/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:16:04 by mservage          #+#    #+#             */
/*   Updated: 2022/02/21 18:29:30 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name(""), grade (150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	this->grade = src.grade;
	this->_name = src._name;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &rhs)
{
	this->grade = rhs.grade;
	this->_name = rhs._name;
	return (*this);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

std::string	const &Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::gradeUp(int incr)
{
	if (incr < 0)
		throw (Bureaucrat::GradeTooHighException());
	if (grade - incr < 1)
		throw (Bureaucrat::GradeTooLowException());
	this->grade -= incr;
}

void	Bureaucrat::gradeDown(int incr)
{
	if (incr < 0)
		throw (Bureaucrat::GradeTooLowException());
	if (grade + incr > 150)
		throw (Bureaucrat::GradeTooHighException());
	this->grade += incr;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}
