// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Obstacle.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:25:32 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/10 20:46:57 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OBSTACLE_HPP
# define OBSTACLE_HPP

#include <iostream>
#include "gameEntity.class.hpp"

class Obstacle : public GameEntity
{

public:
	Obstacle( void);
	Obstacle(coord pos, char c);
	Obstacle(Obstacle const & rf);
	~Obstacle( void );

	int		get_typeob( void );
	void	set_typeob(int t);
	Obstacle & operator=(Obstacle const & rf);

private:

	int		_type
};

#endif // ** OBSTACLE_HPP * //
