// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ennemy.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:42:04 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 01:24:54 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENNEMY_HPP
# define ENNEMY_HPP

#include <iostream>
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

private:

	int		_id;
	char	_tir;
};

#endif // ** ENNEMY_HPP ** //
