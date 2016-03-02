/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:22:42 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/02 11:57:16 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"
#include <stdio.h>

t_camera	*init_cam(void)
{
	t_camera *cam;

	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->cam_ang = (t_vector *)malloc(sizeof(t_vector));
	cam->cam_pos = (t_vector *)malloc(sizeof(t_vector));
	cam->cam_ang->x = 0;
	cam->cam_ang->y = 0;
	cam->cam_ang->z = 0;
	cam->cam_pos->x = 0;
	cam->cam_pos->y = 0;
	cam->cam_pos->z = 0;
	cam->cosx = cos(cam->cam_ang->x);
	cam->cosy = cos(cam->cam_ang->y);
	cam->cosz = cos(cam->cam_ang->z);
	cam->sinx = sin(cam->cam_ang->x);
	cam->siny = sin(cam->cam_ang->y);
	cam->sinz = sin(cam->cam_ang->z);
	return (cam);
}

int			fdf(int keycode, t_mlx *mlx)
{
	static t_camera		*cam = NULL;
	static t_point3d	*point_xs = NULL;
	static t_point3d	*point_xe = NULL;

	if (!cam || !point_xs)
	{
		mlx->color = RED;
		point_xs = (t_point3d *)malloc(sizeof(t_point3d));
		point_xs->coord = (t_vector *)malloc(sizeof(t_vector));
		point_xs->coord->x = 50;
		point_xs->coord->y = 50;
		point_xs->coord->z = 0;
		point_xe = (t_point3d *)malloc(sizeof(t_point3d));
		point_xe->coord = (t_vector *)malloc(sizeof(t_vector));
		point_xe->coord->x = 350;
		point_xe->coord->y = 350;
		point_xe->coord->z = 0;
		cam = init_cam();
	}
	if (keycode == 53)
	{
		printf("1\n");
		free(cam->cam_pos);
		printf("2\n");
		free(cam->cam_ang);
		printf("3\n");
		free(cam);
		printf("4\n");
		free(point_xs->coord);
		printf("5\n");
		free(point_xs);
		printf("6\n");
		free(point_xe->coord);
		printf("7\n");
		free(point_xe);
		printf("8\n");
		exit(EXIT_SUCCESS);
	}
	if (keycode == HAUT)
	{
/*		conversion3d(point_xs, cam);
		printf("XS ---> x = %f et y %f\n", point_xs->coord->x, point_xs->coord->y);
		conversion3d(point_xe, cam);
		printf("XE ---> x = %f et y %f\n", point_xe->coord->x, point_xe->coord->y); */
		draw_line(point_xs, point_xe, RED, mlx);
	}
	return (0);
}

int		main(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 500, 500, "FDF MA CAILLE");
	mlx_key_hook(mlx->win, fdf, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}




