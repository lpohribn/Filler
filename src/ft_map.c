/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:11:57 by lpohribn          #+#    #+#             */
/*   Updated: 2018/08/06 14:11:59 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_width(char *line)
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

int		ft_width_height_map(char *line, t_board *m)
{
	if (m->m_height == 0 && m->m_width == 0)
	{
		if (ft_strstr(line, "Plateau ") != NULL)
		{
			m->m_height = ft_atoi(&line[8]);
			m->m_width = ft_width(&line[8]);
			if (m->m_height <= 0 || m->m_width <= 0)
				return (0);
			if (m->m_height >= 1000 || m->m_width >= 1000)
				return (0);
			free(line);
		}
		else
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

int		ft_read_map(t_board *m, char *line)
{
	int i;

	i = -1;
	if (!(m->map = (char**)malloc(sizeof(char*) * m->m_height + 1)))
		return (0);
	while (++i < m->m_height)
	{
		get_next_line(0, &line);
		m->map[i] = ft_strdup(&line[4]);
		free(line);
	}
	m->map[i] = NULL;
	if (m->h_map == NULL)
		ft_create_heatmap(m);
	else
		ft_heatmap1(m);
	return (1);
}
