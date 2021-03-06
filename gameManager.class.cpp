// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameManager.class.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:31 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/11 10:06:23 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <sys/time.h>
#include <cstdlib>
#include "Player.hpp"
#include "gameManager.class.hpp"
#include "defines.hpp"
#include <fstream>

void	gameManager::debug(std::string msg)
{
	std::ofstream ifout("log.debug", std::ifstream::app);
	ifout << msg << std::endl;
	ifout.close();
}

// ** CANONICAL ** //
gameManager::gameManager( void )
{
	this->_isInit = false;
	this->_entities = new t_list;
	this->_entities->start = NULL;
	this->_entities->end = NULL;
	this->_player = NULL;
	this->_ennemy = 0;
	this->_tir = 0;
}

gameManager::gameManager( gameManager const & src )
{
	this->_isInit = false;
	this->_entities = src.cloneEntities();
	this->_player = src.clonePlayer();
	this->_maxY = src.getMaxY();
	this->_maxX = src.getMaxX();
	this->_field = src.getField();
	this->_score = src.getScore();
}

gameManager::~gameManager( void )
{
	if (this->_isInit)
		endwin();
	delete this->_player;
	this->_deleteAllEntities();
}

gameManager &			gameManager::operator=( gameManager const & src )
{
	this->_entities = src.cloneEntities();
	this->_player = src.clonePlayer();
	this->_maxY = src.getMaxY();
	this->_maxX = src.getMaxX();
	this->_field = src.getField();
	this->_score = src.getScore();
	return (*this);
}

// ** PRIVATE FUNCTION ** //
void					gameManager::_refresh( void )
{
	wrefresh(this->_field);
	wrefresh(this->_score);
}

void					gameManager::_drawBorders(WINDOW *screen)
{
	int		x;
	int		y;
	int		i;

	getmaxyx(screen, y, x);
	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, y - 1, 0, "+");
	mvwprintw(screen, 0, x - 1, "+");
	mvwprintw(screen, y - 1, x - 1, "+");
	for (i = 1; i < (y - 1); i++)
	{
		mvwprintw(screen, i, 0, "|");
		mvwprintw(screen, i, x - 1, "|");
	}
	for (i = 1; i < (x - 1); i++)
	{
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, y - 1, i, "-");
	}
}

void					gameManager::_deleteAllEntities( void )
{
	t_entity	*ptr;
	t_entity	*keep;

	ptr = this->_entities->start;
	while (ptr)
	{
		keep = ptr->next;
		delete ptr->entity;
		delete ptr;
		ptr = keep;
	}
	delete this->_entities;
}

void					gameManager::_addEntity(GameEntity* newEntity, int owner)
{
	t_entity		*node = new t_entity;

	node->entity = newEntity;
	node->owner = owner;
	node->next = NULL;
	node->prev = NULL;
	if (this->_entities->start == NULL)
	{
		this->_entities->start = node;
		this->_entities->end = node;
	}
	else
	{
		node->prev = this->_entities->end;
		this->_entities->end->next = node;
		this->_entities->end = node;
	}
}


void					gameManager::_removeEntity(t_entity *ptr)
{
	int		type;

	type = ptr->entity->get_type();
	if (type == TIR)
	{
		this->_tir--;
		if (this->_tir < 0)
			this->_tir = 0;
	}
	else if (type == ENNEMY || type == OBSTACLE)
	{
		this->_ennemy--;
		if (this->_ennemy < 0)
			this->_ennemy = 0;
		if (type == ENNEMY)
			this->_player->addScore(ENNEMY_SCORE);
		else if (type == OBSTACLE)
			this->_player->addScore(OBSTACLE_SCORE);
	}
	if (ptr->next && ptr->prev)
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
	}
	else if (ptr->next && ptr->prev == NULL)
	{
		ptr->next->prev = NULL;
		this->_entities->start = ptr->next;
	}
	else if (ptr->prev && ptr->next == NULL)
	{
		ptr->prev->next = NULL;
		this->_entities->end = ptr->prev;
	}
	else if (ptr->prev == NULL && ptr->next == NULL)
	{
		this->_entities->start = NULL;
		this->_entities->end = NULL;
	}
	delete ptr;
}

int						gameManager::_treatInput( int input )
{
	if (input == UP || input == DOWN || input == LEFT || input == RIGHT)
		this->_player->move(input, this->_maxY, this->_maxX);
	else if (input == SPACE)
		this->_addShoot(this->_player->getCoord(), UP, this->_player->getTir(), PLAYER);
	else if (input == ESC)
		return (1);
	return (0);
}

