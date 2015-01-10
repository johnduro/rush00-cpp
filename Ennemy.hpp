// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ennemy.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:42:04 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/10 23:41:16 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENNEMY_HPP
# define ENNEMY_HPP

#include <iostream>
#include "gameEntity.class.hpp"

class Ennemy : public GameEntity
{

public:

	Ennemy(coord pos, int id, char c);
	Ennemy( void );
	Ennemy(Ennemy const & rf);
	~Ennemy( void );

	int		get_id( void ) const;
	void	set_id(int const id); 
	Ennemy & operator=(Ennemy const & rf);

private:

	int		_id;
};

#endif // ** ENNEMY_HPP ** //
