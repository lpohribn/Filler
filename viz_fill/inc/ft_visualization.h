/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualization.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 16:06:32 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/06 16:06:34 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUALIZATION_H
# define FT_VISUALIZATION_H

# include <stdio.h>
# include "libft.h"
# include <string.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>

# define WIN_W 1300
# define WIN_H 1100
# define FPS 60

typedef	struct	s_visudata
{
	int				m_width;
	int				m_height;
	int				p_height;
	int				p_width;
	char			*p1;
	char			*p2;
	int				count_p1;
	int				count_p2;
	int				s_rect;
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Surface		*s;
	SDL_Surface		*text_surface;
	SDL_Surface		*text_p1;
	SDL_Surface		*text_p2;
	TTF_Font		*font_big;
	TTF_Font		*font;
	int				w_text1;
	int				h_text1;
	int				w_text2;
	int				h_text2;
	int				c_p1;
	int				c_p2;
	int				close_request;
}				t_visudata;

void			ft_check_header(t_visudata *d);
void			ft_check_players(t_visudata *d);
int				ft_width(char *line);
void			ft_wid_heig_map(t_visudata *d, char *line);
void			ft_error(t_visudata *d, int error);
void			ft_exit(t_visudata *d, int status);
void			ft_map(t_visudata *d);
void			ft_init_sdl(t_visudata *d);
void			ft_draw_game(t_visudata *d);
void			ft_skip_piece(t_visudata *d, char *line);
int				ft_event(t_visudata *d, int stop);
void			ft_score(t_visudata *d);
void			ft_final_score(t_visudata *d);

#endif
