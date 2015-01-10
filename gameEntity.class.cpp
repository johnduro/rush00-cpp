// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameEntity.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:34 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/10 22:35:57 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "gameEntiy.class.cpp"

GameEntity::GameEntity( void )
{
	return ;
}

GameEntity::GameEntity(coord pos, char c, int type) : _alive(alive),
													  _pos(pos), _c(c),
													  _type(type)
{
	return ;
}
GameEntity::GameEntity(GmaeEntity const & rf)
{
	*this = rf;
	return ;
}
GameEntity::~GameEntity( void )
{
	return ;
}

// * GETTER / SETTER

