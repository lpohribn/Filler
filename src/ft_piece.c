/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recording.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:20:32 by lpohribn          #+#    #+#             */
/*   Updated: 2018/08/02 20:20:34 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline int	ft_put_piece1(t_board *m, int y, int x, int i)
{
	int	j;

	j = -1;
	while (m->piece[i][++j])
	{
		if (m->piece[i][j] == '*')
		{
			if (y + (i - m->p_y) >= 0 && x + (j - m->p_x) >= 0
			&& m->map[y + (i - m->p_y)] &&
			m->map[y + (i - m->p_y)][x + (j - m->p_x)] != '\0')
			{
				if (m->map[y + (i - m->p_y)][x + (j - m->p_x)] == m->p.p1)
					m->fd_place++;
				if (m->map[y + (i - m->p_y)][x + (j - m->p_x)] == m->p.p2)
					return (0);
			}
			else
				return (0);
		}
	}
	return (1);
}

static inline int	ft_put_piece(t_board *m, int y, int x)
{
	int	i;

	i = -1;
	m->fd_place = 0;
	while (m->piece[++i])
	{
		if (!ft_put_piece1(m, y, x, i))
			return (0);
	}
	if (m->fd_place != 1)
		return (0);
	return (1);
}

int					ft_find_piece(t_board *m, int y, int x)
{
	m->p_y = -1;
	while (++m->p_y < m->p_height)
	{
		m->p_x = -1;
		while (++m->p_x < m->p_width)
		{
			if (m->piece[m->p_y][m->p_x] == '*')
			{
				if (ft_put_piece(m, y, x) == 1)
					ft_check_best_position(m, y, x);
			}
		}
	}
	return (0);
}

static inline int	ft_height_width_p(t_board *m, char *line)
{
	if (ft_strstr(line, "Piece ") != NULL)
	{
		m->p_height = ft_atoi(&line[6]);
		m->p_width = ft_width(&line[6]);
		if (m->p_height <= 0 || m->p_width <= 0)
			return (1);
		free(line);
	}
	else
	{
		free(line);
		return (0);
	}
	return (1);
}

int					ft_read_piece(t_board *m, char *line)
{
	int i;

	i = -1;
	get_next_line(0, &line);
	ft_height_width_p(m, line);
	if (!(m->piece = (char**)malloc(sizeof(char*) * m->p_height + 1)))
		return (0);
	while (++i < m->p_height)
	{
		get_next_line(0, &line);
		m->piece[i] = line;
	}
	m->piece[i] = NULL;
	ft_find_position(m);
	return (0);
}
