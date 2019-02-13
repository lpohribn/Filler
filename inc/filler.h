/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:03:55 by lpohribn          #+#    #+#             */
/*   Updated: 2018/08/01 19:03:57 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef	struct	s_player
{
	char		p1;
	char		p2;
}				t_player;

typedef	struct	s_board
{
	int			m_width;
	int			m_height;
	int			p_width;
	int			p_height;
	char		**map;
	char		**piece;
	int			**h_map;
	int			result_x;
	int			result_y;
	int			p_x;
	int			p_y;
	int			distance;
	int			flag;
	int			l;
	int			fd_place;
	t_player	p;
}				t_board;

int				ft_width(char *line);
int				ft_read_map(t_board *m, char *line);
int				ft_read_piece(t_board *m, char *line);
int				ft_width_height_map(char *line, t_board *m);
int				ft_create_heatmap(t_board *m);
void			ft_check_best_position(t_board *m, int y, int x);
int				ft_heatmap1(t_board *m);
int				ft_find_position(t_board *m);
int				ft_find_piece(t_board *m, int y, int x);

#endif
