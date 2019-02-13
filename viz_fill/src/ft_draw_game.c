/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:46:30 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/18 17:46:32 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

static inline void	ft_draw_name_game(t_visudata *d)
{
	if (!(d->text_surface = TTF_RenderText_Blended(d->font_big,
		"Filler", (SDL_Color){255, 204, 204, 0})))
		ft_error(d, 10);
	SDL_BlitSurface(d->text_surface, NULL,
		d->s, &(SDL_Rect){(WIN_W / 2) - 70, 10, 50, 50});
	SDL_FreeSurface(d->text_surface);
}

static inline void	ft_draw_name_players(t_visudata *d)
{
	if (TTF_SizeText(d->font, d->p1, &d->w_text1, &d->h_text1) == -1)
		ft_error(d, 10);
	if (!(d->text_p1 = TTF_RenderText_Blended(d->font, d->p1,
		(SDL_Color){68, 148, 154, 0})))
		ft_error(d, 10);
	SDL_BlitSurface(d->text_p1, NULL, d->s, &(SDL_Rect){230, 90, 20, 20});
	SDL_FreeSurface(d->text_p1);
	if (TTF_SizeText(d->font, d->p2, &d->w_text2, &d->h_text2) == -1)
		ft_error(d, 10);
	if (!(d->text_p2 = TTF_RenderText_Blended(d->font, d->p2,
		(SDL_Color){162, 88, 117, 0})))
		ft_error(d, 10);
	SDL_BlitSurface(d->text_p2, NULL, d->s,
		&(SDL_Rect){WIN_W - d->w_text2 - 180, 90, 20, 20});
	SDL_FreeSurface(d->text_p2);
}

void				ft_draw_game(t_visudata *d)
{
	int		tick;
	int		stop;

	SDL_FillRect(d->s, NULL, 0x5c6e82);
	ft_draw_name_game(d);
	ft_draw_name_players(d);
	SDL_UpdateWindowSurface(d->win);
	stop = 1;
	d->count_p1 = 1;
	d->count_p2 = 1;
	while (!d->close_request)
	{
		tick = SDL_GetTicks();
		stop = ft_event(d, stop);
		if (stop % 2)
			continue ;
		ft_map(d);
		SDL_UpdateWindowSurface(d->win);
		if (1000 / FPS > SDL_GetTicks() - tick)
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - tick));
	}
	SDL_Delay(3000);
}
