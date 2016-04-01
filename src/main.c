/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/01 12:44:52 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int		main(int ac, char **av)
{
	int		fd;
	t_all	all;

	all.mlx = mlx_init();
	all.win_len = 500;
	all.win_wid = 500;
	all.win = mlx_new_window(all.mlx, all.win_len, all.win_wid, "FdF");
	init_all(&all);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		parser(fd, &all);
		mlx_key_hook(all.win, key_hook_first, &all);
		draw_map_x(&all);
		mlx_loop(all.mlx);
	}
	else
	{
		ft_putstr("No file input\n");
		return (0);
	}
	return (0);
}
