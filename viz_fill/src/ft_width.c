/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 13:57:09 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/19 13:57:12 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

static inline void	ft_wid_heig_position(t_visudata *d)
{
	if (d->m_height < 24 && d->m_width < 40)
		d->s_rect = 40;
	else if (d->m_height <= 24 && d->m_width <= 40)
		d->s_rect = 20;
	else
		d->s_rect = 8;
}

int					ft_width(char *line)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != '\0')
		n = ft_atoi(&line[i]);
	return (n);
}

void				ft_wid_heig_map(t_visudata *d, char *line)
{
	d->m_height = ft_atoi(&line[8]);
	d->m_width = ft_width(&line[8]);
	if ((d->m_height <= 0 && d->m_width <= 0) ||
		(d->m_height >= 100 && d->m_width >= 100))
		ft_error(d, 3);
	ft_wid_heig_position(d);
	free(line);
}
