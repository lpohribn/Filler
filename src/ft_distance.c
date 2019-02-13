/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:11:51 by lpohribn          #+#    #+#             */
/*   Updated: 2018/08/21 15:11:53 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline int	find_distance(t_board *m, int y, int x)
{
	int	i;
	int	j;
	int	distance;

	distance = 0;
	i = -1;
	while (m->piece[++i])
	{
		j = -1;
		while (m->piece[i][++j])
		{
			if (m->piece[i][j] == '*' &&
			m->h_map[y + (i - m->p_y)][x + (j - m->p_x)] != -1)
			{
				distance += m->h_map[y + (i - m->p_y)][x + (j - m->p_x)];
			}
		}
	}
	return (distance);
}

void				ft_check_best_position(t_board *m, int y, int x)
{
	int	dist;

	dist = find_distance(m, y, x);
	if (dist <= m->distance)
	{
		m->distance = dist;
		m->result_x = x - m->p_x;
		m->result_y = y - m->p_y;
	}
}
