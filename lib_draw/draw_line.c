/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:27:56 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/18 19:34:02 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		d_incx(int start[2], int inc_tab[2], int m_tab[2], int color)
{
	FT_INIT(int, cumul, mx / 2);
	FT_INIT(int, x, start[0]);
	FT_INIT(int, y, start[1]);

	while (x <= inc_tab[0])
	{
		x += inc_tab[0];
		cumul += m_tab[1];
		if (cumul >= m_tab[0])
		{
			cumul -= m_tab[0];
			y += inc_tab[1];
		}
		mlx_pixel_put(list->mlx, list->win, x, y, color);
	}
}

void		draw_line(int start[2], int end[2], t_mlx *list)
{
	FT_INIT(int, mx, end[0] - start[0]);
	FT_INIT(int, my, end[1] - start[1]);
	FT_INIT(int, inc_x, 0);
	FT_INIT(int, inc_y, 0);
	FT_INIT(int, color, WHITE);

	inc_x = mx < 0 ? -1 : 1;
	inc_y = my < 0 ? -1 : 1;
	ft_abs(mx);
	ft_abs(my);
	FT_INIT_COORD(int, m_tab[2], mx, my);
	FT_INIT_COORD(int, inc_tab[2], inc_x, inc_y);
	mlx_pixel_put(list->mlx, list->win, start[0], start[1], color);
	if (mx > my)
		d_incx(start, inc_tab, m_tab, list, color);
	else
		d_incy(start, inc_x, inc_y, list, color);
}
