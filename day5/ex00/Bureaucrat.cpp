/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:16:04 by mservage          #+#    #+#             */
/*   Updated: 2022/02/25 10:22:35 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name(""), grade (150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name)
{
	this->grade = src.grade;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &rhs)
{
	this->grade = rhs.grade;
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
		throw NegativeIncrement();
	if (grade - incr < 1)
		throw GradeTooLowException();
	this->grade -= incr;
}

void	Bureaucrat::gradeDown(int incr)
{
	if (incr < 0)
		throw NegativeIncrement();
	if (grade + incr > 150)
		throw GradeTooHighException();
	this->grade += incr;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}
