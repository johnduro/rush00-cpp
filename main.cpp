// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:24:08 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/10 23:35:52 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ncurses.h>
#include "time.h"

int			main( void )
{
	gameManager*		manager = new gameManager();

	srand(time(NULL));
	manager->init();
	// manager->menu(); //?????????????????
	manager->loop();
	delete manager;
	return (0);
}
