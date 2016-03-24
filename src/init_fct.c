/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 09:19:02 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/24 17:37:17 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

void		init_all(t_all *all)
{
	all->cam = (t_camera *)malloc(sizeof(t_camera));
	all->cam->cam_pos = (t_vector *)malloc(sizeof(t_vector));
	all->cam->cam_ang = (t_vector *)malloc(sizeof(t_vector));
	all->zoom = 90;
	all->cam->cam_pos->x = 0;
	all->cam->cam_pos->y = 0;
	all->cam->cam_pos->z = -10;
	all->cam->cam_ang->x = 0;
	all->cam->cam_ang->y = 0;
	all->cam->cam_ang->z = 0;
	all->cam->cosx = cos(all->cam->cam_ang->x);
	all->cam->cosy = cos(all->cam->cam_ang->y);
	all->cam->cosz = cos(all->cam->cam_ang->z);
	all->cam->sinx = sin(all->cam->cam_ang->x);
	all->cam->siny = sin(all->cam->cam_ang->y);
	all->cam->sinz = sin(all->cam->cam_ang->z);
}

void	init_pt(t_pt3d *pt, double x, double y, double z)
{
	pt->coord = (t_vector *)malloc(sizeof(t_vector));
	pt->coord->x = x;
	pt->coord->y = y;
	pt->coord->z = z;
	pt->x_2d = x;
	pt->y_2d = y;
}
