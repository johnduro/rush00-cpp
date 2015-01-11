// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ennemy.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 20:03:57 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 10:08:46 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstdlib>
#include "Ennemy.hpp"
#include "gameEntity.class.hpp"
#include "gameManager.class.hpp"


Ennemy::Ennemy( void )
{
	this->_planNextPlay();
	this->_tir = '|';
	return ;
}

Ennemy::Ennemy(coord pos, int id, char c, int maxY, int maxX)
	: GameEntity(1, pos, c, ENNEMY, maxY, maxX, DOWN), _id(id)
{
	this->_planNextPlay();
	this->_tir = '|';
	return ;
}

Ennemy::Ennemy(Ennemy const & rf) : GameEntity()
{
	this->_planNextPlay();
	this->_tir = '|';
	*this = rf;
}

Ennemy::~Ennemy( void )
{
	return ;
}

void	Ennemy::_planNextFire( void )
{
	struct timeval		cur;
	struct timeval		add;

	gettimeofday(&cur, NULL);
	add.tv_sec = 0;
	add.tv_usec = FIRE_TIME;
	timeradd(&cur, &add, &(this->_fire));
}

void	Ennemy::_planNextPlay( void )
{
	struct timeval		cur;
	struct timeval		add;

	gettimeofday(&cur, NULL);
	add.tv_sec = PLAY_TIME;
	add.tv_usec = 0;
	timeradd(&cur, &add, &(this->_play));
}


// * GETTER / SETTER

struct timeval		Ennemy::getPlayTime( void ) const
{
	return (this->_play);
}

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

int		Ennemy::play( void )
{
	int		randoo;

	randoo = rand() % 3;
	if (randoo == 0)
		this->move(DOWN, this->_maxY, this->_maxX);
	else if (randoo == 1)
		this->move(LEFT, this->_maxY, this->_maxX);
	else if (randoo == 2)
		this->move(RIGHT, this->_maxY, this->_maxX);
	this->_planNextPlay();
	if (gameManager::isTimeYet(this->_fire))
		return (1);
	return (0);
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
