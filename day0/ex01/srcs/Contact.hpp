/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:58:38 by mservage          #+#    #+#             */
/*   Updated: 2021/11/02 19:20:27 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	std::string fname;
	std::string lname;
	std::string nname;
	std::string number;
	std::string secret;

public:
	Contact(void);
	~Contact(void);
	void		setFname(std::string str);
	void		setLname(std::string str);
	void		setNname(std::string str);
	void		setNumber(std::string str);
	void		setSecret(std::string str);
	std::string	getFname(void);
	std::string	getLname(void);
	std::string	getNname(void);
	std::string	getNumber(void);
	std::string	getSecret(void);
};

#endif