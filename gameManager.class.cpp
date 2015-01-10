// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameManager.class.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:31 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/10 18:16:27 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "gameManager.class.hpp"

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
	//A FAIRE !!!!!!!
}

gameManager::~gameManager( void )
{
	if (this->isInit)
		endwin(); //fin ncurses
	delete this->_player;
	this->_deleteAllEntities();
}

gameManager &			gameManager::operator=( gameManager const & src )
{
	//A FAIRE !!!!!!!
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

void					gameManager::_addEntity(gameEntity* newEntity)
{
	t_entity		*node = new t_entity;

	node->entity = newEntity;
	node->next = NULL;
	node->prev = NULL;
	node->prev = this->_entities->end;
	this->_entities->end->next = node;
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
	while (42)
	{

	}
}
