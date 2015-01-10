// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Obstacle.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 18:26:15 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/10 20:49:58 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Obstacle.hpp"

Obstacle::Obstacle(void)
{
	return ;
}

Obstacle::Obstacle(coord pos, char c, int typeob) : _pos(pos), _type(3),
													_alive(1), _c(c), _typeob(typeob)
{
	return ;
}

Obstacle::Obstacle(Obstacle & const rf)
{
	*this = rf;
	return ;
}

Obstacle::~Obstacle( void )
{
	return ;
}

// * Getteur / Setter *//

int		get_typeob( void ) const
{
	return this->_typeob;
}

void	set_typeob(int const type)
{
	this->_typeob = type;
	return ;
}

// * operator *//

Obstacle & Obstacle::operator=(Obstacle const & rf)
{
	if (this != &rf)
	{
		this->_c = rf.get_c();
		this->_pos = rf.getposition();
		this->_alive = rf.get_alive();
		this->_c = rf.get_c();
		this->_typeob = rf.get_typeob();
		this->_type = rf.get_type();
	}
	return *this;
}
