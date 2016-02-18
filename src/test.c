/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:20:00 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 19:33:01 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			draw_square_drug(int keycode, t_mlx *mlx_s)
{
	FT_INIT(int, x, 0);
	FT_INIT(int, tmp_x, 0);
	FT_INIT(int, max_x, 0);
	FT_INIT(int, y, 0);
	FT_INIT(int, tmp_y, 0);
	FT_INIT(int, max_y, 0);
	FT_INIT(int, color, 0);

	FT_INIT_COORD(int, start[2], 10, 10);
	FT_INIT_COORD(int, end[2], 100, 100);
	srand(time(NULL) + rand());
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 2)
	{
		mlx_clear_window(mlx_s->mlx, mlx_s->win);
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 0, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 25, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 50, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 75, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 100, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 125, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 150, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 175, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 200, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 225, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 250, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 275, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 300, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 325, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 350, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 375, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 400, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 425, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 450, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 475, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
		mlx_string_put(mlx_s->mlx, mlx_s->win, 0, 500, (rand()%(16777215 - 255) + 255), "Dieuson a deserte a 14h...");
	}
	else if (keycode == 49)
	{
		/*
		x = (rand()%(500 - 1) + 1);
		max_x = x + 50;
		tmp_x = x;
		y = (rand()%(500 - 1) + 1);
		max_y = y + 50;
		tmp_y = y;
		color = (rand()%(16777215 - 255) + 255);
		while (y < max_y)
		{
			x = tmp_x;
			while (x < max_x)
			{
				mlx_pixel_put(mlx_s->mlx, mlx_s->win, x, y, color);
				x++;
			}
			y++;
			} */
		draw_line(start, end, mlx_s);
	}
	return (0);
}

int			main(void)
{
	t_mlx	*mlx_s;

	mlx_s = (t_mlx *)malloc(sizeof(mlx_s));
	mlx_s->mlx = mlx_init();
	mlx_s->win = mlx_new_window(mlx_s->mlx, 500, 500, "360BlazeItFDFNOSCOPE");
	mlx_key_hook(mlx_s->win, draw_square_drug, mlx_s);
	mlx_loop(mlx_s->mlx);
	return (0);
}
