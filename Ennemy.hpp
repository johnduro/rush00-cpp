// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ennemy.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:42:04 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 02:38:45 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENNEMY_HPP
# define ENNEMY_HPP

#include <iostream>
#include <sys/time.h>
#include "gameEntity.class.hpp"
#include "defines.hpp"

class Ennemy : public GameEntity
{

public:

	Ennemy(coord pos, int id, char c, int maxY, int maxX);
	Ennemy( void );
	Ennemy(Ennemy const & rf);
	~Ennemy( void );

	int		get_id( void ) const;
	void	set_id(int const id);
	Ennemy & operator=(Ennemy const & rf);
	char	getTir( void ) const;
	struct timeval		getPlayTime( void ) const;
	int					play( void );

private:

	int		_id;
	char	_tir;
	struct timeval _fire;
	struct timeval _play;

	void	_planNextFire( void );
	void	_planNextPlay( void );


};

#endif // ** ENNEMY_HPP ** //