void				gameManager::_addShoot( coord coord, int direction, char print, int owner )
{
	if (this->_tir >= this->_maxTir)
		return ;

	Tir		*fire = new Tir(coord, direction, print, this->_maxY, this->_maxX);

	this->_addEntity(fire, owner);
	this->_tir++;
}

int				gameManager::_makeGame( void )
{
	this->_playLoop();
	if (this->_checkForDead())
		return (1);
	if (this->isTimeYet(this->_nextGen))
		this->_generateEnemy();
	return (0);
}

void				gameManager::_printScreenField( void )
{
	t_entity		*ptr;
	coord			coord;

	int				colorPair;
	int				type;

	ptr = this->_entities->start;
	coord = this->_player->getPrevious();
	mvwaddch(this->_field, coord.y, coord.x, ' ');
	coord = this->_player->getCoord();
	mvwaddch(this->_field, coord.y, coord.x, this->_player->get_c() | COLOR_PAIR(YELLOW));
	while (ptr)
	{
		type = ptr->entity->get_type();
		if (type == TIR)
		{
			if (ptr->owner == COMPUTER)
				colorPair = RED;
			else
				colorPair = MAGENTA;
		}
		else if (type == ENNEMY)
			colorPair = GREEN;
		else
			colorPair = WHITE;
		coord = ptr->entity->getPrevious();
		mvwaddch(this->_field, coord.y, coord.x, ' ');
		coord = ptr->entity->getCoord();
		mvwaddch(this->_field, coord.y, coord.x, ptr->entity->get_c() | COLOR_PAIR(colorPair));
		ptr = ptr->next;
	}
}

void				gameManager::_printScreenScore( void )
{
	mvwprintw(this->_score, 1, 1, "SCORE : ");
	mvwprintw(this->_score, 1, 9, this->_player->getScore());
}

void				gameManager::_generateEnemy( void )
{
	int				i;
	int				nbEnemy;
	int				nbObs;
	GameEntity*		newE;
	coord			coord;

	nbEnemy = rand() % 4;
	nbObs = rand() % 2;
	for (i = 0; i < nbEnemy; i++)
	{
		if (this->_ennemy >= this->_maxEnnemy)
			break ;
		coord.y = 3;
		coord.x = (rand() % (this->_maxX - 2)) + 1;
		newE = new Ennemy(coord, ENNEMY,  'Y', this->_maxY, this->_maxX);
		this->_addEntity(newE, COMPUTER);
		this->_ennemy++;
	}
	for (i = 0; i < nbObs; i++)
	{
		if (this->_ennemy > this->_maxEnnemy)
			break ;
		coord.y = 2;
		coord.x = (rand() % (this->_maxX - 2)) + 1;
		newE = new Obstacle(coord, 'O', 1, this->_maxY, this->_maxX);
		this->_addEntity(newE, COMPUTER);
		this->_ennemy++;
	}
	this->_planNextGen();
}

