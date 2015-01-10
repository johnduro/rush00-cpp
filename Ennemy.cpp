// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ennemy.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 20:03:57 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 00:11:21 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ennemy.hpp"
#include "gameEntity.class.hpp"


Ennemy::Ennemy( void )
{
	return ;
}

Ennemy::Ennemy(coord pos, int id, char c) : GameEntity(1, pos, c, 1), _id(id)
{
	return ;
}

Ennemy::Ennemy(Ennemy const & rf) : GameEntity()
{
	*this = rf;
}

Ennemy::~Ennemy( void )
{
	return ;
}
// * GETTER / SETTER

int		Ennemy::get_id() const
{
	return this->_id;
}

void	Ennemy::set_id(int const id)
{
	this->_id = id;
}

Ennemy & Ennemy::operator=(Ennemy const & rf)
{
	if (this != &rf)
	{
		this->_alive = rf.getAlive();
		this->_pos = rf.get_position();
		this->_c = rf.get_c();
		this->_type = rf.get_type();
		this->_id = rf.get_id();
	}
	return (*this);
}
