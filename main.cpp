// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:24:08 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/10 18:07:34 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ncurses.h>

int			main( void )
{
	gameManager*		manager = new gameManager();

	manager->init();
	// manager->menu(); //?????????????????
	manager->loop();
	delete manager;
	return (0);
}