int					gameManager::_checkForDead( void )
{
	t_entity		*ptr;
	t_entity		*keep;
	t_entity		*other;
	coord			coord;

	ptr = this->_entities->start;
	while (ptr)
	{
		keep = ptr->next;
		if (!ptr->entity->getAlive())
		{
			coord = ptr->entity->getPrevious();
			mvwaddch(this->_field, coord.y, coord.x, ' ');
			coord = ptr->entity->getCoord();
			mvwaddch(this->_field, coord.y, coord.x, ' ');

			this->_removeEntity(ptr);
			ptr = keep;
			continue ;
		}
		other = this->_entities->start;
		coord = ptr->entity->getCoord();
		while (other)
		{
			if (ptr != other)
			{
				if (other->entity->isHurt(ptr->entity->getCoord()))
				{
					if (other == keep)
						keep = other->next;

					coord = ptr->entity->getPrevious();
					mvwaddch(this->_field, coord.y, coord.x, ' ');
					coord = ptr->entity->getCoord();
					mvwaddch(this->_field, coord.y, coord.x, ' ');
					this->_removeEntity(ptr);

					coord = other->entity->getPrevious();
					mvwaddch(this->_field, coord.y, coord.x, ' ');
					coord = other->entity->getCoord();
					mvwaddch(this->_field, coord.y, coord.x, ' ');
					this->_removeEntity(other);
					break ;
				}
			}
			other = other->next;
		}
		ptr = keep;
	}
	ptr = this->_entities->start;
	coord = this->_player->getCoord();
	while (ptr)
	{
		if (ptr->entity->isHurt(coord))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void					gameManager::_playLoop( void )
{
	t_entity			*ptr;

	ptr = this->_entities->start;
	while (ptr)
	{
		if (this->isTimeYet(ptr->entity->getPlayTime()))
		{
			if (ptr->entity->play())
				this->_addShoot(ptr->entity->getCoord(), ptr->entity->getDirection(), ptr->entity->getTir(), COMPUTER);
		}
		ptr = ptr->next;
	}
}

void					gameManager::_planNextGen( void )
{
	struct timeval		cur;
	struct timeval		add;

	gettimeofday(&cur, NULL);
	add.tv_sec = RESPAWN_TIME;
	add.tv_usec = 0;
	timeradd(&cur, &add, &(this->_nextGen));
}

bool				gameManager::isTimeYet(struct timeval ok)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	if (time.tv_sec < ok.tv_sec)
		return (false);
	else if (time.tv_sec == ok.tv_sec)
	{
		if (time.tv_usec < ok.tv_usec)
			return (false);
		else
			return (true);
	}
	else if (time.tv_sec > ok.tv_sec)
		return (true);
	return (false);
}

void				gameManager::_addClonedEntity(t_list *newL, t_entity *newE) const
{
	if (newL->start == NULL)
	{
		newL->start = newE;
		newL->end = newE;
	}
	else
	{
		newE->prev = newL->end;
		newL->end->next = newE;
	}
}

void				gameManager::_checkResize( void )
{
	int			max_y;
	int			max_x;
	t_entity	*ptr;

	getmaxyx(stdscr, max_y, max_x);
	if (this->_maxWinY != max_y || this->_maxWinX != max_x)
	{
		clear();
		this->_maxWinY = max_y;
		this->_maxWinX = max_x;
		wresize(this->_field, this->_maxWinY - this->_scoreSize, this->_maxWinX);
		wresize(this->_score, this->_scoreSize, this->_maxWinX);
		ptr = this->_entities->start;
		while (ptr)
		{
			ptr->entity->changeSize(this->_maxWinY, this->_maxWinX);
			ptr = ptr->next;
		}
		this->_drawBorders(this->_field);
		this->_drawBorders(this->_score);
		this->_printScreenField();
		this->_refresh();
	}
}


// ** PUBLIC FUNCTION **//
void					gameManager::init( void )
{
	coord	coord;

	//initialisation ncurses
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	timeout(0);
	start_color();
	init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(RED, COLOR_RED, COLOR_BLACK);
	init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
	init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(BW, COLOR_BLACK, COLOR_WHITE);
	getmaxyx(stdscr, this->_maxWinY, this->_maxWinX);
	this->_field = newwin(this->_maxWinY - this->_scoreSize, this->_maxWinX, 0, 0);
	this->_score = newwin(this->_scoreSize, this->_maxWinX, this->_maxWinY - this->_scoreSize, 0);
	getmaxyx(this->_field, this->_maxY, this->_maxX);
	this->_refresh();
	coord.x = this->_maxX / 2;
	coord.y = this->_maxY - 2;
	this->_player = new Player(coord, "Player", 5, PLAYER_SPRITE, 0, this->_maxY, this->_maxX);
	this->_drawBorders(this->_field);
	this->_drawBorders(this->_score);
	wbkgd(this->_score, COLOR_PAIR(BW));
	this->_isInit = true;
}

void					gameManager::loop( void )
{
	int		input;

	this->_planNextGen();
	while (42)
	{
		this->_checkResize();
		input = getch();
		if (input >= 0)
		{
			if (this->_treatInput(input))
				return ;
		}
		if (this->_makeGame())
			return ;
		this->_printScreenField();
		this->_printScreenScore();
		this->_refresh();
	}
}

t_list*					gameManager::cloneEntities( void ) const
{
	t_list		*newL = new t_list;
	t_entity	*ptr;
	t_entity	*newE;

	newL->start = NULL;
	newL->end = NULL;
	ptr = this->_entities->start;
	while (ptr)
	{
		newE = new t_entity;
		newE->entity = ptr->entity;
		newE->prev = NULL;
		newE->next = NULL;
		this->_addClonedEntity(newL, newE);
		ptr = ptr->next;
	}
	return (newL);
}

Player*					gameManager::clonePlayer( void ) const
{
	return (new Player(*(this->_player)));
}

int						gameManager::getMaxY( void ) const
{
	return (this->_maxY);
}

int						gameManager::getMaxX( void ) const
{
	return (this->_maxX);
}

WINDOW*					gameManager::getField( void ) const
{
	return (this->_field);
}

WINDOW*					gameManager::getScore( void ) const
{
	return (this->_score);
}
