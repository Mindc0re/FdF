/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:20:27 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/02 11:51:17 by sgaudin          ###   ########.fr       */
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

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_camera
{
	t_vector	*cam_pos;
	t_vector	*cam_ang;
	double		cosx;
	double		cosy;
	double		cosz;
	double		sinx;
	double		siny;
	double		sinz;
}				t_camera;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			color;
}				t_mlx;

typedef struct	s_point3d
{
	t_vector	*coord;
	double		x_2d;
	double		y_2d;
}				t_point3d;

typedef struct	s_line
{
	t_vector	*start;
	t_vector	*end;
	int			inc_x;
	int			inc_y;
	int			color;
}				t_line;

#endif
