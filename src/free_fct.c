/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 10:36:39 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/24 17:34:32 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_all(t_all *all)
{
	ft_memdel((void **)all->cam->cam_pos);
	ft_memdel((void **)all->cam->cam_ang);
	ft_memdel((void **)all->cam);
}
