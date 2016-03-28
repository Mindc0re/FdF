/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:14:19 by sgaudin           #+#    #+#             */
/*   Updated: 2016/03/28 09:59:39 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DRAW_H
# define LIB_DRAW_H

# include "fdf.h"

int				draw_line(t_pt3d *start, t_pt3d *end, int color, t_all *all);
int				conversion3d(t_pt3d *point, t_all *all);
double			opcos(double n);
double			opsin(double n);

#endif
