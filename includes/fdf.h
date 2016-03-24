/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:20:27 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/24 17:35:32 by sgaudin          ###   ########.fr       */
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
# define ESC 53

enum
{
				GAUCHE = 123,
				DROITE,
				BAS,
				HAUT
}				dir_keys;

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

typedef struct	s_pt3d
{
	t_vector	*coord;
	double		x_2d;
	double		y_2d;
}				t_pt3d;

typedef struct	s_line
{
	t_vector	*start;
	t_vector	*end;
	double		inc_x;
	double		inc_y;
	int			color;
}				t_line;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	int			color;
	t_camera	*cam;
	t_vector	*me;
	double		zoom;
}				t_all;

void	init_all(t_all *all);
void	free_all(t_all *all);
void	init_pt(t_pt3d *pt, double x, double y, double z);

#endif










