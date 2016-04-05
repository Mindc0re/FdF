/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/05 11:06:28 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int		main(int ac, char **av)
{
	int		fd;
	t_all	all;

	if (ac >= 2)
	{
		all.mlx = mlx_init();
		all.win_len = (ac == 4 && check_arg(av[2])) ? ft_atoi(av[2]) : 500;
		all.win_wid = (ac == 4 && check_arg(av[3])) ? ft_atoi(av[3]) : 500;
		all.win = mlx_new_window(all.mlx, all.win_len, all.win_wid, "FdF");
		init_all(&all);
		if (ac == 5)
			check_color(av[4], &all);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit(EXIT_FAILURE);
		parser(fd, &all);
		mlx_key_hook(all.win, key_hook_first, &all);
		draw_map_x(&all);
		mlx_loop(all.mlx);
	}
	else
		ft_putstr("No file input\n");
	return (0);
}
