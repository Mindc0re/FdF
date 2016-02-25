/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:20:00 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/25 17:40:14 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int			draw_square_drug(int keycode, t_mlx *mlx_s)
{
	static t_point *start_x = NULL;
	static t_point *start_y = NULL;
	static t_point *end_x = NULL;
	static t_point *end_y = NULL;

	if (!start_x && !start_y && !end_y && !end_x)
	{
		end_y = (t_point *)malloc(sizeof(end_y));
		start_y = (t_point *)malloc(sizeof(start_y));
		end_x = (t_point *)malloc(sizeof(end_x));
		start_x = (t_point *)malloc(sizeof(start_x));
		start_x->x = 50;
		start_x->y = 50;
		end_x->x = 50;
		end_x->y = 300;
		start_y->x = 50;
		start_y->y = 50;
		end_y->x = 300;
		end_y->y = 50;
	}
	if (keycode == 53) // ESC
	{
		free(start_x);
		free(start_y);
		free(end_x);
		free(end_y);
		free(mlx_s);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == HAUT)
	{
		mlx_clear_window(mlx_s->mlx, mlx_s->win);
		start_x->y -= 10;
		end_x->y -= 10;
		start_y->y -= 10;
		end_y->y -= 10;
	}
	else if (keycode == BAS)
	{
		mlx_clear_window(mlx_s->mlx, mlx_s->win);
		start_x->y += 10;
		end_x->y += 10;
		start_y->y += 10;
		end_y->y += 10;
	}
	else if (keycode == DROITE)
	{
		mlx_clear_window(mlx_s->mlx, mlx_s->win);
		start_x->x += 10;
		end_x->x += 10;
		start_y->x += 10;
		end_y->x += 10;
	}
	else if (keycode == GAUCHE)
	{
		mlx_clear_window(mlx_s->mlx, mlx_s->win);
		start_x->x -= 10;
		end_x->x -= 10;
		start_y->x -= 10;
		end_y->x -= 10;
	}
	draw_line(start_x, end_x, RED, mlx_s);
	draw_line(start_y, end_y, GREEN, mlx_s);
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
