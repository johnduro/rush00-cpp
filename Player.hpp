// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:32:56 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/10 19:58:02 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "gameEntity.class.hpp"
#include <string>

class Player : public GameEntity
{
public:

	Player( void );
	Player(t_coord c, std::string name);
	Player(PLayer const & rf);
	~Player( void );


	int				getnb_life( void ) const;
	void			setnb_life(int const nb);
	int				getscore( void ) const;
	void			setscore(int const score);
	std::string		getname( void ) const;
	void			setname(std::string const name);
	Player &	operator=(Player const & rf);

private:

	int				_score;
	int				_nb_life;
	std::string		_name;
};


#endif // * PLAYER_HPP * //
