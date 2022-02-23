/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:53:38 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 19:50:26 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm", 5, 25), target("")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 5, 25), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): Form(src), target(src.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
	target = src.target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == 0)
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	std::cout << this->target << " have been pardonned by Zaphod Beeblebrox." << std::endl;
}
