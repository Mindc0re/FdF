/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 11:35:37 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/31 17:43:29 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int				draw_map_y(t_all *all)
{
	t_pt3d		*tmp_x;
	t_pt3d		*tmp_prev;
	t_pt3d		*tmp;

	while (all->map->prev)
		all->map = all->map->prev;
	FT_MULTI4(tmp_x, tmp_prev, tmp, all->map);
	while (tmp_x->coord->y == 0)
	{
		while (tmp)
		{
			if (tmp->coord->x == tmp_x->coord->x
				&& tmp->coord->y == tmp_prev->coord->y + 1)
			{
				conversion3d(tmp_prev, all);
				conversion3d(tmp, all);
				rotation_x(tmp_prev, all);
				rotation_x(tmp, all);
				all->degrade = tmp->coord->z - tmp_prev->coord->z != 0 ? 1 : all->degrade;
				if (tmp->print && tmp_prev->print)
					draw_line(tmp_prev, tmp, all);
				tmp_prev = tmp;
			}
			else
				tmp = tmp->next;
		}
		tmp_x = tmp_x->next;
		FT_MULTI3(tmp, tmp_prev, tmp_x);
	}
	return (1);
}

int				draw_map_x(t_all *all)
{
	t_pt3d		*tmp;

	while (all->map->prev)
		all->map = all->map->prev;
	tmp = all->map;
	while (tmp)
	{
		if (tmp->next && tmp->next->coord->x == tmp->coord->x + 1
			&& tmp->next->coord->y == tmp->coord->y)
		{
			conversion3d(tmp, all);
			conversion3d(tmp->next, all);
			rotation_x(tmp, all);
			rotation_x(tmp->next, all);
			all->degrade = tmp->coord->z - tmp->next->coord->z != 0 ? 1 : 0;
			if (tmp->print && tmp->next->print)
				draw_line(tmp, tmp->next, all);
		}
		tmp = tmp->next;
	}
	draw_map_y(all);
	return (1);
}
