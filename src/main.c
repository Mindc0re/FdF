/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:15:48 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/15 09:43:58 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int		main(int ac, char **av)
{
	t_all	all;

	if (ac >= 2)
	{
		all.mlx = mlx_init();
		all.win_x = (ac >= 4 && check_arg(av[2])) ? ft_atoi(av[2]) : 500;
		all.win_y = (ac >= 4 && check_arg(av[3])) ? ft_atoi(av[3]) : 500;
		all.win = mlx_new_window(all.mlx, all.win_x, all.win_y, "FdF");
		init_all(&all);
		if (ac == 5)
			check_color(av[4], &all);
		all.fd = open(av[1], O_RDONLY);
		if (all.fd == -1)
			exit(EXIT_FAILURE);
		parser(all.fd, &all);
		mlx_hook(all.win, 2, (1L << 0), key_hook_first, &all);
		draw_map_x(&all);
		mlx_loop(all.mlx);
	}
	else
		help_main();
	return (0);
}
