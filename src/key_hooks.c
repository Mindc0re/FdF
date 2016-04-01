/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:47:58 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/01 17:06:50 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int			key_hook_second(int keycode, t_all *all)
{
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
	else if (keycode == KP_4)
	{
		rotation(all);
		all->rotation->x = -10;
	}
	else if (keycode == KP_6)
	{
		rotation(all);
		all->rotation->x = 10;
	}
	else if (keycode == KP_8)
	{
		rotation(all);
		all->rotation->y += 10;
	}
	else if (keycode == KP_5)
	{
		rotation(all);
		all->rotation->y -= 10;
	}
	else if (keycode == R)
		all->cam->cam_pos->z += 1;
	else if (keycode == F)
		all->cam->cam_pos->z -= 1;
	return (1);
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
	key_hook_second(keycode, all);
	mlx_clear_window(all->mlx, all->win);
	draw_map_x(all);
	return (1);
}
