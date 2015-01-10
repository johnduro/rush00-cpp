// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ennemy.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 20:03:57 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/10 21:00:28 by mdrissi          ###   ########.fr       //
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
