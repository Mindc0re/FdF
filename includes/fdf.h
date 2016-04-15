/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:20:27 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/15 09:43:27 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <time.h>

# define FT_INIT(t, n, v)			t n = v
# define FT_MULTI3(a, b, c)			a = b = c
# define FT_MULTI4(a, b, c, d)		a = b = c = d
# define FT_TER(si, alors, sinon)	si ? alors : sinon

# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define PINK 0x00F400A1
# define GOLD 0x00FFD700

enum {
	ESC = 53,
	GAUCHE = 123,
	DROITE,
	BAS,
	HAUT,
	Q = 12,
	W,
	E,
	A = 0,
	S,
	D,
	R = 15,
	F = 3,
	H,
	KP_MORE = 69,
	KP_LESS = 78,
	KP_1 = 83,
	KP_2,
	KP_3,
	KP_4,
	KP_5,
	KP_6,
	KP_7,
	KP_8 = 91,
	KP_9,
	ALT_L = 261,
	ALT_R
}					keys;

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
	int				print;
	struct s_pt3d	*prev;
	struct s_pt3d	*next;
}					t_pt3d;

typedef struct		s_line
{
	t_vector		*start;
	t_vector		*end;
	double			inc_x;
	double			inc_y;
}					t_line;

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	int				fd;
	int				win_x;
	int				win_y;
	int				color;
	int				degrade;
	double			depth;
	double			zoom;
	t_camera		*cam;
	t_pt3d			*map;
	t_vector		*midmap;
	t_vector		*rotation;
}					t_all;

void				init_all(t_all *all);
void				init_pt(t_pt3d *pt, double x, double y, double z);
void				init_vector(t_vector *vector, double x, double y, double z);
t_pt3d				*init_map(t_all *all, double z);

void				free_all(t_all *all);
void				free_map(t_pt3d *map);

int					key_hook_first(int keycode, t_all *all);

void				parser(int fd, t_all *all);

int					check_arg(char *str);
int					check_color(char *str, t_all *all);

void				help_main(void);
void				help_fdf(t_all *all);
#endif
