/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:04:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/31 17:43:10 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int				rotation_x(t_pt3d *pt, t_all *all)
{
	double x_mod;
	double y_mod;

	if (all->rotation->x)
	{
		x_mod = all->cam->cam_pos->x - all->midmap->x;
		y_mod = all->cam->cam_pos->y - all->midmap->y;
		pt->x_2d += all->midmap->x + (x_mod * opcos(all->rotation->x))
						- (y_mod * opsin(all->rotation->x));
		pt->y_2d += all->midmap->y + (x_mod * opsin(all->rotation->x))
						+ (y_mod * opcos(all->rotation->x));
/*		pt->coord->x = (pt->coord->x * opcos(all->rotation->x))
			- (pt->coord->y * opsin(all->rotation->x));
		pt->coord->y = (pt->coord->x * opsin(all->rotation->x))
		- (pt->coord->y * opcos(all->rotation->x));*/
	}
	return (0);
}

