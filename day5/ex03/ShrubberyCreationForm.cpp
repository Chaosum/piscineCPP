/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:10:46 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:07 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm", 137, 145)
{
	target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 137, 145), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): Form(src)
{
	target = src.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &src)
{
	target = src.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == 0)
		throw FormNotSigned();
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	std::ofstream ofs(this->target + "_shrubbery");
	ofs << "                                                         .\n\
												.         ;\n\
					.              .              ;%     ;;\n\
					,           ,                :;%  %;\n\
					:         ;                   :;%;'     .,\n\
			,.        %;     %;            ;        %;'    ,;\n\
				;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
				%;       %;%;      ,  ;       %;  ;%;   ,%;'\n\
				;%;      %;        ;%;        % ;%;  ,%;'\n\
				`%;.     ;%;     %;'         `;%%;.%;'\n\
					`:;%.    ;%%. %@;        %; ;@%;%'\n\
					`:%;.  :;bd%;          %;@%;'\n\
						`@%:.  :;%.         ;@@%;'\n\
						`@%.  `;@%.      ;@@%;\n\
							`@%%. `@%%    ;@@%;\n\
							;@%. :@%%  %@@%;\n\
								%@bd%%%bd%%:;\n\
								#@%%%%%:;;\n\
								%@@%%%::;\n\
								%@@@%(o);  . '\n\
								%@@@o%;:(.,'\n\
							`.. %@@@o%::;\n\
								`)@@@o%::;\n\
								%@@(o)::;\n\
								.%@@@@%::;\n\
								;%@@@@%::;.\n\
								;%@@@@%%:;;;.\n\
							...;%@@@@@%%:;;;;,..\n,\
			&&& &&  & &&\n\
		&& &\\/&\\|& ()|/ @, &&\n\
		&\\/(/&/&||/& /_/)_&/_&\n\
	&() &\\/&|()|/&\\/ '%  & ()\n\
	&_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
	()&_---()&\\&\\|&&-&&--%---()~\n\
		&&     \\|||\n\
				|||\n\
				|||\n\
				|||\n\
		, -=-~  .-^- _\n,\
	oxoxoo    ooxoo\n\
	ooxoxo oo  oxoxooo\n\
oooo xxoxoo ooo ooox\n\
oxo o oxoxo  xoxxoxo\n\
	oxo xooxoooo o ooo\n\
	ooo\\oo\\  /o/o\n\
		\\  \\/ /\n\
		|   /\n\
		|  |\n\
		| D|\n\
		|  |\n\
		|  |\n\
______/____\\____\n";
}

