/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:17:04 by lpohribn          #+#    #+#             */
/*   Updated: 2018/08/23 16:17:05 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline float	ft_sqrtf(float x)
{
	int		i;
	float	xhalf;

	xhalf = 0.5f * x;
	i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	x = x * (1.5f - xhalf * x * x);
	x = x * (1.5f - (xhalf * x * x));
	return (1.0 / x);
}

static inline int	ft_heatmap2(t_board *m, int y, int x)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	tmp = 0;
	while (++i < m->m_height)
	{
		j = -1;
		while (++j < m->m_width)
		{
			if (m->h_map[i][j] == -2)
			{
				if (m->h_map[y][x] >= 0)
				{
					m->l = ft_power(i - y, 2) + ft_power(j - x, 2);
					m->h_map[y][x] = ft_sqrtf((float)m->l);
				}
				if (m->h_map[y][x] > tmp && tmp != 0)
					m->h_map[y][x] = tmp;
			}
			tmp = m->h_map[y][x];
		}
	}
	return (0);
}

int					ft_heatmap1(t_board *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->m_height)
	{
		j = -1;
		while (++j < m->m_width)
		{
			if (m->map[i][j] == m->p.p1)
				m->h_map[i][j] = -1;
			else if (m->map[i][j] == m->p.p2)
				m->h_map[i][j] = -2;
			else if (m->h_map[i][j] != -1 && m->h_map[i][j] != -2)
				ft_heatmap2(m, i, j);
		}
	}
	return (0);
}

static inline int	ft_heatmap(t_board *m)
{
	int	i;
	int j;

	i = -1;
	m->flag = 0;
	while (++i < m->m_height)
	{
		j = -1;
		while (++j < m->m_width)
		{
			if (m->map[i][j] == m->p.p1)
			{
				m->h_map[i][j] = -1;
				m->flag++;
			}
			else if (m->map[i][j] == m->p.p2)
			{
				m->h_map[i][j] = -2;
				m->flag++;
			}
			if (m->flag == 2)
				return (0);
		}
	}
	return (0);
}

int					ft_create_heatmap(t_board *m)
{
	int	i;

	i = -1;
	if (!(m->h_map = (int**)malloc(sizeof(int*) * m->m_height)))
		return (0);
	while (++i < m->m_height)
	{
		if (!(m->h_map[i] = (int*)malloc(sizeof(int) * m->m_width)))
			return (0);
	}
	ft_heatmap(m);
	ft_heatmap1(m);
	return (0);
}
