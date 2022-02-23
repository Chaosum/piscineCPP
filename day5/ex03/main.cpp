/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:05:00 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 23:33:54 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	creation_test()
{
	try
	{
		std::cout << "good" << std::endl;
		Bureaucrat burA("pierre", 120);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "bad" << std::endl;
		Bureaucrat burA("paul", 156);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "bad" << std::endl;
		Bureaucrat burA("jacques", 156);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "bad" << std::endl;
		Bureaucrat burA("jacques", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "bad" << std::endl;
		Bureaucrat burA("jacques", -1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	sign_test(int grade)
{
	Form *formA = new ShrubberyCreationForm("A");
	Form *formB = new RobotomyRequestForm("B");
	Form *formC = new PresidentialPardonForm("C");

	Bureaucrat paul("Paul", grade);
	try
	{
		std::cout << "signForm A" << std::endl;
		paul.signForm(*formA);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "signForm B" << std::endl;
		paul.signForm(*formB);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "signForm C" << std::endl;
		paul.signForm(*formC);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete formA;
	delete formB;
	delete formC;
}

void	exec_test(int grade)
{
	Form *formA = new ShrubberyCreationForm("DD");
	Form *formB = new RobotomyRequestForm("EE");
	Form *formC = new PresidentialPardonForm("FF");
	
	Bureaucrat director("dir", 1);
	director.signForm(*formA);
	director.signForm(*formB);
	director.signForm(*formC);
	Bureaucrat peon("peon", grade);
	try
	{
		std::cout << "Form exec A" << std::endl;
		formA->execute(peon);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Form exec B" << std::endl;
		formB->execute(peon);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Form exec C" << std::endl;
		formC->execute(peon);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	Form *formG = new ShrubberyCreationForm("GG");
	Form *formH = new RobotomyRequestForm("HH");
	Form *formI = new PresidentialPardonForm("II");
	director.signForm(*formG);
	director.signForm(*formH);
	director.signForm(*formI);
	try
	{
		std::cout << "exec A" << std::endl;
		peon.executeForm(*formG);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "exec B" << std::endl;
		peon.executeForm(*formH);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "exec C" << std::endl;
		peon.executeForm(*formI);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete formA;
	delete formB;
	delete formC;
	delete formG;
	delete formH;
	delete formI;
}

void	Increment_test()
{
	Bureaucrat test("test", 150);

	try
	{
		std::cout << "over than 150" << std::endl;
		test.gradeDown(1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "negative gradeDown" << std::endl;
		test.gradeDown(-1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "under than 1 gradeUP" << std::endl;
		test.gradeUp(150);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "negative gradeUp" << std::endl;
		test.gradeUp(-1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "regular UP" << std::endl;
		test.gradeUp(50);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "regular Down" << std::endl;
		test.gradeUp(25);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Form *formB = new RobotomyRequestForm("EE");
	Bureaucrat boss("boss", 1);
	boss.signForm(*formB);
	Bureaucrat execincr("testexecincr", 46);
	std::cout << "+1 rank" << std::endl;
	try
	{
		execincr.gradeUp(1);
		execincr.executeForm(*formB);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-1 rank" << std::endl;
	try
	{
		execincr.gradeDown(1);
		execincr.executeForm(*formB);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete formB;
}

void	previous_main()
{
std::cout << "Creation test" << std::endl;
	creation_test();
	
std::cout << std::endl << "Increment test" << std::endl;
	Increment_test();
	
std::cout << std::endl << "Sign test" << std::endl;
	std::cout << "150" << std::endl;
	sign_test(150);
	std::cout << "145" << std::endl;
	sign_test(145);
	std::cout << "72" << std::endl;
	sign_test(72);
	std::cout << "25" << std::endl;
	sign_test(25);
	
std::cout << std::endl << "Exec test" << std::endl;
	std::cout << "150" << std::endl;
	exec_test(150);
	std::cout << "137" << std::endl;
	exec_test(137);
	std::cout << "45" << std::endl;
	exec_test(45);
	std::cout << "5" << std::endl;
	exec_test(5);
std::cout << std::endl;
}

void Intern_test()
{
	Bureaucrat boss("boss", 1);
	Intern titouant;
	Form	*temp;

	temp = titouant.makeForm("Does't Exist", "jean-paul");
	temp = titouant.makeForm("Shrubbery Creation", "pierre");
	boss.signForm(*temp);
	boss.executeForm(*temp);
	delete (temp);
	temp = titouant.makeForm("Robotomy Request", "pierre2");
	boss.signForm(*temp);
	boss.executeForm(*temp);
	delete (temp);
	temp = titouant.makeForm("Presidential Pardon", "pierre3");
	boss.signForm(*temp);
	boss.executeForm(*temp);
	delete (temp);
}

int main()
{
	//previous_main();
	Intern_test();
}