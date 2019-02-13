/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:55:52 by lpohribn          #+#    #+#             */
/*   Updated: 2018/09/06 15:55:54 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visualization.h"

int		main(void)
{
	t_visudata	d;

	ft_bzero(&d, sizeof(t_visudata));
	ft_check_header(&d);
	ft_check_players(&d);
	ft_init_sdl(&d);
	ft_draw_game(&d);
	ft_exit(&d, EXIT_SUCCESS);
}
