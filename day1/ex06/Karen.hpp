/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:33:00 by matthieu          #+#    #+#             */
/*   Updated: 2022/02/07 13:50:31 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Karen(void);
	~Karen(void);
	void complain(std::string level);
};

#endif