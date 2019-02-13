/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:59:03 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/23 19:59:04 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

static inline void	ft_draw_score(t_visudata *d, char *s1, char *s2)
{
	SDL_Surface		*text_s1;
	SDL_Surface		*text_s2;
	int				w;
	int				h;

	w = 0;
	while (w++ < WIN_W)
		SDL_FillRect(d->s, &(SDL_Rect){w, 140, 60, 60}, 0x5c6e82);
	if (TTF_SizeText(d->font, s1, &w, &h) == -1)
		ft_error(d, 10);
	if (!(text_s1 = TTF_RenderText_Blended(d->font, s1,
		(SDL_Color){30, 149, 161, 0})))
		ft_error(d, 10);
	SDL_BlitSurface(text_s1, NULL, d->s,
		&(SDL_Rect){230 + d->w_text1 / 2 - w / 2, 140, 30, 30});
	SDL_FreeSurface(text_s1);
	if (TTF_SizeText(d->font, s2, &w, &h) == -1)
		ft_error(d, 10);
	if (!(text_s2 = TTF_RenderText_Blended(d->font, s2,
		(SDL_Color){176, 88, 117, 0})))
		ft_error(d, 10);
	SDL_BlitSurface(text_s2, NULL, d->s,
		&(SDL_Rect){WIN_W - 180 - d->w_text2 / 2 - w / 2, 140, 30, 30});
	SDL_FreeSurface(text_s2);
}

void				ft_score(t_visudata *d)
{
	char *p1;
	char *p2;

	d->c_p1 = d->count_p1;
	d->c_p2 = d->count_p2;
	p1 = ft_itoa(d->count_p1);
	p2 = ft_itoa(d->count_p2);
	ft_draw_score(d, p1, p2);
	free(p1);
	free(p2);
}

void				ft_final_score(t_visudata *d)
{
	SDL_Surface		*winner;
	int				w;
	int				h;

	if (TTF_SizeText(d->font, "WINNER", &w, &h) == -1)
		ft_error(d, 10);
	if (d->c_p1 > d->c_p2)
	{
		if (!(winner = TTF_RenderText_Blended(d->font, "WINNER",
			(SDL_Color){248, 244, 188, 0})))
			ft_error(d, 10);
		SDL_BlitSurface(winner, NULL, d->s,
			&(SDL_Rect){230 + d->w_text1 / 2 - w / 2, 20, 30, 30});
		SDL_FreeSurface(winner);
	}
	else if (d->c_p1 < d->c_p2)
	{
		if (!(winner = TTF_RenderText_Blended(d->font, "WINNER",
			(SDL_Color){248, 244, 188, 0})))
			ft_error(d, 10);
		SDL_BlitSurface(winner, NULL, d->s,
			&(SDL_Rect){WIN_W - 180 - d->w_text2 / 2 - w / 2, 20, 30, 30});
		SDL_FreeSurface(winner);
	}
}
