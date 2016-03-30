/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:04:21 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/30 11:38:47 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int			rotation_x(t_pt3d *pt, t_all *all)
{
	if (all->rotation->x)
	{
		pt->coord->x = (pt->coord->x * opcos(all->rotation->x))
			- (pt->coord->y * opsin(all->rotation->x));
		pt->coord->y = (pt->coord->x * opsin(all->rotation->x))
			- (pt->coord->y * opcos(all->rotation->x));
	}
	return (0);
}
