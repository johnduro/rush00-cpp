// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Tir.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mdrissi <mdrissi@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 17:40:14 by mdrissi           #+#    #+#             //
//   Updated: 2015/01/11 03:45:12 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TIR_HPP
# define TIR_HPP

#include "gameEntity.class.hpp"
#include "defines.hpp"


class Tir : public GameEntity
{
public:

	Tir( void );
	Tir(coord pos, int direction, char type, int maxY, int maxX);
	Tir(Tir const & rf);
	~Tir();

	int		get_typetir( void ) const;
	void	set_typetir(int const type);
	int		get_dir( void ) const;
	void	set_dir(int const dir);
	int		play( void );
	Tir & operator=(Tir const & rf);
	struct timeval		getPlayTime( void ) const;
	char	getTir( void ) const;

private:

	// int		_dir;
	char	_typetir;
	struct timeval	_play;

	void		_planNextPlay( void );
};

#endif // ** TIR_HPP ** //
