/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:34:10 by mservage          #+#    #+#             */
/*   Updated: 2022/02/21 18:24:22 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdexcept>
# include <string>
# include <iostream>

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
	void	gradeDown(int incr);
	void	gradeUp(int incr);
	
private:
	std::string	_name;
	int			grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);