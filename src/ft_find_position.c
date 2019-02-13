/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:57:38 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/24 18:57:42 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_find_position(t_board *m)
{
	int x;
	int y;

	y = -1;
	while (++y < m->m_height)
	{
		x = -1;
		while (++x < m->m_width)
		{
			if (m->map[y][x] == m->p.p1)
			{
				ft_find_piece(m, y, x);
			}
		}
	}
	m->distance = 2147483647;
	return (0);
}
