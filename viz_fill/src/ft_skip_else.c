/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_else.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:02:38 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/19 14:02:40 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

void	ft_skip_piece(t_visudata *d, char *line)
{
	int i;

	d->p_height = ft_atoi(&line[6]);
	d->p_width = ft_width(&line[6]);
	if (d->p_height <= 0 && d->p_width <= 0)
		ft_error(d, 4);
	i = d->p_height;
	free(line);
	while (i-- > 0)
	{
		get_next_line(0, &line);
		free(line);
	}
}
