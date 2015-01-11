// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:32:56 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 02:52:36 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "gameEntity.class.hpp"
#include "defines.hpp"
#include <string>

class Player : public GameEntity
{
public:

	Player( void );
	Player(coord pos, std::string name, int nb_life, char c, int score, int maxY, int maxX);
	Player(Player const & rf);
	~Player( void );


	int				getnb_life( void ) const;
	void			setnb_life(int const nb);
	int				getscore( void ) const;
	const char*			getScore( void ) const;
	void			setscore(int const score);
	std::string		getname( void ) const;
	void			setname(std::string const name);
	Player &	operator=(Player const & rf);
	char			getTir( void ) const;
	int				play( void );
	struct timeval			getPlayTime( void ) const;

private:

	int				_score;
	int				_nb_life;
	std::string		_name;
	char			_tir;
};


#endif // * PLAYER_HPP * //
