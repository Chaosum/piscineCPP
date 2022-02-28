/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:31:55 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 12:06:08 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "whatever.hpp"

class Awesome
{
public:
	Awesome( int n ) : _n( n ) {}

	int	getNbr() { return (this->_n); }
	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) const{ return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) const{ return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) const{ return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) const{ return (this->_n <= rhs._n); }
private:
	int _n;
};

int main( void )
{
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	Awesome test(10);
	Awesome test2(50);

	swap<Awesome>(test, test2);
	std::cout << "1 = " << test.getNbr() << " et 2 = " << test2.getNbr() << std::endl;
	std::cout << "max( c, d ) = " << ::max( test, test2 ).getNbr() << std::endl;
	std::cout << "min( c, d ) = " << ::min( test, test2 ).getNbr() << std::endl;
	return 0;
}