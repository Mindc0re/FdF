/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:47:58 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/11 15:32:44 by sgaudin          ###   ########.fr       */
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
			help_fdf(all);
		}
		else
		{
			mlx_clear_window(all->mlx, all->win);
			draw_map_x(all);
		}
		on *= -1;
	}
}

void		key_hook_second(int keycode, t_all *all)
{
	all->rotation->x = keycode == KP_4 ? -10 : FT_TER(keycode == KP_6, 10, all->rotation->x);
	all->rotation->y = keycode == KP_5 ? -10 : FT_TER(keycode == KP_8, 10, all->rotation->y);
	if (keycode == S)
		all->cam->cam_ang->x += opmod(-5, 360);
	else if (keycode == A)
		all->cam->cam_ang->y += opmod(-5, 360);
	else if (keycode == D)
		all->cam->cam_ang->y += opmod(5, 360);
	else if (keycode == ALT_L)
		all->cam->cam_ang->z += opmod(5, 360);
	else if (keycode == ALT_R)
		all->cam->cam_ang->z += opmod(-5, 360);
	else if (keycode == Q)
		all->depth -= 0.2;
	else if (keycode == E)
		all->depth += 0.2;
	else if (keycode == KP_4 || keycode == KP_6)
		rotation_x(all);
	else if (keycode == KP_5 || keycode == KP_8)
		rotation_y(all);
	else if (keycode == R)
		all->cam->cam_pos->z += 1;
	else if (keycode == F)
		all->cam->cam_pos->z -= 1;
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
	else if (keycode == KP_LESS)
		all->zoom -= 1;
	else if (keycode == W)
		all->cam->cam_ang->x += opmod(5, 360);
	if (keycode != H)
	{
		key_hook_second(keycode, all);
		mlx_clear_window(all->mlx, all->win);
		draw_map_x(all);
	}
	key_hook_third(keycode, all);
	return (1);
}
