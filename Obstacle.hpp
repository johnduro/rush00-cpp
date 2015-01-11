// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Obstacle.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:25:32 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 03:08:52 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OBSTACLE_HPP
# define OBSTACLE_HPP

#include <iostream>
#include "gameEntity.class.hpp"
#include "defines.hpp"

class Obstacle : public GameEntity
{

public:
	Obstacle( void);
	Obstacle(coord pos, char c, int typeob, int maxY, int maxX);
	Obstacle(Obstacle const & rf);
	~Obstacle( void );

	int		get_typeob( void ) const;
	void	set_typeob(int const t);
	Obstacle & operator=(Obstacle const & rf);
	int		play( void );
	struct timeval		getPlayTime( void ) const;
	char		getTir( void ) const;

private:

	int		_typeob;
	struct timeval	_play;

	void		_planNextPlay( void );
};

#endif // ** OBSTACLE_HPP * //
