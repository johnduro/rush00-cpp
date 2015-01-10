// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Tir.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:40:14 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/10 22:23:50 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TIR_HPP
# define TIR_HPP

#include "gameEntity.class.hpp"


class Tir : public GameEntity
{
public:

	Tir( void );
	Tir(coord pos, char type, int direction);
	Tir(Tir const & rf);
	~Tir();

	int		get_typetir( void ) const;
	void	set_typetir(int const type);
	int		get_dir( void ) const;
	void	set_dir(int const dir);
	Tir & operator=(Tir const & rf);

private:

	int		_dir;
	char	_typetir;
};
