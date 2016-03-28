/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:47:58 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/28 15:10:33 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int			key_hook_default(int keycode, t_all *all)
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
	else if (keycode == 34)
		all->zoom += 1;
	else if (keycode == 40)
		all->zoom -= 1;
	else if (keycode == W)
		all->cam->cam_ang->x += 5;
	else if (keycode == S)
		all->cam->cam_ang->x -= 5;
	else if (keycode == A)
		all->cam->cam_ang->y -= 5;
	else if (keycode == D)
		all->cam->cam_ang->y += 5;
	mlx_clear_window(all->mlx, all->win);
	draw_map_x(all);
	return (1);
}
