/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:42:08 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 23:34:15 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	existingFormName[0] = "Presidential Pardon";
	existingFormName[1] = "Robotomy Request";
	existingFormName[2] = "Shrubbery Creation";
}

Intern::Intern(Intern const &src)
{
	existingFormName[0] = src.existingFormName[0];
	existingFormName[1] = src.existingFormName[1];
	existingFormName[2] = src.existingFormName[2];
}

Intern::~Intern(void)
{
}

Intern	&Intern::operator=(Intern &src)
{
	existingFormName[0] = src.existingFormName[0];
	existingFormName[1] = src.existingFormName[1];
	existingFormName[2] = src.existingFormName[2];
	return *this;
}

Form	*Intern::makeForm(std::string Form_name, std::string target)
{
	Form	*createForm[3];
	Form	*dest;
	
	createForm[0] = new PresidentialPardonForm(target);
	createForm[1] = new RobotomyRequestForm(target);
	createForm[2] = new ShrubberyCreationForm(target);
	for (int i = 0; i < 3; i++)
	{
		if (Form_name == this->existingFormName[i])
		{
			std::cout << "Intern creates " << createForm[i]->getName() << std::endl;
			dest = createForm[i];
			for (int j = 0; j < 3; j++)
			{
				if (j != i)
					delete createForm[j];
			}
			return dest;
		}
	}
	delete createForm[0];
	delete createForm[1];
	delete createForm[2];
	std::cout << "Intern didn't found the matching form for : " << Form_name << std::endl;
	return NULL;
}
