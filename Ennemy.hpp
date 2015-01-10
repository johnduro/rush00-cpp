// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ennemy.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:42:04 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/10 20:40:47 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENNEMY_HPP
# define ENNEMY_HPP

#include <iostream>
#include <gameEntity.class.hpp>

class Ennemy : public GameEntity
{

public:

	Ennemy(t_coord c, int id);
	Ennemy();
	Ennemy(Ennemy const &rf);
	~Ennemy();

	int		get_id( void ) const;
	void	set_id(int const id); 
	Ennemy & operator=(Ennemy const & rf);

private:

	int		_id;
};

#endif // ** ENNEMY_HPP ** //
