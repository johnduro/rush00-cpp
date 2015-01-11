// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Obstacle.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 18:26:15 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 04:12:43 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Obstacle.hpp"
#include "gameEntity.class.hpp"

Obstacle::Obstacle(void)
{
	this->_planNextPlay();
	return ;
}

Obstacle::Obstacle(coord pos, char c, int typeob, int maxY, int maxX)
	: GameEntity(1, pos, c, 3, maxY, maxX, DOWN), _typeob(typeob)
{
	this->_planNextPlay();
	return ;
}

Obstacle::Obstacle(Obstacle const & rf) : GameEntity()
{
	this->_planNextPlay();
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

void	Obstacle::_planNextPlay( void )
{
	struct timeval		cur;
	struct timeval		add;

	gettimeofday(&cur, NULL);
	add.tv_sec = 0;
	add.tv_usec = OBSTACLE_TIME;
	timeradd(&cur, &add, &(this->_play));
}

int		Obstacle::play( void )
{
	this->move(this->_dir, this->_maxY, this->_maxX);
	this->_planNextPlay();
	return (0);
}

// * operator *//

Obstacle & Obstacle::operator=(Obstacle const & rf)
{
	if (this != &rf)
	{
		this->_c = rf.get_c();
		this->_pos = rf.getCoord();
		this->_alive = rf.getAlive();
		this->_c = rf.get_c();
		this->_typeob = rf.get_typeob();
		this->_type = rf.get_type();
	}
	return *this;
}

struct timeval		Obstacle::getPlayTime( void ) const
{
	return (this->_play);
}

char		Obstacle::getTir( void ) const
{
	return 'p';
}
