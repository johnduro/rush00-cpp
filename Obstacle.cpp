// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Obstacle.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 18:26:15 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 00:08:16 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Obstacle.hpp"
#include "gameEntity.class.hpp"

Obstacle::Obstacle(void)
{
	return ;
}

Obstacle::Obstacle(coord pos, char c, int typeob) : GameEntity(1, pos, c, 3), _typeob(typeob)
{
	return ;
}

Obstacle::Obstacle(Obstacle const & rf) : GameEntity()
{
	*this = rf;
	return ;
}

Obstacle::~Obstacle( void )
{
	return ;
}

// * Getteur / Setter *//

int		Obstacle::get_typeob( void ) const
{
	return (this->_typeob);
}

void	Obstacle::set_typeob(int const type)
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
		this->_pos = rf.get_position();
		this->_alive = rf.getAlive();
		this->_c = rf.get_c();
		this->_typeob = rf.get_typeob();
		this->_type = rf.get_type();
	}
	return *this;
}
