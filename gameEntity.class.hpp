// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameEntity.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:28 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/10 22:40:15 by mdrissi          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMEENTITY_CLASS_HPP
# define GAMEENTITY_CLASS_HPP

struct	coord{
	int	x;
	int	y;
};

class GameEntity
{
public:

	GameEntity( void );
	GameEntity( bool alive, coord pos, char c, int type);
	GameEntity( GameEntity const & entity);
	~GameEntity( void );

	coord	get_position( void ) const;
	bool	getAlive( void ) const;
	char	get_c( void ) const;
	int		get_type( void ) const;

	void	setAlive(bool const alive);
	void	set_position(coord const x);
	void	set_c(char const c);
	void	set_type(int const type);

	void	move(int dir, int maxY, int maxX);
	GameEntity	& operator=(GameEntity const & rf);

protected:

	bool		_alive;
	coord		_pos;
	char		_c;
	int			_type;

};



#endif // ** GAMEENTITY_CLASS_HPP ** //
