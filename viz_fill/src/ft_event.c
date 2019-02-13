/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:54:22 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/23 19:54:24 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

int	ft_event(t_visudata *d, int stop)
{
	if (SDL_PollEvent(&d->event))
	{
		if (d->event.type == SDL_QUIT)
			d->close_request = 1;
		if (d->event.type == SDL_KEYDOWN)
		{
			if (d->event.key.keysym.sym == SDLK_ESCAPE)
				d->close_request = 1;
			if (d->event.key.keysym.sym == SDLK_SPACE)
				stop++;
		}
	}
	return (stop);
}
