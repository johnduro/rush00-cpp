// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameManager.class.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:24 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/10 18:13:46 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMEMANAGER_CLASS_HPP
# define GAMEMANAGER_CLASS_HPP

#include <ncurses.h>
#include "gameEntity.class.hpp"

typedef struct			s_entity
{
	gameEntity*			entity;
	struct s_entity		*next;
	struct s_entity		*prev;
}						t_entity;

typedef struct			s_list
{
	t_entity			*start;
	t_entity			*end;
}						t_list;


// ** CLASS GAME MANAGER** //

class gameManager
{
private :
	// ** PRIVATE ATTRIBUTES ** //
	static int const	_scoreSize = 3;
	bool				_isInit;
	t_list				*_entities;
	Player				*_player;
	int					_maxY;
	int					_maxX;
	WINDOW				*_field;
	WINDOW				*_score;

	// ** PRIVATE FUNCTION ** //
	void				_refresh( void );
	void				_drawBorders(WINDOW *screen);
	void				_deleteAllEntities( void );
	void				_addEntity(gameEntity* newEntity);

public :
	// ** CANONICAL ** //
	gameManager( void );
	gameManager( gameManager const & src );
	~gameManager( void );
	gameManager &			operator=( gameManager const & src );

	// ** PUBLIC FUNCTION ** //
	void					init( void );
	void					loop( void );
};

#endif // ** GAMEMANAGER_CLASS_HPP ** //
