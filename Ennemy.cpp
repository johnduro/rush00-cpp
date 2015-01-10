// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ennemy.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 20:03:57 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/10 23:08:18 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ennemy.hpp"

Ennemy::Ennemy()
{
	return ;
}

Ennemy::Ennemy(coord pos, char tir, int id) : _alive(1), _pos(pos),
											  _c(c), _tir(tir), id(_id),
											  _type(1)
																
{
	return ;
}

Ennemy::Ennemy(Ennemy & const rf)
{
	*ths = rf;
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
		this->_pos = rf.get_postion();
		this->_c = rf.get_c();
		this->_type = rf.get_type();
		this->_id = rf.get_id();
	}
	return (*this);
}
