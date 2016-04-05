/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:41:32 by sgaudin           #+#    #+#             */
/*   Updated: 2016/04/05 11:07:03 by sgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/lib_draw.h"

int			check_arg(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	if (ft_atoi(str) < 500 || ft_atoi(str) > 1920)
		return (0);
	return (1);
}

int			check_color(char *str, t_all *all)
{
	FT_INIT(int, i, 0);
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			i++;
		else
			return (0);
	}
	ft_strtoupper(str);
	if (!strcmp(str, "WHITE"))
		all->color = WHITE;
	else if (!strcmp(str, "RED"))
		all->color = RED;
	else if (!strcmp(str, "GREEN"))
		all->color = GREEN;
	else if (!strcmp(str, "BLUE"))
		all->color = BLUE;
	else if (!strcmp(str, "PINK"))
		all->color = PINK;
	else if (!strcmp(str, "GOLD"))
		all->color = GOLD;
	else
		all->color = WHITE;
	return (1);
}
