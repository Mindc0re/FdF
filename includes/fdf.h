/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:20:27 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/28 11:26:22 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <time.h>

# define FT_INIT(t, n, v)	t n = v
# define FT_MULTI(a, b, c)	a = b = c

/* **************** COLORS *************** */
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00

/* **************** KEYS ***************** */
# define ESC		53
# define W			13
# define A			0
# define S			1
# define D			2

enum {
	GAUCHE = 123,
	DROITE,
	BAS,
	HAUT
}					dir_keys;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_camera
{
	t_vector		*cam_pos;
	t_vector		*cam_ang;
}					t_camera;

typedef struct		s_pt3d
{
	t_vector		*coord;
	double			x_2d;
	double			y_2d;
	struct s_pt3d	*prev;
	struct s_pt3d	*next;
}					t_pt3d;

typedef struct		s_line
{
	t_vector		*start;
	t_vector		*end;
	double			inc_x;
	double			inc_y;
	int				color;
}					t_line;

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	int				win_len;
	int				win_wid;
	int				color;
	t_camera		*cam;
	double			zoom;
	t_pt3d			*map;
}					t_all;

void				init_all(t_all *all);
void				init_pt(t_pt3d *pt, double x, double y, double z);
t_pt3d				*init_map(t_all *all, double z);

void				free_all(t_all *all);
void				free_map(t_pt3d *map);

int					key_hook_default(int keycode, t_all *all);

int					parser(int fd, t_all *all);
int					draw_map(t_all *all);

#endif
