/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 19:07:48 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/06 19:07:49 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

void	ft_init_sdl(t_visudata *d)
{
	d->close_request = 0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_error(d, 5);
	if (TTF_Init() == -1)
		ft_error(d, 9);
	if (!(d->font_big = TTF_OpenFont("font/font.ttf", 60)))
		ft_error(d, 10);
	if (!(d->font = TTF_OpenFont("font/font.ttf", 40)))
		ft_error(d, 10);
	if (!(d->win = SDL_CreateWindow("Filler", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, 0)))
		ft_error(d, 6);
	if (!(d->s = SDL_GetWindowSurface(d->win)))
		ft_error(d, 7);
}
