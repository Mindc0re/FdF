/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:10:59 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/25 16:48:31 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_line	*init_line(t_point *s, t_point *e, int i_x, int i_y, int color)
{
	t_line	*line;

	if (!(line = (t_line*)malloc(sizeof(line))))
		return (NULL);
	line->start = s;
	line->end = e;
	line->inc_x = i_x;
	line->inc_y = i_y;
	line->color = color;
	return (line);
}

static int		line_2(t_line *line, int dx, int dy, t_mlx *s_mlx)
{
	FT_INIT(int, cumul, (2 * dx) - dy);
	FT_INIT(int, incrE, 2 * dx);
	FT_INIT(int, incrNE, 2 * (dx - dy));
	FT_INIT(int, x, line->start->x);
	FT_INIT(int, y, line->start->y);

	while (y <= line->end->y)
	{
		y += line->inc_y;
		mlx_pixel_put(s_mlx->mlx, s_mlx->win, x, y, line->color);
		if (cumul >= 0)
		{
			x += line->inc_x;
			cumul += incrNE;
		}
		else
			cumul += incrE;
	}
	return (0);
}

static int		line_1(t_line *line, int dx, int dy, t_mlx *s_mlx)
{
	FT_INIT(int, cumul, (2 * dy) - dx);
	FT_INIT(int, incrE, 2 * dy);
	FT_INIT(int, incrNE, 2 * (dy - dx));
	FT_INIT(int, x, line->start->x);
	FT_INIT(int, y, line->start->y);

	while (x <= line->end->x)
	{
		x += line->inc_x;
		mlx_pixel_put(s_mlx->mlx, s_mlx->win, x, y, line->color);
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

int				draw_line(t_point *start, t_point *end, int color, t_mlx *s_mlx)
{
	FT_INIT(int, dx, end->x - start->x);
	FT_INIT(int, dy, end->y - start->y);
	int		inc_x;
	int		inc_y;
	t_line	*line;

	inc_x = dx < 0 ? -1 : 1;
	inc_y = dy < 0 ? -1 : 1;
	if (!(line = init_line(start, end, inc_x, inc_y, color)))
		return (-1);
	ft_abs(dx);
	ft_abs(dy);
	if (dx > dy)
		line_1(line, dx, dy, s_mlx);
	else
		line_2(line, dx, dy, s_mlx);
	ft_memdel((void **)&line);
	return (0);
}
