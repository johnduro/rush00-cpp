// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   defines.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 18:30:03 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/11 03:01:01 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DEFINES_HPP
# define DEFINES_HPP

struct	coord{
	int	x;
	int	y;
};

#include <sys/time.h>

# define UP 259
# define DOWN 258
# define LEFT 260
# define RIGHT 261
# define ESC 27
# define SPACE 32
# define PLAYER 0
# define ENNEMY 1
# define TIR 2
# define OBSTACLE 3
# define COMPUTER 1
# define WHITE 1
# define RED 2
# define YELLOW 3
# define MAGENTA 4
# define RESPAWN_TIME 4
# define PLAY_TIME 1
# define FIRE_TIME 1500000
# define OBSTACLE_TIME 500000
# define FIRE_MOVE_TIME 250000

#endif // ** DEFINES_HPP ** //
