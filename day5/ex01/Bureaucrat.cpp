/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:16:04 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 20:21:17 by mservage         ###   ########.fr       */
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
		throw (GradeTooHighException());
	if (grade - incr < 1)
		throw (GradeTooLowException());
	this->grade -= incr;
}

void	Bureaucrat::gradeDown(int incr)
{
	if (incr < 0)
		throw (GradeTooLowException());
	if (grade + incr > 150)
		throw (GradeTooHighException());
	this->grade += incr;
}
void	Bureaucrat::SignForm(Form &src)
{
	try
	{
		src.beSigned(*this);
		std::cout << this->getName() << "Signed " << src.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getGrade() << "couldn't sign " << src.getName() << " because" << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}
