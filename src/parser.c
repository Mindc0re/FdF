/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:37:42 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/31 15:16:40 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

static t_pt3d		*new_point(t_pt3d *map, int x, int y, int z)
{
	t_pt3d	*new;

	new = (t_pt3d *)malloc(sizeof(t_pt3d));
	new->coord = (t_vector *)malloc(sizeof(t_vector));
	new->coord->x = x;
	new->coord->y = y;
	new->coord->z = z;
	new->prev = map;
	new->next = NULL;
	new->print = 1;
	return (new);
}

int					parser(int fd, t_all *all)
{
	char		**split;

	FT_INIT(int, y, 0);
	FT_INIT(int, i, 0);
	FT_INIT(char *, line, ft_strnew(1));
	FT_INIT(t_pt3d *, map, NULL);
	while (get_next_line(fd, &line))
	{
		split = ft_strsplit(line, ' ');
		i = 0;
		while (split[i])
		{
			if (!map)
			{
				map = init_map(all, ft_atoi(split[i]));
				i++;
			}
			map->next = new_point(map, i, y, ft_atoi(split[i]));
			map = map->next;
			i++;
		}
		y++;
	}
	return (1);
}
