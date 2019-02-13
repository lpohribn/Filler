/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:38:44 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/11 15:38:47 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

void	ft_exit(t_visudata *d, int status)
{
	free(d->p1);
	free(d->p2);
	TTF_CloseFont(d->font);
	TTF_Quit();
	SDL_DestroyWindow(d->win);
	exit(status);
}
