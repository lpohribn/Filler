/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:24:22 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/10 14:24:23 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

static inline char	*ft_name_player(t_visudata *d, char *str)
{
	int		i;
	char	*s;
	char	*st;

	i = 0;
	if ((s = ft_strstr(str, ".filler")) == NULL)
		ft_error(d, 2);
	while (*s-- != '/')
		++i;
	if (!(st = ft_strnew(i - 1)))
		ft_error(d, 1);
	s += 2;
	ft_strncpy(st, s, i - 1);
	return (st);
}

static inline int	ft_who_is_it(t_visudata *d, char *str)
{
	int	ret;

	ret = 0;
	if (get_next_line(0, &str) < 0)
		ft_error(d, 1);
	if (ft_strncmp(str, "$$$ exec p1 : ", 13) == 0)
		d->p1 = ft_name_player(d, str);
	else if (ft_strncmp(str, "$$$ exec p2 : ", 13) == 0)
		d->p2 = ft_name_player(d, str);
	else
		ret = -1;
	free(str);
	return (ret);
}

void				ft_check_players(t_visudata *d)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		ft_error(d, 1);
	free(line);
	if (ft_who_is_it(d, line) < 0)
		ft_error(d, 2);
	if (get_next_line(0, &line) < 0)
		ft_error(d, 1);
	free(line);
	if (ft_who_is_it(d, line) < 0)
		ft_error(d, 2);
}

static inline int	ft_check_l(t_visudata *d, char *str)
{
	char	*line;
	int		ret;

	line = NULL;
	if ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_strcmp(str, line) == 0)
		{
			free(line);
			return (1);
		}
		free(line);
	}
	else if (ret == 0)
		return (0);
	else
		ft_error(d, 1);
	return (0);
}

void				ft_check_header(t_visudata *d)
{
	if (ft_check_l(d, "# -------------- VM  version 1.1 ------------- #") == 0)
		ft_error(d, 1);
	if (ft_check_l(d, "#                                              #") == 0)
		ft_error(d, 1);
	if (ft_check_l(d, "# 42 / filler VM Developped by: Hcao - Abanlin #") == 0)
		ft_error(d, 1);
	if (ft_check_l(d, "#                                              #") == 0)
		ft_error(d, 1);
	if (ft_check_l(d, "# -------------------------------------------- #") == 0)
		ft_error(d, 1);
}
