// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameEntity.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:34 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/11 07:12:33 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "gameEntity.class.hpp"
#include <fstream>

GameEntity::GameEntity( void )
{
	return ;
}

GameEntity::GameEntity(bool alive, coord pos, char c, int type, int maxY, int maxX, int dir)
	: _alive(alive), _pos(pos), _c(c), _type(type), _maxY(maxY), _maxX(maxX), _dir(dir), _previous(pos)
{
	return ;
}
GameEntity::GameEntity(GameEntity const & rf)
{
	*this = rf;
	return ;
}
GameEntity::~GameEntity( void )
{
	return ;
}

// * GETTER / SETTER

coord	GameEntity::getCoord( void ) const
{
	return (this->_pos);
}

coord	GameEntity::getPrevious( void ) const
{
	return (this->_previous);
}

bool	GameEntity::getAlive( void ) const
{
	return (this->_alive);
}

bool	GameEntity::isHurt( coord coord ) const
{
	if (coord.x == this->_pos.x && coord.y == this->_pos.y)
		return (true);
	return (false);
}

char	GameEntity::get_c( void ) const
{
	return (this->_c);
}

int		GameEntity::get_type( void ) const
{
	return (this->_type);
}

// SETTER

void	GameEntity::setAlive(bool const alive)
{
	this->_alive = alive;
}

void	GameEntity::set_position(coord const pos)
{
	this->_pos.x = pos.x;
	this->_pos.y = pos.y;
}

void	GameEntity::set_c(char const c)
{
	this->_c = c;
}

void	GameEntity::set_type(int const type)
{
	this->_type = type;
}

// * MEMBER FUNC

void	GameEntity::move(int dir, int maxY, int maxX)
{
	coord	tmp;
	tmp.x = this->_pos.x;
	tmp.y = this->_pos.y;

	if (dir == UP )
	{
		if ((tmp.y - 1) >= 1)
			tmp.y--;
		else
			this->_alive = false;
	}
	else if (dir == DOWN)
	{
		if ((tmp.y + 1) < (maxY - 1))
			tmp.y++;
		else
			this->_alive = false;
	}
	else if ((dir == LEFT) && ((tmp.x - 1) >= 1))
		tmp.x--;
	else if ((dir == RIGHT) && ((tmp.x + 1) < (maxX - 1)))
		tmp.x++;
	this->_previous.x = this->_pos.x;
	this->_previous.y = this->_pos.y;
	this->set_position(tmp);
}

GameEntity	& GameEntity::operator=(GameEntity const & rf)
{
	if (this != &rf)
	{
		this->_alive = rf.getAlive();
		this->_pos = rf.getCoord();
		this->_c = rf.get_c();
		this->_type = rf.get_type();
	}
	return (*this);
}

int		GameEntity::getDirection( void ) const
{
	return (this->_dir);
}
