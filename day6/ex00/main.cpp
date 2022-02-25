/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:18:52 by mservage          #+#    #+#             */
/*   Updated: 2022/02/25 18:23:43 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>

void	type_is_char(std::string arg)
{
	char c = static_cast<char>(arg[0]);
	if (c >= 32 && c <= 126)
	{
		std::cout << "char : '" << c << "'" << std::endl;
		int	i = static_cast<int>(c);
		std::cout << "int : " << i << std::endl;
		int	f = static_cast<float>(c);
		std::cout << "float : " << f << "f" << std::endl;
		int	d = static_cast<double>(c);
		std::cout << "double : " << d << std::endl;
		return ;
	}
	std::cout << "char: Non displayable" << std::endl;
	int	i = static_cast<int>(c);
	std::cout << "int : " << i << std::endl;
	int	f = static_cast<float>(c);
	if (roundf(f) == f)
		std::cout << "float : " << f << ".0" << "f" << std::endl;
	else
		std::cout << "float : " << f << "f" << std::endl;
	int	d = static_cast<double>(c);
	if (roundf(d) == d)
		std::cout << "double : " << d << ".0" << std::endl;
	else
		std::cout << "double : " << d << std::endl;
	return ;
}

void	float_double_special_case(std::string arg)
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	std::cout << "float : " << arg << "f" << std::endl;
	std::cout << "double : " << arg << std::endl;
}

void	float_case(char *arg)
{
	char	c;
	int		i;
	float	f;
	double	d;

	f = static_cast<float>(std::strtod(arg, NULL));
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	if (f < -127 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (c >= 32 && c <= 126)
		std::cout << "char : '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f > INT_MAX || f < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << i << std::endl;
	if (roundf(f) == f)
		std::cout << "float : " << f << ".0" << "f" << std::endl;
	else
		std::cout << "float : " << f << "f" << std::endl;
	if ((double)roundf(d) == d)
		std::cout << "double : " << d << ".0" << std::endl;
	else
		std::cout << "double : " << d << std::endl;
}

void	double_case(char *arg)
{
	char	c;
	int		i;
	float	f;
	double	d;

	d = static_cast<double>(std::strtod(arg, NULL));
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
	if (d < 0 || d > 255)
		std::cout << "char: impossible" << std::endl;
	else if (c >= 32 && c <= 126)
		std::cout << "char : '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << i << std::endl;
	if (isinf(f))
		std::cout << "float : impossible" << std::endl;
	else if (roundf(f) == f)
		std::cout << "float : " << f << ".0" << "f" << std::endl;
	else
		std::cout << "float : " << f << "f" << std::endl;
	if (isinf(d))
		std::cout << "double : impossible" << std::endl;
	else if ((double)roundf(d) == d)
		std::cout << "double : " << d << ".0" << std::endl;
	else
		std::cout << "double : " << d << std::endl;
}

int	is_valid_string(char *arg)
{
	int i = 0;
	int	dot_count = 0;

	if (arg[i] && arg[i] == '-')
		i++;
	if (arg[i] && arg[i] == '.')
		return (0);
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			dot_count++;
		}
		else if ((arg[i] < '0' || arg[i] > '9' ) && ((i != (int)strlen(arg) - 1) && arg[i] != 'f'))
			return (0);
		i++;
	}
	if (dot_count > 1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cout << "Too many args" << std::endl;
		return (1);
	}
	if (ac < 2)
	{
		std::cout << "No args" << std::endl;
		return (1);
	}
	std::string arg = av[1];
	if (arg.size() == 1 && (arg[0] >= 0 && arg[0] <= 127) && !(arg[0] >= '0' && arg[0] <= '9'))
	{
		type_is_char(arg);
		return (0);
	}
	if (arg == "nan" || arg == "-inf" || arg == "+inf")
	{
		float_double_special_case(arg);
		return (0);
	}
	if (is_valid_string(av[1]) == 0)
	{
		std::cout << "No char, int, float or double argument" << std::endl;
		return (1);
	}
	if (arg[arg.size() - 1] == 'f')
	{
		float_case(av[1]);
		return (0);
	}
	double_case(av[1]);
	return (0);
}