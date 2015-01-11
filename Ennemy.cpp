// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ennemy.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 20:03:57 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 01:24:21 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ennemy.hpp"
#include "gameEntity.class.hpp"


Ennemy::Ennemy( void )
{
	this->_tir = '|';
	return ;
}

Ennemy::Ennemy(coord pos, int id, char c, int maxY, int maxX)
	: GameEntity(1, pos, c, 1, maxY, maxX), _id(id)
{
	this->_tir = '|';
	return ;
}

Ennemy::Ennemy(Ennemy const & rf) : GameEntity()
{
	this->_tir = '|';
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

char	Ennemy::getTir( void ) const
{
	return (this->_tir);
}

Ennemy & Ennemy::operator=(Ennemy const & rf)
{
	if (this != &rf)
	{
		this->_alive = rf.getAlive();
		this->_pos = rf.getCoord();
		this->_c = rf.get_c();
		this->_type = rf.get_type();
		this->_id = rf.get_id();
		this->_tir = rf.getTir();
	}
	return (*this);
}
