/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_to_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:06:57 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/07 13:01:28 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int			conversion3d(t_pt3d *point, t_all *all)
{
	FT_INIT(double, tmp_z, point->coord->z);
	if (tmp_z)
		tmp_z *= all->depth;
	FT_INIT(double, x_mod, 0);
	FT_INIT(double, y_mod, 0);
	FT_INIT(double, z_mod, 0);
	FT_INIT(double, x, point->coord->x - all->cam->cam_pos->x);
	FT_INIT(double, y, point->coord->y - all->cam->cam_pos->y);
	FT_INIT(double, z, tmp_z - all->cam->cam_pos->z);
	x_mod = opcos(all->cam->cam_ang->y) * (opsin(all->cam->cam_ang->z) * y
		+ opcos(all->cam->cam_ang->z) * x) - (opsin(all->cam->cam_ang->y) * z);
	y_mod = opsin(all->cam->cam_ang->x) * (opcos(all->cam->cam_ang->y) * z
		+ (opsin(all->cam->cam_ang->y) * (opsin(all->cam->cam_ang->z) * y
		+ opcos(all->cam->cam_ang->z) * x))) + opcos(all->cam->cam_ang->x)
		* (opcos(all->cam->cam_ang->z) * y - opsin(all->cam->cam_ang->z) * x);
	z_mod = opcos(all->cam->cam_ang->x) * (opcos(all->cam->cam_ang->y) * z
		+ (opsin(all->cam->cam_ang->y) * (opsin(all->cam->cam_ang->z) * y
		+ opcos(all->cam->cam_ang->z) * x))) - opsin(all->cam->cam_ang->x)
		* (opcos(all->cam->cam_ang->z) * y - opsin(all->cam->cam_ang->z) * x);
	point->print = z_mod >= 0 ? 1 : 0;
	z_mod = z_mod == 0 ? 0.0001 : z_mod;
	point->x_2d = ((10 / z_mod) * x_mod) * all->zoom + all->win_len / 2;
	point->y_2d = ((10 / z_mod) * y_mod) * all->zoom + all->win_wid / 2;
//	printf("x_mod = %f, y_mod = %f, z_mod = %f\n", x_mod, y_mod, z_mod);
//	printf("pt->x_2d = %f, pt->y_2d = %f, pt->x = %f, pt->y = %f, pt->z = %f\n", point->x_2d, point->y_2d, point->coord->x, point->coord->y, point->coord->z);
	return (0);
}
