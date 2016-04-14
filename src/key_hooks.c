/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:47:58 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/14 17:46:43 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

void		key_hook_third(int keycode, t_all *all)
{
	static int on = 1;

	if (keycode == H)
	{
		if (on == 1)
		{
			mlx_clear_window(all->mlx, all->win);
			mlx_string_put(all->mlx, all->win, all->win_x / 2 - 205,
			all->win_y / 2 - 205, all->color,
			"Touches directionnelles pour bouger la ");
			help_fdf(all);
		}
		else
		{
			mlx_clear_window(all->mlx, all->win);
			draw_map_x(all);
		}
		on *= -1;
	}
	else if (keycode == KP_LESS)
		all->zoom -= 1;
	else if (keycode == W)
		all->cam->cam_ang->x += opmod(5, 360);
}

void		key_hook_second(int k, t_all *a)
{
	a->rotation->x = k == KP_4 ? -10 : FT_TER(k == KP_6, 10, a->rotation->x);
	a->rotation->y = k == KP_5 ? -10 : FT_TER(k == KP_8, 10, a->rotation->y);
	if (k == S)
		a->cam->cam_ang->x += opmod(-5, 360);
	else if (k == A)
		a->cam->cam_ang->y += opmod(-5, 360);
	else if (k == D)
		a->cam->cam_ang->y += opmod(5, 360);
	else if (k == ALT_L)
		a->cam->cam_ang->z += opmod(5, 360);
	else if (k == ALT_R)
		a->cam->cam_ang->z += opmod(-5, 360);
	else if (k == Q)
		a->depth -= 0.2;
	else if (k == E)
		a->depth += 0.2;
	else if (k == KP_4 || k == KP_6)
		rotation_x(a);
	else if (k == KP_5 || k == KP_8)
		rotation_y(a);
	else if (k == R)
		a->cam->cam_pos->z += 1;
	else if (k == F)
		a->cam->cam_pos->z -= 1;
}

int			key_hook_first(int keycode, t_all *all)
{
	if (keycode == ESC)
	{
		free_map(all->map);
		free_all(all);
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
	else if (keycode == KP_MORE)
		all->zoom += 1;
	key_hook_third(keycode, all);
	if (keycode != H)
	{
		key_hook_second(keycode, all);
		mlx_clear_window(all->mlx, all->win);
		draw_map_x(all);
	}
	printf("pos_x = %f, pos_y = %f, pos_z = %f, ang_x = %f, ang_y = %f, ang_z = %f\n",
		   all->cam->cam_pos->x, all->cam->cam_pos->y, all->cam->cam_pos->z, all->cam->cam_ang->x, all->cam->cam_ang->y, all->cam->cam_ang->z);
	return (1);
}
