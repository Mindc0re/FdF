/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_to_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:06:57 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/02 11:29:23 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			conversion3d(t_point3d *point, t_camera *cam)
{
	FT_INIT(double, x_mod, 0);
	FT_INIT(double, y_mod, 0);
	FT_INIT(double, z_mod, 0);
	FT_INIT(double, x, point->coord->x - cam->cam_pos->x);
	FT_INIT(double, y, point->coord->y - cam->cam_pos->y);
	FT_INIT(double, z, point->coord->z - cam->cam_pos->z);

	x_mod = (cam->cosy * (cam->sinz * y + cam->cosz * x)) - cam->siny * z;
	y_mod = (cam->sinx * (cam->cosy * z + cam->siny *
						(cam->sinz * y + cam->cosz * x))) + (cam->cosx *
						(cam->cosz * y - cam->sinz * x));
	z_mod = (cam->cosx * (cam->cosy * z + cam->siny *
						(cam->sinz * y + cam->cosz * x))) - (cam->sinx *
						(cam->cosz * y - cam->sinz * x));
	point->x_2d = ((-20 / z_mod) * x_mod) - -250;
	point->y_2d = ((-20 / z_mod) * y_mod) - -250;
	return (0);
}
