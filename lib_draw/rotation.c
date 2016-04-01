/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:04:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/01 17:17:48 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int			rotation(t_all *all)
{
	static int angle = 0;

	all->cam->cam_pos->x = all->midmap->x
		+ (30 * opcos(opmod(angle, 360)));
	all->cam->cam_pos->z = all->midmap->y
		+ (30 * opsin(opmod(angle, 360)));
	all->cam->cam_ang->y = opmod(all->cam->cam_ang->y - 10, 360);
	angle += 10;
	return (0);
}
