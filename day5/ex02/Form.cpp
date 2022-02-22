/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:33:16 by mservage          #+#    #+#             */
/*   Updated: 2022/02/21 19:05:24 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("Default"), _signed(0), _gradeExec(150), _gradeSign(150)
{
}

Form::Form(std::string const &name, int exec, int sign): _name(name), _signed(0)
, _gradeExec(exec), _gradeSign(sign)
{
	if (_gradeSign > 150 || _gradeExec > 150)
		throw Form::GradeTooHighException();
	if (_gradeSign < 1 || _gradeExec < 1)
		throw Form::GradeTooLowException();
}

Form::~Form(void)
{
}

std::string	const &Form::getName() const
{
	return (this->_name);
}
bool	const &Form::getSigned() const
{
	return (this->_signed);
}
int	const	&Form::getGradeExec() const
{
	return (this->_gradeExec);
}
int	const	&Form::getGradeSign() const
{
	return (this->_gradeSign);
}

void	Form::beSigned(Bureaucrat const &src)
{
	if (this->_signed)
		return ;
	if (src.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	this->_signed = 1;
}


std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << rhs.getName() <<", Form signed  " << rhs.getSigned() << "Required level for sign : " << rhs.getGradeSign() << " And for exec : " << rhs.getGradeExec() << "." << std::endl;
	return (o);
}