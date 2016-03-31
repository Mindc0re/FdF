/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 09:19:02 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/31 17:26:07 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

void		init_vector(t_vector *vector, double x, double y, double z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
}

void		init_all(t_all *all)
{
	all->cam = (t_camera *)malloc(sizeof(t_camera));
	all->cam->cam_pos = (t_vector *)malloc(sizeof(t_vector));
	all->cam->cam_ang = (t_vector *)malloc(sizeof(t_vector));
	all->midmap = (t_vector *)malloc(sizeof(t_vector));
	all->rotation = (t_vector *)malloc(sizeof(t_vector));
	all->zoom = 50;
	init_vector(all->cam->cam_pos, 0, 0, -30);
	init_vector(all->cam->cam_ang, 0, 0, 0);
	init_vector(all->rotation, 0, 0, 0);
	init_vector(all->midmap, 0, 0, 0);
	all->depth = 1;
	all->color = GOLD;
	all->degrade = 0;
}

void		init_pt(t_pt3d *pt, double x, double y, double z)
{
	pt->coord = (t_vector *)malloc(sizeof(t_vector));
	init_vector(pt->coord, x, y, z);
	pt->x_2d = x;
	pt->y_2d = y;
	pt->print = 1;
}

t_pt3d		*init_map(t_all *all, double z)
{
	t_pt3d *map;

	map = (t_pt3d *)malloc(sizeof(t_pt3d));
	map->coord = (t_vector *)malloc(sizeof(t_vector));
	map->coord->x = 0;
	map->coord->y = 0;
	map->coord->z = z;
	map->prev = NULL;
	map->next = NULL;
	all->map = map;
	return (map);
}
