/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanetti <tzanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:58:32 by glucken           #+#    #+#             */
/*   Updated: 2025/07/16 23:37:55 by tzanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	*get_int_map(char *map, t_map smap)
{
	int	*int_map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	int_map = malloc(sizeof(int) * (smap.x * smap.y) + 1);
	if (!int_map)
		return (NULL);
	while (map[j])
	{
		if (map[j] == '\n')
			j++;
		if (map[j] == smap.block)
			int_map[i] = 0;
		else
			int_map[i] = 1;
		j++;
		i++;
	}
	return (int_map);
}
