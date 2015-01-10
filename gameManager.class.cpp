// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameManager.class.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:31 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/10 23:49:30 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "gameManager.class.hpp"
#include "defines.hpp"

//refresh() --> raffraichi l ecran
//int move(int y, int x); --> bouge le curseur


// ** CANONICAL ** //
gameManager::gameManager( void )
{
	this->_isInit = false;
	this->_entities = new t_list;
	this->_entities->start = NULL;
	this->_entities->end = NULL;
	this->_player = new Player();
}

gameManager::gameManager( gameManager const & src )
{
	this->_isInit = false;
	this->_entities = src.cloneEntities();//a faire
	this->_player = src.clonePlayer();
	this->_maxY = src.getMaxY();
	this->_maxX = src.getMaxX();
	this->_field = src.getField();
	this->_score = src.getScore();
}

gameManager::~gameManager( void )
{
	if (this->isInit)
		endwin();
	delete this->_player;
	this->_deleteAllEntities();
}

gameManager &			gameManager::operator=( gameManager const & src )
{
	this->_entities = src.cloneEntities();//a faire
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

void					gameManager::_drawBorder(WINDOW *screen)
{
	int		x;
	int		y;
	int		i;

	getmaxyx(screen, y, x);
	// corners
	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, y - 1, 0, "+");
	mvwprintw(screen, 0, x - 1, "+");
	mvwprintw(screen, y - 1, x - 1, "+");
	// sides
	for (i = 1; i < (y - 1); i++)
	{
		mvwprintw(screen, i, 0, "|");
		mvwprintw(screen, i, x - 1, "|");
	}
	// top and bottom
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

void					gameManager::_addEntity(gameEntity* newEntity, int owner)
{
	t_entity		*node = new t_entity;

	node->entity = newEntity;
	node->owner = owner;
	node->next = NULL;
	node->prev = NULL;
	node->prev = this->_entities->end;
	this->_entities->end->next = node;
}


void					gameManager::_removeEntity(t_entity *ptr)
{
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
	delete ptr;
}

int						gameManager::_treatInput( int input )
{
	coord		coord;

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
	Tir		*fire = new Tir(coord, direction, print);

	this->_addEntity(fire, owner);
}

int				gameManager::_makeGame( void );
{
//	this->_scrollDown();//??
	this->_playLoop();
	if (this->checkForDead())
		return (1);
	if (this->_isTimeYet(this->_nextGen))
		this->_generateEnemy();
	return (0);
}

void				gameManager::_printScreenField( void )
{
//mvwprintw(screen, y - 1, x - 1, "+");
	// attron(COLOR_PAIR(1));
	// attroff(COLOR_PAIR(1));
	t_entity		*ptr;
	coord			coord;
	int				colorPair;
	int				type;

	ptr = this->_entities->start;
	this->_drawBorders(this->_field);
	this->_drawBorders(this->_score);
	coord = this->_player->getCoord();
	attron(COLOR_PAIR(YELLOW));
	mvwprintw(this->_field, coord.y, coord.x, this->_player->getChar());
	attroff(COLOR_PAIR(YELLOW));
	while (ptr)
	{
		type = ptr->entity->getType();
		coord = ptr->entity->getCoord();
		if (type == TIR)
		{
			if (ptr->owner == COMPUTER)
				colorPair = RED;
			else
				colorPair = MAGENTA;
		}
		else if (type == ENEMY || type == OBSTACLE)
			colorPair = WHITE;
		attron(COLOR_PAIR(pair));
 		mvwprintw(this->_field, coord.y, coord.x, ptr->entity->getChar());
		attroff(COLOR_PAIR(pair));
		ptr = ptr->next;
	}
}

void				gameManager::_printScreenScore( void )
{
	mvwprintw(this->_score, 1, 1, this->_player->getScore());
}

void				gameManager::_generateEnemy( void )
{
	int				nbEnemy;
	int				nbObs;
	gameEntity*		*newE;
	coord			coord;

	nbEnemy = rand() % 4;
	nbObs = rand() % 2;
	for (i = 0; i < nbEnemy; i++)
	{
		coord.y = 1;
		coord.x = rand() % this->_maxX;;
		newE = new Ennemy(coord, "Y", 1);
		this->_addEntity(newE, COMPUTER);
	}
	for (i = 0; i < nbObs; i++)
	{
		coord.y = 1;
		coord.x = rand() % this->_maxX;;
		newE = new Obstacle(coord, "O", 1);
		this->_addEntity(newE, COMPUTER);
	}
	this->_planNextGen();
}

// void				gameManager::_scrollDown( void )
// {
// 	t_entity		*ptr;

// 	ptr = this->_entities->start;
// 	while (ptr)
// 	{
// 		if (ptr->owner == COMPUTER)
// 			ptr->entity->move(DOWN, this->_maxY, this->_maxX);
// 		ptr = ptr->next;
// 	}
// }

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
				if (other->entity->isHurt(coord))
				{
					if (other == keep)
						keep = other->next;
					this->_removeEntity(ptr);
					this->_removeEntity(other);
					break ;
				}
			}
		}
		ptr = keep;
	}
	ptr = this->_entities->start;
	coord = this->_player->getCoord();
	while (ptr)
	{
		if (ptr->entity->isHurt(coord))
			return (1);
	}
	return (0);
}

void					gameManager::_playLoop( void )
{
	t_entity			*ptr;

	ptr = this->_entities->start;
	while (ptr)
	{
		if (ptr->entity->play())
			this->_addShoot(ptr->entity->getCoord(), ptr->entity->getDirection(), COMPUTER);
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

bool					gameManager::_isTimeYet(struct timeval ok)
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


// ** PUBLIC FUNCTION **//
void					gameManager::init( void )
{
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
	getmaxyx(stdscr, this->_maxY, this->_maxX);
	this->_field = newwin(this->_maxY - this->_scoreSize, this->_maxX, 0, 0);
	this->_score = newwin(this->_scoreSize, this->_maxX, this->_maxY - this->_scoreSize, 0);
	mvwprintw(this->_field, 0, 0, "Field");
	mvwprintw(this->_score, 0, 0, "Score");
	this->_refresh();
	this->_isInit = true;
}

void					gameManager::loop( void )
{
	int		input;

	this->_planNextGen();
	while (42)
	{
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
