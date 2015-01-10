// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameEntity.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:34 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/11 00:13:57 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "gameEntity.class.hpp"

GameEntity::GameEntity( void )
{
	return ;
}

GameEntity::GameEntity(bool alive, coord pos, char c, int type) : _alive(alive),
													  _pos(pos), _c(c),
													  _type(type)
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

coord	GameEntity::get_position( void ) const
{
	return (this->_pos);
}

bool	GameEntity::getAlive( void ) const
{
	return (this->_alive);
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

	if ((dir == 1) && ((tmp.y - 1) >= 0))
		tmp.y--;
	else if ((dir == 2) && ((tmp.y + 1) < maxY))
		tmp.y++;
	else if ((dir == 3) && ((tmp.x - 1) >= 0))
		tmp.x--;
	else if ((dir == 4) && ((tmp.x + 1) <= maxX))
		tmp.x++;
	this->set_position(tmp);
}

GameEntity	& GameEntity::operator=(GameEntity const & rf)
{
	if (this != &rf)
	{
		this->_alive = rf.getAlive();
		this->_pos = rf.get_position();
		this->_c = rf.get_c();
		this->_type = rf.get_type();
	}
	return (*this);
}
