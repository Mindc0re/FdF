/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:20:27 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/25 17:27:02 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <time.h>

# define FT_INIT(t, n, v)	t n = v

/* **************** COLORS *************** */
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00

/* **************** KEYS ***************** */
enum
{
				GAUCHE = 123,
				DROITE,
				BAS,
				HAUT
}				keys;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			color;
}				t_mlx;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_line
{
	t_point		*start;
	t_point		*end;
	int			inc_x;
	int			inc_y;
	int			color;
}				t_line;

#endif
