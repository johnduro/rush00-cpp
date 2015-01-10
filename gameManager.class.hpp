// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameManager.class.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:24 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/11 00:12:38 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMEMANAGER_CLASS_HPP
# define GAMEMANAGER_CLASS_HPP

#include <ncurses.h>
#include <sys/time.h>
#include "gameEntity.class.hpp"

typedef struct			s_entity
{
	gameEntity*			entity;
	int					owner;
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
	struct timeval		_nextGen;
//	struct timeval		_nextPrint;

	// ** PRIVATE FUNCTION ** //
	void				_refresh( void );
	void				_drawBorders( WINDOW *screen );
	void				_deleteAllEntities( void );
	void				_addEntity( gameEntity* newEntity, int owner );
	void				_removeEntity( t_entity *ptr);
	int					_treatInput( int input );
	void				_addShoot( coord coord, int direction, int owner );
	int					_makeGame( void );
	void				_printScreenField( void );
	void				_printScreenScore( void );
	void				_generateEnemy( void );
	// void				_scrollDown( void );
	int					_checkForDead( void );
	void				_playLoop( void );
	void				_planNextGen( void );
	bool				_isTimeYet(struct timeval ok);
	void				_addClonedEntity(t_list *newL, t_entity *newE);

public :
	// ** CANONICAL ** //
	gameManager( void );
	gameManager( gameManager const & src );
	~gameManager( void );
	gameManager &			operator=( gameManager const & src );

	// ** PUBLIC FUNCTION ** //
	void					init( void );
	void					loop( void );
	t_list*					cloneEntities( void );
	Player*					clonePlayer( void );
	int						getMaxY( void );
	int						getMaxX( void );
	WINDOW					*getField( void );
	WINDOW					*getScore( void );
};

#endif // ** GAMEMANAGER_CLASS_HPP ** //
