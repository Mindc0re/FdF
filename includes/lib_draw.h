/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:14:19 by sgaudin           #+#    #+#             */
/*   Updated: 2016/02/25 15:56:07 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_DRAW_H
# define LIB_DRAW_H

# include "fdf.h"

int				draw_line(t_point *start, t_point *end, int color, t_mlx *s_mlx);

#endif
