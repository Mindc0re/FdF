/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:10:59 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/24 14:44:25 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_line	*init_line(t_pt3d *s, t_pt3d *e, double ix, double iy, int c)
{
	t_line		*line;

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

static int		line_2(t_line *line, double dx, double dy, t_all *all)
{
	FT_INIT(double, cumul, (2 * dx) - dy);
	FT_INIT(double, incrE, 2 * dx);
	FT_INIT(double, incrNE, 2 * (dx - dy));
	FT_INIT(double, x, line->start->x);
	FT_INIT(double, y, line->start->y);
	FT_INIT(int, i, 0);
	while (y <= line->end->y)
	{
		y += line->inc_y;
		if (x >= 0 && y >= 0)
			mlx_pixel_put(all->mlx, all->win, x, y, line->color);
		if (cumul >= 0)
		{
			x += line->inc_x;
			cumul += incrNE;
		}
		else
			cumul += incrE;
		i++;
	}
	return (0);
}

static int		line_1(t_line *line, double dx, double dy, t_all *all)
{
	FT_INIT(double, cumul, (2 * dy) - dx);
	FT_INIT(double, incrE, 2 * dy);
	FT_INIT(double, incrNE, 2 * (dy - dx));
	FT_INIT(double, x, line->start->x);
	FT_INIT(double, y, line->start->y);
	while (x <= line->end->x)
	{
		x += line->inc_x;
		if (x >= 0 && y >= 0)
			mlx_pixel_put(all->mlx, all->win, x, y, line->color);
		if (cumul >= 0)
		{
			y += line->inc_y;
			cumul += incrNE;
		}
		else
			cumul += incrE;
	}
	return (0);
}

int				draw_line(t_pt3d *start, t_pt3d *end, int color, t_all *all)
{
	FT_INIT(double, dx, end->x_2d - start->x_2d);
	FT_INIT(double, dy, end->y_2d - start->y_2d);
	double		inc_x;
	double		inc_y;
	t_line	*line;

	inc_x = dx < 0 ? -1 : 1;
	inc_y = dy < 0 ? -1 : 1;
	if (!(line = init_line(start, end, inc_x, inc_y, color)))
		return (-1);
	ft_abs(dx);
	ft_abs(dy);
	if (dx > dy)
		line_1(line, dx, dy, all);
	else
		line_2(line, dx, dy, all);
	free(line->start);
	free(line->end);
	free(line);
	return (0);
}
