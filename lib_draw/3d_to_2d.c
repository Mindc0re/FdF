/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_to_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:06:57 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/24 17:36:47 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			conversion3d(t_pt3d *point, t_all *all)
{
	FT_INIT(double, x_mod, 0);
	FT_INIT(double, y_mod, 0);
	FT_INIT(double, z_mod, 0);
	FT_INIT(double, x, point->coord->x - all->cam->cam_pos->x);
	FT_INIT(double, y, point->coord->y - all->cam->cam_pos->y);
	FT_INIT(double, z, point->coord->z - all->cam->cam_pos->z);

	x_mod = all->cam->cosy * (all->cam->sinz * y + all->cam->cosz * x)
		- all->cam->siny * z;
	y_mod = all->cam->sinx * (all->cam->cosy * z + (all->cam->siny *
			(all->cam->sinz * y + all->cam->cosz * x)))
		+ all->cam->cosx * (all->cam->cosz * y - all->cam->sinz * x);
	z_mod = all->cam->cosx * (all->cam->cosy * z + (all->cam->siny *
			(all->cam->sinz * y + all->cam->cosz * x))) - all->cam->sinx *
			(all->cam->cosz * y - all->cam->sinz * x);
	point->x_2d = ((-10 / z_mod) * x_mod) * all->zoom + 500 / 2;
	point->y_2d = ((-10 / z_mod) * y_mod) * all->zoom + 500 / 2;
	printf("x_2d = %f\n", point->x_2d);
	printf("y_2d = %f\n", point->y_2d);
	return (0);
}
