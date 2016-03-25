/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 09:14:07 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/25 18:18:03 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int		fdf(int keycode, t_all *all)
{
	static	int		test = 0;
	static	t_pt3d	origin;
	static	t_pt3d	i;
	static	t_pt3d	j;
	static	t_pt3d	k;
	static	t_pt3d	l;
	static	t_pt3d	m;
	static	t_pt3d	n;
	static	t_pt3d	o;

	if (test == 0)
	{
		init_pt(&origin, 0, 0, 0);
		init_pt(&i, 1, 0, 0);
		init_pt(&j, 0, 1, 0);
		init_pt(&k, 0, 0, 1);
		init_pt(&l, 1, 0, 1);
		init_pt(&m, 0, 1, 1);
		init_pt(&n, 1, 1, 1);
		init_pt(&o, 1, 1, 0);
		test++;
	}
	if (keycode == ESC)
	{
		free_all(all);
		free(origin.coord);
		free(i.coord);
		free(j.coord);
		free(k.coord);
		free(l.coord);
		free(m.coord);
		free(n.coord);
		free(o.coord);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == GAUCHE)
		all->cam->cam_pos->x -= 1;
	else if (keycode == HAUT)
		all->cam->cam_pos->y -= 1;
	else if (keycode == DROITE)
		all->cam->cam_pos->x += 1;
	else if (keycode == BAS)
		all->cam->cam_pos->y += 1;
	else if (keycode == 34)
		all->zoom += 1;
	else if (keycode == 40)
		all->zoom -= 1;
	mlx_clear_window(all->mlx, all->win);

	conversion3d(&origin, all);
	conversion3d(&i, all);
	conversion3d(&j, all);
	conversion3d(&k, all);
	conversion3d(&l, all);
	conversion3d(&m, all);
	conversion3d(&n, all);
	conversion3d(&o, all);

	draw_line2(&origin, &i, GREEN, all);
	draw_line2(&origin, &j, RED, all);
	draw_line2(&origin, &k, BLUE, all);
	draw_line2(&j, &o, WHITE, all);
	draw_line2(&o, &i, WHITE, all);
	draw_line2(&i, &l, WHITE, all);
	draw_line2(&k, &l, WHITE, all);
	draw_line2(&o, &n, WHITE, all);
	draw_line2(&n, &l, WHITE, all);
	draw_line2(&m, &k, WHITE, all);
	draw_line2(&j, &m, WHITE, all);
	draw_line2(&m, &n, WHITE, all);
	return (0);
}

int		main()
{
	t_all	all;

	all.mlx = mlx_init();
	all.win_len = 500;
	all.win_wid = 500;
	all.win = mlx_new_window(all.mlx, all.win_len, all.win_wid, "FdF");
	init_all(&all);
	mlx_key_hook(all.win, fdf, &all);
	mlx_loop(all.mlx);
	return (0);
}
