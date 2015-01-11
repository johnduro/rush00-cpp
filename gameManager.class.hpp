// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameManager.class.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:24 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/11 04:51:23 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMEMANAGER_CLASS_HPP
# define GAMEMANAGER_CLASS_HPP

#include <ncurses.h>
#include <sys/time.h>
#include "defines.hpp"
#include "gameEntity.class.hpp"
#include "Player.hpp"
#include "Obstacle.hpp"
#include "Ennemy.hpp"
#include "Tir.hpp"

typedef struct			s_entity
{
	GameEntity*			entity;
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
	void				_addEntity( GameEntity* newEntity, int owner );
	void				_removeEntity( t_entity *ptr);
	int					_treatInput( int input );
	void				_addShoot( coord coord, int direction, char print, int owner );
	int					_makeGame( void );
	void				_printScreenField( void );
	void				_printScreenScore( void );
	void				_generateEnemy( void );
	// void				_scrollDown( void );
	int					_checkForDead( void );
	void				_playLoop( void );
	void				_planNextGen( void );
	void				_addClonedEntity(t_list *newL, t_entity *newE) const;

public :
	// ** CANONICAL ** //
	gameManager( void );
	gameManager( gameManager const & src );
	~gameManager( void );
	gameManager &			operator=( gameManager const & src );

	// ** PUBLIC FUNCTION ** //
	void					debug(std::string msg);
	void					init( void );
	void					loop( void );
	t_list*					cloneEntities( void ) const ;
	Player*					clonePlayer( void ) const ;
	int						getMaxY( void ) const ;
	int						getMaxX( void ) const ;
	WINDOW					*getField( void ) const ;
	WINDOW					*getScore( void ) const ;
	static bool				isTimeYet(struct timeval ok);
};

#endif // ** GAMEMANAGER_CLASS_HPP ** //
