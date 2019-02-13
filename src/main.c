/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nachalo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:35:57 by lpohribn          #+#    #+#             */
/*   Updated: 2018/07/31 18:36:00 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline void	init(t_board *m)
{
	m->m_height = 0;
	m->m_width = 0;
	m->p_height = 0;
	m->p_width = 0;
	m->result_x = 0;
	m->result_y = 0;
	m->distance = 2147483647;
}

static inline void	clean_all(t_board *m)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < m->m_height)
		free(m->map[i]);
	free(m->map);
	while (++j < m->p_height)
		free(m->piece[j]);
	free(m->piece);
}

static inline void	ft_send_coordinates(t_board *m)
{
	ft_putnbr(m->result_y);
	ft_putchar(' ');
	ft_putnbr(m->result_x);
	ft_putchar('\n');
}

static inline int	which_player(char *line, t_board *m)
{
	if (ft_strstr(line, "$$$ exec p1 : [./lpohribn.filler]"))
	{
		m->p.p1 = 'O';
		m->p.p2 = 'X';
		free(line);
		return (1);
	}
	else if (ft_strstr(line, "$$$ exec p2 : [./lpohribn.filler]"))
	{
		m->p.p1 = 'X';
		m->p.p2 = 'O';
		free(line);
		return (1);
	}
	return (0);
}

int					main(void)
{
	char		*line;
	t_board		m;

	get_next_line(0, &line);
	m.h_map = NULL;
	if (!which_player(line, &m))
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		init(&m);
		if (!ft_width_height_map(line, &m))
			return (0);
		get_next_line(0, &line);
		free(line);
		ft_read_map(&m, line);
		ft_read_piece(&m, line);
		ft_send_coordinates(&m);
		clean_all(&m);
	}
	return (0);
}
