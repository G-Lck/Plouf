/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanetti <tzanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:51:11 by glucken           #+#    #+#             */
/*   Updated: 2025/07/16 23:22:40 by tzanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bsq.h"

int	get_x(int index, t_map smap)
{
	return (index % smap.x);
}

int	get_y(int index, t_map smap)
{
	return (index / smap.y);
}

int	get_column(char *str)
{
	int	i;
	int	l;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	l = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
		l++;
	}
	return (l);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}
