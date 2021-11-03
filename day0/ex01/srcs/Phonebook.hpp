/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:14:45 by mservage          #+#    #+#             */
/*   Updated: 2021/11/02 21:01:23 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include "Contact.hpp"
# include <cstdlib>

class Phonebook
{
private:
	Contact	contact[8];
	int		contact_number;

public:
	Phonebook(void);
	~Phonebook(void);
	void	setContact(int i);
	int		getContact_number();
	void	setContact_number(int nbr);
	void	ft_add();
	void	ft_search();
};

#endif