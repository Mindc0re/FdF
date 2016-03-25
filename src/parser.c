/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:37:42 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/25 18:28:04 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

t_pt3d		*new_point(t_pt3d *map, int x, int y, int z)
{
	t_pt3d	*new;

	new = (t_pt3d *)malloc(sizeof(t_pt3d));
	new->coord = (t_vector *)malloc(sizeof(t_vector));
	new->coord->x = x;
	new->coord->y = y;
	new->coord->z = z;
	new->prev = map;
	new->next = NULL;
	return (new);
}

void	print_map(t_pt3d *map)
{
	int test = 0;
	while (map->prev)
	{
		ft_putnbr(test);
		ft_putchar('\n');
		test++;
		map = map->prev;
	}
	test = 0;
	while (map)
	{
		if (test == 19)
		{
			printf("\n");
			test = 0;
		}
		printf("%d ", (int)map->coord->z);
		map = map->next;
		test++;
	}
}

void		parser(int fd, t_all *all)
{
	FT_INIT(int, y, 0);
	FT_INIT(int, i, 0);
	char		*line;
	char		**split;
	t_pt3d		*map;

	line = ft_strnew(1);
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
	print_map(map);
}

int		main(int ac, char **av)
{
	int fd;
	t_all all;

	init_all(&all);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		parser(fd, &all);
//		print_map(&all);
	}
	else
	{
		ft_putstr("No file input\n");
		return (0);
	}
	return (0);
}
