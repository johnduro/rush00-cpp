// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 19:02:19 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 02:52:26 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"
#include <string>
#include <sstream>

Player::Player()
{
	this->_tir = '|';
	return ;
}

Player::Player(coord pos, std::string name, int nb_life, char c, int score, int maxY, int maxX)
	: GameEntity(1, pos, c, 0, maxY, maxX, UP),	_score(score), _nb_life(nb_life),_name(name)
{
	this->_tir = '|';
	return ;
}

Player::Player(Player const & rf) : GameEntity()
{
	this->_tir = '|';
	*this = rf;
	return ;
}

// * GEtter / Setter

int		Player::getnb_life( void ) const
{
	return (this->_nb_life);
}

int		Player::getscore( void ) const
{
	return (this->_score);
}

const char*		Player::getScore( void ) const
{
	std::stringstream ss;
	ss << this->_score;
	return (ss.str().c_str());
}

std::string	Player::getname( void ) const
{
	return (this->_name);
}

char	Player::getTir( void ) const
{
	return (this->_tir);
}

// SETTER

void	Player::setname(std::string const name)
{
	this->_name = name;
}

void	Player::setnb_life(int const nb_life)
{
	this->_nb_life = nb_life;
}
void	Player::setscore(int const score)
{
	this->_score = score;
}

Player & Player::operator=(Player const & rf)
{
	if (this != & rf)
	{
		this->_alive = rf.getAlive();
		this->_nb_life = rf.getnb_life();
		this->_name = rf.getname();
		this->_score = rf.getscore();
		this->_pos = rf.getCoord();
		this->_c = rf.get_c();
		this->_type = rf.get_type();
		this->_tir = rf.getTir();
	}
	return (*this);
}

int		Player::play( void ){ return (0);}

struct timeval		Player::getPlayTime( void ) const
{
	struct timeval fake;

	return (fake);
}
