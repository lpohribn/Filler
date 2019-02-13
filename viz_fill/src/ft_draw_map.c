/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:58:26 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/11 17:58:28 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

static	void	ft_count(t_visudata *d, char *line, int x)
{
	if (line[(x + 4)] == 'o' || line[(x + 4)] == 'O')
		d->count_p1++;
	else if (line[(x + 4)] == 'x' || line[(x + 4)] == 'X')
		d->count_p2++;
}

static	void	ft_fillrect(t_visudata *d, char *line, int x, int y)
{
	int	start_x;
	int	start_y;
	int	s;

	start_y = (WIN_H / 2) - ((d->m_height * d->s_rect) / 2) + 80;
	start_x = (WIN_W / 2) - ((d->m_width * d->s_rect) / 2);
	s = d->s_rect - 2;
	if (line[(x + 4)] == '.')
		SDL_FillRect(d->s, &(SDL_Rect){start_x + (x * d->s_rect),
			start_y + (y * d->s_rect), s, s}, 0x66788c);
	else if (line[(x + 4)] == 'X')
		SDL_FillRect(d->s, &(SDL_Rect){start_x + (x * d->s_rect),
			start_y + (y * d->s_rect), s, s}, 0xa25875);
	else if (line[(x + 4)] == 'O')
		SDL_FillRect(d->s, &(SDL_Rect){start_x + (x * d->s_rect),
			start_y + (y * d->s_rect), s, s}, 0x44949a);
	else if (line[(x + 4)] == 'x')
		SDL_FillRect(d->s, &(SDL_Rect){start_x + (x * d->s_rect),
			start_y + (y * d->s_rect), s, s}, 0xcdb5bc);
	else if (line[(x + 4)] == 'o')
		SDL_FillRect(d->s, &(SDL_Rect){start_x + (x * d->s_rect),
			start_y + (y * d->s_rect), s, s}, 0x9fbbbe);
	else
		ft_error(d, 1);
	ft_count(d, line, x);
}

static	void	ft_draw_map(t_visudata *d)
{
	int		x;
	int		y;
	char	*line;

	line = NULL;
	y = 0;
	while (y < d->m_height)
	{
		if (get_next_line(0, &line) < 0)
			ft_error(d, 1);
		x = 0;
		while (line[(x + 4)] != '\0' && x < d->m_width)
		{
			ft_fillrect(d, line, x, y);
			x++;
		}
		free(line);
		y++;
	}
	ft_score(d);
	d->count_p1 = 0;
	d->count_p2 = 0;
}

void			ft_map1(t_visudata *d, char *line)
{
	if (!ft_strncmp("Piece ", line, 6))
		ft_skip_piece(d, line);
	else if (!ft_strncmp("<got (X): ", line, 10) ||
		!ft_strncmp("<got (O): ", line, 10))
		free(line);
	else if (!ft_strncmp("Player with X: error on input", line, 29) ||
	!ft_strncmp("Player with O: error on input", line, 29))
		free(line);
	else if (!ft_strncmp("== O fin: ", line, 10) ||
		!ft_strncmp("== X fin: ", line, 10))
	{
		ft_final_score(d);
		d->close_request = 1;
		free(line);
	}
	else
		ft_error(d, 1);
}

void			ft_map(t_visudata *d)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		ft_error(d, 1);
	else if (!ft_strncmp("Plateau ", line, 8))
		ft_wid_heig_map(d, line);
	else if (!ft_strncmp("    0123456789", line, 14))
	{
		free(line);
		ft_draw_map(d);
	}
	else
		ft_map1(d, line);
}
