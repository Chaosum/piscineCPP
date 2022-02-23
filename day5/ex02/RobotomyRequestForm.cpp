/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:30:08 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 23:45:43 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm", 45, 72)
{
	target = "";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 45, 72), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): Form(src)
{
	target = src.target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
	target = src.target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == 0)
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	std::cout << "Drill go Brrrrrrrrrrrrr !!" << std::endl;
	srand((unsigned)time(0));
	int	rnd = rand();
	if (rnd % 2)
	{
		std::cout << this->target << " got succesfully robotized !" << std::endl;
	}
	else
	{
		std::cout << "Robotization failed on " << this->target << std::endl;
	}
}