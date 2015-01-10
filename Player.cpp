// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 19:02:19 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 00:20:47 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"
#include <string>

Player::Player()
{
	return ;
}

Player::Player(coord pos, std::string name, int nb_life, char c, int score) : GameEntity(1, pos, c, 0),
																						_score(score), _nb_life(nb_life),
																						_name(name)
{
	return ;
}

Player::Player(Player const & rf) : GameEntity()
{
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

std::string	Player::getname( void ) const
{
	return (this->_name);
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
		this->_pos = rf.get_position();
		this->_c = rf.get_c();
		this->_type = rf.get_type();
	}
	return (*this);
}
