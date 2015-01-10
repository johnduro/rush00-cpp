// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Obstacle.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:25:32 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 00:05:22 by mdrissi          ###   ########.fr       //
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
	Obstacle(coord pos, char c, int typeob);
	Obstacle(Obstacle const & rf);
	~Obstacle( void );

	int		get_typeob( void ) const;
	void	set_typeob(int const t);
	Obstacle & operator=(Obstacle const & rf);

private:

	int		_typeob;
};

#endif // ** OBSTACLE_HPP * //
