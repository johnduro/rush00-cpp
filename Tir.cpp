// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Tir.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 18:47:49 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 01:19:18 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Tir.hpp"

Tir::Tir( void )
{
	return ;
}

Tir::Tir(coord pos, int dir, char typetir, int maxY, int maxX)
	: GameEntity(1, pos, 0, 1, maxY, maxX), _dir(dir), _typetir(typetir)
{
	this->move(dir, maxY, maxX);
	this->move(dir, maxY, maxX);
	return ;
}

Tir::Tir(Tir const & rf) : GameEntity()
{
	*this = rf;
	return ;
}

Tir::~Tir( void )
{
	return ;
}

// * Getter / Stter *//

int		Tir::get_typetir(void) const
{
	return (this->_typetir);
}

int		Tir::get_dir( void ) const
{
	return (this->_dir);
}

void	Tir::set_typetir( int const t)
{
	this->_typetir = t;
}

void	Tir::set_dir(int const d)
{
	this->_dir = d;
}

Tir &	Tir::operator=(Tir const & rf)
{
	if (this != &rf)
	{
		this->_pos = rf.getCoord();
		this->_type = rf.get_type();
		this->_typetir = rf.get_typetir();
		this->_dir = rf.get_dir();
		this->_alive = rf.getAlive();
		this->_c = rf.get_c();
	}
	return (*this);
}
