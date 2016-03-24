/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:45:11 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/24 17:47:52 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_line	*init_line2(t_pt3d *s, t_pt3d *e, double ix, double iy, int c)
{
	t_line *line;

	line = (t_line *)malloc(sizeof(t_line));
	line->start = (t_vector *)malloc(sizeof(t_vector));
	line->end = (t_vector *)malloc(sizeof(t_vector));
	line->start->x = s->x_2d;
	line->start->y = s->y_2d;
	line->end->x = e->x_2d;
	line->end->y = e->y_2d;
	line->inc_x = ix;
	line->inc_y = iy;
	line->color = c;
	return (line);
}

static int		line_2b(t_line *line, double dx, double dy, t_all *all)
{
	FT_INIT(double, x, line->start->x);
	FT_INIT(double, y, line->start->y);
	double	cumul;
	int		i;

	i = 1;
	cumul = fabs(dy) / 2;
	while (i <= fabs(dy))
	{
		i++;
		y += line->inc_y;
		cumul += fabs(dx);
		if (cumul >= fabs(dy))
		{
			cumul -= fabs(dy);
			x += line->inc_x;
		}
		mlx_pixel_put(all->mlx, all->win, x, y, line->color);
	}
	return (0);
}

static int		line_1b(t_line *line, double dx, double dy, t_all *all)
{
	FT_INIT(double, x, line->start->x);
	FT_INIT(double, y, line->start->y);
	double	cumul;
	int		i;

	i = 1;
	cumul = fabs(dx) / 2;
	while (i <= dx)
	{
		i++;
		x += line->inc_x;
		cumul += fabs(dy);
		if (cumul >= fabs(dx))
		{
			cumul -= fabs(dx);
			y += line->inc_y;
		}
		mlx_pixel_put(all->mlx, all->win, x, y, line->color);
	}
	return (0);
}

int				draw_line2(t_pt3d *start, t_pt3d *end, int color, t_all *all)
{
	FT_INIT(double, dx, end->x_2d - start->x_2d);
	FT_INIT(double, dy, end->y_2d - start->y_2d);
	double		inc_x;
	double		inc_y;
	t_line		*line;

	inc_x = dx < 0 ? -1 : 1;
	inc_y = dy < 0 ? -1 : 1;
	if (!(line = init_line2(start, end, inc_x, inc_y, color)))
		return (-1);
	dx = fabs(dx);
	dy = fabs(dy);
	mlx_pixel_put(all->mlx, all->win, start->x_2d, start->y_2d, color);
	if (dx > dy)
		line_1b(line, dx, dy, all);
	else
		line_2b(line, dx, dy, all);
	free(line->start);
	free(line->end);
	free(line);
	return (0);
}
