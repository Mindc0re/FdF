/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 10:36:39 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/31 16:20:20 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_all(t_all *all)
{
	free(all->cam->cam_pos);
	free(all->cam->cam_ang);
	free(all->rotation);
	free(all->midmap);
	free(all->cam);
}

void		free_map(t_pt3d *map)
{
	t_pt3d *tmp;

	tmp = (t_pt3d *)malloc(sizeof(t_pt3d));
	while (map)
	{
		tmp = map->next;
		ft_memdel((void **)&map->coord);
		ft_memdel((void **)map);
		map = tmp;
	}
	ft_memdel((void **)tmp);
}
