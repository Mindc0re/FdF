/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 09:14:07 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/24 17:44:35 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int		fdf(int keycode, t_all *all)
{
	t_pt3d	st;
	t_pt3d	endx;
	t_pt3d	endy;
	t_pt3d	endz;

	if (keycode == ESC)
	{
		free_all(all);
		free(st.coord);
		free(endx.coord);
/*		free(endz.coord);
		free(endy.coord); */
		exit(EXIT_SUCCESS);
	}
	else if (keycode == GAUCHE)
		all->cam->cam_pos->x -= 10;
	else if (keycode == HAUT)
		all->cam->cam_pos->y -= 10;
	else if (keycode == DROITE)
		all->cam->cam_pos->x += 10;
	else if (keycode == BAS)
		all->cam->cam_pos->y += 10;
	else if (keycode == 34)
		all->zoom += 1;
	else if (keycode == 40)
		all->zoom -= 1;
	mlx_clear_window(all->mlx, all->win);

	init_pt(&st, 0, 0, 0);
	conversion3d(&st, all);
	init_pt(&endx, 30, 0, 0);
	conversion3d(&endx, all);

	init_pt(&endy, 0, 30, 0);
	conversion3d(&endy, all);

	init_pt(&endz, 0, 0, 15);
	conversion3d(&endz, all);

	draw_line2(&st, &endy, GREEN, all);
	draw_line2(&st, &endx, RED, all);
	draw_line2(&st, &endz, BLUE, all);
	return (0);
}

int		main()
{
	t_all	all;

	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, 500, 500, "FdF");
	init_all(&all);
	mlx_key_hook(all.win, fdf, &all);
	mlx_loop(all.mlx);
	return (0);
}
