/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:28:18 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/11 15:28:21 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

void	ft_error(t_visudata *d, int error)
{
	if (error == 1)
		ft_putendl("You have problems, man!");
	else if (error == 2)
		ft_putendl("Bad player");
	else if (error == 3)
		ft_putendl("Wrong size of map");
	else if (error == 4)
		ft_putendl("Wrong size of piece");
	else if (error == 5)
		ft_putendl("error initializing SDL");
	else if (error == 6)
		ft_putendl("error creating window");
	else if (error == 7)
		ft_putendl("error getting surface of window");
	else if (error == 8)
		ft_putendl("bad line");
	else if (error == 9)
		ft_putendl("error initializing TTF");
	else if (error == 10)
		ft_putendl("error type of font");
	ft_exit(d, EXIT_FAILURE);
}
