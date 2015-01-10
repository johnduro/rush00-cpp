// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   gameManager.class.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 16:05:24 by mle-roy           #+#    #+#             //
//   Updated: 2015/01/10 16:11:17 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMEMANAGER_CLASS_HPP
# define GAMEMANAGER_CLASS_HPP

class gameManager
{
public :
	// ** CANONICAL ** //
	gameManager( void );
	gameManager( gameManager const & src );
	~gameManager( void );
	gameManager &			operator=( gameManager const & src );
}

#endif // ** GAMEMANAGER_CLASS_HPP ** //
